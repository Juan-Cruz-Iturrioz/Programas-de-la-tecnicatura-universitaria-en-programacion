/*  EL ARCHIVO "INGRESO" TIENE LOS DATOS DE LA INSCRIPCION DE ALUMNOS  */
/*  A UNA UNIVERSIDAD. SE COMPONE DE ESTRUCTURAS INGRESO               */
/*  SE COMPONEN DE LEGAJO DEL ALUMNO Y CARRERA EN LA QUE SE INSCRIBIO  */

/*  EL ARCHIVO "EXAMEN" TIENE LOS DATOS DEL EXAMEN DE INGRESO COMUN A  */
/*  TODAS LAS CARRERAS. SE COMPONE DE ESTRUCTURAS EXAMEN               */
/*  ESTAS ESTAN FORMADAS POR EL LEGAJO DEL ALUMNO Y LA NOTA DEL EXAMEN */

/*  SE PIDE  :                                                           */
/*  1. PERMITIR EL INGRESO DE UN NOMBRE DE CARRERA E INDICAR :           */
/*  	A)  CUANTOS ALUMNOS SE INSCRIBIERON EN ESA CARRERA               */
/*  	B)  CUANTOS ALUMNOS SE PRESENTARON A EXAMEN (DE ESA CARRERA)     */
/*  	C)  CUANTOS ALUMNOS DE ESA CARRERA APROBARON (NOTA >= 6)         */

/*  2. CUAL ES LA CARRERA QUE TUVO MAYOR CANTIDAD DE INGRESANTES         */


#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



struct INGRESO {
		int LEG ;
		char CARRERA[20] ;
};

struct EXAMEN {
		int LEG ;
		int NOTA ;
};




int main()
{
			
		printf ("\n\n\nFIN DEL PROGRAMA  " );
		return 0 ;
}



