using System;
using System.IO;
using System.Text;

namespace Problema_del_caballo
{
    class Program
    {
        static void Main(string[] args)
        {
            /* Anfitrion ANF = new Anfitrion();
             ANF.Mesas();*/

            string path = @"c:\temp\MyTest.txt";

            try
            {
                // Create the file, or overwrite if the file exists.
                using (FileStream fs = File.Create(path))
                {
                    byte[] info = new UTF8Encoding(true).GetBytes("This is some text in the file.");
                    // Add some information to the file.
                    fs.Write(info, 0, info.Length);
                }

                // Open the stream and read it back.
                using (StreamReader sr = File.OpenText(path))
                {
                    string s = "";
                    while ((s = sr.ReadLine()) != null)
                    {
                        Console.WriteLine(s);
                    }
                }
            }

            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }


            Console.WriteLine("\nFIN del programa\n");
            Console.ReadKey();
        }
    }
}
