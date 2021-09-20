<?php


class Pasajeros extends Model
{
	
	public function SetPasajeros($Nom,$DNI){
		
		$AUX = (strlen($DNI) <> 8 or !is_numeric($DNI));
		$AUX = ( $AUX or (!preg_match("/^([a-zA-Z' ]+)$/",$Nom)) );

		if(!$AUX){

			$Array =  array(&$Nom , &$DNI );

			$AUX = $this->db->Prepare("exec SetPasajeros @Nombre = ?, @DNI = ? ",$Array);
		
			$this->db->Execute($AUX);
						
			return $this->SetId_Pasajeros($DNI);

		}
		else{
			return false;
		}


	}

	public function SetBoletos($ID_V,$ID_P,$PRE,$N_V,$N_A,$DNI){

		$AUX = $this->Verificacion_Id_Pasajero($ID_P, $DNI);

		$Via = new Viajes();
		$Via = !$Via->verificacion_Id($ID_V);
		
		$Asi = new Asientos();
		$Asi = !$Asi->Verificacion_Num($N_A);

		$Vag = new Vagones();
		$Vag = !$Vag->Verificacion_Num($N_V);

		$AUX = ($AUX and $Via and $Asi and $Vag);
		
		var_dump($Asi);
		if($AUX){
			$Array = array(&$ID_V, &$ID_P, &$PRE, &$N_A, &$N_V );

			$AUX = $this->db->Prepare("exec SetBoletos @Id_viaje = ? , @Id_pas = ? , @PRE = ? , @N_A = ? , @N_V = ? ",$Array);

			$AUX = $this->db->Execute($AUX);

			$AUX = $this->Ultimo_id_Boletos();
		}		

		return $AUX;
		
	}

	public function GetID_Tren($ID_V){

		$this->db->query("select v.id_tren from Viajes v
					where v.id_viaje = ".$ID_V. "");
				
		return $this->db->fetchALL();

	}

	public function Ultimo_id_Boletos(){
		
		$this->db->query("Select IDENT_CURRENT ('Boletos') as Id_boleto " );

		return $this->db->fetchALL();
	}

	public function SetPasajero_Viajes($DNI , $ID_V){
		
		$AUX = (strlen($DNI) <> 8 or !is_numeric($DNI));

		$Via = new Viajes();
		$Via = $Via->verificacion_Id($ID_V);

		if(!($AUX and $Via)){
			$this->db->query("select p.id_pasajero from Pasajeros p
							left join Boletos b on b.Id_pasajero = p.id_pasajero
							where  p.DNI = ". $DNI . " and b.Id_viaje = ". $ID_V ."");
				
			return $this->db->fetchALL();
		}
		else{
			return false;
		}


	}

	public function SetId_Pasajeros($DNI){
		
		$AUX = (strlen($DNI) <> 8 or !is_numeric($DNI)); 
		
		if(!$AUX) {
			
			$this->db->query("select p.id_pasajero from Pasajeros p
								where p.DNI =".$DNI."" );
				
			return $this->db->fetchALL();
		}
		else{
			return false;
		}

	}

	public function Verificacion_Id_Pasajero_Viaje ($ID_P, $DNI , $ID_V){
		$Via = new viajes();
		$Via = !$Via->verificacion_Id($ID_V);

		$AUX = $this->Verificacion_Id_Pasajero($ID_P, $DNI);

		if(  $Via and $AUX  ){
			
			$Via = $this->SetPasajero_Viajes($DNI , $ID_V);
			$AUX = array();
			foreach ($Via as $V) {
				$AUX[] = $V['id_pasajero'];
			}
			if(count($AUX) == 0){
				$AUX[] = 0;
			}
			$Via = array($ID_P);

			$AUX = (count(array_diff($Via,$AUX)) == count($AUX));
			
		}
		else{
			$AUX = false;
			
		}

		return $AUX;
	}

	public function Verificacion_Id_Pasajero ($ID_P, $DNI){

		$IDS = $this->SetId_Pasajeros($DNI);
		
		if($IDS <> false){
			
			$AUX = array();
		
			foreach ($IDS as $V) {
				$AUX[] = $V['id_pasajero'];
			}

			if(count($AUX) >= 1){
				$IDS = array($ID_P);
				$IDS = (count(array_diff($AUX,$IDS)) <> count($AUX));
			}
			else{
				$IDS = false;	
			}
		}

		return $IDS; 

		
	}

}


?>