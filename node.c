// general purpose standard C lib
#include <stdio.h>
#include <stdlib.h> // includes malloc(),free()
#include <string.h> // includes strlen(), memcpy()
#include <ctype.h> // includes toupper(), tolower()

// user-defined header files
#include "node.h" // do not modify this file

// put your function prototypes for additional helper functions below:
node* goToIndex(node* nd,int index){
	if (index==0){
		return nd;
	}
	else{
        if (index > 0){
            index--;
            return goToIndex(nd->next,index);
        }
        else{
            index++;
		    return goToIndex(nd->prev,index);
        }
	}
}



// implementation
void insert_node_before(list *lst, int index, char *word)
{	
	node* new = (node*)malloc(sizeof(sizeof(node)));
	new->word = word;

    if(lst->head == NULL){
        lst->head = new;
        new->next = new;
        new->prev = new;
    }
    else{
        node* indexed = (node*) goToIndex(lst->head,index);
        indexed->prev->next = new;
        new->prev = indexed->prev;
        indexed->prev = new;
        new->next = indexed;
    }
}

void insert_node_after(list *lst, int index, char *word)
{
	node* new = (node*)malloc(sizeof(sizeof(node)));
	new->word = word;

    if(lst->head == NULL){
        lst->head = new;
        new->next = new;
        new->prev = new;
    }
    else{
        node* indexed = (node*) goToIndex(lst->head,index);
        indexed->next->prev = new;
        new->next = indexed->next;
        new->prev = indexed;
        indexed->next = new;
    }

}

char *list_to_sentence(list *lst)
{
	char* sentence = (char*) malloc(sizeof(char)*MAX_WORD_LENGTH);
    strcpy(sentence,"");
    node* temp = lst->head;
    while(temp != lst->head){
        strcat(sentence,temp->word);
        if (temp->next != lst->head){
            strcat(sentence," ");
        }
        temp = temp->next;

    }
    return sentence; // Change this line accordingly
}

void delete_node(list *lst, int index)
{
	node* nd = (node*)goToIndex(lst->head,index);
    nd->prev->next = nd->next;
    nd->next->prev = nd->prev;

    free(nd->word);
    free(nd);
}

void delete_list(list *lst)
{
	node* nxt = lst->head->next;
    node* temp;
    while(nxt != lst->head){
        temp = nxt->next;
        free(nxt);
        nxt =temp;
    }

    free(lst->head);
    lst->head = NULL;
}
