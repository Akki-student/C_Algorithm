#include <stdio.h>

unsigned char setParity(unsigned char data);
unsigned char input();

int main(void)
{
    unsigned char    data;
    
    data = input();
    data = setParity(data);
    printf("結果 : 0x%02x\n" , data);
}

//------------------------------------------------

unsigned char setParity(unsigned char data)
{
    int    i;
    int    n;
    
    n = 0;
    
    for(i = 0; i < 7; i++){
        if((data & (1 << i)) != 0){
            n++;
        }
    }
    
    if((n & 1) == 0){
        data |= 0x80;
    }
    
    return data;
}

//---------------------------------------------------

unsigned char input()
{
    char    buff[8];
    int    i;
    unsigned char    data;
    
    printf("7ビットの2進数を入力 : ");
    fgets(buff , sizeof(buff), stdin);
    
    data = 0;
    for(i = 0; buff[i] == '1' || buff[i] == '0'; i++)
    {
        data = data * 2 + (buff[i]-'0');
    }
    
    return data;
}
