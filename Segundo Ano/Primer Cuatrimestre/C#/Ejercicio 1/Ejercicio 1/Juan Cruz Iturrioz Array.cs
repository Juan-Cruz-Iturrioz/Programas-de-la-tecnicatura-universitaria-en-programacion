using System;
using System.Collections;
using System.Linq;

namespace Ejercicio_1
{
    class Program
    {
        static void Main(string[] args)
        {

            string [] Lista = new string[10];

            string NOM = "";
            int I = 0,CON;

            Console.WriteLine("Ingrese asta 10 apellidos o asta se ingrese la palabra 'Salir'\n");
            
            Console.ReadKey();

            while (I != Lista.GetLength(0) && NOM != "Salir")
            {               
                Console.WriteLine("\nIngrese uno apellidos");
                NOM = Console.ReadLine();
                Lista[I]= NOM;
                I++;
                
            }

            if(Lista[I-1] == "Salir")
            {
                Lista[I-1] = "";
                I--;
            }

            CON = I;
            Console.Write("la lista de apellidos es orden de ingreso \n\n");
            
            Console.ReadKey();
            
            for ( I = 0; I < CON; I++)
            {              
                Console.WriteLine(Lista[I]);
            }

            Console.ReadKey();

            Array.Sort(Lista,0,CON);
            
            Console.Write("la lista de apellidos orden alfabético es\n\n");

            Console.ReadKey();

            for (I = 0; I < CON; I++)
            {    
                Console.WriteLine(Lista[I]);
            }

            Console.ReadKey();

            Console.WriteLine("\nFIN\n");

            Console.ReadKey();
        }
    }
}
