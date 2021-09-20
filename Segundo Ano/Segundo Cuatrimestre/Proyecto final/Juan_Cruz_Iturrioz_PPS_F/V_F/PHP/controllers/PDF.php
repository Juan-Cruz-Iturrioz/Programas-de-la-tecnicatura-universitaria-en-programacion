<?php 
require '../fw/FW.php';
require '../fw/FPDF/fpdf.php';
require '../models/Viajes.php';
require '../models/Boletos.php';
require '../models/Vagones.php';
require '../models/Asientos.php';
require '../models/Pasajeros.php';
require '../views/FormPasajeros.php';
require '../views/PDF.php';

$AUX = (isset($_COOKIE['Id_viaje']) and isset($_COOKIE['Vagon']) and isset($_COOKIE['Asiento']) and isset($_COOKIE['ID_BOL']) );


if(!$AUX){
die("Error 0 expiracion del programa");
}

$Id_viaje = $_COOKIE['Id_viaje'];
$Vagon = $_COOKIE['Vagon'];
$Asiento = $_COOKIE['Asiento'];
$ID_BOL = $_COOKIE['ID_BOL'];

verificacion_cookies($Id_viaje,$Vagon,$Asiento);

$Precio = array( "Turista" => '2440' ,  "Pulman" => '2640' );
		
$AUX = new Vagones();

$query = $AUX->getVagones($Vagon);

$AUX = new Boletos();

$AUX = $AUX->GetID_Pasajero($Id_viaje,$Vagon,$Asiento);

$Nom = $AUX[0]['nombre_completo'];
$DNI = $AUX[0]['DNI'];
$ID_PAS = $AUX[0]['id_pasajero'];
$ID = $AUX[0]['Id_boleto'];

$Precio = $Precio[$query[0]['Clase_vagones']];

$PAS = new Pasajeros();
		
$ID_Tren = $PAS->GetID_Tren($Id_viaje); 

$ID_Tren = $ID_Tren[0]['id_tren'];

if ( ($PAS->Verificacion_Id_Pasajero_Viaje($ID_PAS,$DNI,$Id_viaje) ) ){
	die("Error 404");
}

if($ID <> $ID_BOL){
	die("Error 404");
}


$AUX = new PDF();
$AUX->SetPDF($ID_Tren,$Vagon,$query[0]['Clase_vagones'],$query[0]['Plaza'],$Precio,$Asiento,$Nom,$DNI);

function verificacion_cookies($ID_V,$Vag,$Asi){
	$AUX = new viajes();
	$AUX = $AUX->verificacion_Id($ID_V);

	$AUX_V = new Vagones();
	$AUX_V = $AUX_V->Verificacion_Num($Vag);

	if($AUX or $AUX_V ){
		die("Error 3 modificacion de cookies");
	}

}

?>
