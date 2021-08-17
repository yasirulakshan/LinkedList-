// general purpose standard C lib
#include <stdio.h>
#include <stdlib.h> // stdlib includes malloc() and free()

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
        new->prev = nd;
        nd->next = new;
        return;
    }

    else{
        return (addToLst(nd->next,str));
    }
}


int main()
{
    list * lst = (list *) malloc(sizeof(list));
    lst->head = NULL;
	run(&lst);
    print_list(lst);
    free(lst);
	return 0;
}

// parse the input
void run(list *lst) 
{
	char* word = (char* ) malloc(20*sizeof(char));
    while (1){
        scanf("%s",word);
        if (!strcmp(word,"0")){
            break;
        }
        lst->head =NULL;
        addToLst(&(lst->head),word);
        
    }
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

