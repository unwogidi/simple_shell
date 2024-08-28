#include "shell.h"

/**
 * main - checks the code
 *
 * Return: 0 Success
 */
int main(void)
{
	char input[BUFFER_SIZE];

	while (1)
	{
		display_prompt();
		read_input(input);

		/* Handle the "exit" command to exit the shell */
		if (_strcmp(input, "exit") == 0)
		{
			break;
		}

		/* Execute the command */
		execute_command(input);
	}

	return (0);
}
