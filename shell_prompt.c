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
}

/**
 * parse_input - parse input into arguments
 * @input: input
 * @argv: pointer to a pointer
 *
 * Return: Nothing
 */
void parse_input(char *input, char **argv)
{
	int i = 0;

	argv[i] = strtok(input, " ");
	while (argv[i] != NULL)
	{
		i++;
		argv[i] = strtok(NULL, " ");
	}
}


/**
 * execute_command - executes a command
 * @argv: pointer to a pointer of a argument
 *
 * Return: Nothing
 */
void execute_command(char **argv)
{
	pid_t pid = fork();

	if (argv[0] == NULL)
	{
		return;
	}

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
