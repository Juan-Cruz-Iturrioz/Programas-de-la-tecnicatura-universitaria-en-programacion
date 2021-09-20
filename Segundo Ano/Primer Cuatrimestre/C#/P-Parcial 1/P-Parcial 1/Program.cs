using System;

namespace P_Parcial_1
{
    class Program
    {
        static void Main(string[] args)
        {
            CMaqPesada.setSeguro(919f);
            
            CMaqPesadas Lista = new CMaqPesadas();

            Lista.registrar(10, "aa", 0, true);
            Lista.registrar(20, "ee", 9, false);

            Console.WriteLine(Lista.darDatos(10));
            Console.ReadKey();

            Console.WriteLine(Lista.darDatos(20));
            Console.ReadKey();

            Console.WriteLine(Lista.darDatos(2));
            Console.ReadKey();

            Lista.remover(10);

            Console.WriteLine(Lista.darDatos(10));
            Console.ReadKey();

            int AUX = Lista.buscar(10).CompareTo(Lista.buscar(20)) ;
            Console.WriteLine( AUX);
          
            Console.ReadKey();

            Console.WriteLine("Hello World!");
            Console.ReadKey();
        }
    }
}
