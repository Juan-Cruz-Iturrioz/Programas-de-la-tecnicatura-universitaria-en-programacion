using Microsoft.Office.Interop.Excel;
using System;
using System.Diagnostics;
using System.IO;

namespace P_DataGridView
{
    class Program
    {
        static void Main(string[] args)
        {

            string Ruta = "C:\\Users\\iturr\\OneDrive\\Escritorio\\Text1.xlsx";

            if (!(File.Exists(Ruta)))
            {

                Microsoft.Office.Interop.Excel.Application Wapp = new Microsoft.Office.Interop.Excel.Application();
                Microsoft.Office.Interop.Excel.Worksheet Wsheet;
                Microsoft.Office.Interop.Excel.Workbook Wbook;


                Wbook = Wapp.Workbooks.Add(true);
                Wsheet = (Worksheet)Wbook.ActiveSheet;

                Wsheet.Cells[3, 2] = "Hola";
                Wbook.SaveAs(Filename: Ruta, ConflictResolution: XlSaveConflictResolution.xlLocalSessionChanges, AddToMru: false);

                Wbook.Close();
                Wapp.Quit();

                foreach (var process in Process.GetProcessesByName("excel"))
                {
                    if (process.MainWindowTitle.Trim() == "")
                    {
                        process.Kill();
                    }

                }
            }

            else
            {

                Microsoft.Office.Interop.Excel.Application Wapp = new Microsoft.Office.Interop.Excel.Application();
                Microsoft.Office.Interop.Excel.Workbook Wbook;
                Microsoft.Office.Interop.Excel.Worksheet Wsheet;

                Wbook = Wapp.Workbooks.Open(Ruta);

                Wsheet = (Worksheet)Wbook.Worksheets[1];

                string AUX = (string)((Microsoft.Office.Interop.Excel.Range)Wsheet.Cells[1, 1]).Value2;

                Console.WriteLine(AUX);


                Wbook.Close();
                Wapp.Quit();


                foreach (var process in Process.GetProcessesByName("excel"))
                {
                    if(process.MainWindowTitle.Trim() == "")
                    {
                        process.Kill();
                    }

                }



            }



        }
    }
}
