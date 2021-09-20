
#include <stdio.h>

int SUMDIV(int);

int main()
{
		int NUM;

        printf("NUM ES");
        scanf("%d",&NUM);
		 
		 printf("la suma es %D",SUMDIV(NUM));
		 
		 
		return 0;
}

	int SUMDIV(int NUM){

	int DIV,SUM;
		SUM=1;
		for(DIV=2;DIV<=NUM/2;DIV++){

		if(!(NUM%DIV))
		SUM=SUM+DIV;

		return SUM;
		}


	}



