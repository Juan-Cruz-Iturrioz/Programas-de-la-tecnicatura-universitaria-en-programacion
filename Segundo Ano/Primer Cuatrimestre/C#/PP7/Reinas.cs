using System;
using System.Collections.Generic;
using System.Text;

namespace PP7
{
    class Reinas
    {
        private int[,] MAR;
        private int NUM = 0;
        private int N;
        public Reinas()
        {
            Console.WriteLine("Ingrese las filas y columnas");
            N = int.Parse(Console.ReadLine());

            MAR = new int[N, N];
            Console.Clear();
        }

        public void Cargar(int I)
        {
            bool V = true;
            if (I == N)
            {
                if (Respuesta())
                {
                    NUM = NUM + 1;
                    Mira(NUM );
                }
                V = false;
            }

            if (V)
            {

                for (int J = 0; J < MAR.GetLength(1); J++)
                {
                    MAR[I, J] = 1;
                    Cargar(I + 1);
                    MAR[I, J] = 0;

                }

            }
        }     
        private bool Respuesta()
        {
            int[,] RES;
            RES = new int[N, 3];
            int K = 0;
            for (int I = 0; I < MAR.GetLength(0); I++)
            {
                for (int J = 0; J < MAR.GetLength(1); J++)
                {
                    if( MAR[I, J] == 1)
                    {
                        RES[K, 0] = J;
                        RES[K, 1] = I + J;
                        RES[K, 2] = I - J;
                        K = K + 1;
                        break;
                    }

                }
                
            }

            for(int I = 0; I < RES.GetLength(0); I++)
            {
                for (int J = I+1; J < RES.GetLength(0); J++)
                {
                  if( RES[I,0] == RES[J, 0] || RES[I, 1] == RES[J, 1] || RES[I, 2] == RES[J, 2])
                    {
                        return false;
                    }

                }
            }

            return true;
        }
        public void Mira(int K)
        {

            Console.WriteLine("NUM = {0}", K);

            for (int I = 0; I < MAR.GetLength(0); I++)
            {
                for (int J = 0; J < MAR.GetLength(1); J++)
                {
                    Console.Write("|" + MAR[I, J]);

                }
                Console.WriteLine();
            }
            //Console.ReadKey();
            //Console.Clear();
        }
    }
}
