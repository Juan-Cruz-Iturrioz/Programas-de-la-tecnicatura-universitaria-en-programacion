using System;
using System.IO;
using System.Linq;
using System.Timers;

namespace El_camino_del_caballo
{
    class Program
    {
        static void Main(string[] args)
        {
            Normal AUX = new Normal();
            AUX.Start();

            /*string AUX = string.Format("{0:HH:mm:ss}", DateTime.Now);


            string AUX1 = string.Format("{0:HH:mm:ss}", DateTime.Now.AddSeconds(30) );

            Console.WriteLine(AUX);
            Console.WriteLine(AUX1);


            Console.WriteLine(AUX1.CompareTo(AUX));
            /* 
            int I, J;
            I = 0;
            J = 0;
            string NOM = @"\Resultado " + Convert.ToString( I )+ "-" + Convert.ToString( J )+ " Normal.txt";

            Console.WriteLine(NOM.Contains(Convert.ToString(I) + "-" + Convert.ToString(J)));
            */


            Console.WriteLine("\nFIN\n");
            Console.ReadKey(); 
        }
    }
}
