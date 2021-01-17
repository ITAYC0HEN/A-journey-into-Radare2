/////////////////////////////////////////////////////////////////////////////////////////////
// Name: megabeets_0x2.c
// Description: Vulnerable program to teach radare2 framework capabilities.
// Compilation: $ gcc -no-pie -m32 -fno-stack-protector -no-pie megabeets_0x2.c -o megabeets_0x2
//
// Author: Itay Cohen (@megabeets_)
// Website: https://www.megabeets.net
/////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>

void rot13 (char *s) {
    if (s == NULL)
        return;
    int i;
    for (i = 0; s[i]; i++) {
        if (s[i] >= 'a' && s[i] <= 'm') { s[i] += 13; continue; }
        if (s[i] >= 'A' && s[i] <= 'M') { s[i] += 13; continue; }
        if (s[i] >= 'n' && s[i] <= 'z') { s[i] -= 13; continue; }
        if (s[i] >= 'N' && s[i] <= 'Z') { s[i] -= 13; continue; }
    }
}

int beet(char *name)
{
    char buf[128];
    strcpy(buf, name);
    char string[] = "Megabeets";
    rot13(string);

    return !strcmp(buf, string);
}

int main(int argc, char *argv[])
{
    char *input; 
    puts("\n  .:: Megabeets ::.\n");
    puts("Show me what you got:");
    
    scanf("%ms", &input);
    if (beet(input))
    {
        printf("Success!\n\n");
    }
    else
        puts("Nop, Wrong argument.\n\n");

    return 0;
}
