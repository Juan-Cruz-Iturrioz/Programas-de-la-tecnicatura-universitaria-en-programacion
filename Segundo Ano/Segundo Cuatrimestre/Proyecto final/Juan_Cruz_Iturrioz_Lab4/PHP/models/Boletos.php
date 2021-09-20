<?php


class Boletos extends Model
{
	
	public function getVentas($N_V,$ID_V){
		
		$this->db->query("select b.Numero_de_asiento from Boletos b
							where b.Numero_vagon = '".$N_V."' and b.id_viaje = '".$ID_V."'
							ORDER BY b.Numero_de_asiento
							");


		return $this->db->fetchALL();
	}

	public function getAsientos($N_V){
		
		$this->db->query("select a.Numero_de_asiento,a.Tipo_asiento from Asientos a
							where a.Numero_vagon = '".$N_V."'");


		return $this->db->fetchALL();
	}

	public function getVagones($N_V){
		
		$this->db->query("select v.Clase_vagones, v.Plaza from Vagones v
							where v.Numero_vagon = '".$N_V."'");


		return $this->db->fetchALL();
	}


	public function GetID_Pasajero($ID_V,$N_V,$N_A){
		$this->db->query("select b.id_pasajero, p.nombre_completo, p.DNI from Boletos b
							join Pasajeros p on p.id_pasajero = b.id_pasajero 
							where b.id_viaje = '".$ID_V."' and b.Numero_vagon = '".$N_V."' and b.Numero_de_asiento = '".$N_A."'");

		return $this->db->fetchALL();;
	}



}


?>