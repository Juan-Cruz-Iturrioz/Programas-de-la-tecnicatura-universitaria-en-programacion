
#include <stdio.h>

int PERFECTOS(int);

int main()
{
		int NUM,P,A,D;
P=0; A=0; D=0;
        for(NUM=2;NUM<=10000;NUM++){

        if(NUM==PERFECTOS(NUM))
         P=P+1;


        if(NUM>PERFECTOS(NUM))
            A=A+1;

        if(NUM<PERFECTOS(NUM))
            D=D+1;


        }

        printf("P son %d\nA son %d\nD son %d\n ",P,A,D);
		return 0;
}

	int PERFECTOS(int NUM){

	int DIV,SUM;
        SUM=1;
		for(DIV=2;DIV<=NUM/2;DIV++){

		if(!(NUM%DIV))
		SUM=SUM+DIV;


		}
        return SUM;

	}



