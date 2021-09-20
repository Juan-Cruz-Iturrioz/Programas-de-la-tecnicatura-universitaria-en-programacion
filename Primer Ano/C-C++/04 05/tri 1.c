
#include <stdio.h>



int main()
{
		int NUM,DIV,SUM,Tn;

        for(NUM=1;NUM<=100;NUM++){
        SUM=0;

		for(DIV=1;DIV<=NUM;DIV++){

		if(!(NUM%DIV)){
		SUM=SUM+DIV;
        Tn=(SUM*(SUM+1)/2);


        }
        printf("%d ",Tn);
        }


}

return 0;}








