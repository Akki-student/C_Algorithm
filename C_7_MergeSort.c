#include <stdio.h>
#define N 8

void sort( int *p , int n , int *pw);
void merge( int *p1 , int n , int *p2 , int m , int *pw);
void copy( int *des , int *src , int n);
void printData( int *p , int n);

int main(void)
{
    int data[N] = { 47, 74, 68, 33, 55, 89, 25, 10};
    int work[N];
    
    printf("元のデータ　: ");
    printData( data , N);
    
    sort( data , N , work);
    
    printf("ソート結果 : ");
    printData( data , N);
    
    return 0;
}

//---------------------------------------------

void sort( int *p , int n , int *pw)
{
    int mid;
    
    if(n > 1){
        mid = n/2;
        sort( p , mid , pw);
        sort( p + mid , n - mid , pw + mid);
        
        merge( p , mid , p+mid , n-mid , pw);
        copy( p , pw , n);
    }
}

//-----------------------------------------------

void merge( int *p1 , int n , int *p2 , int m , int *po)
{
    int i;
    int j;
    int k;
    
    for( i = 0, j = 0, k = 0; i < n && j < m; k++){
        if(*(p1+i) < *(p2+j)){
            *(po+k) = *(p1+i);
            i++;
        }
        else{
            *(po+k) = *(p2+j);
            j++;
        }
    }
    
    copy( po+k , p1+i , n-i);
    copy( po+k , p2+j , m-j);
}

//---------------------------------------------

void copy(int *des , int *src , int n)
{
    int i;
    
    for( i = 0; i < n; i++){
        *(des+i) = *(src+i);
    }
}

//---------------------------------------------

void printData( int *p , int n)
{
    int i;
    
    for( i = 0; i < n; i++ , p++){
        printf( "%5d" , *p);
    }
    
    printf("\n");
}
