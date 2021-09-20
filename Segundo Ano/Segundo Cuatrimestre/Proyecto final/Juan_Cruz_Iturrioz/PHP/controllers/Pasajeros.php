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

$AUX = (isset($_COOKIE['Id_viaje']) and isset($_COOKIE['Vagon']) and isset($_COOKIE['Asiento']) );

if(!$AUX){
die("Error 0 expiracion del programa");
}

$Id_viaje = $_COOKIE['Id_viaje'];
$Vagon = $_COOKIE['Vagon'];
$Asiento = $_COOKIE['Asiento'];

verificacion_cookies($Id_viaje,$Vagon,$Asiento);

if(isset($_POST['Nombre']) and isset($_POST['DNI'])){

		$Nom = $_POST['Nombre'];
		$DNI = (int)($_POST['DNI']);

		if(strlen($DNI) <> 8 or !is_numeric($DNI) ){
			die("Error 1 DNI es invalido");
		}

		if(!preg_match("/^([a-zA-Z' ]+)$/",$Nom)){
			die("Error 2 Nombre es invalido");
		}

		$PAS = new Pasajeros();
		$ID_PAS = $PAS->SetPasajeros($Nom,$DNI);

		if($ID_PAS <> false){

			$ID_PAS = $ID_PAS[0]['id_pasajero'];

			$Precio = array( "Turista" => '2440' ,  "Pulman" => '2640' );
		
			$AUX = new Vagones();

			$query = $AUX->getVagones($Vagon);

			$Precio = $Precio[$query[0]['Clase_vagones']];
		
			$ID_Tren = $PAS->GetID_Tren($Id_viaje); 

			$ID_Tren = $ID_Tren[0]['id_tren'];
		}

		else{
			die("Error 404");
		}

		if ( !($PAS->Verificacion_Id_Pasajero_Viaje($ID_PAS,$DNI,$Id_viaje) ) ){
			die("Error 404");
		}
			
		$AUX = $PAS->SetBoletos($Id_viaje,$ID_PAS,$Precio,$Vagon,$Asiento,$DNI);
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




function verificacion_cookies($ID_V,$Vag,$Asi){
	$AUX = new viajes();
	$AUX = $AUX->verificacion_Id($ID_V);

	$AUX_V = new Vagones();
	$AUX_V = $AUX_V->Verificacion_Num($Vag);

	if($AUX or $AUX_V ){
		die("Error 3 modificacion de cookies");
	}

	$AUX_V = new Boletos();
	$AUX_V = $AUX_V->Verificacion_Venta($Vag,$ID_V,$Asi);

	if($AUX_V){
		die("Error 4 asiento vendido");
	}

}

?>
