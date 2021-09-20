<?php


class FormFecha extends View
{
	
	public $ORI;
	public $DES;
	public $VIA;

	public $V = True;


	public function Setdatos_1($Viajes){
		$this->ORI = $Viajes[0]['Origen'];
		$this->DES = $Viajes[0]['Destino'];
		$AUX = array();
	
 		foreach ($Viajes as $V ){
			$AUX[] = $V['Fecha_de_viaje']->format('d/m/y');
		}
		$AUX = array_unique($AUX);
		
		sort($AUX);
				
		$V = $this->cmp($AUX[9],$AUX[10]);
		usort($AUX, array($this, "cmp"));

		$this->VIA = $AUX;

		 
	}

	public function Setdatos_2($O,$D){

		$this->V = false;

		$this->ORI = $O;
		$this->DES = $D;
		$AUX = array();
		$V = time();

		for($I = 0; $I <= 30; $I++ ){

		$AUX[] = date('d/m/y',($V  + (86400*$I) ) );
		
		}

		$this->VIA = $AUX;
	}

	public function cmp($a, $b) {

		$A = date_create_from_format('d/m/y',$a);
		$B = date_create_from_format('d/m/y',$b);
		
		$A = $A->getTimestamp();
		$B = $B->getTimestamp();

		if ($A == $B) {
        	return 0;
    	}
    	
    	return ($A < $B) ? -1 : 1;
  	
	}


	
}
?>