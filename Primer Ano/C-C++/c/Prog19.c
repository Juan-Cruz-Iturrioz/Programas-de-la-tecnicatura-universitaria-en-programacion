#include<stdio.h> 

int main(){
	int n,n2=0,div,acum2=0;
	
	for(n=1;n<10000;n++){
		n2=0;
		for(div=1;div<n;div++){
			if(n%div==0){
				n2=n2+div;
			}	
		}
		acum2=0;
		for(div=1;div<n2;div++){
				if(n2%div==0)
					acum2=acum2+div;
			}
		if(acum2==n && n2!=n)
			printf("%d,%d\n\n",n,n2);	
	}

	return 0;
}



