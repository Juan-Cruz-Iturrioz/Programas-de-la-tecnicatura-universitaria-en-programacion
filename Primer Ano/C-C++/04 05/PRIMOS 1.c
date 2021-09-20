
#include <stdio.h>


int PRIMO(int );

int pote(int);
int main()
{
		int NUM,P,R,C;
        C=0;
		for(NUM=2;NUM<32;NUM++){

		if(PRIMO(NUM)){
        P=NUM;

        R = pote(P)-1;
        C=R;


        printf("%d ",PRIMO(NUM));


        }
        }



		return 0;
}

	int PRIMO(int NUM ){

	int DIV,R;

		for(DIV=2;DIV<=NUM/2;DIV++){

		if(!(NUM%DIV))
		R=0;

		R=1;


		}
        return R;

	}
            int pote(int P){

            int K,I;
            I=2;
            for(K=1;K<P;K++){I=I*2;}
            return I;}

