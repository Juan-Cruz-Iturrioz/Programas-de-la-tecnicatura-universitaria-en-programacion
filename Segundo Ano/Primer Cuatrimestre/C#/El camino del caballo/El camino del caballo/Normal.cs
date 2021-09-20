using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;

namespace El_camino_del_caballo
{
    class Normal : Base_Caballo
    {
        private static byte N = 8;
        private byte CON = 1;
        private byte MON;
        private bool V = true;
        private string NOM;
        private string Timer;

        public Normal() : base()
        {
            Console.WriteLine("\n\t Calculadora el resultados el Tabla de {0} por {1} para el problema del caballo", N, N);
        }

        public void Start()
        {

            MON = GetMON();

            

            for (int I = 0; I < N; I++)
            {
                for (int J = 0; J < N; J++)
                {
                    NOM = @"\Resultado " + I + "-" + J + " Normal.txt";

                    if (Archivo_Is_Exists(NOM))
                    {
                        SetTimer();
                        SetMatrix(ref I, ref J, CON);
                   
                        Console.WriteLine("\n\t Punto de inicio X = {0} Y = {1}", I + 1, J + 1);


                        Matematicas(I, J);
                        Limpiar_MAR();
                        CON = 1;
                        V = true;
                        
                    }

                }

            }
        }


        public void Matematicas(int X, int Y)
        {

            if (Verifica(CON) && V)
            {
                if (Resultado(ref X, ref Y))
                {
                    V = false;
                    Guardar(false, NOM);
                    Mirar();
                }

                int AUX_X, AUX_Y;

                for (byte I = 0; I < MON; I++)
                {
                    AUX_X = X;
                    AUX_Y = Y;

                    if (Movimiento(ref AUX_X, ref AUX_Y, I))
                    {

                        if (AutoMove())
                        {
                            CON++;
                            SetMatrix(ref AUX_X, ref AUX_Y, CON);
                            Matematicas(AUX_X, AUX_Y);
                            SetMatrix(ref AUX_X, ref AUX_Y, 0);
                            CON--;
                        }
                        
                    }

                }

            }
        }

        public void SetTimer()
        {
            Timer = string.Format("{0:HH:mm:ss}", DateTime.Now.AddSeconds(60*5));
        }


        public bool AutoMove()
        {
            if( ( string.Format("{0:HH:mm:ss}", DateTime.Now) ).CompareTo(Timer) >= 0 )
            {

                if(CON <= 7)
                {
                    SetTimer();
                    return true;
                }

                return false;
            }
            else
            {
                return true;
            }


        }
    }
}