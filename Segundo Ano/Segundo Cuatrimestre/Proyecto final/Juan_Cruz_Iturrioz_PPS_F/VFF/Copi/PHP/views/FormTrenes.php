<?php


class FormTrenes extends View
{
	
	public $ORI;
	public $DES;
	public $FECHA;
	public $HE;
	public $HL;
	
	public $VIA;

	public function Setdatos($O,$D,$F,$E,$L,$Viajes){
		$this->ORI = $O;
		$this->DES = $D;
		$this->FECHA = $F;
 		$this->HE = $E;
		$this->HL = $L;

		$AUX = array();
	
 		foreach ($Viajes as $V ){
			$AUX[] = $V['Id_tren'];
		}

		$AUX = array_unique($AUX);
		sort($AUX);

		$this->VIA = $AUX;
			
	}
	
}

?>