#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef struct meibo
{
    int number;
    char *name;
    int age;
}MEIBO;

MEIBO *search( MEIBO *p , int n , int key);
void printData(MEIBO *p);
int input();

int main(void)
{
    MEIBO data[N+1] = {
        { 1002 , "小林" , 18},
        { 1005 , "佐藤" , 18},
        { 1006 , "鈴木" , 18},
        { 1001 , "伊藤" , 19},
        { 1010 , "山本" , 19},
        { 1008 , "田中" , 20},
        { 1009 , "渡辺" , 20},
        { 1003 , "斎藤" , 21},
        { 1004 , "佐々木" , 23},
        { 1007 , "高橋" , 23},
        { -1, NULL , -1}
    };
    
    int key;
    MEIBO *p;
    
    printf("探索したい年齢 : ");
    key = input();
    p = search( data , N , key);
    
    if(p != NULL){
        for( ; p -> number != -1 && p -> age == key; p++){
            printData(p);
        }
    }
    else{
        printf("みつかりません。\n");
    }
}

//------------------------------------------------------------

MEIBO *search( MEIBO *p , int n , int key)
{
    int m;
    int m_age;
    
    if(n > 0){
        m = n/2;
        m_age = (p+m) -> age;
        
        if(key == m_age){
            p += m;
            
            for( ; (p-1) -> age == key; p--);
        }
        else if(key < m_age){
            p = search( p , m , key);
        }
        else{
            p = search( p+m+1 , n-m-1 , key);
        }
    }
    else{
        p = NULL;
    }
    
    return p;
}

//-----------------------------------------------------------

void printData(MEIBO *p)
{
    printf( "%4d %-10s %2d才 \n" , p -> number , p -> name , p -> age);
}

//---------------------------------------------------------

int input()
{
    char buff[10];
    
    fgets( buff , sizeof(buff) , stdin);
    
    return atoi(buff);
}
