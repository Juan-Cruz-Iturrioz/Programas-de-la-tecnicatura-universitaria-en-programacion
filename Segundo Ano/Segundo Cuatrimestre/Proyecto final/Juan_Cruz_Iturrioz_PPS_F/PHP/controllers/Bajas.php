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

//DELETE FROM Viajes where Id_viaje = 7

if(isset($_POST['Id_viaje'])){
	$AUX = "NOT";

	$ID = $_POST['Id_viaje'];

	$Base = new BasaSelect();
	$Base->verificacion_Id_viaje($ID);

	$Base = new ABM();
	$Base = $Base->Bajas($ID);
	
	if($Base){

		setcookie("id_viaje", $ID, time()+3600);

		$host  = $_SERVER['HTTP_HOST'];
		$uri   = rtrim(dirname($_SERVER['PHP_SELF']), '/\\');
		$extra = 'Roma_V2.php';
		
		header("Location: http://$host$uri/$extra");
	}
	else{
		die("Error 404");
	}
	
}
else{
	$Base = new BasaSelect();
	$AUX = $Base->ALLForm();	
}

if(!is_null($AUX) and $AUX <> "NOT"){

	$Base = new BasaSelect();
	$Base->verificacion_Id_viaje($AUX);
	
	$Base = new Viajes();
	$Base = $Base->getViajes_For_ID($AUX);
	

	if($AUX){
		$F_via = new FormViajes();
		$F_via->Setdatos_1($Base);
		$F_via->AutoTitle();
		$F_via->renden();
	}
	else{
		die("Error 404");
	}
	
}


?>