<?php


class FormFecha extends View
{
	
	public $ORI;
	public $DES;
	public $VIA;

	public function Setdatos_1($Viajes){
		$this->ORI = $Viajes[0]['Origen'];
		$this->DES = $Viajes[0]['Destino'];
		$this->VIA = array();
	
 		foreach ($Viajes as $V ){
			$this->VIA[] = $V['Fecha_de_viaje']->format('d/m/y');
		}
		$this->VIA = array_unique($this->VIA);
		sort($this->VIA);
		
	}

	public function Setdatos_2($O,$D){

		$this->ORI = $O;
		$this->DES = $D;
		$AUX = array();
		$V = time();

		for($I = 0; $I <= 30; $I++ ){

		$AUX[] = date('d/m/y',($V  + (86400*$I) ) );
		
		}

		$this->VIA = $AUX;
	}

}

?>