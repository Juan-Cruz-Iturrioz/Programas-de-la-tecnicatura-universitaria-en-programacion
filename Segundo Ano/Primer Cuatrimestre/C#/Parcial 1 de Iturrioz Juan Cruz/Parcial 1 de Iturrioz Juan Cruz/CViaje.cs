using System;

namespace Parcial_1_de_Iturrioz_Juan_Cruz
{
    class CViaje : IComparable
    {
        private string Código;
        private string Origen;
        private string Destino;
        private float Precio;

        public CViaje(string COD, string ORI, string DES)
        {
            this.Código = COD;
            this.Origen = ORI;
            this.Destino = DES;
        }


        public string GetOrigen()
        { return this.Origen; }

        public string GetDestino()
        { return this.Destino; }

        public string GetCodigo()
        { return this.Código; }

        public float PrecioViaje
        {
            get { return this.Precio; }

            set { this.Precio = value; }
        }

        public float darPrecio(byte cuotas)
        {
            float recargo = 0f;
            
            if (cuotas == 1)
            { recargo = 0f; }

            if (cuotas == 3)
            { recargo = 0.1f; }

            if (cuotas == 6)
            { recargo = 0.2f; }

            if (cuotas == 12)
            { recargo = 0.4f; }

            return this.Precio + (this.Precio * recargo);

        }

        public virtual string darDatos()
        {
            string AUX = "Código :" + this.Código;
            AUX += "\t Origen :" + this.Origen;
            AUX += "\t Destino :" + this.Destino;
            AUX += "\t Precio :$" + Convert.ToString(this.Precio);

            return AUX;
        }

        public int CompareTo(object obj)
        {
            int Puntos = 0;

            if(obj is CViaje)
            {
                if(this.Destino != ((CViaje)obj).GetDestino())
                { Puntos += 1; }

                if (this.Origen != ((CViaje)obj).GetOrigen())
                { Puntos += 2; }
            }
            
            return Puntos;
        }
    }
}
