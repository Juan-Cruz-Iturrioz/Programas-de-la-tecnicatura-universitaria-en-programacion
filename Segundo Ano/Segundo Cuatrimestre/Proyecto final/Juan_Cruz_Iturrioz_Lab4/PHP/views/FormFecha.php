<?php


class FormFecha extends View
{
	
	public $ORI;
	public $DES;
	public $VIA;

	public function Setdatos($Viajes){
		$this->ORI = $Viajes[0]['Origen'];
		$this->DES = $Viajes[0]['Destino'];
		$this->VIA = array();
	
 		foreach ($Viajes as $V ){
			$this->VIA[] = $V['Fecha_de_viaje']->format('d/m');
		}
		$this->VIA = array_unique($this->VIA);
		sort($this->VIA);
		
	}

}

?>