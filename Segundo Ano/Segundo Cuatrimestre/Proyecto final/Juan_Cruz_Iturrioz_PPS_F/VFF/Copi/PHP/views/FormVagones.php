<?php


class FormVagones extends View
{
	
	public $Clase ; //= array("Turista","Pulman");
	public $Plaza ; //= array("Fumador","No fumador");
	public $Precio = array( "Turista" => '2440' ,  "Pulman" => '2640' );

	public function Setdatos($VAG){

		$AUX_C = array();
		$AUX_P = array();

		foreach ($VAG as $V ) {
			$AUX_C[] = $V['Clase_vagones'];
			$AUX_P[] = str_replace('_', " ",$V['Plaza']);
		}

		$this->Clase = array_unique($AUX_C);
		$this->Plaza = array_unique($AUX_P);

		sort($this->Clase);
		sort($this->Plaza);

	}
}

?>