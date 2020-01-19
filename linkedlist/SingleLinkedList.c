/*
 * Implementation of Singly LinkedList in C
 * Auther - Saimohan Rao
 * email  - saimohanrao92@gmail.com
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>

/* Linkedlist node structure */
typedef struct node {
	int data;
	struct node *next;
} node_t;

enum op {
	DISPLAY = 1,
	INSERT_AT_FRONT,
	INSERT_AT_END,
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
static node_t *
delete_complete_list(node_t *head)
{
	node_t *temp;
	
	if (!head)
		goto out;

	while ((temp = head) && temp) {
		head = head->next;
		printf("Releasing memory for node: (%p)\n", temp);
		free(temp);
	}
	head = NULL;
out:
	return head;
}

/* Release all memory and closed te app */
static void
exit_app(node_t *head) {

	if (!head)
		goto out;
	delete_complete_list(head);
	assert(head == NULL);
out:
	printf("Application closed Successfully\n");
}

static int
get_user_data()
{
	int data;
	printf("Please enter the data: ");
	scanf("%d", &data);
	return data;
}

/* Allocates memory for new node  */
static node_t *
alloc_node()
{
	node_t *new = NULL;
	new = (node_t *) malloc(sizeof(node_t));
	if (!new) {
		printf("Could not able to allocate\n");
		goto out;
	}

	memset(new, 0, sizeof(node_t));
	new->data = get_user_data();
	new->next = NULL;

out:
	return new;
}

/* Insert a new node at front of the linkedlist */
static node_t *
insert_at_front(node_t *head)
{
	node_t *new = alloc_node();
	if (!new)
		goto out;

	if (!head) {
		head = new;
	} else {
		new->next = head;
		head = new;
	}
	printf("Successfully Inserted node into linkedlist: (%p) %d\n",
						new, new->data);
out:
	return head;
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
			case DISPLAY:
				display_list(head);
				break;
			case INSERT_AT_FRONT:
				head = insert_at_front(head);
				break;
			case DELETE_LIST:
				head = delete_complete_list(head);
				break;
			case EXIT:
				exit_app(head);
				exit(0);
			default:
				printf("Please Enter a valid input!!\n");
				break;	

		}
	}

	return 0;
}
