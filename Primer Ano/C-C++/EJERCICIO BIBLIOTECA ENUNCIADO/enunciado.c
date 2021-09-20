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
    
    
    printf("\n\n\n\n   FIN DEL PROGRAMA\n\n");
    getchar() ; 
}
