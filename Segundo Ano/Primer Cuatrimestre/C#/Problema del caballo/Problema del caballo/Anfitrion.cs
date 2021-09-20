using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace Problema_del_caballo
{
    class Anfitrion
    {
        private static string DIR = Directory.GetCurrentDirectory();

        public void Mesas()
        {
            string NOM = @"c:\new.txt";
            string T = DIR + NOM;

            using (StreamWriter sw = File.CreateText(T))
            {
                sw.WriteLine("Hello");
                sw.WriteLine("And");
                sw.WriteLine("Welcome");
            }
        }
    
    }


   
}
