using System;

namespace Ejercicio_3
{
    public class CPersona
    {
        private string NOMBRES;
        private string APELLIDOS;
        private uint DNI;

        public CPersona()
        {
            this.NOMBRES = "";
            this.APELLIDOS = "";
            this.DNI = 0;
        }

        public CPersona(string AuxNom, string AuxApe, uint AuxDNI)
        {
            this.NOMBRES = AuxNom;
            this.APELLIDOS = AuxApe;
            this.DNI = AuxDNI;
        }

        public string DarDatos()
        {
            string ret = this.DNI.ToString();
            ret += " - " + this.APELLIDOS + ", " + this.NOMBRES;
            return ret;
        }

        public void SetNOM(string aux)
        {
            this.NOMBRES = aux;
        }

        public void SetAPE(string aux)
        {
            this.APELLIDOS = aux;
        }

        public void SetDNI (uint aux)
        {
            this.DNI = aux;
        }

        public string GetNOM()
        {
            return this.NOMBRES; 
        }

        public string GetAPE()
        {
            return this.APELLIDOS;
        }

        public uint GetDNI()
        {
            return this.DNI;
        }


    }
}
