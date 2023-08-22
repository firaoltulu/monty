#include "monty.h"
/**
 * Cutsom_pstr - This Function prints the string
 * starting at the top of the stack followed
 * by a new.
 * @one: stack_t pointer that points to the
 * stack head.
 * @two: int that represent the lenght.
 *
 * Return: Nothing(Void).
 */
void Cutsom_pstr(stack_t **one, unsigned int two)
{
    stack_t *three;
    (void)two;

    three = *one;
    while (three)
    {
        if (three->n > 127 || three->n <= 0)
        {
            break;
        }
        printf("%c", three->n);
        three = three->next;
    }
    printf("\n");
}

/**
 * Cutsom_rotl- This Function rotates the stack to the top.
 *
 * @one: stack_t pointer that points to the stack head.
 * @two: int that represent the lenght.
 *
 * Return: Nothing(Void).
 */
void Cutsom_rotl(stack_t **one, __attribute__((unused)) unsigned int two)
{
    stack_t *three = *one, *four;

    if (*one == NULL || (*one)->next == NULL)
    {
        return;
    }
    else
    {
        four = (*one)->next;
        four->prev = NULL;
        while (three->next != NULL)
        {
            three = three->next;
        }
        three->next = *one;
        (*one)->next = NULL;
        (*one)->prev = three;
        (*one) = four;
    }
}

/**
 * Cutsom_rotr- This function rotates the stack to the bottom.
 *
 * @one: stack_t pointer that points to the stack head.
 * @two: int that represent the lenght.
 *
 * Return: Nothing(Void).
 */
void Cutsom_rotr(stack_t **one, __attribute__((unused)) unsigned int two)
{
    stack_t *three;

    three = *one;
    if (*one == NULL || (*one)->next == NULL)
    {
        return;
    }
    else
    {
        while (three->next)
        {
            three = three->next;
        }
        three->next = *one;
        three->prev->next = NULL;
        three->prev = NULL;
        (*one)->prev = three;
        (*one) = three;
    }
}

/**
 * Cutsom_queue - This Function prints the top.
 *
 * @one: stack_t double pointer that points
 * to the stack head.
 * @counter: int that contains the lenght.
 *
 * Return: Nothing(Void).
 */
void Cutsom_queue(stack_t **one, unsigned int two)
{
    (void)one;
    (void)two;
    con.four = 1;
}

/**
 * Cutsom_stack - This Function prints the top.
 * @one: stack_t double pointer that points
 * to the stack head.
 * @two: int that contains the lenght.
 * Return: Nothing(Void).
 */
void Cutsom_stack(stack_t **one, unsigned int two)
{
    (void)one;
    (void)two;
    con.four = 0;
}