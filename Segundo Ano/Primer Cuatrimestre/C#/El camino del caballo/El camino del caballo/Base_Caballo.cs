using System;
using System.IO;
using System.Text;

namespace El_camino_del_caballo
{
    abstract class Base_Caballo
    {
        private int[,] MAR;
        private int[,] MON;
        private static byte N = 8;
        private string Ruta;

        public Base_Caballo()
        {
            MAR = new int[N, N];
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

            Limpiar_MAR();

            Carpetas();
        }

        public void Limpiar_MAR()
        {
            for(int I = 0; I < N; I++)
            {
                for(int J = 0; J < N; J++)
                {
                    MAR[I, J] = 0;
                }
            }
        }

        public void Mirar()
        {
            Console.WriteLine();
            for (int I = 0; I < N; I++)
            {
                for (int J = 0; J < N; J++)
                {   
                    switch(J)
                    {
                        case 0:
                            Console.Write("\t {0}", MAR[I, J]);
                            break;
                        
                        default:
                            Console.Write("|{0}", MAR[I, J]);
                            break;
                    }
                    
                }
                Console.WriteLine();
            }
        }

        public bool Verifica(byte CON)
        {
            byte NUM = 0;
            int X, Y;
            bool Verdad;
            for (byte I = 0; I < this.MAR.GetLength(0); I++)
            {
                for (byte J = 0; J < this.MAR.GetLength(1); J++)
                {
                    if (MAR[I, J] == 0)
                    {
                        for (byte K = 0; K < this.MON.GetLength(0); K++)
                        {
                            X = I;
                            Y = J;
                            Verdad = Movimiento(ref X,ref Y, K);

                            if (Verdad)
                            {
                                if (this.MAR[X, Y] == 0 || this.MAR[X, Y] == CON - 1)
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
                                if (X < 0 || X >= N || Y < 0 || Y >= N)
                                {
                                    NUM++;
                                    continue;
                                }

                            }

                        }

                        if (NUM == this.MON.GetLength(0))
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

        public bool Movimiento(ref int X, ref int Y, byte I)
        {
            
                if (X + this.MON[I, 0] >= 0 && X + this.MON[I, 0] < N && Y + this.MON[I, 1] >= 0 && Y + this.MON[I, 1] < N && this.MAR[X + this.MON[I, 0], Y + this.MON[I, 1]] == 0)
                {
                    X = X + this.MON[I, 0];
                    Y = Y + this.MON[I, 1];
                    return true;

                }
            X = X + this.MON[I, 0];
            Y = Y + this.MON[I, 1];
            return false;
        }

        public void SetMatrix(ref int X, ref int Y,  byte NUM)
        {
            MAR[X, Y] = NUM;
        }

        public byte GetMatrix(ref int X, ref int Y)
        {
            return (byte) (this.MAR[X, Y]);
        }

        public byte GetMON()
        {
            return (byte)(this.MON.GetLength(0));
        }

        public void Carpetas()
        {
            Ruta = Path.GetDirectoryName(System.Reflection.Assembly.GetEntryAssembly().Location);
            /* link 
             https://www.it-swarm.dev/es/c%23/cual-es-la-mejor-manera-de-obtener-la-ruta-ejecutable-del-exe-en-.net/967446206/ */
            
            string AUX;
            string [] VEC = new string[4];
            VEC[0] =  @"\Soluciones" ;
            VEC[1] = VEC[0] + @"\Normal";
            VEC[2] = VEC[0] + @"\Cerrado";
            VEC[3] = VEC[0] + @"\Auxiliar";

            for(byte I = 0; I < VEC.GetLength(0); I++)
            {
                AUX = Ruta + VEC[I];

                    if (!Directory.Exists(AUX))
                    { 
                        Directory.CreateDirectory(AUX); 
                    }
            }

            AUX = Ruta + VEC[3] + @"\limite.txt";
            if (!File.Exists(AUX))
            {
                StreamWriter Archivo = new StreamWriter(AUX);
                Archivo.WriteLine(2);
                Archivo.Close();
            }
            
            Ruta += VEC[0];
            
        }

        public virtual bool Resultado(ref int X, ref int Y)
        {
            if (MAR[X, Y] == 64)
            { return true; }
            else { return false; }
        }


        public void Guardar (bool Cerrado, string NOM)
        {
            string AUX;

            if (Cerrado)
            { AUX = Ruta + @"\Cerrado"; }
            else { AUX = Ruta + @"\Normal"; }

            AUX += NOM;

            if (!File.Exists(AUX))
            {   
                StreamWriter Archivo = File.CreateText(AUX);
                for (int I = 0; I < MAR.GetLength(0); I++)
                {
                    for (int J = 0; J < MAR.GetLength(1); J++)
                    {
                        switch (J)
                        {
                            case 0:
                                Archivo.Write(" {0}", MAR[I, J]);
                                break;

                            default:
                                Archivo.Write("|{0}", MAR[I, J]);
                                break;
                        }

                        //Archivo.Write("|{0}", MAR[I, J]);

                    }
                    Archivo.Write("\n");
                }
                Archivo.Close();
            }
            
        }

        public bool Recuperar(string NOM, ref int MAX)
        {
            if (File.Exists(NOM))
            {
                StreamReader Archivo = new StreamReader(NOM);

                
                int I = 0, J = 0;
                string AUX = "";
                char Letra;

                while (Archivo.EndOfStream == false)
                {
                    Letra = (char)Archivo.Read();
                    if ((Letra == '|' || Letra == '\n'))
                    {
                        //Console.WriteLine(NOM);
                        if (AUX != "")
                        {
                            MAR[I, J] = Int32.Parse(AUX);
                            AUX = "";

                            if (MAR[I, J] > MAX)
                            {
                                MAX = MAR[I, J];
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
                        AUX = AUX + Letra;
                    }
                }

            return true;
            
            }
            
            return false;
        }
        
        public virtual bool Archivo_Is_Exists(string NOM)
        {
            string AUX;
            
            AUX = "Normal.txt";

            if (NOM.Contains(AUX))
            {
                AUX = Ruta + @"\Normal" + NOM;

                if (File.Exists(AUX))
                {
                    return false;
                }
                else 
                {
                    return true;
                }

            }

            AUX = "Cerrado.txt";
            if (NOM.Contains(AUX))
            {
                AUX = Ruta + @"\Cerrado" + NOM;
                if (File.Exists(AUX))
                {
                    return false;
                }
                else
                {
                    return true;
                }

            }

            return true;


        }


    }
}
