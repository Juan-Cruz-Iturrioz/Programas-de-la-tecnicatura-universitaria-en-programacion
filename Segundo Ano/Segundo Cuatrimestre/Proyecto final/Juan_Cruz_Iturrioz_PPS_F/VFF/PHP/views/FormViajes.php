<?php


class FormViajes extends View
{
	public $From = false; 
	public $Viajes;
	public $Datos;

	public function Setdatos($Query){
		$this->Viajes = $Query;

	}

	public function Setdatos_1($Query){
		$this->From = true;
		$this->Setdatos($Query);

	}

	public function Setdatos_2($Query){
		$this->From = true;
		$this->Datos = $Query;


	}
}

?>