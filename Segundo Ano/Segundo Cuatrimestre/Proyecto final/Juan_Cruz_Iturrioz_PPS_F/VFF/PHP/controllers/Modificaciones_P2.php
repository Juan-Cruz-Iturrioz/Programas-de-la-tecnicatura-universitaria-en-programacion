<?php

require '../fw/FW.php';
require '../controllers/BasaSelect.php';
require '../controllers/BaseModifi.php';

require '../models/ABM.php';
require '../models/Viajes.php';
require '../models/Trenes.php';
require '../models/Boleterias.php';
require '../views/FormEstacion.php';
require '../views/FormViajes.php';
require '../views/FormFecha.php';
require '../views/FormHoras.php';

require '../views/FormTrenes.php';
require '../views/SelectTime.php';

	
if(!(isset($_COOKIE['id_viaje']))){
	die("Error 0 expiracion del programa");
}

$Id_viaje = $_COOKIE['id_viaje'] ;
$AUX = new Viajes();
$AUX = $AUX->verificacion_Id($Id_viaje);

if( $AUX ){
	die("Error 7 modificacion de cookie");
}

if(isset($_POST['Datos']) and isset($_POST['Id_viaje']) ){
	$Base = new ABM();
	$Datos = $Base->recuperacion($_POST['Datos']);

	$ID_V = $_POST['Id_viaje'] ;
	$AUX = new Viajes();
	$V = $AUX->verificacion_Id($ID_V);	

	if( $V ){
		die("Error 9 modificacion del hidden");
	}

	$Base = $Base->Modificaciones($Datos,$ID_V);

	if($Base){
		setcookie("id_viaje", $ID_V, time()+3600);

		$host  = $_SERVER['HTTP_HOST'];
		$uri   = rtrim(dirname($_SERVER['PHP_SELF']), '/\\');
		$extra = 'Roma.php';
		
		header("Location: http://$host$uri/$extra");
	}
	else{
		die("Error 404");
	}

}
else{
	$AUX = new BaseModifi();
	$DATA = $AUX->ALLForm();

	if(!is_null($DATA)){
		
		$Base = new ABM();
		$Base = $Base->recuperacion($DATA);

		$AUX = new Trenes();
		$AUX = $AUX->verificacion_Trene_1($Base[0]['Origen'],$Base[0]['Destino'],$Base[0]['Fecha_de_viaje'],$Base[0]['Horario_de_embarcacion'],$Base[0]['Horario_de_llegada'],$Base[0]['Id_tren']);

		$DATA = new Viajes();
		$DATA = $DATA->getViajes_For_ID($Id_viaje);
		
		if($AUX){
			$F_via = new FormViajes();
			$F_via->Setdatos_1($DATA);
			$F_via->Setdatos_2($Base);
			$F_via->renden();
		}
		else{
			die("Error 404");
		}
	}

}


?>