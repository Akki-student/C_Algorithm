#include <stdio.h>
#include <string.h>
#define HASH_SIZE 7

typedef struct list
{
    int        number;
    char       *p_name;
    struct list *p_next;
}LIST;

void makeList( LIST *p_tbl[], int h, LIST data[], int n);
int getHash( char *p, int h);
void printHash( LIST *p_tbl[], int h);
LIST *search( LIST *p_tbl[], int h, char *ps);

int main(void)
{
    LIST *p_tbl[HASH_SIZE];
    LIST data[] = {
        { 1001, "ito", NULL},
        { 1002, "saito", NULL},
        { 1003, "sato", NULL},
        { 1004, "suzuki", NULL}
    };
    LIST *p;
    
    makeList( p_tbl, HASH_SIZE, data, 4);
    
    if((p = search( p_tbl, HASH_SIZE, "suzuki")) != NULL)
        printf( "%4d:%s\n", p->number, p->p_name);
    else
        printf( "%sはありません。\n", "suzuki");
    
    if((p = search( p_tbl, HASH_SIZE, "sakai")) != NULL)
        printf( "%4d:%s\n", p->number, p->p_name);
    else
        printf( "%sはありません。\n", "sakai");
    
    if((p = search( p_tbl, HASH_SIZE, "sato")) != NULL)
        printf( "%4d:%s\n", p->number, p->p_name);
    else
        printf( "%sはありません。\n", "sato");
}

//-----------------------------------------

LIST *search( LIST *p_tbl[], int h, char *ps)
{
    int index;
    LIST *p;
    
    index = getHash( ps, h);
    
    for( p = p_tbl[index]; p != NULL && strcmp( p->p_name, ps) != 0; p = p->p_next);
    
    return p;
}

//---------------------------------

void makeList( LIST *p_tbl[], int h, LIST data[], int n)
{
    int i;
    int index;
    LIST *p;
    
    for( index = 0; index < h; index++){
        p_tbl[index] = NULL;
    }
    
    for( i = 0; i < n; i++){
        index = getHash( data[i].p_name, h);
        if(p_tbl[index] == NULL){
            p_tbl[index] = &data[i];
        }
        else{
            for( p = p_tbl[index]; p->p_next != NULL; p = p->p_next);
            p->p_next = &data[i];
        }
    }
}

//-----------------------------------

int getHash( char *p, int h)
{
    int total = 0;
    
    for( ; *p != '\0'; p++){
        total += *p;
    }
    
    return total % h;
}

//----------------------------------

void printHash( LIST *p_tbl[], int h)
{
    int index;
    LIST *p;
    
    for( index = 0; index < h; index++){
        printf( "[%d]:", index);
        
        for( p = p_tbl[ index]; p != NULL; p = p->p_next){
            printf( "%4d %-10s ", p->number, p->p_name);
        }
        
        printf("\n");
    }
}
