//Archivo CAlumno.cs
namespace Ejemplo
{
    class CAlumno:CPersona
    {
        private string legajo;
        public CAlumno():base()
        {
            this.legajo = "15-00000";
        }
        public CAlumno (string leg, string doc, string nom, string ape):base(doc,nom,ape)
        {
            this.legajo = leg;
        }
        public void SetLegajo(string leg)
        {
            this.legajo = leg;
        }
        public string Legajo
        {
            get { return this.legajo; }
        }
        public override string DarDatos()
        {
            string datos = "Legajo: " + this.legajo;
            datos+= " - " + base.DarDatos();
            return datos;
        }

    }
}
