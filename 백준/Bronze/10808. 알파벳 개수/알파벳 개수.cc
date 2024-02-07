#include <stdio.h>
#include <string.h>

int main(void){

    char str1[101];
    int alph[26]={0};

    scanf("%s", str1);


    for(int i = 0 ; i < strlen(str1) ; i++){

        alph[str1[i]-'a']++;

    }

    for(int i = 0 ; i < 26 ; i++){

        printf("%d ", alph[i]);

    }

}


