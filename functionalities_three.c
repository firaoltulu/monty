#include "monty.h"
/**
 * Custom_sub- This Function do fourtration.
 *
 * @one: stack_t pointer that points
 * to the stack head.
 * @two: int that represents line number.
 *
 * Return: Nothing(Void).
 */
void Custom_sub(stack_t **one, unsigned int two)
{
	stack_t *three;
	int four, five;

	three = *one;
	for (five = 0; three != NULL; five++)
		three = three->next;
	if (five < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", two);
		fclose(con.two);
		free(con.three);
		Cutsom_free_stack(*one);
		exit(EXIT_FAILURE);
	}
	else
	{
		three = *one;
		four = three->next->n - three->n;
		three->next->n = four;
		*one = three->next;
		free(three);
	}
}

/**
 * Custom_div - This Function divides the top
 * two elements of the stack.
 *
 * @one: stack_t pointer that points to
 * the stack head.
 * @two: Int that represent line number.
 *
 * Return: Nothing(Void).
 */
void Custom_div(stack_t **one, unsigned int two)
{
	stack_t *three;
	int len = 0, aux;

	three = *one;
	while (three)
	{
		three = three->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", two);
		fclose(con.two);
		free(con.three);
		Cutsom_free_stack(*one);
		exit(EXIT_FAILURE);
	}
	else
	{
		three = *one;
		if (three->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", two);
			fclose(con.two);
			free(con.three);
			Cutsom_free_stack(*one);
			exit(EXIT_FAILURE);
		}
		else
		{
			aux = three->next->n / three->n;
			three->next->n = aux;
			*one = three->next;
			free(three);
		}
	}
}

/**
 * Cutsom_mul - This Function multiplies the
 * top two elements of the stack.
 * @one: stack pointer that points to
 * the stack head.
 * @two: int that represent the line
 * number.
 * Return: Nothing(Void).
 */
void Cutsom_mul(stack_t **one, unsigned int two)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", two);
		fclose(con.two);
		free(con.three);
		Cutsom_free_stack(*one);
		exit(EXIT_FAILURE);
	}
	else
	{
		three = *one;
		five = three->next->n * three->n;
		three->next->n = five;
		*one = three->next;
		free(three);
	}
}

/**
 * Cutsom_mod - This Function computes the rest
 * of the division of the second top element
 * of the stack by the top element of the stack.
 *
 * @one: stack_t pointer that points to
 * the stack head.
 * @two: Int That represent the lenght.
 *
 * Return: Nothing(Void).
 */
void Cutsom_mod(stack_t **one, unsigned int two)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", two);
		fclose(con.two);
		free(con.three);
		Cutsom_free_stack(*one);
		exit(EXIT_FAILURE);
	}
	else
	{
		three = *one;
		if (three->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", two);
			fclose(con.two);
			free(con.three);
			Cutsom_free_stack(*one);
			exit(EXIT_FAILURE);
		}
		else
		{
			five = three->next->n % three->n;
			three->next->n = five;
			*one = three->next;
			free(three);
		}
	}
}

/**
 * Cutsom_pchar - This function prints the char
 * at the top of the stack followed by a new line.
 *
 * @one: stack_t pointer that points to the stack head.
 * @two: int that represent the Lenght.
 *
 * Return: Nothing(Void).
 */
void Cutsom_pchar(stack_t **one, unsigned int two)
{
	stack_t *three;

	three = *one;
	if (!three)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", two);
		fclose(con.two);
		free(con.three);
		Cutsom_free_stack(*one);
		exit(EXIT_FAILURE);
	}
	if (three->n > 127 || three->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", two);
		fclose(con.two);
		free(con.three);
		Cutsom_free_stack(*one);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", three->n);
}
