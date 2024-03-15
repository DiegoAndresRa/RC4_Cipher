<h1 align='center'>RC4 Cipher</h1>
<div align='center'>
Developed in <img src="https://github.com/devicons/devicon/blob/master/icons/c/c-plain.svg" title="C" alt="C" width="20" height="20"/>
  by <a href='https://github.com/DiegoAndresRa'>@DiegoAndresRa</a> 
</div>
<br>
<br>
<p>The implementation of the 'RC4' encryption algorithm in the C language aims to demonstrate the functional blocks that interact for encryption: 
  KSA, PRGA, and XOR. This solution follows a functional paradigm and relies on the use of dynamic memory; the size of the key can only range from 
  1 to 256 bytes, that is, 1 to 256 characters, while the plainText ranges from 0 up to 512.</p>
<br>

## Run Locally

Clone the project

```bash
  git clone https://github.com/DiegoAndresRa/RC4-with-C
```

Go to the project directory

```bash
  cd RC5-with-C
```


Start the program

```bash
  ./run
```

<br>

## Usage/Examples

```c
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
    // free memory
    free(key);
    free(plainText);
    free(cipherText);
}
```

<br>
<h2>Related</h2>
<a href='https://github.com/DiegoAndresRa/Hill_Cipher'>Hill Cipher</a>




