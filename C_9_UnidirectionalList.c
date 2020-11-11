#include <stdio.h>

typedef struct list{
    struct list *p_next;
    char       *p_name;
}LIST;

void printList(LIST *p);

int main( void){
    LIST data4 = { NULL, "Yamamoto"};
    LIST data3 = { &data4, "Sato"};
    LIST data2 = { &data3, "Saito"};
    LIST data1 = { &data2, "Ito"};
    LIST *head = &data1;
    
    printList(head);
}

//------------------------------------

void printList(LIST *p){
    for( ; p != NULL; p = p->p_next)
    {
        printf( "%s\n", p->p_name);
    }
}
