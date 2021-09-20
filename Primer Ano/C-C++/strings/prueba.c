#include <stdio.h>
#include <string.h>

int main() {
    char i, materia[20];
    char cada_uno;
    int edad;

    //scanf("%s %d", materia, &edad);
    gets(materia);
    scanf("%d", &edad);

    //materia[4] = 0;

    for(i=0; i<20; i++) {
        cada_uno = materia[i];
        printf("\n %x %d %c", cada_uno, cada_uno, cada_uno);
    }

    //printf("\n\n %s", materia);
    //puts("el nombre es:");
    //puts(materia);
    //printf("\n %d", edad);
    printf("el nombre es %s y su edad es %d", materia, edad);
}
