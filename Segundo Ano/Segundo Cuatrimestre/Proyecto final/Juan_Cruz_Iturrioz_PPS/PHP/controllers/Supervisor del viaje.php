<?php

require '../fw/FW.php';
require '../models/viajes.php';
require '../views/FormSupervisor.php';
require '../views/FormAsiento.php';


if(count($_POST) > 1){
	if( isset($_POST['Clase_vagones'])  and isset($_POST['Id_viaje'])){
	
	$Id_viaje = $_POST['Id_viaje'];
	$Clase = $_POST['Clase_vagones'];

	if( verificacion_Id_viaje($Id_viaje) ){
	die("Error 0 Id de viaje es invalido");
	}	

	$AUX = verificacion_Clase($Clase);
		setcookie("Id_viaje", $Id_viaje, time()+3600);
		setcookie("Clase", $Clase, time()+3600);

		$host  = $_SERVER['HTTP_HOST'];
		$uri   = rtrim(dirname($_SERVER['PHP_SELF']), '/\\');
		$extra = 'Disposicion.php';
		header("Location: http://$host$uri/$extra?Vagon=$AUX");
		exit;
	}

}
else {

$F_SUP = new FormSupervisor; 
$F_SUP->renden();

}

function verificacion_Clase($C){

$AUX_C = array("Turista","Pulman");

$AUX = array($C);

if ( count(array_diff($AUX_C,$AUX)) == count($AUX_C) ) {
	die("Error 1 de Clase vagones es invalido");
}

else{
	
	switch ($C) {

		case 'Turista' ;
			$AUX_C = 5;
			break;

		case 'Pulman' :
			$AUX_C = 1;
			break;
	}

}

return $AUX_C;

}




function verificacion_Id_viaje($ID){

$VIA = new viajes();
$query = $VIA->getViajes_ID();
$AUX_V = array();

foreach ($query as $V ){
	$AUX_V[] = $V['id_viaje'];
}

$AUX = array($ID);

$AUX_V = (count(array_diff($AUX_V,$AUX)) == count($AUX_V));

return $AUX_V; 

}

?>
