<?php


class viajes extends Model
{
	
	public function getViajes_now ($O,$D){
		$this->db->query("select * from Viajes v
							where v.Fecha_de_viaje >= CONVERT(DATE, GETDATE()) 
							and v.Fecha_de_viaje <= CONVERT(DATE, GETDATE() + 30 ) 
							and v.Horario_de_embarcacion > CONVERT(TIME,GETDATE()) 
							and v.Destino = '" . $D . "' and v.Origen = '" . $O ."'");

		return $this->db->fetchALL();
	}


	public function getViajes_day($O,$D,$F){
		$this->db->query("select * from Viajes v
							where CONVERT(varchar,v.Fecha_de_viaje,3) like '".$F."/20' 
							and v.Destino = '" . $D . "' and v.Origen = '" . $O ."'
							order by v.Horario_de_embarcacion
							");


		return $this->db->fetchALL();
	}

	public function getViajes_time($O,$D,$F,$HE,$HL){
		$this->db->query("select * from Viajes v
							where CONVERT(varchar,v.Fecha_de_viaje,3) like '".$F."/20' 
							and v.Destino = '" . $D . "' and v.Origen = '" . $O ."'
							and v.Horario_de_embarcacion = '".$HE."' 
							and v.horario_de_llegada= '".$HL."'" );


		return $this->db->fetchALL();
	}

	public function getViajes_now_time($time){
		$this->db->query(" select * from Viajes v
							where v.Fecha_de_viaje = CONVERT(DATE, GETDATE()) 
							and v.Fecha_de_viaje <= CONVERT(DATE, GETDATE() + 30 ) 
							and v.Horario_de_embarcacion < CONVERT(TIME,'".$time."') 
							and v.horario_de_llegada > CONVERT(TIME,'".$time."')");


		return $this->db->fetchALL();
	}

	public function getViajes_ID(){
		$this->db->query("select v.id_viaje from Viajes v
							where v.Fecha_de_viaje >= CONVERT(DATE, GETDATE()) 
							and v.Fecha_de_viaje <= CONVERT(DATE, GETDATE() + 30 ) 
							and v.Horario_de_embarcacion > CONVERT(TIME,GETDATE())" );

		return $this->db->fetchALL();
	}

}


?>