using System;
using System.Collections.Generic;
using System.Text;

namespace P_Parcial_1
{
    abstract class  CMaquinaria : IComparable
    {
        private ulong numInv;
        private string detalle;
        private float alquiler;


        public CMaquinaria(ulong inv , string det)
        {
            this.numInv = inv;
            this.detalle = det;
            this.alquiler = 0f;
        }

        public ulong getNumInv()
        {
            return this.numInv;
        }

        public float AlqDiario
        {
            get { return this.alquiler;  }

            set { this.alquiler = value; }
        }

        public virtual float darCosto(ushort Dias)
        {
            return (this.alquiler * Dias);
        }

        public virtual string darDatos() 
        {
            string AUX = "Número de Inventario :" + Convert.ToString(this.numInv);
            AUX += "\t Detalle :" + this.detalle;
            AUX += "\t Alquiler Diario :" + Convert.ToString(this.alquiler);
            return AUX;
        }

        public int CompareTo(object obj)
        {       
            if(obj is CMaquinaria)
            {
                int AUX = (int)(this.numInv - ((CMaquinaria)obj).getNumInv()) ; 
                return System.Math.Abs (AUX); /* Esto es para que siemper sea positivo 
                ej -1 * ( X - X^2 ) ==   X^2 - X    
                    -1*( 10 - 100 ) == 100 - 10  
                                 90 == 90                       
                 */
            }
            return (int)(this.numInv);


        }


    }
}
