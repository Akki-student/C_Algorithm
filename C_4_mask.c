#include <stdio.h>
#define N 16

int get_n( unsigned int one , int n);

int main(void)
{
    unsigned int data[N] = {
        0x8000 , 0x0020 , 0x2102 , 0x0801 ,
        0x0144 , 0x9210 , 0x8800 , 0x42A4 ,
        0x1240 , 0x0112 , 0x08A9 , 0x0200 ,
        0x1142 , 0x4400 , 0x1110 , 0x0002
    };
    
    unsigned int mask[N] = {
        0x0000 , 0x0000 , 0x0000 , 0x0000 ,
        0x1E00 , 0x3E00 , 0x07F0 , 0x07F8 ,
        0x0FFE , 0x0FFE , 0x0FFE , 0x0FFE ,
        0x0FFE , 0x0FFE , 0x0FF8 , 0x0FF8
    };
    
    int n_black;
    int n_mask;
    int i;
    
    n_black = 0;
    n_mask = 0;
    
    for(i = 0; i < N; i++){
        n_black += get_n(data[i] & mask[i] , N);
        n_mask += get_n(mask[i] , N);
    }
    
    printf( "黒のマスは %d 個\n 白のマスは %d 個\n 黒の割合は %.2f\n" , n_black , n_mask , (double)n_black / n_mask);
    
    return 0;
}

//-----------------------------------------------------------------

int get_n( unsigned int one, int n)
{
    int count =0;
    int i;
    
    for( i = 0; i < N; i++ , one = one >> 1){
        if((one & 1) == 1)
            count++;
    }
    
    return count;
}
