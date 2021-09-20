using System;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int F = 4 , C = 2;

            int[,] mat = new int[F, ];

            for(int I = 0; I < mat.GetLength(0); I++)
            {
                for (int J = 0; J < 8; J++)
                {
                    mat[I, J] = I+J;
                }
            }

            Console.WriteLine();
            for (int I = 0; I < mat.GetLength(0); I++)
            {
                for (int J = 0; J < mat.GetLength(1); J++)
                {
                    Console.Write("|{0}", mat[I, J]);
                }
                Console.WriteLine();
            }



        }
    }
}
