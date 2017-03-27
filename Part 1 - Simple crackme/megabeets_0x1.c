/////////////////////////////////////////////////////////////////////////////////////////////
// Name: megabeets_0x1.c
// Description: Simple crackme intended to teach radare2 framework capabilities.
// Compilation: $ gcc megabeets_0x1.c -o megabeets_0x1 -fno-stack-protector -m32 -z execstac
//
// Author: Itay Cohen (@megabeets)
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
    printf("\n  .:: Megabeets ::.\n");
    printf("Think you can make it?\n");
    if (argc >= 2 && beet(argv[1]))
    {
        printf("Success!\n\n");
    }
    else
        printf("Nop, Wrong argument.\n\n");

    return 0;
}
