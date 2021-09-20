<?php

require '../fw/FW.php';
require '../controllers/BasaSelect.php';

require '../models/Viajes.php';
require '../models/Vagones.php';
require '../models/Boleterias.php';
require '../views/FormEstacion.php';
require '../views/FormViajes.php';
require '../views/FormFecha.php';
require '../views/FormHoras.php';
require '../views/FormSupervisor.php';

$Basa = new BasaSelect();
$ID = $Basa->ALLForm();
	
if(!is_null($ID)){
			
	$Basa->verificacion_Id_viaje($ID);

	$Q = new Vagones();
	$Q = $Q->getVagones_Clase();

	$F_SUP = new FormSupervisor; 
	$F_SUP->Setdatos($Q,$ID);
	$F_SUP->AutoTitle();
	$F_SUP->renden();

}
	
if( isset($_POST['Clase_vagones']) and isset($_POST['Id_viaje']) ){

	$Id_viaje = $_POST['Id_viaje'];
	$Clase = $_POST['Clase_vagones'];

	$AUX = new BasaSelect();
	$AUX->verificacion_Id_viaje($Id_viaje);

	$AUX = verificacion_Clase($Clase);
		
	setcookie("Id_viaje", $Id_viaje, time()+3600);
	setcookie("Clase", $Clase, time()+3600);

	$host  = $_SERVER['HTTP_HOST'];
	$uri   = rtrim(dirname($_SERVER['PHP_SELF']), '/\\');
	$extra = 'Disposicion.php';
	header("Location: http://$host$uri/$extra?Vagon=$AUX");
	exit;
		
}

function verificacion_Clase($C){

	$AUX = new Vagones();
	$AUX = $AUX->Verificacion_Clase($C);

	if ( $AUX ) {
		die("Error 1 de Clase vagones es invalido");
	}

	else{
	
		switch ($C) {

			case 'Turista' ;
				$AUX = 5;
				break;

			case 'Pulman' :
				$AUX = 1;
				break;
		}

	}
	
	return $AUX;

}

?>