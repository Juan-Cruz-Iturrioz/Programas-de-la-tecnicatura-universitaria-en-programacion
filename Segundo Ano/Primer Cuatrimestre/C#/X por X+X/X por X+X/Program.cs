using System;

namespace X_por_X_X
{
    class Program
    {
        static void Main(string[] args)
        {
            
            for(long X = 0; X < Int64.MaxValue; X++)
            {
                //long Y = (long)X;
                ulong AUX_1 = (ulong)( -1*(X - (X ^ 2)));
              
                ulong AUX_2 = (ulong)((X ^ 2) - X);
                if (!(AUX_1 == AUX_2))
                {
                    Console.WriteLine("\n {0} != {1} \n", AUX_1, AUX_2);
                }
            }

           
            Console.WriteLine("\nFin\n");
            Console.ReadKey();
        }
    }
}
