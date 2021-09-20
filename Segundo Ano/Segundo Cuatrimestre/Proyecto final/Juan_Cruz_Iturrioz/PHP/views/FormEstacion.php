<?php


class FormEstacion extends View
{
	
	public $Estacion;


	public function Setdatos($EST){
		
		$AUX = array();
		foreach ($EST as $V) {
			$AUX[] = $V['Estacion'];
		}

		$this->Estacion = $AUX;
	}
}

?>