using System;

namespace PP
{
    class Program
    {
        public static bool Primos (int N)
        {
            int I;

            for (I = 2; I <=(N/2); I++)
            {
                if ( (N%I) == 0) {
                    return false;
                }
                    

            }
            return true;

        }

        static void Main(string[] args)
        {
            int N;
           
            for (N = 1; N <=100; N ++)
            {
                
                if (Primos(N))
                {
                    Console.Write(N);
                    Console.Write("\n");
                }
                
            }
            Console.Write("\nFIN\n");
            Console.ReadKey();
        }
    }
}
