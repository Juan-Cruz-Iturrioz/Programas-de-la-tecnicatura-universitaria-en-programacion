using System;
using System.Collections;

namespace Parcial_1_de_Iturrioz_Juan_Cruz
{
    class CCatalogo
    {
        private ArrayList Listado;

        public CCatalogo()
        {
            this.Listado = new ArrayList();
        }

        public bool Registrar(string COD, string ORI, string DES, float PEG, bool TIPO)
        {
            bool V = true; // V for vendetta || V for victory

            foreach (CAereo AUX in this.Listado)
            {
                if (AUX.GetCodigo() == COD)
                { V = false; }
            }
            
            if( V )
            {
                CAereo AUX = new CAereo(COD, ORI, DES, PEG, TIPO);
                this.Listado.Add(AUX);
            }

            return V;

        }

        public bool Remover(string COD)
        {
            bool V = false;
            CAereo BUS = null; // BUS == Buscado

            foreach (CAereo AUX in this.Listado)
            {
                if (AUX.GetCodigo() == COD)
                {
                    BUS = AUX;
                    V = true;
                }
            }
            
            if( V )
            { this.Listado.Remove(BUS); }

            return V;
        }


        public void Remover()
        {
            this.Listado.Clear();
        }


    }
}
