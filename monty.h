#ifndef MONTY_H
#define MONTY_H

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct carry - variables -one, two, three and four
 * @one: char pointer that points to the value.
 * @two: file pointer that points to monty file.
 * @three: char pointer that points to line content.
 * @four: int that contains the flag change stack <-> queue.
 *
 */
typedef struct carry
{
	char *one;
	FILE *two;
	char *three;
	int four;

} carry_t;
extern carry_t con;

void Cutsom_free_stack(stack_t *one);
void Custom_addnode(stack_t **one, int two);
void Custom_addqueue(stack_t **one, int two);

void Cutsom_push(stack_t **one, unsigned int two);
void Custom_pall(stack_t **one, unsigned int two);
void Custom_print(stack_t **one, unsigned int two);
void Custom_pop(stack_t **one, unsigned int two);
void Custom_swap(stack_t **one, unsigned int two);
void Custom_add(stack_t **one, unsigned int two);
void Custom_nop(stack_t **one, unsigned int two);
void Custom_sub(stack_t **one, unsigned int two);
void Custom_div(stack_t **one, unsigned int two);
void Cutsom_mul(stack_t **one, unsigned int two);
void Cutsom_mod(stack_t **one, unsigned int two);
void Cutsom_pchar(stack_t **one, unsigned int two);
void Cutsom_pstr(stack_t **one, unsigned int two);
void Cutsom_rotl(stack_t **one, __attribute__((unused)) unsigned int two);
void Cutsom_rotr(stack_t **one, __attribute__((unused)) unsigned int two);
void Cutsom_queue(stack_t **one, unsigned int two);
void Cutsom_stack(stack_t **one, unsigned int two);

#endif
