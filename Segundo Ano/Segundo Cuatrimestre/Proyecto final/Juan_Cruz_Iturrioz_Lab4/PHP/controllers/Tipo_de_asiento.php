<?php

require '../fw/FW.php';
require '../models/viajes.php';
require '../views/FormVagones.php';
require '../views/FormAsiento.php';

if(!(isset($_COOKIE['id_viaje']))){
	die("Error 0 expiracion del programa");
}

$Id_viaje = $_COOKIE['id_viaje'] ;


if( verificacion_Id_viaje($Id_viaje) ){
	die("Error 7 modificacion de cookie");
}


if(count($_POST) == 3){
	if( isset($_POST['Clase_vagones']) and isset($_POST['Plaza']) ){
	$Clase = $_POST['Clase_vagones'];
	$Plaza = $_POST['Plaza'];

	$Vagones = verificacion_Vagones($Clase,$Plaza);
	
	$F_Asi = new FormAsiento();
	$F_Asi->Vag = $Vagones;
	$F_Asi->renden();
	
	}

	if( isset($_POST['Tipo_asiento']) and isset($_POST['Vagones']) ){

		$Tipo = $_POST['Tipo_asiento'];
		$Vagon = $_POST['Vagones'];
		verificacion_Asiento($Tipo,$Vagon);

		setcookie("Id_viaje", $Id_viaje, time()+3600);
		setcookie("Tipo", $Tipo, time()+3600);
		setcookie("Vagon_N", $Vagon, time()+3600);

		$host  = $_SERVER['HTTP_HOST'];
		$uri   = rtrim(dirname($_SERVER['PHP_SELF']), '/\\');
		$extra = 'Boletos.php';
		header("Location: http://$host$uri/$extra?Vagon=$Vagon");
		exit;
	}

}
else {

$F_Vag = new FormVagones(); 
$F_Vag->renden();

}

function verificacion_Vagones($C,$P){

$AUX_C = array("Turista","Pulman");
$AUX_P = array("Fumador","No fumador");

$AUX = array($C);

$AUX_C = (count(array_diff($AUX_C,$AUX)) == count($AUX_C));

$AUX = array($P);

$AUX_P = (count(array_diff($AUX_P,$AUX)) == count($AUX_P));

if (($AUX_C or $AUX_P)) {
			
	if ($AUX_C and !$AUX_P) {
		die("Error 1 de Clase vagones es invalido");
	}
	elseif($AUX_P and !$AUX_C){
		die("Error 2 de Plaza es invalido");
	}

die("Error 3 los Clase vagones y Plaza son invalido");

}

else{
	
	switch ($C) {

		case 'Turista' ;
			$AUX_C = array(5,6,7,8);
			break;

		case 'Pulman' :
			$AUX_C = array(1,2,3,4);
			break;

	}

	switch ($P) {
		case 'Fumador':
			$AUX_P = array(1,8);
			break;
		
		case 'No fumador':
			$AUX_P = array(2,3,4,5,6,7);
			break;
	}

$AUX = array_intersect($AUX_C,$AUX_P);

return $AUX;

}

}

function verificacion_Asiento($T,$Vag){

$AUX_T = array("Ventanilla","Pasillo");

$AUX = array($T);

$AUX_T = (count(array_diff($AUX_T,$AUX)) == count($AUX_T));

$AUX_Vag = array(1,2,3,4,5,6,7,8);

$AUX = array($Vag);

$AUX_Vag = (count(array_diff($AUX_Vag,$AUX)) == count($AUX_Vag));

if (($AUX_T or $AUX_Vag)) {
			
	if ($AUX_T and !$AUX_Vag) {
		die("Error 4 de Tipo asiento es invalido");
	}
	elseif($AUX_Vag and !$AUX_T){
		die("Error 5 de Vagones es invalido");
	}

die("Error 6 los Tipo asiento y Vagones son invalido");
}


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
