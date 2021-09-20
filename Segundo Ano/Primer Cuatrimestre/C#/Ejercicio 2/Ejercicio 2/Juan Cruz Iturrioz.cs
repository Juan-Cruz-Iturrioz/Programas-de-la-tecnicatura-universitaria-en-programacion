using Alumnos;
using System;
using System.Collections;

namespace Ejercicio_2
{
    class Program
    {
        static void Main(string[] args)
        {

           

            Console.WriteLine("Ingrese la cuota");

            int I = 0 ,CON, MAX = 10;
            
            CAlumno.setCUOTA(float.Parse(Console.ReadLine()));

            ArrayList Lista = new ArrayList(MAX);

            CAlumno AUX;

            Console.WriteLine("\nIngrese los dato de los alumnos asta 10 0 asta que se ingrese uno legajo de 0\n");
            
            Console.ReadKey();

            ulong LEG = 2;

            string APE, NOM;

            float BEC;


            Console.WriteLine("\nIngrese el Legajo");
            LEG = ulong.Parse(Console.ReadLine());

            while (I < MAX&& LEG != 0)
            {   
                             
                Console.WriteLine("\nIngrese el Apellido");
                APE = Console.ReadLine();

                Console.WriteLine("\nIngrese el Nombre");
                NOM = Console.ReadLine();

                Console.WriteLine("\nIngrese el Beca");
                BEC = float.Parse(Console.ReadLine());
                
                AUX = new CAlumno(LEG, APE, NOM, BEC);

                Lista.Add(AUX);

                I++;
                
                Console.WriteLine("\nIngrese el Legajo");
                LEG = ulong.Parse(Console.ReadLine());

               
            }

            // ((CAlumno)Lista[I]).darDatos();

            for (I = 0; I < Lista.Count-1; I++)
            {
                for (int J = I+1; J < Lista.Count; J++)
                {
                    if( ((CAlumno)Lista[I]).getLegajo() > ((CAlumno)Lista[J]).getLegajo())
                    {
                        AUX = ((CAlumno)Lista[I]);
                        Lista[I] = Lista[J];
                        Lista[J] = AUX;
                    }
                }
            }

            Console.WriteLine("Los Datos de los alumno en orden de menor a mayor número de legajo\n");
            Console.ReadKey();
           
            for(I = 0; I < Lista.Count; I++)
            {
                Console.WriteLine(((CAlumno)Lista[I]).darDatos());
            }

                Console.WriteLine("\nFIN\n");

            Console.ReadKey();
        }
    }
}
