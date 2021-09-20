using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PP2
{
    class Vectores
    {
        private int[] VER;

        public void Cargar()
        {
            int I, N;
            N = 10;
            VER = new int[N];
            for (I = 0; I < VER.Length; I++)
            { 
                VER[I] =  N-I;
            }
        }

        public void Imprimir()
        {
            for (int f = 0; f < VER.Length; f++)
            {
                Console.Write(VER[f]);
                Console.Write("-");
            }
            Console.Write("\n");
        }
       
        public void Ordenamiento()
        {
            int I, J, AUX;

            for (I = 0; I < VER.Length-1; I++)
            {
                for (J = 0; J < VER.Length-1; J++)
                {

                    if (VER[J] > VER[J + 1])
                    {
                        AUX = VER[J];
                        VER[J] = VER[J + 1];
                        VER[J + 1] = AUX;

                    }


                }


            }

        }


        static void Main(string[] args)
        {
            Vectores pv = new Vectores();
            pv.Cargar();
            pv.Imprimir();
           pv.Ordenamiento();
           pv.Imprimir();
            Console.WriteLine("\nFIN\n");
           Console.ReadKey();
        }
    }
}

