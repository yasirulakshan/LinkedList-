// general purpose standard C lib
#include <stdio.h>
#include <stdlib.h> // stdlib includes malloc() and free()
#include <string.h>

// user-defined header files
#include "node.h"

// macros

#define INSERT_BEFORE 1
#define INSERT_AFTER 2
#define DELETE_NODE 3
#define DELETE_LIST 4

// function prototypes
void print_list(list * lst); 
void run(list * lst);

int main()
{
    list * lst = (list *) malloc(sizeof(list));
    lst->head = NULL;
	run(lst);
    print_list(lst);
    free(lst);
	return 0;
}

// parse the input
void run(list *lst) 
{
	char* word = (char* ) malloc(20*sizeof(char));
    //node* nd = (node*)malloc(sizeof(node));
    //nd=NULL;
    list* temp = (list *) malloc(sizeof(list));
    temp->head = NULL;

    while (1){
        scanf("%s",word);
        if (!strcmp(word,"0")){
            break;
        }
        addToLst(temp->head,word); 
    }
    lst=temp;
    
}

//Print the list contents
void print_list(list * lst)
{
    node* printing = malloc(sizeof(node));
    printing = lst->head;
    while(printing!=NULL){
        printf("%s\n",printing->word);
        printing = printing->next;
    }
}

