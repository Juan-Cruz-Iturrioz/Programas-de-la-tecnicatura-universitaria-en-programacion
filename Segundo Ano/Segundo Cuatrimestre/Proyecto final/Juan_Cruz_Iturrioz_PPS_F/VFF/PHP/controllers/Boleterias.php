<?php

require '../fw/FW.php';
require '../controllers/BasaSelect.php';

require '../models/Viajes.php';
require '../models/Boleterias.php';
require '../views/FormEstacion.php';
require '../views/FormViajes.php';
require '../views/FormFecha.php';
require '../views/FormHoras.php';

	$Basa = new BasaSelect();
	$ID = $Basa->ALLForm();

	if(!is_null($ID)){

	$Basa->verificacion_Id_viaje($ID);
	
	setcookie("id_viaje", $ID, time()+3600);
	header("Location: Tipo_de_asiento");
	exit;
	}	
	
?>