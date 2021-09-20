using System;

namespace Ejercicio_3
{
    public class CInterfaz
    {
        static CInterfaz()
        {
            Console.BackgroundColor = ConsoleColor.White;
            Console.ForegroundColor = ConsoleColor.Black;
        }
        public static string DarOpcion()
        {
            Console.Clear();
            Console.WriteLine("***********************************************");
            Console.WriteLine("*        Sistema de Gestión de Personas        *");
            Console.WriteLine("***********************************************");
            Console.WriteLine("\n\n[A] Agregar una Persona.");
            Console.WriteLine("\n[M] Mostrar datos de una Persona.");
            Console.WriteLine("\n[L] Listar los datos de todas las Personas.");
            Console.WriteLine("\n[R] Remover una Persona.");
            Console.WriteLine("\n[S] Salir de la aplicación.");
            Console.WriteLine("\n**********************************************");
            return CInterfaz.PedirDato("opción elegida");
        }
        public static string PedirDato(string nombDato)
        {
            Console.Write("[?] Ingrese " + nombDato + ": ");
            string ingreso = Console.ReadLine();
            while (ingreso == "")
            {
                Console.Write("[!] " + nombDato + "es de ingreso OBLIGATORIO:");
                ingreso = Console.ReadLine();
            }
            Console.Clear();
            return ingreso.Trim();
        }
        public static void MostrarInfo(string mensaje)
        {
            Console.WriteLine(mensaje);
            Console.Write("<Pulse Enter>");
            Console.ReadLine();
            Console.Clear();
        }
    }
}

