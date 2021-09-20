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


	if(isset($_POST['Id_viaje'])){
		
		$Basa = new BasaSelect();
		$ID = $_POST['Id_viaje'];
		$Basa->verificacion_Id_viaje($ID);
		
		setcookie("id_viaje", $ID, time()+3600);

		$host  = $_SERVER['HTTP_HOST'];
		$uri   = rtrim(dirname($_SERVER['PHP_SELF']), '/\\');
		$extra = 'Modificaciones_P2.php';
		
		header("Location: http://$host$uri/$extra");

	}
	else{
		$Basa = new BasaSelect();
		$ID = $Basa->ALLForm();
	
	
		if(!is_null($ID)){
			$Basa->verificacion_Id_viaje($ID);
			
			$Basa = new viajes();
			$Basa = $Basa->getViajes_For_ID($ID);

			$ID = new FormViajes();
			$ID->Setdatos_1($Basa);
			$ID->renden();
		}
	}
	
	

?>