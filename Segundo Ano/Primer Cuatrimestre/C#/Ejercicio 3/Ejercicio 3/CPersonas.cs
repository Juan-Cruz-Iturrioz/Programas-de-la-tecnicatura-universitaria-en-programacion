using System;
using System.Collections;

namespace Ejercicio_3
{
    public class CPersonas
    {
        private ArrayList Lista;

        public CPersonas()
        {
            this.Lista = new ArrayList();
        }

        public CPersona BuscaPersona(uint dni)
        {
            foreach (CPersona aux in this.Lista)
            {
                if (aux.GetDNI() == dni) return aux;
            }
            return null;
        }

        public bool CrearPersona(uint dni, string ape, string nom)
        {
            if (this.BuscaPersona(dni) == null)
            {
                this.Lista.Add(new CPersona(nom, ape, dni));
                return true;
            }
            return false;
        }

        public bool EliminarPersona(uint dni)
        {
            CPersona aux = this.BuscaPersona(dni);
            if (aux != null)
            {
                this.Lista.Remove(aux);
                return true;
            }
            return false;
        }

        public string DarDatos(uint dni)
        {
            CPersona aux = this.BuscaPersona(dni);
            if (aux != null) return aux.DarDatos();
            return "Persona inexistente";
        }
        public string DarDatos()
        {
            if (this.Lista.Count != 0)
            {
                this.Lista.Sort();
                String datos = "";
                foreach (CPersona aux in this.Lista) datos += aux.DarDatos() + "\n";
                return datos;
            }
            return "No se registraron personas";
        }
    }
}