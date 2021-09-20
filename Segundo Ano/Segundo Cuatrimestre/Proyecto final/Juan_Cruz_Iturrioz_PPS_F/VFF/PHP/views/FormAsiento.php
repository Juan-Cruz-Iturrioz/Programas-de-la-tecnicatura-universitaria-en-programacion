<?php


class FormAsiento extends View
{
	public $Tipos;
	public $Vag;

	public function Setdatos($T,$V){
		$this->Vag = $V;
		
		$this->Tipos = array();

		foreach ($T as $AUX ) {
			$this->Tipos[] = $AUX['Tipo_asiento'];		
		}
	}

}

?>