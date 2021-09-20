using System;

namespace Parcial_1_de_Iturrioz_Juan_Cruz
{
    class CAereo : CViaje
    {
        private static float impuesto; //impuesto a viajes aéreos
        private bool internacional; // tipo de vuelo, true ==  internacional , false == cabotaje 

        internal static void Setimpuesto(float imp)
        { impuesto = imp;}

        public CAereo(string COD, string ORI, string DES , float PEG, bool TIPO) : base(COD, ORI, DES)
        {
            PrecioViaje = PEG;
            this.internacional = TIPO;
        }

        public override string darDatos()
        {
            string AUX = base.darDatos();
            AUX += " \t impuesto a viajes aéreos :$" + Convert.ToString(impuesto);

            AUX += " \t tipo de vuelo :";
            if (internacional)
            { AUX += "internacional"; }
            
            else
            { AUX += "cabotaje"; }

            return AUX;
        }

    }
}
