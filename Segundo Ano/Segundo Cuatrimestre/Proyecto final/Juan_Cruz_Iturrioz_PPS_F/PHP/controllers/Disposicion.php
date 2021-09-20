<?php

require '../fw/FW.php';
require '../models/Boletos.php';
require '../models/Vagones.php';
require '../models/Asientos.php';
require '../models/viajes.php';
require '../views/SelectBoleto.php';
require '../views/List_Pasajeros.php';

$AUX = (isset($_COOKIE['Id_viaje']) and isset($_COOKIE['Clase']) );

if(!$AUX){
die("Error 0 expiracion del programa");
}

$Id_viaje = $_COOKIE['Id_viaje'];
$Clase = $_COOKIE['Clase'];
$Vagon = $_GET["Vagon"];


verificacion_cookies($Id_viaje,$Clase,$Vagon);

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

	if($AUX_V){

		$query = $Bon->GetID_Pasajero($Id_viaje,$Vagon,$ASI);
		$L_PAS = new List_Pasajeros();
		$L_PAS->PAS = $query;
		$L_PAS->ManualTitle("Supervisor del viaje");
		$L_PAS->renden();
	}
	else{
		echo"Asiento no asignado";

	}
}

else{

	$Bon = new Vagones();
	
	$query = $Bon->getVagones($Vagon);	
	
	$Bool = ($query[0]['Clase_vagones'] == $Clase); 
	$Plaza = $query[0]['Plaza'];
	$C = $query[0]['Clase_vagones'];
	$Bon = new Boletos();
	$Array = array();

	for ($I = 1 ; $I <= 8 ; $I++) {
		
		$query = $Bon->getVentas($I,$Id_viaje);

		$Array[] = count($query);
	}
	
	

	$AUX = $Bon->getVentas($Vagon,$Id_viaje);
	$Bon = new Asientos();
	
	$query = $Bon->getAsientos($Vagon);

	$S_ASI = new SelectBoleto();

	$S_ASI->Setdatos($query,$AUX,$Clase,$Plaza,$Bool,$Array,$C);
	$S_ASI->ManualTitle("Supervisor del viaje");
	$S_ASI->renden();
}


function verificacion_Id_viaje($ID){

$VIA = new viajes();
$VIA = $VIA->verificacion_Id($ID);
return $VIA;

}


function verificacion_cookies($ID_V,$C,$Vag){


$AUX_C = new Vagones();
$AUX = $AUX_C->Verificacion_Num($Vag);
$AUX_C = $AUX_C->Verificacion_Clase($C);

if(verificacion_Id_viaje($ID_V) or $AUX_C){
	die("Error 1 modificacion de cookies");
}

//$Vag < 1 or $Vag > 8 
if( $AUX ){
	die("Error 2 modificacion del numero de Vagon");
}


}


?>
