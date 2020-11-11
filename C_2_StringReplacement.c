#include <stdio.h>
#include <string.h>

char *replace(char *src , char *key , char *str , char *des , size_t size);
int input(char *buff , int size , char *msg);

int main(void)
{
    char src[] = "01234567890123456789";
    char key[21];
    char str[21];
    char des[31];
    
    printf("%s\n" , src);
    
    input(key , sizeof(key), "探索したい文字列を入力:");
    input(str , sizeof(str), "置換したい文字列を入力:");
    
    printf("%s\n" , replace(src , key , str , des , sizeof(des)));
}

//----------------------------------------------------------------------------

char *replace(char *src , char *key , char *str , char *des , size_t size)
{
    int n_key = strlen(key);
    int n_str = strlen(str);
    char *des_save = des;
    
    while(*src != '\0' && des_save + size - 1 > des){
        if(strncmp(src , key , n_key) == 0){
            if(des_save + size > des + n_str){
            strcpy(des , str);
            des += n_str;
            }
            else{
                strncpy(des , str , size - (des - des_save) - 1);
                des += size - (des - des_save) - 1;
            }
            src += n_key;
        }
        else{
            *des = *src;
            src++;
            des++;
        }
    }
    *des = '\0';

    return des_save;
}

//------------------------------------------------------------------------

int input(char *buff , int size, char *msg)
{
    size_t n;
    
    printf("探索したい文字列を入力:%s" , msg);
    fgets(buff , size , stdin);
    
    n = strlen(buff);
    if(*(buff + n - 1) == '\n'){
        *(buff + n - 1) = '\0';
        n--;
    }
    return n;
}
