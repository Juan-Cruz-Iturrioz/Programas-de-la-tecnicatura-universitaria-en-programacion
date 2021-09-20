#include <stdio.h>
#include <string.h>

int main() {
    char nombre1[40];
    char nombre2[40];
    int comparacion;

    puts("Ingrese el nombre 1:");
    gets(nombre1);

    printf("Ingrese el nombre 2:");
    scanf("%s", nombre2);

    comparacion = strcmp(nombre1,nombre2);
    if(comparacion < 0) printf("%s esta antes que %s y tiene %d letras", nombre1, nombre2, strlen(nombre1));
    else printf("%s esta antes que %s y tiene %d letras", nombre2, nombre1, strlen(nombre2));
    //printf("\n\n %d", comparacion);
}
