<?php


class FormSupervisor extends View
{	
	public $Clase;
	public $ID;
	public function Setdatos($query,$ID){
	
		$AUX = array();

		
		foreach ($query as $V ) {
			$AUX[] = $V['Clase_vagones'];
		}

		sort($AUX);

		$this->Clase = $AUX;
		$this->ID = $ID;
	
	}
	
}

?>