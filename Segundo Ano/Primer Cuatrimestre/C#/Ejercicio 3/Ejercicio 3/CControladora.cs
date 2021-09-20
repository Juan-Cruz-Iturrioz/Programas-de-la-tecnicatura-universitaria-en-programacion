using System;

namespace Ejercicio_3
{
    public class CControladora
    {
        public static void Main()
        {
            CPersonas ListadePersonas = new CPersonas();
            char opcion;
            uint auxDNI;
            do
            {
                char.TryParse(CInterfaz.DarOpcion().ToUpper(), out opcion);
                
                switch (opcion)
                {
                    case 'A':
                        auxDNI = Convert.ToUInt32(CInterfaz.PedirDato("DNI"));
                        string auxApe = CInterfaz.PedirDato("Apellido");
                        string auxNom = CInterfaz.PedirDato("Nombre");
                        if (!ListadePersonas.CrearPersona(auxDNI, auxApe, auxNom))
                        {
                            CInterfaz.MostrarInfo("Este DNI ya esta en uso.");
                        }
                        break;
                    case 'M':
                        auxDNI = Convert.ToUInt32(CInterfaz.PedirDato("DNI"));
                        CInterfaz.MostrarInfo(ListadePersonas.DarDatos(auxDNI));
                        break;
                     case 'L':
                        CInterfaz.MostrarInfo(ListadePersonas.DarDatos());
                        break;
                    case 'R':
                        auxDNI = Convert.ToUInt32(CInterfaz.PedirDato("DNI"));
                        if (!ListadePersonas.EliminarPersona(auxDNI))
                        {
                            CInterfaz.MostrarInfo("Persona Inexistente");
                        }
                        break;
                    case 'S':
                        break;
                    default:
                        CInterfaz.MostrarInfo("Opción inválida");
                        break;
                }
            } while (opcion != 'S');
        }
    }
}