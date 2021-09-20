<?php

require '../fw/FW.php';
require '../models/Boletos.php';
require '../models/Viajes.php';
require '../models/Vagones.php';
require '../models/Asientos.php';
require '../views/SelectAsiento.php';

$AUX = (isset($_COOKIE['Id_viaje']) and isset($_COOKIE['Tipo']) and isset($_COOKIE['Vagon_N']) );

if(!$AUX){
	die("Error 0 expiracion del programa");
}

$Id_viaje = $_COOKIE['Id_viaje'];
$Tipo = $_COOKIE['Tipo'];

$Vagon = $_GET["Vagon"];
$Vagon_N = $_COOKIE['Vagon_N'];

verificacion_cookies($Id_viaje,$Tipo,$Vagon,$Vagon_N);

if(isset($_POST['Asiento'])){

	$ASI = $_POST['Asiento'];

	$AUX = new Asientos();

	$AUX = $AUX->Verificacion_Num($ASI);
	
	if(!is_numeric($ASI) or $AUX ){
		die("Error 3 modificacion del input");
	}


	$AUX_V = new Boletos();
	$AUX_V = $AUX_V->Verificacion_Venta($Vagon,$Id_viaje,$ASI);

	/*
	$host  = $_SERVER['HTTP_HOST'];
	$uri   = rtrim(dirname($_SERVER['PHP_SELF']), '/\\');
	*/
	if($AUX_V){
		echo "Hay esta vendido";
		//$extra = 'Boletos.php';

		//echo "<a href=" . "http://$host$uri/$extra?Vagon=$Vagon" . "> Retroceder </a>" ;
		echo "<a href=" . "Boletos-Vagon=$Vagon" . "> Retroceder </a>" ;
	}
	else{
		
		setcookie("Id_viaje", $Id_viaje, time()+3600);
		setcookie("Vagon", $Vagon, time()+3600);
		setcookie("Asiento", $ASI, time()+3600);
		
		/*$extra = 'Pasajeros.php';
		header("Location: http://$host$uri/$extra");
		*/
		header("Location: Pasajeros");
		exit;
	}

	

}

else{

	$Vag = new Vagones();

	$AUX = ($Vag->getVagones($Vagon_N) and $Vag->getVagones($Vagon)); 

	if($AUX){
		$query = $Vag->getVagones($Vagon_N);

		if($query == false){
			die("Error 404 + 1");
		}

		$AUX = array($query[0]['Clase_vagones'],$query[0]['Plaza']);

		$query = $Vag->getVagones($Vagon);

		if($query == false){
			die("Error 404 + 2");
		}

		$Clase = $query[0]['Clase_vagones'];
		$Plaza = $query[0]['Plaza'];

		$AUX_2 = array($Clase,$Plaza);

		$AUX = (count(array_diff($AUX,$AUX_2)) == 0);

		$Bon = new Boletos();
	
		$AUX_2 = $Bon->getVentas($Vagon,$Id_viaje);

		if($AUX_2 <> false or is_array($AUX_2) ){

			$ASI = new Asientos();

			$query = $ASI->getAsientos($Vagon);

			$S_ASI = new SelectAsiento();
			$S_ASI->Setdatos($query,$AUX_2,$Tipo,$AUX,$Clase,$Plaza);
			$S_ASI->ManualTitle("Boleterias");
			$S_ASI->renden();
		
		}
		else{
			die("Error 404 + 3");
		}

			
	
	}
	else{
		die("Error 404");
	}
	
}



function verificacion_cookies($ID_V,$T,$Vag,$Vag_N){

$AUX_1 = new Viajes();
$AUX_1 = $AUX_1->verificacion_Id($ID_V);


$AUX_2 = new Asientos();
$AUX_2 = $AUX_2->Verificacion_Tipo($T);

if($AUX_1 or $AUX_2){
	die("Error 1 modificacion de cookies");
}

$AUX_2 = new Vagones();

$AUX_1 = $AUX_2->Verificacion_Num($Vag);

$AUX_2 = $AUX_2->Verificacion_Num($Vag_N);


if( $AUX_1 or $AUX_2 ){
	die("Error 2 modificacion del numero de Vagon");
}


}


?>
