<?php 
require '../fw/FW.php';
require '../fw/FPDF/fpdf.php';
require '../models/viajes.php';
require '../models/Boletos.php';
require '../models/Pasajeros.php';
require '../views/FormPasajeros.php';
require '../views/PDF.php';

$Id_viaje = $_COOKIE['Id_viaje'];
$Vagon = $_COOKIE['Vagon'];
$Asiento = $_COOKIE['Asiento'];

$AUX = (isset($_COOKIE['Id_viaje']) and isset($_COOKIE['Vagon']) and isset($_COOKIE['Asiento']) );

if(!$AUX){
die("Error 0 expiracion del programa");
}

verificacion_cookies($Id_viaje,$Vagon,$Asiento);

if(isset($_POST['Nombre']) and isset($_POST['DNI'])){

		$Nom = $_POST['Nombre'];
		$DNI = $_POST['DNI'];

		if(strlen($DNI) <>8 or !is_numeric($DNI) ){
			die("Error 1 DNI es invalido");
		}

		if(!preg_match("/^([a-zA-Z' ]+)$/",$Nom)){
			die("Error 2 Nombre es invalido");
		}

		$PAS = new Pasajeros();
		$ID_PAS = $PAS->SetPasajeros($Nom,$DNI);


		$ID_PAS = $ID_PAS[0]['id_pasajero'];

		$Precio = array( "Turista" => '2440' ,  "Pulman" => '2640' );
		
		$AUX = new Boletos();

		$query = $AUX->getVagones($Vagon);

		$Precio = $Precio[$query[0]['Clase_vagones']];
		
		$ID_Tren = $PAS->GetID_Tren($Id_viaje); 

		$ID_Tren = $ID_Tren[0]['id_tren'];
 
		$AUX = $PAS->SetBoletos($Id_viaje,$ID_PAS,$Precio,$Vagon,$Asiento);

		if($AUX){
			$AUX = new PDF();
			$AUX->SetPDF($ID_Tren,$Vagon,$query[0]['Clase_vagones'],$query[0]['Plaza'],$Precio,$Asiento,$Nom,$DNI);
		}
		else{
			die("Error 5 ingreso de dato");
		}

}

else{

	$F_PAS = new FormPasajeros();
	$F_PAS->renden();
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

function verificacion_cookies($ID_V,$Vag,$Asi){

	$AUX_V = ($Vag < 1 or $Vag > 8);

	if(verificacion_Id_viaje($ID_V) or $AUX_V ){
		die("Error 3 modificacion de cookies");
	}

	$BOL = new Boletos();
	$query = $BOL->getVentas($Vag,$ID_V);

	$AUX = array($Asi);
	$AUX_V = array();

	foreach ($query as $V) {
		$AUX_V[] = $V['Numero_de_asiento'];
	}
	
	$AUX_V =(count(array_diff($AUX_V,$AUX)) <> count($AUX_V));

	if($AUX_V){
		die("Error 4 asiento vendido");
	}



}

?>
