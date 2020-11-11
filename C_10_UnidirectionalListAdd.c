#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct list
{
    struct list *p_next;
    char       *p_name;
}LIST;

void printList(LIST *p);
LIST *addList( LIST *ph, char *ps);
void freeArea(LIST *p);

int main(void)
{
    LIST *head;
    
    head = addList( NULL, "Saito");
    head = addList( head, "Ito");
    head = addList( head, "Yamamoto");
    head = addList( head, "Sato");
    
    printList(head);
    freeArea(head);
}

//-------------------------------------

LIST *addList( LIST *ph, char *ps)
{
    LIST *p;
    LIST *pd;
    LIST *pb;
    
    pd = (LIST*)malloc(sizeof(LIST));
    pd->p_name = (char *)malloc(strlen(ps) + 1);
    strcpy( pd->p_name, ps);
    pd->p_next = NULL;
    
    if(ph == NULL){
        ph = pd;
    }
    else{
        pb = NULL;
        p = ph;
        
        while(p != NULL && strcmp( p->p_name, ps) < 0){
            pb = p;
            p = p->p_next;
        }
        
        if(pb == NULL){
            pd->p_next = p;
            ph = pd;
        }
        else{
            pd->p_next = p;
            pb->p_next = pd;
        }
    }
    
    return ph;
}

//-----------------------------------

void freeArea(LIST *p)
{
    LIST *p_next;
    
    while(p != NULL){
        p_next = p->p_next;
        printf( "%sの領域を開放します。\n", p->p_name);
        free(p->p_name);
        free(p);
        p = p_next;
    }
}

//---------------------------------

void printList(LIST *p)
{
    for( ; p != NULL; p = p->p_next){
        printf( "%s\n", p->p_name);
    }
}
