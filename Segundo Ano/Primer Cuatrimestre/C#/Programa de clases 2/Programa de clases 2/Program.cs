using Microsoft.VisualBasic;
using System;

namespace Programa_de_clases_2
{
    class Program
    {
        static void Main(string[] args)
        {
            ulong LEG = 0UL; 
            // LEG de legajo de el mejor alumno
            ulong AUX = 0UL;
            
            int NOT1 = 0;
            int NOT2 = 0;
            // notas de primer y del segundo parcial 

            int M_NOT1 = 0;
            // nota de primer del mejor alumno
            int M_NOT2 = 0;
            // nota de segundo del mejor alumno
            
            float PRO = 0f;
            //promedio
            float PRO_G = 0f;
            // para la sumar de todos los promedio , PRO_G de promedio general 
            float PRO_M = 0f;
            // para la guadad del mejor promedio , PRO_M de promedio del mejor alumno
            int CON = 0;
            // CON de contador de alumnos
            int MEN = 0;
            // MEN de menor,es para contador alumnos con promedio < 4
            int MED = 0;
            // MED de medio, es para contador alumnos con promedio = 4 y < 7
            int MAX = 0;
            // MAX de maximo, es para contador alumnos con promedio >=7

            string NOM = ""; 
            string GAN = "";
            // GAN de ganador por se el mejor alumno en primero ingresado

           
            Verificador_legajo(ref AUX);
            while(AUX != 0)
            {
                CON++;
                
                Console.WriteLine("ingreso el nombre del alumno");
                NOM = Console.ReadLine();
                //no verificador porque es mas fácil ingreso el lugar que estan en la lista de alumnos

                Console.WriteLine("\ningreso la nota de primer parcial entre 0 y 10");
                Verificador_notas(ref NOT1);
               
                Console.WriteLine("\ningreso la nota de segundo parcial entre 0 y 10");
                Verificador_notas(ref NOT2);

                PRO = Convert.ToSingle(NOT1 + NOT2) / 2;
                
                PRO_G += PRO;

                if(PRO_M < PRO)
                {
                    GAN = NOM;
                    LEG = AUX;
                    M_NOT1 = NOT1;
                    M_NOT2 = NOT2;
                    PRO_M = PRO;
                    GAN = NOM;
                }


                if(PRO < 4)
                {
                    MEN++;
                }

                if (PRO >= 4 && PRO < 7)
                {
                    MED++;
                }

                if (PRO >= 7)
                {
                    MAX++;
                }
                
                Verificador_legajo(ref AUX);
            
            }


            Console.WriteLine("\n\n 1) La contador alumnos son {0} con promedio general de {1}", CON, PRO_G / CON);
            Console.ReadKey();
            
            Console.WriteLine("\n 2) El mejor alumno es {0}, su legajo es {1}, en su primer parcial tiene {2}, segundo tiene {3} y su promedio es {4}", GAN ,LEG , M_NOT1 , M_NOT2 , PRO_M);
            Console.ReadKey();
            
            Console.WriteLine("\n 3) La contador de alumno con promedio menor a 4 son {0} , con mayor o igual 4, pero menor a 7 es {1} y mayor o igual 7 es {2}", MEN , MED , MAX);
            Console.ReadKey();
            
            Console.WriteLine("\n FIN del programa \n");
            Console.ReadKey();
        }
    
        public static void Verificador_notas(ref int NOT)
        {
            //como hay que verificar dos nota me parece mas facil usar un metodo
                        
            string AUX = Console.ReadLine();
            if (Information.IsNumeric(AUX))
            {
                NOT = Convert.ToInt32(AUX);
            }

            while (NOT < 0 || NOT > 10)
            {
                Console.WriteLine("por favor ingreso la nota entre 0 y 10");

                AUX = Console.ReadLine();
                if (Information.IsNumeric(AUX))
                {
                    NOT = Convert.ToInt32(AUX);
                }
                
            }
            
        }


        public static void Verificador_legajo(ref ulong LEG)
        {
            Console.WriteLine("\ningreso el numero de legajo o 0 para finaliza el programa ");
            string AUX = Console.ReadLine();

            while (!(Information.IsNumeric(AUX)) || (Convert.ToInt64(AUX) < 0))
            {
                Console.WriteLine("por favor ingreso el numero de legajo o 0 para finaliza el programa ");
                AUX = Console.ReadLine();
            }

            LEG = Convert.ToUInt64(AUX);
        }

    }
}
