#include "monty.h"

/**
 * Cutsom_push - This Function add node to the stack.
 *
 * @one: stack_t pointer that points
 * to the stack head.
 * @two: Int that represent the line_number.
 *
 * Return: Nothing(Void).
 */
void Cutsom_push(stack_t **one, unsigned int two)
{
	int three;
	int four = 0;
	int five = 0;

	if (con.one)
	{
		if (con.one[0] == '-')
			four++;
		for (; con.one[four] != '\0'; four++)
		{
			if (con.one[four] > 57 || con.one[four] < 48)
				five = 1;
		}
		if (five == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", two);
			fclose(con.two);
			free(con.three);
			Cutsom_free_stack(*one);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", two);
		fclose(con.two);
		free(con.three);
		Cutsom_free_stack(*one);
		exit(EXIT_FAILURE);
	}
	three = atoi(con.one);
	if (con.four == 0)
	{
		Custom_addnode(one, three);
	}
	else
	{
		Custom_addqueue(one, three);
	}
}

/**
 * Custom_pall - This Function prints
 * the stack.
 *
 * @one: stack_t pointer that points
 * to the stack head.
 * @two: Int That has no use.
 *
 * Return: Nothing(Void).
 */
void Custom_pall(stack_t **one, unsigned int two)
{
	stack_t *three;
	(void)two;

	three = *one;
	if (three == NULL)
	{
		return;
	}
	else
	{
		while (three)
		{
			printf("%d\n", three->n);
			three = three->next;
		}
	}
}

/**
 * Cutsom_free_stack - This Function frees A
 * doubly linked list.
 *
 * @one: stack_t pointer that points
 * to the head of the stack.
 *
 * Return: Nothing(Void).
 */
void Cutsom_free_stack(stack_t *one)
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

/**
 * Custom_addnode - This function add node
 * to the head stack.
 *
 * @one: stack_t pointer that points
 * to the head of the stack.
 * @two: Int that represent the new value.
 *
 * Return: Nothing(Void).
 */
void Custom_addnode(stack_t **one, int two)
{

	stack_t *three, *four;

	four = *one;
	three = malloc(sizeof(stack_t));
	if (three == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	else
	{
		if (four)
			four->prev = three;
		three->n = two;
		three->next = *one;
		three->prev = NULL;
		*one = three;
	}
}

/**
 * Custom_addqueue - This Function add node to
 * the tail stack.
 *
 * @two: Int that reprsent the new value to add.
 * @one: stack_t pointer that points to
 * the head of the stack.
 *
 * Return: Nothing(Void).
 */
void Custom_addqueue(stack_t **one, int two)
{
	stack_t *three, *four;

	four = *one;
	three = malloc(sizeof(stack_t));
	if (three == NULL)
	{
		printf("Error\n");
	}
	else
	{
		three->n = two;
		three->next = NULL;
		if (four)
		{
			while (four->next)
				four = four->next;
		}
		if (!four)
		{
			*one = three;
			three->prev = NULL;
		}
		else
		{
			four->next = three;
			three->prev = four;
		}
	}
}
