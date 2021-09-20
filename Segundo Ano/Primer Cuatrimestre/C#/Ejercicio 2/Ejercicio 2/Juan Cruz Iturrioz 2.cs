using Alumnos;
using System;

namespace Ejercicio_2
{
    class Program
    {
        static void Main(string[] args)
        {

            float CUOTA;

            Console.WriteLine("Ingrese la cuota");

            CUOTA = float.Parse(Console.ReadLine());

            CAlumno.setCUOTA(CUOTA);

            CAlumno[] ALU = new CAlumno[10];

            int I = -1 ,CON;

            Console.WriteLine("\nIngrese los dato de los alumnos asta 10 0 asta que se ingrese uno legajo de 0\n");
            
            Console.ReadKey();

            ulong LEG = 2;

            string APE, NOM;

            float BEC; 




            while (I != ALU.GetLength(0) && LEG != 0)
            {   
                I++;

                Console.WriteLine("\nIngrese el Legajo");
                LEG = ulong.Parse(Console.ReadLine());

                Console.WriteLine("\nIngrese el Apellido");
                APE = Console.ReadLine();

                Console.WriteLine("\nIngrese el Nombre");
                NOM = Console.ReadLine();

                Console.WriteLine("\nIngrese el Beca");
                BEC = float.Parse(Console.ReadLine());
                
                ALU[I] = new CAlumno(LEG, APE, NOM, BEC);
                

            } 


            CON = I;
            
            for(I = 0; I < CON; I++)
            {
                for (int J = 0; J < CON - 1; J++)
                {
                    if(ALU[J].getLegajo() > ALU[J + 1].getLegajo())
                    {
                        LEG = ALU[J].getLegajo();
                        ALU[J].setLegajo(ALU[J + 1].getLegajo());
                        ALU[J+1].setLegajo(LEG);

                        APE = ALU[J].getApellidos();
                        ALU[J].setApellidos(ALU[J + 1].getApellidos());
                        ALU[J + 1].setApellidos(APE);

                        NOM = ALU[J].getNombres();
                        ALU[J].setNombres(ALU[J + 1].getNombres());
                        ALU[J + 1].setNombres(NOM);

                        BEC = ALU[J].getBeca();
                        ALU[J].setBeca(ALU[J + 1].getBeca());
                        ALU[J + 1].setBeca(BEC);

                    }
                }
            }


            Console.WriteLine("Los Datos de los alumno en orden de menor a mayor número de legajo\n");
            Console.ReadKey();
            for (I = 0; I < CON; I++)
            {
                Console.WriteLine("\n" + ALU[I].darDatos());
            }

                Console.WriteLine("\nFIN\n");

            Console.ReadKey();
        }
    }
}
