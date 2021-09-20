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

if(isset($_POST['Datos'])){
	$AUX = "NOT";

	$Base = new ABM();
	$Datos = $Base->recuperacion($_POST['Datos']);
	$ID = $Base->Alta($Datos);

	$Basa = new BasaSelect();
	$Basa->verificacion_Id_viaje($ID);
		
	setcookie("id_viaje", $ID, time()+3600);

	$host  = $_SERVER['HTTP_HOST'];
	$uri   = rtrim(dirname($_SERVER['PHP_SELF']), '/\\');
	$extra = 'Roma.php';
		
	header("Location: http://$host$uri/$extra");

}
else{
	$Base = new BaseModifi();
	$AUX = $Base->ALLForm();	
}

if(!is_null($AUX) and $AUX <> "NOT"){

	$Base = new ABM();
	$Base = $Base->recuperacion($AUX);
	
	$AUX = new Trenes();
	$AUX = $AUX->verificacion_Trene_1($Base[0]['Origen'],$Base[0]['Destino'],$Base[0]['Fecha_de_viaje'],$Base[0]['Horario_de_embarcacion'],$Base[0]['Horario_de_llegada'],$Base[0]['Id_tren']);

	
	if($AUX){
		$F_via = new FormViajes();
		$F_via->Setdatos_2($Base);
		$F_via->AutoTitle();
		$F_via->renden();
	}
	else{
		die("Error 404");
	}
	
}


?>