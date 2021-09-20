<?php

/*
require '../fw/FW.php';
require '../controllers/BasaSelect.php';


require '../models/Viajes.php';
require '../models/Trenes.php';
require '../models/Boleterias.php';
require '../views/FormEstacion.php';
require '../views/FormViajes.php';
require '../views/FormFecha.php';
require '../views/FormHoras.php';

require '../views/SelectTime.php';

*/

class ABM extends Model
{
	public function Alta ($DATA){
		
		$FECHA = date_create_from_format('d/m/y', $DATA[0]['Fecha_de_viaje']);
		$FECHA = $FECHA->format('Y-m-d'); 
		
		
		$Array = array(&$DATA[0]['Id_tren'] , &$DATA[0]['Destino'] , &$DATA[0]['Origen'] , &$FECHA, &$DATA[0]['Horario_de_embarcacion'] , &$DATA[0]['Horario_de_llegada'] );
		

		$q = "insert into Viajes (Id_tren,Destino,Origen,Fecha_de_viaje,Horario_de_embarcacion,Horario_de_llegada) values (?,?,?,?,?,?)";
;
		
		$this->db->ABM($q, $Array);
		
		$Pre = $this->Ultimo_id_viajes();
		
		$Pre = $Pre[0]['id_viaje'];
		
		return $Pre;
	}

	public function Modificaciones ($DATA , $ID_V){
		
		$FECHA = date_create_from_format('d/m/y', $DATA[0]['Fecha_de_viaje']);
		$FECHA = $FECHA->format('Y-m-d'); 
		
		
		$Array = array(&$DATA[0]['Id_tren'] , &$DATA[0]['Destino'] , &$DATA[0]['Origen'] , &$FECHA, &$DATA[0]['Horario_de_embarcacion'] , &$DATA[0]['Horario_de_llegada'] );
		

		$q = "UPDATE Viajes SET Id_tren = (?),Destino =(?), Origen=(?), Fecha_de_viaje = (?), Horario_de_embarcacion = (?) , Horario_de_llegada = (?)
			WHERE Id_viaje = $ID_V";

		
		$this->db->ABM($q, $Array);
		
		return true;
	}

	public function Bajas ( $ID_V ){
				
		$Array = new Viajes();
		$Array = $Array->verificacion_Id($ID_V);
		
		if(!$Array){
			$Array = array(&$ID_V);
		
			$q = "DELETE FROM Viajes where Id_viaje = (?)";
		
			$this->db->ABM($q, $Array);
		
			return true;
		}
		else{
			return false;
		}

		
	}

	public function Ultimo_id_viajes(){
		
		$this->db->query("Select IDENT_CURRENT ('Viajes') as id_viaje " );

		return $this->db->fetchALL();
	}

	public function verificacion_Date($F){
	
		$AUX = new BasaSelect();
		$AUX->validateDate($F);
		
		$paymentDate = date_create();
 		$contractDateBegin = date_create_from_format('d/m/y', $F);
 		$contractDateEnd = date_create_from_format('d/m/y',(date('d/m/y', (time() + (86400*30) ) ) ) );
 		
 		$AUX = (
 			 ($contractDateBegin->getTimestamp() >= $paymentDate->getTimestamp()) and 
 			($contractDateBegin->getTimestamp() <= $contractDateEnd->getTimestamp() )
 		);
		
		if(!$AUX){
			die("Error N fecha invalida");
		}
	}

	public function verificacion_Fecha($O,$D,$F){

		$Basa = new BasaSelect();
		$Basa->verificacion_Origen_y_Destino($O,$D);

		$this->verificacion_Date($F);
	}

	public function verificacion_Time($Time){
	
		$V =!( preg_match("/^([0-1][1-9]|[2][0-3])(:)([0-5][0-9])$/", $Time) );
	
		return $V;
	
	}

	public function verificacion_Horarios($O,$D,$F,$HE,$HL){

		$this->verificacion_Fecha($O,$D,$F);

		$AUX_HE = (bool)($this->verificacion_Time($HE));
		$AUX_HL = (bool)($this->verificacion_Time($HL));
		
		if (($AUX_HE or $AUX_HL)) {
			
			if (!$AUX_HL and $AUX_HE) {
				die("Error 6 de Horario de embarcacion es invalido");
			}
	
			elseif($AUX_HL and !$AUX_HE){
				die("Error 7 de Horario de llegada es invalido");
			}

		die("Error 8 los Horarios son invalido");

		}

		$AUX_HE = date_create_from_format('H:i',$HE);
		$AUX_HL = date_create_from_format('H:i',$HL);
		
		if( $AUX_HE->getTimestamp() >= $AUX_HL->getTimestamp() ){
			die("Error 8 los Horarios son invalido");
		}


	}

	public function recuperacion($DATA){
		
		if(strlen($DATA) < 39 or substr_count($DATA,'||') <> 1){
			die("Error 9 modificacion del hidden");
		}

		list($AUX,$ID_T) = explode("||", $DATA);

		if(strlen($AUX) <> 36 or substr_count($AUX,'::') <> 4){
			die("Error 9 modificacion del hidden");
		}

		list($ORI,$DES,$FECHA,$EMB,$LLE) = explode("::", $AUX);

		$this->verificacion_Horarios($ORI,$DES,$FECHA,$EMB,$LLE);

		$AUX = array();
		$AUX[0] = array();
	
		$AUX[0]['Id_tren'] = $ID_T;
		$AUX[0]['Origen'] = $ORI;
		$AUX[0]['Destino'] = $DES;
		$AUX[0]['Fecha_de_viaje'] = $FECHA;
		$AUX[0]['Horario_de_embarcacion'] = $EMB;
		$AUX[0]['Horario_de_llegada'] = $LLE;
		
		return $AUX;
	}


}?>