using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace Caballo_IF_FIN
{
    class Caballo
    {
        private static int[,] MAR;
        private static int[,] MON;
        private static int N = 8;
        private static int M = 0;
        private static int CON = 1;
        private static bool V = true;
        private static bool DIOS;
        private static string NOM;
        private static int MAX;
        private static int MAXX = 12949672;
        private static string AUX;
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

            Nuevos();
            string DIR;
            
            for (int I = 0; I < MAR.GetLength(0); I++)
            {
                for (int J = 0; J < MAR.GetLength(1); J++)
                {
                                       
                        NOM = "\\MAR[" + I + "," + J + "].txt";
                        DIR = "D:\\Dato de Escritorio\\C\\C#\\N Caballo I a F\\bin\\Release\\netcoreapp3.1\\MAR" + NOM;
                        AUX = "D:\\Dato de Escritorio\\C\\C#\\Caballo IF FIN\\bin\\Release\\netcoreapp3.1\\AUXX\\MAR[" + I + "," + J + "].txt";
                        
                        if (!(File.Exists(DIR)) && (File.Exists(AUX)))
                        {   
                            Recuperar();                       
                            MAR[I, J] = CON;
                            CON++;
                            Console.WriteLine("\nDe I = {0}, J = {1}", I, J);
                            
                            Los_Caballo(I, J);
                            Borrar();
                            CON = 1;
                            MAX = 0;
                            V = true;
                        }
                        

                }
                    Console.Clear();
            }






        }

        public static void Los_Caballo(int I, int J)
        {

            bool B;

            int NUM = CON;

            if(CON == M + 1 && DIOS)
            {                  
                DIOS = false;
                
            }

            if (CON == N * N + 1 && FIN())
            {
                    Mira();
                    Archivo();
                

                V = false;
            }
            if (!DIOS)
            {
                B = Verifica();
            }
            else
            {
                B = true;
            }
            

            if (V && B)
            {
                CON++;

                for (byte K = 0; K < MON.GetLength(0); K++)
                {
                    if (I + MON[K, 0] >= 0 && I + MON[K, 0] < N && J + MON[K, 1] >= 0 && J + MON[K, 1] < N && MAR[I + MON[K, 0], J + MON[K, 1]] == 0 &&(!DIOS))
                    {
                        MAX++;
                        MAR[I + MON[K, 0], J + MON[K, 1]] = NUM;
                        Los_Caballo(I + MON[K, 0], J + MON[K, 1]);
                        MAR[I + MON[K, 0], J + MON[K, 1]] = 0;
                    }

                    if (I + MON[K, 0] >= 0 && I + MON[K, 0] < N && J + MON[K, 1] >= 0 && J + MON[K, 1] < N && MAR[I + MON[K, 0], J + MON[K, 1]] == NUM && DIOS)
                    {
                        
                        Los_Caballo(I + MON[K, 0], J + MON[K, 1]);
                        MAR[I + MON[K, 0], J + MON[K, 1]] = 0;
                    }

                }
                CON--;
            }
            if ( MAX >= MAXX)
            {
                Guardar();
                Console.Write(" | ");
                MAX = 0;
                
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
            string DIR = "D:\\Dato de Escritorio\\C\\C#\\N Caballo I a F\\bin\\Release\\netcoreapp3.1\\MAR" + NOM;
            StreamWriter Sr = File.CreateText(DIR);

            for (int I = 0; I < MAR.GetLength(0); I++)
            {
                for (int J = 0; J < MAR.GetLength(1); J++)
                {
                    if (MAR[I, J] == 1)
                    {
                        Sr.Write("|{0}/1",N*N+1);
                    }
                    else
                    {
                        Sr.Write("|{0}", MAR[I, J]);
                    }


                }
                Sr.Write("\n");
            }
            Sr.Close();
        }

        private static void Guardar()
        {
            string E = "D:\\Dato de Escritorio\\C\\C#\\Caballo IF FIN\\bin\\Release\\netcoreapp3.1\\AUXX" + NOM;
            StreamWriter Sr = File.CreateText(E);

            for (int I = 0; I < MAR.GetLength(0); I++)
            {
                for (int J = 0; J < MAR.GetLength(1); J++)
                {                   
                        Sr.Write("|{0}", MAR[I, J]);                   
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

        private static bool FIN()
        {
            for (byte I = 0; I < MAR.GetLength(0); I++)
            {
                for (byte J = 0; J < MAR.GetLength(1); J++)
                {
                    if (MAR[I, J] == N * N)
                    {
                        for (byte K = 0; K < MON.GetLength(0); K++)
                        {
                            if (I + MON[K, 0] >= 0 && I + MON[K, 0] < N && J + MON[K, 1] >= 0 && J + MON[K, 1] < N)
                            {
                                if (MAR[I + MON[K, 0], J + MON[K, 1]] == 1)
                                {
                                    return true;
                                }
                            }

                        }

                    }
                }

            }
            return false;
        }

        private static void Nuevos()
        {
            string NOT,VIN;
            for (int I = 0; I < MAR.GetLength(0); I++)
            {
                for (int J = 0; J < MAR.GetLength(1); J++)
                {
                    NOT = "D:\\Dato de Escritorio\\C\\C#\\N Caballo I a F\\bin\\Release\\netcoreapp3.1\\MAR\\MAR[" + I + "," + J + "].txt";
                    AUX = "D:\\Dato de Escritorio\\C\\C#\\Caballo IF FIN\\bin\\Release\\netcoreapp3.1\\AUXX\\MAR[" + I + "," + J + "].txt";
                    VIN = "D:\\Dato de Escritorio\\C\\C#\\N caballo\\bin\\Release\\netcoreapp3.1\\MAR\\MAR[" + I + "," + J + "].txt";
                    if ( !File.Exists(NOT) && !File.Exists(AUX))
                    {                      
                        StreamWriter FN = File.CreateText(AUX);
                        StreamReader FP = new StreamReader(VIN);
                        
                        while (FP.EndOfStream == false)
                        {
                            FN.Write(FP.ReadLine());
                        }
                        
                        FP.Close();
                        FN.Close();
                    }
                }
            }
        
        }

        private static void Recuperar()
        {
            StreamReader FP = new StreamReader(AUX);
            int I=0, J=0;
            string E = "";
            char C;
            while (FP.EndOfStream == false)
            {
                C = (char)FP.Read();
                if ((C == '|' || C == '\n' ))
                {
                    //Console.WriteLine(NOM);
                    if (E != "")
                    {
                        MAR[I, J] = Int32.Parse(E);
                        E = "";
                        
                        if(MAR[I,J] > M)
                        {
                            M = MAR[I, J];
                        }

                        J++;
                        if (J == N)
                        {
                            J = 0;
                            I++;
                        }
                    }

                }
                else
                {
                    E = E + C;
                }
            }
            FP.Close();
                if (E  != "")
                {
                MAR[N-1, N-1] = Int32.Parse(E);
                }

                if (MAR[N-1, N-1] > M)
                {
                M = MAR[N-1, N-1];
                }

            DIOS = true;
           
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
                            if (I + MON[K, 0] >= 0 && I + MON[K, 0] < N && J + MON[K, 1] >= 0 && J + MON[K, 1] < N)
                            {
                                if (MAR[I + MON[K, 0], J + MON[K, 1]] == 0 || MAR[I + MON[K, 0], J + MON[K, 1]] == CON - 1)
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
                                if (I + MON[K, 0] < 0 || I + MON[K, 0] >= N || J + MON[K, 1] < 0 || J + MON[K, 1] >= N)
                                {
                                    NUM++;
                                    continue;
                                }

                            }

                        }

                        if (NUM == MON.GetLength(0))
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
