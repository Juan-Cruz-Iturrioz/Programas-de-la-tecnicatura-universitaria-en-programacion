using System;
using System.IO;
using System.Text;

namespace RP
{
    class Program
    {
        
        private static int[,] MAR;
        private static int[,] MON;
        private static int N = 8;
        private static string NOT;
        static void Main(string[] args)
        {
            string NOM;


            /*MAR = new int[N, N];
            
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

            for (int I = 0; I < 8; I++)
            {
                for (int J = 0; J < 8; J++)
                {
            
                    NOM = "D:\\Dato de Escritorio\\C\\C#\\N caballo\\bin\\Release\\netcoreapp3.1\\MAR\\MAR[" + I + "," + J + "].txt";
                    NOT = "D:\\Dato de Escritorio\\C\\C#\\N Caballo I a F\\bin\\Release\\netcoreapp3.1\\MAR\\MAR[" + I + "," + J + "].txt";
                    
                    if(File.Exists(NOM) && (!File.Exists(NOT) ))
                    {
                        FP = new StreamReader(NOM);
                        Datos();                    
                        FP.Close();
                        
                        if (FIN()) 
                        {
                            
                            Archivo();
                        }
                    }
                }

            }*/
            //StreamWriter PF;
            for (int I = 0; I < 8; I++)
            {
                for(int J = 0; J < 8; J++)
                {   
                    for(int C = 2; C < 6; C++)
                    {
                        NOM = "D:\\Dato de Escritorio\\C\\C#\\N Caballo I a F\\bin\\Release\\netcoreapp3.1\\NOT MAR\\MAR[" + I + "," + J + "] CON = " +C+".txt";

                        StreamWriter PF = File.CreateText(NOM);
                        PF.Write("NOT");
                        PF.Close();
                    }
                    
                }
            }

            for (int C = 6; C < 14; C++)
            {
                NOM = "D:\\Dato de Escritorio\\C\\C#\\N Caballo I a F\\bin\\Release\\netcoreapp3.1\\NOT MAR\\MAR[" + 7 + "," + 6 + "] CON = " +C+".txt";

                StreamWriter PF = File.CreateText(NOM);
                PF.Write("NOT");
                PF.Close();
            }

            for (int C = 6; C < 64; C++)
            {
                NOM = "D:\\Dato de Escritorio\\C\\C#\\N Caballo I a F\\bin\\Release\\netcoreapp3.1\\NOT MAR\\MAR[" + 7 + "," + 7 + "] CON = " + C + ".txt";

                StreamWriter PF = File.CreateText(NOM);
                PF.Write("NOT");
                PF.Close();
            }


        }

        /*static void Datos()
        {
            int I = 0;
            int J=0;
            //bool V;
            char C;
            /*string P;
            P = FP.Read()
            string NOM = "";

            
            while (FP.EndOfStream == false)
            {
                C = (char)FP.Read();
                if ((C == '|' || C == '\n')  )
                {
                    //Console.WriteLine(NOM);
                    if(NOM != "")
                    {
                        MAR[I, J] = Int32.Parse(NOM);
                        NOM = "";
                        I++;
                        
                        if (I == 8)
                        {
                            I = 0;
                            J = J + 1;
                        }
                    }
                    
                }
                else
                {
                    NOM = NOM + C;
                }
                //Console.Write(C);
            }
            
          
        }*/

        private static void Archivo()
        {
            StreamWriter Sr = File.CreateText(NOT);

            for (int I = 0; I < MAR.GetLength(0); I++)
            {
                for (int J = 0; J < MAR.GetLength(1); J++)
                {
                    if (MAR[I, J] == 1)
                    {
                        Sr.Write("|65/1");
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

    }
}
