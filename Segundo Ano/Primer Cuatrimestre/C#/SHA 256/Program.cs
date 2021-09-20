using System;
using System.IO;
using System.Text;
using System.Security.Cryptography;

namespace SHA_256
{
    class Program
{
    static void Main(string[] args)
    {
        string plainData;
        Console.Write("Ingrese el Texto\n");
        plainData = Console.ReadLine();
        Console.WriteLine("\nDato : {0}", plainData);
        string hashedData = ComputeSha256Hash(plainData);
        Console.WriteLine("\nHash {0}", hashedData);



            Fopen(hashedData);

        Console.ReadKey();
    }

    static string ComputeSha256Hash(string rawData)
    {
        // Create a SHA256   
        using (SHA256 sha256Hash = SHA256.Create())
        {
            // ComputeHash - returns byte array  
            byte[] bytes = sha256Hash.ComputeHash(Encoding.UTF8.GetBytes(rawData));

            // Convert byte array to a string   
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < bytes.Length; i++)
            {
                builder.Append(bytes[i].ToString("x2"));
            }
            return builder.ToString();
        }
    }


        public static void Fopen(string CON)
        {

            Stream FP = new FileStream("./texto.txt", FileMode.Create, FileAccess.Write);
            StreamWriter SW = new StreamWriter(FP);

            SW.Write(CON);

            SW.Close();
            FP.Close();

        }

    }
}