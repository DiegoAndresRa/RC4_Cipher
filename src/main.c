#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "RC4.h"
#include "Utilidades.h"

int main(int argc, char* argv[]){
    char* key = (char*)malloc(256*sizeof(char));
    char* plainText = (char*)malloc(512*sizeof(char));
    
    // read data form terminal
    scanf("%s",key);
    getchar();
    scanf("%[^\n]s",plainText);

    //cipher
    int* cipherText = rc4_encrypt(key,plainText);

    // print cipher text
    util_printVector(cipherText,strlen(plainText),'x');
    printf("\n");

    free(key);
    free(plainText);
    free(cipherText);
}