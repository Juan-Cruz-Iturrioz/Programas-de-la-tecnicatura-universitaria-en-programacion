<?php

class Trenes extends Model
{	

	public function GetId_tren_1($O,$D,$F,$HE,$HL){

		$ABM = new ABM();

		$ABM->verificacion_Horarios($O,$D,$F,$HE,$HL);

			$this->db->query("select distinct t.Id_tren from Trenes t where t.Id_tren not in (
			select distinct v.Id_tren from Viajes v where ( CONVERT(varchar,v.Fecha_de_viaje,3) like '" . $F . "') and (
					( v.horario_de_llegada >= CONVERT(TIME,'" . $HE . "') 
					and v.Horario_de_embarcacion <= CONVERT(TIME,'" . $HE . "') )
					or
					( v.horario_de_llegada >= CONVERT(TIME,'" . $HL . "') 
					and v.Horario_de_embarcacion <= CONVERT(TIME,'" . $HL . "') )	
				)
			)
			order by t.Id_tren");

			return $this->db->fetchALL();
		
	}

	public function GetTrenes($ID){

		$AUX = new Viajes();
		$AUX = $AUX->verificacion_Id($ID);
		if( !$AUX ){
			
			$this->db->query("select v.Id_tren from Viajes v where v.Id_viaje = ". $ID ." " );

			return $this->db->fetchALL();
		}
		return false;
	}

	public function GetId_tren_2($O,$D,$F,$HE,$HL,$ID){

		$P1 = $this->GetId_tren_1($O,$D,$F,$HE,$HL);
		$P2 = $this->GetTrenes($ID);
		
		$P1[] = $P2[0];

		return $P1;
	}

	public function verificacion_Trene_1($O,$D,$F,$HE,$HL,$ID){

		$AUX = $this->GetId_tren_1($O,$D,$F,$HE,$HL);

		$VEN  = array();

			foreach ($AUX as $V ){
				$VEN[] = $V['Id_tren'];
			}

		$AUX = array($ID);
		$AUX = ( count(array_diff($VEN,$AUX)) <> count($VEN) );
		return $AUX;
	}

	public function verificacion_Trene_2($O,$D,$F,$HE,$HL,$ID,$ID_V){

		$AUX = $this->GetId_tren_2($O,$D,$F,$HE,$HL,$ID_V);

		$VEN  = array();

			foreach ($AUX as $V ){
				$VEN[] = $V['Id_tren'];
			}

		$AUX = array($ID);
		$AUX = ( count(array_diff($VEN,$AUX)) <> count($VEN) );
		return $AUX;
	}



}

?>