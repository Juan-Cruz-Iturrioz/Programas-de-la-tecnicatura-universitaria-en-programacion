<?php


class Pasajeros extends Model
{
	
	public function SetPasajeros($Nom,$DNI){
		

		$Array =  array(&$Nom , &$DNI );

		$AUX = $this->db->Prepare("exec SetPasajeros @Nombre = ?, @DNI = ? ",$Array);
		
		$this->db->Execute($AUX);
		
		$this->db->query("select p.id_pasajero from Pasajeros p
								where p.DNI ='".$DNI."'" );
				
		return $this->db->fetchALL();;
	}

	public function SetBoletos($ID_V,$ID_P,$PRE,$N_V,$N_A){

		$Array = array(&$ID_V, &$ID_P,&$PRE, &$N_A, &$N_V );

		$AUX = $this->db->Prepare("exec SetBoletos @Id_viaje = ? , @Id_pas = ? , @PRE = ? , @N_A = ? , @N_V = ? ",$Array);

		$AUX = $this->db->Execute($AUX);

		return $AUX;
	}

	public function GetID_Tren($ID_V){

		$this->db->query("select v.id_tren from Viajes v
				where v.id_viaje = '".$ID_V. "'");
				
		return $this->db->fetchALL();;

	}


}


?>