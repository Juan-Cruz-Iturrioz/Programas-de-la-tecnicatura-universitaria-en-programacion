<?php


class SelectBoleto extends View
{
	public $ASI;
	public $CAN;
	public $Clase;
	public $Plaza;
	public $Bool;

	public function Setdatos($VEC_ASI,$VEC_VEN,$C,$P,$Bool,$ARY){

	$this->CAN = $ARY;
	$this->Clase = $C;
	$this->Plaza = $P;
	$this->Bool = $Bool;

	$AUX = array();
	
	foreach($VEC_VEN as $V){
		$AUX[] = $V['Numero_de_asiento'];
	}

	if( count($AUX) == 0){
		$AUX[] = 0;
	}

	$this->ASI = array();
	$J = 0;

	for($I = 0; $I < count($VEC_ASI) ;$I++){
		
		$Venta = ($VEC_ASI[$I]['Numero_de_asiento'] == $AUX[$J]);
		
		if(count($AUX) <> $J and $Venta){
			$J++;			
			if(count($AUX) == $J){
				$J = $J - 1;
			}
		}
		
		$this->ASI[] = array("Numero_de_asiento" => $VEC_ASI[$I]['Numero_de_asiento'], "Tipo_asiento" => $VEC_ASI[$I]['Tipo_asiento'], 
			"Venta" => $Venta  );


	}

	
	}
}

?>