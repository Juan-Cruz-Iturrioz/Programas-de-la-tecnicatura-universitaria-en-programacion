using System;
using System.Collections.Generic;
using System.Text;

namespace PRO3_C4
{
    class CPaquete
    {
        private float IMPUESTO;
        private uint numPaquete;
        private string Detalle;
        private float Precio;

            public void setIMPUESTO(float porcentaje)
            {
                this.IMPUESTO = porcentaje;
            }

            CPaquete(uint número, string descripción)
            {
                this.numPaquete = número;
                this.Detalle = descripción;
            }

            public void setPrecio(float monto)
            {
                this.Precio = monto;
            }

            public float getPrecio()
            {
                return this.Precio;
            }
            
            public float darMontoTotal()
            {
                float Total = this.Precio * (this.IMPUESTO / 100);
                return Total;
            }

            public float darMontoTotal(ushort cuotas)
            {
                float Total = this.Precio * (this.IMPUESTO / 100);
                
                if(cuotas != 1)
                {
                    Total *= Convert.ToSingle(0.1 * cuotas);
                }

                return Total;
               
                
            }
        
    }
}
