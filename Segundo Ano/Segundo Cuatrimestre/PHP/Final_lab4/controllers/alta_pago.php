<?php

require '../fw/FW.php';
require '../models/Pagos.php';
require '../views/FormPago.php';

$AUX = (isset($_POST['Piso']) and isset($_POST['Letra']) and isset($_POST['Fecha']) and isset($_POST['Monto']) ) ;

if( count($_POST) > 1 and $AUX ){

	if(! is_numeric($_POST['Piso']) ){
		die("error 1 modificacion del piso");
	} 

	if(! (preg_match("/^([a-zA-Z']+)$/",$_POST['Letra'])) and (strlen($_POST['Letra']) == 1) ){
		die("error 2 modificacion del Letra");
	} 

	if(! strtotime($_POST['Fecha']) ){
		die("error 3 modificacion del fecha");
	} 

	if(! is_numeric( $_POST['Monto'] ) ){
		die("error 4 modificacion del Monto");
	} 

	$P = new Pagos();
	$AUX = $P->getId_departamento($_POST['Piso'] , $_POST['Letra']);

	if(count($AUX) == 0) {
		echo "No hay departamento";
	}
	else{
		$AUX = $AUX[0]['id_departamento'];
		$Fecha = new DateTime($_POST['Fecha']);
		
		$V = $P->setPago($AUX,date('Y-m-d',$Fecha ),$_POST['Monto']);		
		
		//var_dump($Fecha->format('Y-m-d'));
		echo "string";
		
	}


}


else{

$AUX = new FormPago();
$AUX->render();

}

?>