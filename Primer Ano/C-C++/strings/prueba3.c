#include <stdio.h>
#include <string.h>

int main() {
    char str1[10];
    char str2[10];
    int i;

    strcpy(str1, "holaholah");
    strcpy(str2, "mundo");
    strcpy(str1, str2);

    for(i=0; i<10; i++)  printf("\n %x %d %c", str1[i], str1[i], str1[i]);

    printf("%s %s", str1, str2);

}
