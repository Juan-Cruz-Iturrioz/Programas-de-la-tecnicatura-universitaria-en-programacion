<?php


class FormHoras extends View
{
	public $Viajes;
	public $ORI;
	public $DES;
	public $FEC;


	public function Setdatos($V){
		$this->Viajes = $V;
		$this->ORI = $this->Viajes[0]['Origen'];
		$this->DES = $this->Viajes[0]['Destino'];
		$this->FEC = $this->Viajes[0]['Fecha_de_viaje']->format('d/m/y');

		
	}

}

?>