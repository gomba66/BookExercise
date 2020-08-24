#include <stdio.h>
#include <stdlib.h>


/**
 * struct naturalsNumbers - Single Linked List
 * @character: (character) Store 10 Chars
 * @nextPtr: (struct naturalsNumbers *) points to the next node
 *
 * Description: Store a line of text
 *
 */
struct list {
    char character;
    struct list *nextPtr;
};

typedef struct list list_char;

void insert_nodes(list_char **head, char mcharacter);
void insert_rev(list_char *head, list_char *new);
void print_nodes(list_char *head);
void delete_node(list_char *head);


/**
 * main - (Creating a Linked List, Then Reversing Its Elements)
 *
 * Return: (int) 0 if is success
 */
int main(void)
{
        list_char *head = NULL, *rev = NULL;

        insert_nodes(&head, 'a');
        insert_nodes(&head, 'b');
        insert_nodes(&head, 'c');
        insert_nodes(&head, 'd');
        insert_nodes(&head, 'e');
        insert_nodes(&head, 'f');
        insert_nodes(&head, 'g');
        insert_nodes(&head, 'h');
        insert_nodes(&head, 'i');
        insert_nodes(&head, 'j');

        /* Make a List in Reverse */
        insert_rev(head, rev);

        /* Print Lists */
        print_nodes(rev);
        puts("----------------------");

        delete_node(head);
        puts("----------------------");
        delete_node(rev);

	return (0);
}


/**
 * insert_rev - Insert Nodes in Reverse
 * @head: (list_char *) Head of the node
 * @new: (list_char *) New List in reverse order
 *
 */
void insert_rev(list_char *head, list_char *new)
{
        if (!(head))
                return;

        insert_rev(head->nextPtr, new);
        insert_nodes(&new, head->character);
        printf("%c\n", head->character);
}


/**
 * insert_nodes - Insert node in next position
 * @head: (NaturalNums) Head of the Pointer
 * @n: (int) Number of Integer
 *
 */
void insert_nodes(list_char **head, char mcharacter)
{
	list_char *newPtr = malloc(sizeof(list_char));
        list_char *currentPtr = *head;

	if (!newPtr)
		exit(EXIT_FAILURE);

	/* Copy info From Arguments */
        newPtr->character = mcharacter;
	newPtr->nextPtr = NULL;

        if (!(*head)) {
                newPtr->nextPtr = *head;
                *head = newPtr;
        } else {
	        /* Traversing list Until NULL or Find Letter minour */
                for (; currentPtr->nextPtr != NULL; (currentPtr = currentPtr->nextPtr))
                        ;

                /* Assign the NULL Value */
                newPtr->nextPtr = currentPtr->nextPtr;
                /* Assign the ptr at the Head */
                currentPtr->nextPtr = newPtr;
        }
}


/**
 * delete_node - Delete all nodes
 * @head: (NaturalNums) Head of the Pointer
 *
 */
void delete_node(list_char *head)
{
	list_char *tmp = NULL;
	int i = 0;

	putchar(10);
	while (head) {
		tmp = head;
		head = head->nextPtr;
		printf("Eliminated item (%d)\n", i);
		free(tmp);
		++i;
	}
	tmp = NULL;
	puts("\nSuccessfull");
}


/**
 * print_nodes - Print the nodes
 * @head: (NaturalNums) Head of the Pointer
 *
 */
void print_nodes(list_char *head)
{
	while (head != NULL) {
		printf("%c\n", head->character);
		head = head->nextPtr;
	}
}
