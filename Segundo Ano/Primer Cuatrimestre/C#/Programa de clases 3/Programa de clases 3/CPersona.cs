//Archivo CPersona.cs
namespace Ejemplo
{
    class CPersona
    {
        private string dni;
        private string apellidos;
        private string nombres;

        public CPersona(string doc)
        {
            this.dni = doc;
        }
        public CPersona(string doc, string nom, string ape)
        {
            this.dni = doc;
            this.apellidos = ape;
            this.nombres = nom;
        }
        public CPersona() : this("00000000", "John", "Doe")
        { }
        public string Dni
        {
            set { this.dni = value; }
            get { return this.dni; }
        }
        public void SetApellidos(string ape)
        {
            this.apellidos = ape;
        }
        public string GetApellidos()
        {
            return this.apellidos;
        }
        public void SetNombres(string nom)
        {
            this.nombres = nom;
        }
        public string GetNombres()
        {
            return this.nombres;
        }
        public virtual string DarDatos()
        {
            string datos = "DNI: " + this.dni;
            datos += " - Apellidos: " + this.apellidos;
            datos += " - Nombres: " + this.nombres + ".";
            return datos;
        }
    }
}
