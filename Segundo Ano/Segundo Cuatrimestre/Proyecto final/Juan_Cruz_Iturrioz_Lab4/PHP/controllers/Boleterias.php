<?php

require '../fw/FW.php';
require '../models/viajes.php';
require '../views/FormEstacion.php';
require '../views/FormViajes.php';
require '../views/FormFecha.php';
require '../views/FormHoras.php';

if(count($_POST) > 1){
	if( isset($_POST['Origen']) and isset($_POST['Destino']) ){
	
		$ORI = $_POST['Origen'];
		$DES = $_POST['Destino'];
		
		verificacion_Origen_y_Destino($ORI,$DES);
		
		$VIA = new viajes();
		$query = $VIA->getViajes_now($ORI,$DES);

		if( count($query) >=1){
			$F_fecha = new FormFecha();
			$F_fecha->Setdatos($query);
			$F_fecha->renden();

		}
		else{
			echo "No hay viajes";
		}
	}
	
	elseif( isset($_POST['Origen']) or isset($_POST['Destino']) ){
	
		$Est = array("Cairo","Luxor");
		$F_est = new FormEstacion();
		$F_est->Estacion=$Est;
		$F_est->renden();
	
	}

	if(isset($_POST['Fecha'])){
		
		$AUX = $_POST['Fecha'];

		if(strlen($AUX) <> 19 or substr_count($AUX,'::') <> 2){
			die("Error 4 modificacion del select");
		}

		list($ORI,$DES,$FECHA) = explode("::", $AUX);

		verificacion_Fecha($ORI,$DES,$FECHA);

		$VIA = new viajes();
		$query = $VIA->getViajes_day($ORI,$DES,$FECHA);
		
		$F_horas = new FormHoras();
		$F_horas->Setdatos($query);
		$F_horas->renden();
	}

	if(isset($_POST['Horario_de_embarcacion'])){
		
		$AUX = $_POST['Horario_de_embarcacion'];

		if(strlen($AUX) <> 33 or substr_count($AUX,'::') <> 4){
			die("Error 4 modificacion del select");
		}

		list($ORI,$DES,$FECHA,$Hora_E,$Hora_L) = explode("::", $AUX);

		verificacion_Horarios($ORI,$DES,$FECHA,$Hora_E,$Hora_L);

		
		$VIA = new viajes();
		$query = $VIA->getViajes_time($ORI,$DES,$FECHA,$Hora_E,$Hora_L);
		
		setcookie("id_viaje", $query[0]['Id_viaje'], time()+3600);

		$host  = $_SERVER['HTTP_HOST'];
		$uri   = rtrim(dirname($_SERVER['PHP_SELF']), '/\\');
		$extra = 'Tipo_de_asiento.php';
		header("Location: http://$host$uri/$extra");
		exit;	
		
		}

}

else{
	$Est = array("Cairo","Luxor");
	$F_est = new FormEstacion();
	$F_est->Estacion=$Est;
	$F_est->renden();
}


function verificacion_estacion($EST){

	switch ($EST) {
		case 'Cairo':
			$AUX = true;
			break;
		
		case 'Luxor':
			$AUX = true;
			break;

		default:
			$AUX = false;
			break;
	}
	return $AUX;
}

function verificacion_Origen_y_Destino($O,$D){

$AUX_1 = verificacion_estacion($O);
$AUX_2 = verificacion_estacion($D);
		
if (!($AUX_1 and $AUX_2)) {
			
	if (!$AUX_1 and $AUX_2) {
		die("Error 1 de Origen es invalido");
	}
	elseif($AUX_1 and !$AUX_2){
		die("Error 2 de Destino es invalido");
	}

die("Error 3 de Origen y Destino son invalido");
}


}

function verificacion_Fecha($O,$D,$F){

verificacion_Origen_y_Destino($O,$D);

$VIA = new viajes();
$AUX = $VIA->getViajes_now($O,$D);

$VEN  = array();

foreach ($AUX as $V ){
	$VEN[] = $V['Fecha_de_viaje']->format('d/m');
}

$VEN = array_unique($VEN);
sort($VEN);

$AUX = array($F);
if( count(array_diff($VEN,$AUX)) == count($VEN)) {
	die("Error 5 fechas es invalido");
}


}

function verificacion_Horarios($O,$D,$F,$HE,$HL){

verificacion_Fecha($O,$D,$F);

$VIA = new viajes();
$AUX = $VIA->getViajes_day($O,$D,$F);

$AUX_HE = array();
$AUX_HL = array();

foreach ($AUX as $V ){
	$AUX_HE[] = $V['Horario_de_embarcacion']->format('H:i');
	$AUX_HL[] = $V['Horario_de_llegada']->format('H:i');
}

$AUX = array($HE);

$AUX_HE = (count(array_diff($AUX_HE,$AUX)) == count($AUX_HE));

$AUX = array($HL);

$AUX_HL = (count(array_diff($AUX_HL,$AUX)) == count($AUX_HL));


	if (($AUX_HE or $AUX_HL)) {
			
		if (!$AUX_HL and $AUX_HE) {
			die("Error 6 de Horario de embarcacion es invalido");
		}
	
		elseif($AUX_HL and !$AUX_HE){
			die("Error 7 de Horario de llegada es invalido");
		}

	die("Error 8 los Horarios son invalido");

	}

}




?>