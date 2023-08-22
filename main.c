#include "monty.h"

carry_t con = {NULL, NULL, NULL, 0};

int Custom_execute(char *one, stack_t **two, unsigned int three, FILE *four);
void Main_Cutsom_free_stack(stack_t *one);

/**
 * main - Entry Function to monty
 * code interpreter.
 *
 * @argc: int that represent the
 * number of arguments.
 * @argv: char pointer that points
 * to the monty file location.
 *
 * Return: 0 on success,
 * 1 (EXIT_FAILURE) on fail.
 */
int main(int argc, char *argv[])
{
	char *one;
	FILE *two;
	size_t three = 0;
	ssize_t four = 1;
	stack_t *five = NULL;
	unsigned int six = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		two = fopen(argv[1], "r");
		con.two = two;
		if (!two)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		else
		{
			while (four > 0)
			{
				one = NULL;
				four = getline(&one, &three, two);
				con.three = one;
				six++;
				if (four > 0)
				{
					Custom_execute(one, &five, six, two);
				}
				free(one);
			}
			Main_Cutsom_free_stack(five);
			fclose(two);
			return (0);
		}
	}
}

/**
 * Custom_execute - This Function executes
 * the opcode.
 * @two: Double stack_t pointer that points
 * to the head linked list - stack.
 * @three: Int that represent line_counter.
 * @four: File pointer that points to the
 * monty file
 * @one: char pointer that points to the
 * line content.
 * Return: Int 0 fail or 1 success.
 */
int Custom_execute(char *one, stack_t **two, unsigned int three, FILE *four)
{
	instruction_t seven[] = {
		{"nop", Custom_nop}, {"sub", Custom_sub}, {"div", Custom_div},
		{"push", Cutsom_push}, {"pall", Custom_pall}, {"pint", Custom_print},
		{"mul", Cutsom_mul}, {"mod", Cutsom_mod}, {"pchar", Cutsom_pchar},
		{"pop", Custom_pop}, {"swap", Custom_swap}, {"add", Custom_add},
		{"pstr", Cutsom_pstr}, {"rotl", Cutsom_rotl}, {"rotr", Cutsom_rotr},
		{"queue", Cutsom_queue}, {"stack", Cutsom_stack}, {NULL, NULL}};

	unsigned int five = 0;
	char *six;

	six = strtok(one, " \n\t");
	if (six && six[0] == '#')
	{
		return (0);
	}
	else
	{
		con.one = strtok(NULL, " \n\t");
		while (seven[five].opcode && six)
		{
			if (strcmp(six, seven[five].opcode) == 0)
			{
				seven[five].f(two, three);
				return (0);
			}
			five++;
		}
		if (six && seven[five].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", three, six);
			fclose(four);
			free(one);
			Main_Cutsom_free_stack(*two);
			exit(EXIT_FAILURE);
		}
		return (1);
	}
}

/**
 * Main_Cutsom_free_stack - This Function frees A
 * doubly linked list.
 *
 * @one: stack_t pointer that points
 * to the head of the stack.
 *
 * Return: Nothing(Void).
 */
void Main_Cutsom_free_stack(stack_t *one)
{
	stack_t *two;

	two = one;
	while (one)
	{
		two = one->next;
		free(one);
		one = two;
	}
}
