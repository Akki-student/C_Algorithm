#include <stdio.h>

typedef struct list
{
    struct list *next;
    struct list *pre;
    char       *name;
}LIST;

void printList(LIST *p);
void printListDesc(LIST *p);

int main(void)
{
    LIST data4 = { NULL, NULL, "Yamamoto"};
    LIST data3 = { &data4, NULL, "Sato"};
    LIST data2 = { &data3, NULL, "Saito"};
    LIST data1 = { &data2, NULL, "Ito"};
    
    LIST *head = &data1;
    LIST *tail = &data4;
    
    data4.pre = &data3;
    data3.pre = &data2;
    data2.pre = &data1;
    
    printf("降順\n");
    printList(head);
    
    printf("\n逆順\n");
    printListDesc(tail);
}

//-----------------------------

void printList(LIST *p)
{
    for( ; p != NULL; p = p->next){
        printf( "%s\n", p->name);
    }
}

//--------------------------
void printListDesc(LIST *p)
{
    for( ; p != NULL; p = p->pre){
        printf( "%s\n", p->name);
    }
}
