#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 10

int main(){
srand(1969);
int I,C=1;
char ST1[N],ST2[]="FIN",ST3[N];
	
	while(C!=0){
	gets(ST1);
	if(strcmp(ST1,ST2)==0)
	C=0;
	if(strcmp(ST3,ST1)<0)
	strcpy(ST3,ST1);
	}
	printf("%s",ST3);
	
	

return 0;}
