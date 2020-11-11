#include <stdio.h>
#define TRUE 1
#define FALSE 0

void sort( int *p , int n);
int sort1( int *p , int n);
void printData( int *p , int n);
void swap( int *p1, int *p2);

int main(void)
{
    int data[] = {25 , 10 , 33 , 47 , 68 , 55 , 74 , 89};
    
    printf("元のデータ : ");
    printData( data , sizeof(data)/sizeof(int));
    
    sort( data , sizeof(data)/sizeof(int));
    
    printf("ソート結果 : ");
    printData( data , sizeof(data)/sizeof(int));
}

//--------------------------------------------------------

void sort(int *p , int n)
{
    int i;
    int flg;
    
    flg = TRUE;
    
    for( i = n; i > 1; i--){
        flg = sort1(p , i);
    }
}

//----------------------------------------------------

int sort1( int *p , int n)
{
    int i;
    int flg = FALSE;
    
    for( i = 0; i < n-1; i++){
        if(*p > *(p + 1)){
            swap( p , p + 1);
            flg = TRUE;
        }
    }
    
    return flg;
}

//--------------------------------------------------

void printData( int *p , int n)
{
    int i;
    
    for( i = 0; i < n; i++ , p++){
        printf( "%5d" , *p);
    }
    
    printf("\n");
}

//---------------------------------------------------

void swap( int *p1 , int *p2)
{
    int temp;
    
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
