<?php

/*
require '../fw/FW.php';
require '../controllers/BasaSelect.php';

require '../models/Viajes.php';
require '../models/Boleterias.php';
require '../views/FormEstacion.php';
require '../views/FormViajes.php';
require '../views/FormFecha.php';
require '../views/FormHoras.php';
*/

class BasaSelect {
	
public function ALLForm(){

	if(count($_POST) > 1){
		
		if( isset($_POST['Origen']) and isset($_POST['Destino']) ){
	
			$ORI = $_POST['Origen'];
			$DES = $_POST['Destino'];
			
			$this->Estaciones($ORI,$DES);

		}
	

		if(isset($_POST['Fecha']) and isset($_POST['Data'])){
		
			$Fecha = $_POST['Fecha'];
			$AUX = $_POST['Data'];
			
			$this->Fecha($Fecha,$AUX);
		
		}

		if(isset($_POST['Horario_de_embarcacion']) and isset($_POST['Horario_de_llegada']) 
			and isset($_POST['Data'])){
		
			$Emb = $_POST['Horario_de_embarcacion'];
			$Lle = $_POST['Horario_de_llegada'];
			$AUX = $_POST['Data'];
			
			$ID = $this->Horarios($AUX,$Emb,$Lle);
			
			return $ID;
		}

	}

	else{
		$this->Default();

	}
}

	public function Estaciones($O,$D){

		$this->verificacion_Origen_y_Destino($O,$D);
		
		$query = new viajes();
		$query = $query->getViajes_now($O,$D);

		if( $query <> false or is_array($query) ){

			if( count($query) >=1 ){
				$F_fecha = new FormFecha();
				$F_fecha->Setdatos_1($query);
				$F_fecha->AutoTitle();
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

	public function	Fecha($FECHA,$AUX){
		

		if(strlen($AUX) <> 12 or substr_count($AUX,'::') <> 1){
			die("Error 9 modificacion del hidden");
		}

		$this->validateDate($FECHA);

		list($ORI,$DES) = explode("::", $AUX);
		
		$this->verificacion_Fecha($ORI,$DES,$FECHA);

		$query = new viajes();
		$query = $query->getViajes_day($ORI,$DES,$FECHA);

		if($query <> false){
			
			if(count($query) <> 0){
			
			$F_horas = new FormHoras();
			$F_horas->Setdatos($query);
			$F_horas->AutoTitle();
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

	public function Horarios($AUX,$Hora_E,$Hora_L){
		
		if(strlen($AUX) <> 22 or substr_count($AUX,'::') <> 2){
			die("Error 4 modificacion del select");
		}

		list($ORI,$DES,$FECHA) = explode("::", $AUX);

		$this->verificacion_Horarios($ORI,$DES,$FECHA,$Hora_E,$Hora_L);

		
		$VIA = new viajes();
		$query = $VIA->getViajes_time($ORI,$DES,$FECHA,$Hora_E,$Hora_L);
		
		if($query <> false){
			return $query[0]['Id_viaje'];
		}
		else{
			die("Error 404");
		}
	}

	public function Default(){

		$Est = new Boleterias ();
		$Est = $Est->getEstacion();
		
		$F_est = new FormEstacion();
		$F_est->Setdatos($Est);
		$F_est->AutoTitle();
		$F_est->renden();
	}

	public function validateDate($date){
	
		$date = str_replace('/', "-",$date);
		
		$V = preg_match("/^(0[1-9]|[1-2][0-9]|3[0-1])-(0[1-9]|1[0-2])-[0-9]{2}$/",$date);

		if($V){
    		$format = 'd-m-y';
    		$D = DateTime::createFromFormat($format, $date);
    		$D = ($D && $D->format($format) == $date);
    		$V = $V + $D;    
    
    	}
    	
    	switch ($V) {
    		case 0:
        	die("Error 4 modificacion del select");
        	break;
    	
    		case 1:
        	die("Error N fecha invalida");
        	break;
		}
	}

	public function verificacion_Origen_y_Destino($O,$D){

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

	public function verificacion_Fecha($O,$D,$F){

		$this->verificacion_Origen_y_Destino($O,$D);

		$AUX = new viajes();
		$AUX = $AUX->Verificacion_Day($O,$D,$F);

		if( $AUX ) {
			die("Error 5 fechas es invalido");
		}

	}

	public function verificacion_Horarios($O,$D,$F,$HE,$HL){

		$this->verificacion_Fecha($O,$D,$F);

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

	public  function verificacion_Id_viaje($ID){

	$VIA = new viajes();
	$VIA = $VIA->verificacion_Id($ID);
	
	if( $VIA ){
		die("Error 0 Id de viaje es invalido");
	}	

	}
}

?>