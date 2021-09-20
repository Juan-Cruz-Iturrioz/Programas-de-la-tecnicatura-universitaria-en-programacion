<?php


class SelectTime extends View
{
	public $V = true;
	public $ORI;
	public $DES;
	public $FEC;

	public function Setdatos($O,$D,$F){
		$this->V = false;
		$this->ORI = $O;
		$this->DES = $D;
		$this->FEC = $F;

	}
}

?>