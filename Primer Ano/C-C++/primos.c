#include <stdio.h>
int es_divisible(int , int ) ;

int main() {
    int n;
    scanf("%d", &n);

    if(es_primo(n)) printf("es primo");
    else printf("no es primo");
}

//retorna un 1 si es divisible, o un 0 si no lo es
int es_divisible(int numero, int divisor) {
    if(numero % divisor==0) return 1;
    else return 0;
}

//retorna un 1 si es primo, o un 0 si no lo es
int es_primo(int numero) {

    int i;
    for(i=2; i<numero; i++) {
        if(es_divisible(numero, i)) return 0;
    }

    return 1;
}
