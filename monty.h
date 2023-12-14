#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void open_file(char *file_name);
int parse_line(char *buffer, int line_number, int format);
void read_file(FILE *);
int len_chars(FILE *);
void find_func(char *, char *, int, int);

/*Stack operations*/
stack_t *create_node(int n);
void free_nodes(void);
void disp_stk(stack_t **, unsigned int);
void ad_stk(stack_t **, unsigned int);
void ad_que(stack_t **, unsigned int);

void gt_hpy(op_func, char *, char *, int, int);

void vw_hd(stack_t **, unsigned int);
void vw_hd(stack_t **, unsigned int);
void epty(stack_t **, unsigned int);
void mv_hd(stack_t **, unsigned int);

/*Math operations with nodes*/
void ad_hd(stack_t **, unsigned int);
void sb_hd(stack_t **, unsigned int);
void dv_hd(stack_t **, unsigned int);
void ml_hd(stack_t **, unsigned int);
void md_hd(stack_t **, unsigned int);

/*String operations*/
void disp_chr(stack_t **, unsigned int);
void disp_str(stack_t **, unsigned int);
void rep1(stack_t **, unsigned int);

/*Error hanlding*/
void issue(int error_code, ...);
void mre_iss(int error_code, ...);
void string_err(int error_code, ...);
void rep2(stack_t **, unsigned int);

#endif
