using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace N_caballo
{
    class Caballo
    {
        private static int[,] MAR;
        private static int[,] MON;
        private static int N = 8;
        private static int CON = 1;
        private static bool V = true;
        private static string DIR = "D:\\Dato de Escritorio\\C\\C#\\N caballo\\bin\\Release\\netcoreapp3.1\\MAR";
        private static string NOM;
        private static int MAX;
        private static int MAXX = 12949672;
        private static int C;
        public Caballo()
        {
            //Console.WriteLine("Ingrese las filas y columnas");
            //N = int.Parse(Console.ReadLine());
            
            MAR = new int[N, N];
            Console.Clear();
            MON = new int[8, 2];

            MON[0, 0] = 2;
            MON[0, 1] = 1;

            MON[1, 0] = 1;
            MON[1, 1] = 2;

            MON[2, 0] = -1;
            MON[2, 1] = 2;

            MON[3, 0] = -2;
            MON[3, 1] = 1;

            MON[4, 0] = -2;
            MON[4, 1] = -1;

            MON[5, 0] = -1;
            MON[5, 1] = -2;

            MON[6, 0] = 1;
            MON[6, 1] = -2;

            MON[7, 0] = 2;
            MON[7, 1] = -1;

            string NOT;
            int LIM;
            StreamReader Sr = File.OpenText(DIR +"\\A.txt");
            LIM = Int32.Parse(Sr.ReadLine());
            Sr.Close();
            for (C = LIM; C < 50; C++)
            {

                for (int I = 0; I < MAR.GetLength(0); I++)
                {
                    for (int J = 0; J < MAR.GetLength(1); J++)
                    {

                        NOM = DIR + "\\MAR[" + I + "," + J + "].txt";
                        NOT = "D:\\Dato de Escritorio\\C\\C#\\N caballo\\bin\\Release\\netcoreapp3.1\\NOT MAR\\MAR[" + I + "," + J + "] CON = " + C + ".txt";
                        if (!(File.Exists(NOM)) && !(File.Exists(NOT)) )
                        {
                            MAR[I, J] = CON;
                            CON++;
                            Console.WriteLine("\nDe I = {0}, J = {1}, C = {2}", I, J,C);
                            Los_Caballo(I, J);
                            Borrar();
                            CON = 1;
                            MAX = 0;
                            V = true;
                        }
                        if (!(File.Exists(NOM))){
                            StreamWriter FN = File.CreateText(NOT);
                            FN.Write("NOT");
                            FN.Close();
                        }

                    }
                }
                Console.Clear();
                StreamWriter SW = File.CreateText(DIR+"\\A.txt");
                SW.Write(C+1);
                SW.Close();
            }

        }

        public static void Los_Caballo(int I, int J)
        {

            bool B;

            int NUM = CON;

            if (CON == N * N + 1 || MAX >= MAXX)
            {
                if (CON == N * N + 1)
                {
                    Mira();
                    Archivo();
                }

                V = false;
            }

            B = Verifica();

            if (V && B)
            {
                CON++;

                for (byte K = 0; K < MON.GetLength(0); K++)
                {
                    if (I + MON[K, 0] >= 0 && I + MON[K, 0] < N && J + MON[K, 1] >= 0 && J + MON[K, 1] < N && MAR[I + MON[K, 0], J + MON[K, 1]] == 0)
                    {
                        MAX++;
                        MAR[I + MON[K, 0], J + MON[K, 1]] = NUM;
                        Los_Caballo(I + MON[K, 0], J + MON[K, 1]);
                        MAR[I + MON[K, 0], J + MON[K, 1]] = 0;
                    }


                }
                CON--;
            }
            if (CON == C && MAX >= MAXX)
            {
                Console.Write(" | ");
                MAX = 0;
                V = true;
            }

        }

        private static void Mira()
        {
            Console.WriteLine();
            for (byte I = 0; I < MAR.GetLength(0); I++)
            {
                for (byte J = 0; J < MAR.GetLength(1); J++)
                {
                    Console.Write("|{0}", MAR[I, J]);
                }
                Console.WriteLine();
            }

        }

        private static void Archivo()
        {
            StreamWriter Sr = File.CreateText(NOM);
            
            for (int I = 0; I < MAR.GetLength(0); I++)
            {
                for (int J = 0; J < MAR.GetLength(1); J++)
                {
                    Sr.Write("|{0}",MAR[I, J]);
                                  
                }
                Sr.Write("\n");
            }
            Sr.Close();
        }

        private static void Borrar()
        {
            
            for (byte I = 0; I < MAR.GetLength(0); I++)
            {
                for (byte J = 0; J < MAR.GetLength(1); J++)
                {
                    MAR[I, J] = 0;
                }
               
            }

        }
    

        private static bool Verifica()
        {

            byte NUM = 0;
            for (byte I = 0; I < MAR.GetLength(0); I++)
            {
                for (byte J = 0; J < MAR.GetLength(1); J++)
                {
                    if (MAR[I, J] == 0)
                    {
                        for (byte K = 0; K < MON.GetLength(0); K++)
                        {
                            if ( I + MON[K, 0] >= 0 && I + MON[K, 0] < N && J + MON[K, 1] >= 0 && J + MON[K, 1] < N  )
                            {   
                                if(MAR[I + MON[K, 0], J + MON[K, 1]] == 0 || MAR[I + MON[K, 0], J + MON[K, 1]] == CON - 1)
                                {
                                    break;
                                }
                                else
                                {
                                    NUM++;
                                    continue;
                                }
                            }
                            else
                            {
                                if( I + MON[K, 0] < 0 || I + MON[K, 0] >= N || J + MON[K, 1] < 0 || J + MON[K, 1] >= N )
                                {
                                 NUM++;
                                 continue;
                                }
                            
                            }
                            
                        }
                        
                        if(NUM == MON.GetLength(0))
                        {  
                            return false;          
                        }
                        else
                        {
                            NUM = 0;
                        }

                    }

                }

                
            }


        return true;
        }

    }

}
