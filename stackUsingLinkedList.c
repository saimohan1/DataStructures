/* 
 * Implementation of Stack using LinkedList in C 
 * Auther - Saimohan Rao
 * email  - saimohanrao92@gmail.com
 */

#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define PUSH	0x01
#define POP	0x02
#define DISPLAY	0x03

/* Struct for Stack */
typedef struct stack {
	int data;
	struct stack *next;
} stack_t;


static int
get_data() {
	int input;
	fprintf(stdout,"Enter the Number to push/pop: ");
	scanf("%d", &input);
	return input;
}

/* Allocates an element type struct stack */
static struct stack *
alloc_stack_elem(int data) {
	struct stack *new = malloc(sizeof(struct stack));
	if (!new)
		return NULL;
	memset(new, 0, sizeof(*new));
	new->data = data;
	new->next = NULL;
	return new;	
}

/* Checks if stack is empty or not */
static bool
isStackEmpty(struct stack *stackHead) {
	return stackHead == NULL ? true : false;
}

/*
 * Push an element into the stack
 * 
 */
static struct stack *
push_into_stack(struct stack *stackHead, int data) {
	struct stack *new_elem = alloc_stack_elem(data);
	
	assert(new_elem);
	if (stackHead == NULL) {
		stackHead = new_elem;
	} else {
		new_elem->next = stackHead;
		stackHead = new_elem;
	}
	fprintf(stdout,"Successfully push an elem(%d) into the stack\n", data);
	return stackHead;
}

/* Poped an element from the stack */
static struct stack * 
pop_from_stack(struct stack *stackHead) {
	struct stack *tmp = stackHead;
	if (isStackEmpty(stackHead)) {
		fprintf(stdout,"Stack is Empty!! Can not pop\n");
		goto out;
	}		
	stackHead = stackHead->next;
	fprintf(stdout,"Successfully poped elem(%d)\n", tmp->data);
	free(tmp);
out:
	return stackHead;

}

/* Displays the stack */
static void 
display_stack(struct stack *stackHead) {
	struct stack *tmp = stackHead;
	
	if (stackHead == NULL) {
		fprintf(stdout,"Stack in Empty!!\n");
		return;
	} else {
		while(tmp) {
			fprintf(stdout,"%d->", tmp->data);
			tmp = tmp->next;
		}
	}
	fprintf(stdout,"NULL\n");
}

int main() {
	int input, data;
	struct stack *stackHead = NULL;
	while(1) {
		fprintf(stdout,"1. Push\n");
		fprintf(stdout,"2. Pop\n");	
		fprintf(stdout,"3. Display\n");
		scanf("%d", &input);
		switch (input) {
			case PUSH:
				data = get_data();
				stackHead = push_into_stack(stackHead, data);
				break;
			case POP:
				stackHead = pop_from_stack(stackHead);
				break;
			case DISPLAY:
				display_stack(stackHead);
				break; 
			default:
				fprintf(stdout,"Invalid input entered. Please try Again!!\n");
				break;
	
		}
	}	
}
