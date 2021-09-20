using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;

namespace P_Parcial_1
{
    class CMaqPesadas
    {
        ArrayList listadoMaqPes;

        public CMaqPesadas()
        {
            this.listadoMaqPes = new ArrayList();
        }

        public CMaqPesada buscar(ulong inv)
        {
            foreach (CMaqPesada AUX in this.listadoMaqPes)
            {
                if(AUX.getNumInv() == inv)
                {
                    return AUX;
                }
            }
            return null;
        }

        public bool registrar(ulong inv, string det, float alq, bool reg)
        {
            CMaqPesada AUX = buscar(inv);

            if(AUX == null)
            {
                AUX = new CMaqPesada(inv, det, reg);

                if(alq != 0)
                {
                    AUX.AlqDiario = alq;
                }

                this.listadoMaqPes.Add(AUX);
                return true;
            }
            else
            {
                return false;
            }
        }

        public bool remover(ulong inv)
        {
            CMaqPesada AUX = buscar(inv);

            if(AUX != null)
            {
                this.listadoMaqPes.Remove(AUX);
                return true;
            }
            else
            {
                return false;
            }
            
        }

        public string darDatos(ulong inv)
        {
            CMaqPesada AUX = buscar(inv);

            if (AUX != null)
            { return AUX.darDatos(); }
            
            else
            {    return "Maquinaria pesada no registrada"; }

        }
    }
}
