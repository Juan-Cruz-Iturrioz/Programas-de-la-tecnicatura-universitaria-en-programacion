#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LIBRO {
       int CODIGO ;          	/*  ID DEL LIBRO  */
       char TITULO[30];
       char AUTOR[20];
       char TEMATICA[20];		/*  GENERO DEL LIBRO  */
       char STATUS ;			/*  0 = DISPONIBLE   1 = PRESTADO  */
       int LECTOR ;				/*  CODIGO DE ID DEL USUARIO  */
};


struct USUARIO {
               int LECTOR ;		/*  CODIGO DE ID DEL USUARIO  */
               char NOM[20];
               int TE ;       
};


struct MOVIMIENTO {
                  int LECTOR ;		/*  CODIGO DE ID DEL USUARIO  */
                  int CODIGO ;		/*  CODIGO DE ID DEL LIBRO  */
                  char OPERACION ;  /*  0 = DEVOLUCION    1 = PRESTAMO  */  
};

/*     ARCHIVO USUARIOS    :    BASE DE DATOS DE LOS CLIENTES            */
/*	   ARCHIVO BIBLIOTECA  :    BASE DE DATOS DE LOS LIBROS              */
/*     ARCHIVO MOVIMIENTOS :    REGISTRO DE LAS OPERACIONES REALIZADAS   */


/*   1.   MOSTRAR EN PANTALLA LOS 3 ARCHIVOS  */
/*   2.   INGRESAR EL NOMBRE DE UN CLIENTE E INDICAR QUE LIBROS   */
/*        TIENE EN ESTE MOMENTO                                   */
/*   3.   MOSTRAR LOS DATOS DE LOS CLIENTES QUE TENGAN MAS DE 2 LIBROS  */
/*   4.   DETERMINAR CUAL ES EL LIBRO DE MAYOR USO (CANTIDAD DE PRESTAMOS) */
/*   5.   CUAL ES EL CLIENTE QUE MAS USA LA BIBLIOTECA  */
/*   6.   INDICAR SI EL GENERO "TERROR" ES MAS POPULAR QUE "NOVELA ROMANTICA" */
/*   7.   MOSTRAR EL HISTORICO DE OPERACIONES DE UN CLIENTE  */


int main(){
    
    
    FILE *FP_BIB , *FP_USU ,*FP_MOV ;
	
	struct LIBRO LIB;
	struct USUARIO USU;
	struct MOVIMIENTO MOV;	
	
	
	if( !(FP_BIB = fopen("BIBLIOTECA","rb")  ) ){
		
		printf("\n\n   ERROR APERTURA DE ARCHIVO BIBLIOTECA \n\n");
	
		exit(1) ;
	
	
	}
	
	if( !(FP_USU = fopen("USUARIOS","rb")  ) ){
	
		printf("\n\n   ERROR APERTURA DE ARCHIVO USUARIOS \n\n");
	
		exit(1) ;
	
	}
	
	if( !(FP_MOV = fopen("MOVIMIENTOS","rb")  ) ){
	
		printf("\n\n   ERROR APERTURA DE ARCHIVO MOVIMIENTO \n\n");
	
		exit(1) ;
	
	}
		
		printf("\n\n\t\t DATOS DE BIBLIOTECA");
		
		printf("\n\n\t %10s %30s %20s %20s %8s %10s" ,"CODIGO" , " TITULO" ,"AUTOR" , "TEMATICA" , "STATUS" ,"LECTOR" ) ;
			
		fread(&LIB , sizeof(LIB) , 1 , FP_BIB);
		
			while( ! feof(FP_BIB) ){
		
				printf("\n\n\t %10d %30s %20s %20s %8d %10d" ,LIB.CODIGO , LIB.TITULO , LIB.AUTOR , LIB.TEMATICA , LIB.STATUS , LIB.LECTOR ) ;	
			
				fread(&LIB , sizeof(LIB) , 1 , FP_BIB);
			}
		
		getchar() ;
		system("cls");
	    
	    
	    	printf("\n\n\t\t DATOS DE USUARIOS");
	    
	    	printf ("\n\n\t %10s %20s %10s" , "LECTOR" , "NOMBLE" , "TELEFONO");
	    
	    	fread (&USU, sizeof(USU) , 1 , FP_USU);
	    	
	    		while( ! feof (FP_USU ) ){
			
				printf ("\n\n\t %10d %20s %10d" ,USU.LECTOR , USU.NOM , USU.TE);
					
				fread (&USU, sizeof(USU) , 1 , FP_USU );
				}
	    
	    getchar() ;
		system("cls");
	    
			printf("\n\n\t\t DATOS DE MOVIMENTOS");	    
	    	
	    	printf("\n\n\t %10s %10s %10s" , "LECTOR" , "CODIGO" , "OPERACION");
	    	
	    	fread(&MOV , sizeof(MOV) , 1 , FP_MOV);
	    	
	    		while( ! feof (FP_MOV) ){
					
					printf("\n\n\t %10d %10d %10d" , MOV.LECTOR , MOV.CODIGO , MOV.OPERACION);
					
					fread(&MOV , sizeof(MOV) , 1 , FP_MOV);
				}
		
		getchar() ;
		system("cls");		
		
	    
    printf("\n\n\n\n\t\t es es esto todo amigos FIN DEL PROGRAMA\n\n");
    
    fclose(FP_BIB);
    
	fclose(FP_USU);
    
	fclose(FP_MOV);
	
	getchar() ; 

return 0;}
