#include "monty.h"
/**
 * Custom_print - This Function prints the top.
 * @one: stack_t pointer that points
 * to the stack head.
 * @two: int that represent
 * the line number.
 * Return: Nothing(Void).
 */
void Custom_print(stack_t **one, unsigned int two)
{
	if (*one == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", two);
		fclose(con.two);
		free(con.three);
		Cutsom_free_stack(*one);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", (*one)->n);
	}
}

/**
 * Custom_pop - This Fuction Pops the top.
 *
 * @one: stack_t pointer that points
 * to the stack head.
 * @two: int that represent the
 * line number.
 *
 * Return: Nothing(Void).
 */
void Custom_pop(stack_t **one, unsigned int two)
{
	stack_t *three;

	if (*one == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", two);
		fclose(con.two);
		free(con.three);
		Cutsom_free_stack(*one);
		exit(EXIT_FAILURE);
	}
	else
	{
		three = *one;
		*one = three->next;
		free(three);
	}
}

/**
 * Custom_swap - THis Function adds the top two
 * elements of the stack.
 *
 * @one: stack_t pointer that points to
 * the stack head.
 * @two: int that represent the line number.
 *
 * Return: Nothing(Void).
 */
void Custom_swap(stack_t **one, unsigned int two)
{
	stack_t *three;
	int four = 0, five;

	three = *one;
	while (three)
	{
		three = three->next;
		four++;
	}
	if (four < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", two);
		fclose(con.two);
		free(con.three);
		Cutsom_free_stack(*one);
		exit(EXIT_FAILURE);
	}
	else
	{
		three = *one;
		five = three->n;
		three->n = three->next->n;
		three->next->n = five;
	}
}

/**
 * Custom_add - This Function adds the top
 * two elements of the stack.
 *
 * @one: stack_t pointer that points
 * to the stack head.
 * @two: int that represent the
 * line number.
 *
 * Return: Nothing(Void).
 */
void Custom_add(stack_t **one, unsigned int two)
{
	stack_t *three;
	int four = 0;
	int five;

	three = *one;
	while (three)
	{
		three = three->next;
		four++;
	}
	if (four < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", two);
		fclose(con.two);
		free(con.three);
		Cutsom_free_stack(*one);
		exit(EXIT_FAILURE);
	}
	else
	{
		three = *one;
		five = three->n + three->next->n;
		three->next->n = five;
		*one = three->next;
		free(three);
	}
}

/**
 *Custom_nop- This Function do Nothing.
 *@one: stack_t pointer that points to the stack head.
 *@two: int that represent line_number.
 *Return: Nothing(Void).
 */
void Custom_nop(stack_t **one, unsigned int two)
{
	(void)one;
	(void)two;
}
