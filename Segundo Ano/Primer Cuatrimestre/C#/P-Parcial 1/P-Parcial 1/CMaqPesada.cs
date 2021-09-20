using System;
using System.Collections.Generic;
using System.Runtime.CompilerServices;
using System.Text;

namespace P_Parcial_1
{
    class CMaqPesada : CMaquinaria
    {

        private static float seguro;
        private bool registroEspecial;

        internal static void setSeguro(float seg)
        {
            seguro = seg;            
        }

        public CMaqPesada(ulong inv, string det, bool reg) : base(inv, det)
        {
            this.registroEspecial = reg;
            
            AlqDiario = 10000.00f;
        }

        public override float darCosto(ushort Dias)
        {
            return seguro + base.darCosto(Dias);
        }

        public override string darDatos()
        {
            string AUX = base.darDatos();

            AUX += "\t Seguro :" + Convert.ToString(seguro);
            
            AUX += "\t RegistroEspecial :" + Convert.ToString(this.registroEspecial);

            return AUX;

        }
    }
}
