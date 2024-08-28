#include "shell.h"

/**
 * main - checks the code
 *
 * Return: 0 Success
 */
int main(void)
{
	char input[BUFFER_SIZE];
	char *argv[BUFFER_SIZE / 2 + 1];

	while (1)
	{
		display_prompt();
		read_input(input);

		/* Handle the "exit" command to exit the shell */
		if (_strcmp(input, "exit") == 0)
		{
			break;
		}

		/* Parse the input into arguments */
		parse_input(input, argv);

		/* Execute the command */
		execute_command(argv);
	}

	return (0);
}
