<?php
//Trenes
require '../fw/FW.php';
require '../models/Viajes.php';
require '../models/Boleterias.php';
require '../views/FormEstacion.php';
require '../views/FormViajes.php';
require '../views/FormFecha.php';
require '../views/FormHoras.php';

if(count($_POST) > 1){
	if( isset($_POST['Origen']) and isset($_POST['Destino']) ){
	
		$ORI = $_POST['Origen'];
		$DES = $_POST['Destino'];
		
		verificacion_Origen_y_Destino($ORI,$DES);
		
		$VIA = new viajes();
		$query = $VIA->getViajes_now($ORI,$DES);

		if( $query <> false or is_array($query) ){

			if( count($query) >=1 ){
				$F_fecha = new FormFecha();
				$F_fecha->Setdatos($query);
				$F_fecha->renden();

			}
			else{
				echo "No hay viajes";
			}
		}

		else{
			die("Error 404");
		}
	}
	

	if(isset($_POST['Fecha'])){
		
		$AUX = $_POST['Fecha'];

		if(strlen($AUX) <> 19 or substr_count($AUX,'::') <> 2){
			die("Error 4 modificacion del select");
		}

		list($ORI,$DES,$FECHA) = explode("::", $AUX);

		verificacion_Fecha($ORI,$DES,$FECHA);

		$VIA = new viajes();
		$query = $VIA->getViajes_day($ORI,$DES,$FECHA);
		echo $query;
		if($query <> false){
			
			if(count($query) <> 0){
			
			$F_horas = new FormHoras();
			$F_horas->Setdatos($query);
			$F_horas->renden();
			}
			
			else{
				echo "No hay viajes";
			}
		}
		else{
			die("Error 404");
		}
		
	}

	if(isset($_POST['Horario_de_embarcacion'])){
		
		$AUX = $_POST['Horario_de_embarcacion'];

		if(strlen($AUX) <> 33 or substr_count($AUX,'::') <> 4){
			die("Error 4 modificacion del select");
		}

		list($ORI,$DES,$FECHA,$Hora_E,$Hora_L) = explode("::", $AUX);

		verificacion_Horarios($ORI,$DES,$FECHA,$Hora_E,$Hora_L);

		
		$VIA = new viajes();
		$query = $VIA->getViajes_time($ORI,$DES,$FECHA,$Hora_E,$Hora_L);
		
		if($query <> false){
			
			setcookie("id_viaje", $query[0]['Id_viaje'], time()+3600);

			header("Location: Tipo_de_asiento");
			exit;	
		}
		else{
			die("Error 404");
		}

		
		}

}

else{

	$Est = new Boleterias ();
	$Est = $Est->getEstacion();
	$F_est = new FormEstacion();
	$F_est->Setdatos($Est);
	$F_est->renden();
}


function verificacion_Origen_y_Destino($O,$D){

	$Bol = new Boleterias ();

	$AUX_1 = $Bol->Verificacion_Estacion($O);
	$AUX_2 = $Bol->Verificacion_Estacion($D);

	if ( ($AUX_1 or $AUX_2)) {
			
		if (!$AUX_1 or $AUX_2) {
			die("Error 1 de Origen es invalido");
		}
		elseif($AUX_1 or !$AUX_2){
			die("Error 2 de Destino es invalido");
		}

	die("Error 3 de Origen y Destino son invalido");
	}


}

function verificacion_Fecha($O,$D,$F){

	verificacion_Origen_y_Destino($O,$D);

	$AUX = new viajes();
	$AUX = $AUX->Verificacion_Day($O,$D,$F);

	if( $AUX ) {
		die("Error 5 fechas es invalido");
	}


}

function verificacion_Horarios($O,$D,$F,$HE,$HL){

	verificacion_Fecha($O,$D,$F);

	$AUX = new viajes();

	$AUX = $AUX->Verificacion_Time($O,$D,$F,$HE,$HL);

	list( $AUX_HE , $AUX_HL) = explode("::", $AUX);

	$AUX_HE = (bool)($AUX_HE);
	$AUX_HL = (bool)($AUX_HL);

	if (($AUX_HE or $AUX_HL)) {
			
		if (!$AUX_HL and $AUX_HE) {
			die("Error 6 de Horario de embarcacion es invalido");
		}
	
		elseif($AUX_HL and !$AUX_HE){
			die("Error 7 de Horario de llegada es invalido");
		}

	die("Error 8 los Horarios son invalido");

	}

}


?>