<?php


class FormEstacion extends View
{
	
	public $Estacion;
 	public $V = true;

	public function Setdatos($EST){
		
		$AUX = array();
		foreach ($EST as $V) {
			$AUX[] = $V['Estacion'];
		}

		$this->Estacion = $AUX;
	}

	public function Setdatos_2($EST){
		$this->V = false;
		$this->Setdatos($EST);
	}

	
}

?>