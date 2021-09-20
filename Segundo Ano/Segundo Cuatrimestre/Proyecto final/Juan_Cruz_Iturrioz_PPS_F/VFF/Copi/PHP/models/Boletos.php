<?php


class Boletos extends Model
{
	
	public function getVentas($N_V,$ID_V){
		
		$Vag = new Vagones();
		$Vag = !$Vag->Verificacion_Num($N_V);
		
		$Via = new viajes();
		$Via = !$Via->verificacion_Id($ID_V);

		if($Vag and $Via){
			
			$this->db->query("select b.Numero_de_asiento from Boletos b
							where b.Numero_vagon = ".$N_V." 
							and b.id_viaje = ".$ID_V."
							ORDER BY b.Numero_de_asiento
							");


			return $this->db->fetchALL();
		}
		else{
			return false;
		}

	}

	
	public function GetID_Pasajero($ID_V,$N_V,$N_A){

		$Vag = new Vagones();
		$Vag = !$Vag->Verificacion_Num($N_V);
		
		$Via = new viajes();
		$Via = !$Via->verificacion_Id($ID_V);

		$Asi = new Asientos();
		$Asi = !$Asi->Verificacion_Num($N_A);

		if($Vag and $Via and $Asi){

			$this->db->query("select b.Id_boleto, b.id_pasajero, p.nombre_completo, p.DNI from Boletos b
								join Pasajeros p on p.id_pasajero = b.id_pasajero 
								where b.id_viaje = ".$ID_V." 
								and b.Numero_vagon = ".$N_V." 
								and b.Numero_de_asiento = ".$N_A."");

			return $this->db->fetchALL();
		}
		else{
			return false;
		}


	}

	public function Verificacion_Venta($N_V,$ID_V,$ASI){

		$AUX = $this->getVentas($N_V,$ID_V);
		
		if($AUX <> false or is_array($AUX)){
			
			$AUX_V = array();

			foreach($AUX as $V){
				$AUX_V[] = $V['Numero_de_asiento'];
			}

			if(count($AUX_V) == 0){
				$AUX_V[] = 0;
			}

			$AUX = array($ASI);

			$AUX_V = (count(array_diff($AUX_V,$AUX)) <> count($AUX_V));
		}
		else{
			$AUX_V = true;	
		}


		return $AUX_V;

	}



}


?>