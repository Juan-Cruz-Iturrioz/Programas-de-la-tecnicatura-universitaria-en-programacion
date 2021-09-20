<?php
//Tipo_de_Asientos
require '../fw/FW.php';
require '../models/Viajes.php';
require '../models/Vagones.php';
require '../models/Asientos.php';
require '../views/FormVagones.php';
require '../views/FormAsiento.php';

if(!(isset($_COOKIE['id_viaje']))){
	die("Error 0 expiracion del programa");
}

$Id_viaje = $_COOKIE['id_viaje'] ;
$VIA = new Viajes();
$VIA = $VIA->verificacion_Id($Id_viaje);

if( $VIA ){
	die("Error 7 modificacion de cookie");
}


if(count($_POST) == 3){
	if( isset($_POST['Clase_vagones']) and isset($_POST['Plaza']) ){
	
	$Clase = $_POST['Clase_vagones'];
	$Plaza = $_POST['Plaza'];

	$Vagones = verificacion_Vagones($Clase,$Plaza);
	
	if($Vagones <> false){
		
		$Tipo = new Asientos();

		$Tipo = $Tipo->getAsientos_Tipo();

		$F_Asi = new FormAsiento();
		$F_Asi->Setdatos($Tipo,$Vagones);
		$F_Asi->ManualTitle("Boleterias");
		$F_Asi->renden();
	
	}
	else{
		die("Error 404");
	}

	}

	if( isset($_POST['Tipo_asiento']) and isset($_POST['Vagones']) ){

		$Tipo = $_POST['Tipo_asiento'];
		$Vagon = $_POST['Vagones'];
		verificacion_Asiento($Tipo,$Vagon);

		
		setcookie("Id_viaje", $Id_viaje, time()+3600);
		setcookie("Tipo", $Tipo, time()+3600);
		setcookie("Vagon_N", $Vagon, time()+3600);
	
		/*
		$host  = $_SERVER['HTTP_HOST'];
		$uri   = rtrim(dirname($_SERVER['PHP_SELF']), '/\\');
		$extra = 'Boletos.php';
		header("Location: http://$host$uri/$extra?Vagon=$Vagon");
		*/
		header("Location: Boletos-Vagon=$Vagon");
		exit;
		
	}

}
else {

	$VAG = new Vagones();
	$query = $VAG->getVagones_Tipo();
	
	$F_Vag = new FormVagones(); 
	$F_Vag->Setdatos($query);
	$F_Vag->ManualTitle("Boleterias");
	$F_Vag->renden();

}

function verificacion_Vagones($C,$P){

	$VAG = new Vagones();
	$AUX = $VAG->Verificacion_Vagones($C,$P);

	list( $AUX_C , $AUX_P) = explode("::", $AUX);

		$AUX_C = (bool)($AUX_C);
		$AUX_P = (bool)($AUX_P);
	
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
	
		$AUX = $VAG->getVagones_Num($C,$P);
	
		if($AUX <> false){
		
			$VAG = array();

			foreach ($AUX as $V) {
				$VAG[] = $V['Numero_vagon'];
			}	

			return $VAG;
		}
		else{
			return false;
		}

	}

}

function verificacion_Asiento($T,$Vag){

	$AUX_T = new Asientos();

	$AUX_T = $AUX_T->Verificacion_Tipo($T);

	$AUX_Vag = new Vagones();

	$AUX_Vag = $AUX_Vag->Verificacion_Num($Vag);
	
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



?>
