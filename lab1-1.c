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
	char* word = (char* ) malloc(MAX_WORD_LENGTH*sizeof(char));
    
    while(1){
        scanf("%20[^,\n]",word);
        insert_node_before(lst,0,word);
        char temp;
        scanf("%c",&temp);
        if (temp == '\n'){
            break;
        }
        word = (char* ) malloc(MAX_WORD_LENGTH*sizeof(char));
    }

    while(1){
        int cmd;
        scanf("%d",&cmd);
        if (cmd == 0){
            break;
        }
        else{
            int index;
            char* word =  (char *)malloc(sizeof(char) * MAX_WORD_LENGTH) ;
            switch (cmd)
            {
            case INSERT_BEFORE:
                scanf("%d %s\n",&index,word);
                insert_node_before(lst,index,word);
                break;

            case INSERT_AFTER:
                scanf("%d %s\n",&index,word);
                insert_node_after(lst,index,word);
                break;

            case DELETE_NODE:
                scanf("%d %s\n",&index,word);
                insert_node_after(lst,index,word);
                break;
            
            case DELETE_LIST:
                delete_list(lst);
                break;
            
            default:
                break;
            }
        }
    }
    
}

//Print the list contents
void print_list(list * lst)
{
    char* sentence = list_to_sentence(lst);
    printf("%s\n",sentence);
    free(sentence);
}

