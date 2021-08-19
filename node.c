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
		return &nd;
	}
	else{
		index--;
		return goToIndex(&(nd->next),index);
	}
}

void addToLst(node* nd,char* str){
    if(nd == NULL){
        node* new = (node*) malloc(sizeof(node));
        new->word = (char* ) malloc(20*sizeof(char));
        strcpy(new->word,str);
        new->prev = NULL;
        new->next = NULL;
        nd = new;
        return;
    }
    else if(nd->next == NULL){
        node* new = (node*) malloc(sizeof(node));
        new->word = (char* ) malloc(20*sizeof(char));
        strcpy(new->word,str);
        new->next = NULL;
        new->prev = (node*) malloc(sizeof(node));
        new->prev = nd;
        nd->next = new;
        return;
    }

    else{
        return (addToLst(nd->next,str));
    }
}

// implementation
void insert_node_before(list *lst, int index, char *word)
{	
	int going = 0;
	node* indexed = goToIndex(&(lst->head),index);
	node* new = (node*)malloc(sizeof(sizeof(node)));
	new->word = (char*)malloc(20*sizeof(char));
	strcpy(new->word,word);
	new->next = indexed;
	new->prev = indexed->prev;
	indexed->prev = new;
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
