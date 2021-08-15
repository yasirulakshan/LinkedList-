// general purpose standard C lib
#include <stdio.h>
#include <stdlib.h> // includes malloc(),free()
#include <string.h> // includes strlen(), memcpy()
#include <ctype.h> // includes toupper(), tolower()

// user-defined header files
#include "node.h" // do not modify this file

// put your function prototypes for additional helper functions below:


// implementation
void insert_node_before(list *lst, int index, char *word)
{	
	if (lst->head == NULL){
		struct NODE* word = malloc(sizeof(struct NODE));
		lst->head = word;
	}

	else{
		node* current = lst->head;
		node* previous = current->prev;
		int going = 0;
		while (going < index){
			going++;
			current = current->next;
			previous = current;
		}
		struct NODE* word = malloc(sizeof(struct NODE));
		word->word = word;
		word->prev = previous;
		word->next = current;
		previous->next = word;
		current->prev = word;

	}

}

void insert_node_after(list *lst, int index, char *word)
{
	// TODO
}

char *list_to_sentence(list *lst)
{
	// TODO
    return NULL; // Change this line accordingly
}

void delete_node(list *lst, int index)
{
	// TODO
}

void delete_list(list *lst)
{
	// TODO
}
