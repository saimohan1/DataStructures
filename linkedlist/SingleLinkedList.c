#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

/* Linkedlist node structure */
typedef struct node {
	int data;
	struct node *next;
} node_t;

enum op {
	DISPLAY = 1,
	ADD_AT_FRONT,
	ADD_AT_END,
	DELETE_LIST,
	EXIT,
};


/* prints out the linkedlist */
static void
display_list(node_t *head)
{
	node_t *temp;

	if (!head) {
		printf("List is Empty!!\n");
		return;
	}
	
	temp = head;
	while(temp) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

/* Deletes the complete linkedlist */
static void
delete_complete_list(node_t *head)
{
	node_t *temp;
	
	if (!head)
		return;

	while ((temp = head) && temp) {
		head = head->next;
		free(temp);
	}
	head = NULL;
}

static void
exit_app(node_t *head) {

	if (!head)
		return;
	delete_complete_list(head);
	assert(head == NULL);
}

int main() {
	struct node *head = NULL;
	int choice;
	while (1) {
		printf("\n1. Display Linkedlist\n");
		printf("2. Inster at front of Linkedlist\n");
		printf("3. Inster at End of Linkedlist\n");
		printf("4. Delete Entire linkedlist\n");
		printf("5. Exit\n");
		printf("Please Enter you choice: ");
		scanf("%d", &choice);
		switch (choice)	{
			case DISPLAY: 		display_list(head); break;
			case DELETE_LIST: 	delete_complete_list(head); break;
			case EXIT:			exit_app(head); exit(0);
			default:
				printf("Please Enter a valid input!!\n");
				break;	

		}
	}

	return 0;
}
