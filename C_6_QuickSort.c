#include <stdio.h>

void sort( int *p , int n);
void swap( int *p1 , int *p2);
void printData( int *p , int n);

int main(void)
{
    int data[] = {47 , 74 , 68 , 33 , 55 , 89 , 25 , 10};
    
    printf("元のデータ : ");
    printData( data , sizeof(data)/sizeof(int));
    
    sort( data , sizeof(data)/sizeof(int));
    
    printf("ソート結果 : ");
    printData( data , sizeof(data)/sizeof(int));
}

//-------------------------------------------------------

void sort( int *p , int n)
{
    int i;
    int j;
    int t;
    
    if(n == 2){
        if(*p > *(p + 1)){
            swap( p , p + 1);
        }
    }
    else if(n > 2){
        t = *(p + n/2);
        i = -1;
        j = n;
        
        while(i < j){
            for( i++; *(p+i) < t; i++);
                for( j--; *(p+j) > t; j--);
            
            if(i < j){
                swap( p+i , p+j);
            }
            else if(i == j){
                sort( p , i);
                sort( p+j+1 , n-j-1);
            }
            else{
                sort( p , j+1);
                sort( p+i , n-i);
            }
        }
    }
}

//-----------------------------------------------------

void printData( int *p , int n)
{
    int i;
    
    for( i = 0; i < n; i++ , p++){
        printf( "%5d" , *p);
    }
    
    printf("\n");
}

//------------------------------------------------------

void swap( int *p1 , int *p2)
{
    int temp;
    
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
