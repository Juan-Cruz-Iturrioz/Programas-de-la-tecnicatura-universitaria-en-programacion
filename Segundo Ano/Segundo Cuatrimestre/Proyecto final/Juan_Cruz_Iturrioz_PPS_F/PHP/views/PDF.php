<?php

class PDF extends View
{	
	public $N_T;
	public $VAGON;
	public $CLA;
	public $PLA;
	public $PRECIO;
	public $ASIENTO;
	public $NOM;

	public $ORI; 
	public $DES;
	public $FEC;
	public $HE;
	public $HL;

	
	public function SetPDF($ID,$VAG,$C,$P,$PRE,$ASI,$P_NOM,$AUX){

		$this->N_T = $ID;
		$this->VAGON = $VAG;
		$this->CLA = $C;
		$this->PLA = str_replace('_', " ",$P);
		$this->PRECIO = $PRE;
		$this->ASIENTO = $ASI;
		$this->P_NOM = $P_NOM;

		$this->ORI = $AUX[0]['Origen']; 
		$this->DES = $AUX[0]['Destino'];
		$this->FEC = $AUX[0]['Fecha_de_viaje']->format('d/m/y');
		$this->HE = $AUX[0]['Horario_de_embarcacion']->format('H:i');
		$this->HL = $AUX[0]['Horario_de_llegada']->format('H:i');
	}


}

?>