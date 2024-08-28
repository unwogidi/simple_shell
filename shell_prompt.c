#include "shell.h"

/**
 * display_prompt - displays the shell prompt
 *
 * Return: Nothing.
 */
void display_prompt(void)
{
	const char prompt[] = "$ ";

	write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
}


/**
 * read_input - reads input from the user
 * @input: inputs
 *
 * Return: Nothing
 */
void read_input(char *input)
{
	ssize_t bytes_read;

	/* Read input from stdin using the read system call */
	bytes_read = read(STDIN_FILENO, input, BUFFER_SIZE - 1);
	if (bytes_read == -1)
	{
		/* Handle read error */
		handle_error("Read error\n");
		exit(EXIT_FAILURE);
	}
	else if (bytes_read == 0)
	{
		/* Handle Ctrl+D (EOF) */
		const char newline[] = "\n";

		write(STDOUT_FILENO, newline, sizeof(newline) - 1);
		exit(0);
	}

	/* Null-terminate the input string */
	input[bytes_read] = '\0';

	/* Remove the newline character from the input */
	input[_strcspn(input, "\n")] = 0;

	/* Handle empty input */
	if (_strcmp(input, "") == 0)
	{
		input[0] = '\0'; /* Ensure the input is an empty string */
	}
}


/**
 * execute_command - executes a command
 * @input: inputs
 *
 * Return: Nothing
 */
void execute_command(char *input)
{
	char *argv[2];
	pid_t pid = fork();

	if (input[0] == '\0')
		return;

	argv[0] = input;
	argv[1] = NULL;

	if (pid == 0)
	{
		/* Child process */
		if (execvp(argv[0], argv) == -1)
		{
			handle_error("$: No such file or directory\n");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		/* Fork failed */
		handle_error("Fork failed\n");
	}
	else
	{
		/* Parent process */
		wait(NULL);
	}
}


/**
 * handle_error - handles errors and write error messages
 * @message: messages
 *
 * Return: Nothing.
 */
void handle_error(char *message)
{
	write(STDERR_FILENO, message, _strlen(message));
}
