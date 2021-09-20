<?php

require '../fw/FW.php';
require '../models/Boletos.php';
require '../models/viajes.php';
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

	$AUX = ($ASI < 1 or $ASI > 60);
	
	if(!is_numeric($ASI) or $AUX ){
		die("Error 3 modificacion del input");
	}


	$Bon = new Boletos();
	$query = $Bon->getVentas($Vagon,$Id_viaje);

	$AUX_V = array();

	foreach($query as $V){
		$AUX_V[] = $V['Numero_de_asiento'];
	}

	if(count($AUX_V) == 0){
		$AUX_V[] = 0;
	}

	$AUX = array($ASI);

	$AUX_V = (count(array_diff($AUX_V,$AUX)) <> count($AUX_V));

	$host  = $_SERVER['HTTP_HOST'];
	$uri   = rtrim(dirname($_SERVER['PHP_SELF']), '/\\');

	if($AUX_V){
		echo "Hay esta vendido";
		$extra = 'Boletos.php';

		echo "<a href=" . "http://$host$uri/$extra?Vagon=$Vagon" . "> Retroceder </a>" ;
	}
	else{
		
		setcookie("Id_viaje", $Id_viaje, time()+3600);
		setcookie("Vagon", $Vagon, time()+3600);
		setcookie("Asiento", $ASI, time()+3600);
		
		$extra = 'Pasajeros.php';
		header("Location: http://$host$uri/$extra");
	}

	

}

else{

	$Bon = new Boletos();
	$query = $Bon->getVagones($Vagon_N);

	$AUX = array($query[0]['Clase_vagones'],$query[0]['Plaza']);

	$query = $Bon->getVagones($Vagon);

	$Clase = $query[0]['Clase_vagones'];
	$Plaza = $query[0]['Plaza'];

	$AUX_2 = array($Clase,$Plaza);

	$AUX = (count(array_diff($AUX,$AUX_2)) == 0);

	$AUX_2 = $Bon->getVentas($Vagon,$Id_viaje);

	$query = $Bon->getAsientos($Vagon);

	$S_ASI = new SelectAsiento();
	$S_ASI->Setdatos($query,$AUX_2,$Tipo,$AUX,$Clase,$Plaza);
	$S_ASI->renden();
}


function verificacion_Id_viaje($ID){

$VIA = new viajes();
$query = $VIA->getViajes_ID();
$AUX_V = array();

foreach ($query as $V ){
	$AUX_V[] = $V['id_viaje'];
}

$AUX = array($ID);

$AUX_V = (count(array_diff($AUX_V,$AUX)) == count($AUX_V));

return $AUX_V; 

}




function verificacion_cookies($ID_V,$T,$Vag,$Vag_N){

$AUX_T = array("Ventanilla","Pasillo");

$AUX = array($T);

$AUX_T = (count(array_diff($AUX_T,$AUX)) == count($AUX_T));


if(verificacion_Id_viaje($ID_V) or $AUX_T){
	die("Error 1 modificacion de cookies");
}


if( ( ($Vag < 1 or $Vag > 8) or ($Vag_N < 1 or $Vag_N > 8) ) ){
	die("Error 2 modificacion del numero de Vagon");
}


}


?>
