<?php

require '../fw/FW.php';

require '../models/Viajes.php';

require '../views/FormViajes.php';


	
if(!(isset($_COOKIE['id_viaje']))){
	die("Error 0 expiracion del programa");
}
else{
	$ID_V = $_COOKIE['id_viaje'] ;
	$AUX = new Viajes();
	$V = $AUX->verificacion_Id($ID_V);

	if( $V ){
		die("Error 7 modificacion de cookie");
	}

	$AUX = $AUX->getViajes_For_ID($ID_V);
		
	if(count($AUX) > 0){
		$Datos = new FormViajes();
		$Datos->Setdatos($AUX);
		$Datos->ManualTitle("Final de la asignación");
		$Datos->renden();
	}
}



	




?>