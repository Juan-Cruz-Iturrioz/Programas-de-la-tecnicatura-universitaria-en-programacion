<?php

class PDF extends View
{
	
	function SetPDF($ID,$VAG,$C,$P,$PRE,$ASI,$P_NOM,$P_DNI){

		$PDF = new FPDF();
		$PDF->AddPage();
		$PDF->SetFont('Arial','B',16);
		
		$AUX = 'ID de tren = ' . $ID;
		$PDF->Cell(40,10,$AUX,1);

		$P = str_replace('_',' ',$P);

		$AUX = 'Numero de vagon = ' . $VAG . '			Clase = ' . $C . '			Plaza = '. $P;
		$PDF->Ln();
		$PDF->Ln();
		$PDF->Cell(40,10,$AUX,0,0);
		

		$AUX = 'Numero de asiento = ' . $ASI . '		Precio = ' . $PRE;
		$PDF->Ln();
		$PDF->Ln();
		$PDF->Cell(40,10,$AUX,0,0);

		$AUX = 'Nombre de pasajero = ' . $P_NOM . '		DNI = ' . $P_DNI;
		$PDF->Ln();
		$PDF->Ln();
		$PDF->Cell(40,10,$AUX,0,0);

		$PDF->Output();
	}

}

?>