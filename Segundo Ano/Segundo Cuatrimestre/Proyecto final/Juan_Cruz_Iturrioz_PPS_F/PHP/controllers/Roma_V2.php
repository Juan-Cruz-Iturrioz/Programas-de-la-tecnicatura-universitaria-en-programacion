<?php

require '../fw/FW.php';

require '../models/Viajes.php';

require '../views/FormViajes.php';


	
if(!(isset($_COOKIE['id_viaje']))){
	die("Error 0 expiracion del programa");
}
else{
	$Datos = new FormViajes();
	$Datos->ManualTitle("Final de la asignación");
	$Datos->renden();	
}

?>