<?php

require '../fw/FW.php';
require '../models/viajes.php';
require '../views/FormViajes.php';
require '../views/SelectTime.php';

if(isset($_POST['Horario']) ){

$Hora = $_POST['Horario'];

if(strlen($Hora) <> 5 or substr_count($Hora,':') <> 1){
die("Error 1 modificacion del input");
}

if( strtotime($Hora) == false){
die("Error 2 Tiempo es invalido");	
}

$VIA = new viajes();
$query = $VIA->getViajes_now_time($Hora);

if(count($query) > 0){
	$F_via = new FormViajes();
	$F_via->Viajes = $query;
	$F_via->renden();
}
else{
	echo "No hay viajes";
}

}
else{
$AUX = new SelectTime();
$AUX->renden();
}
	


?>