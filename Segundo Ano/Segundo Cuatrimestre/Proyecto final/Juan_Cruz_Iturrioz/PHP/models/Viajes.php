<?php

class viajes extends Model
{
	
	public function getViajes_now ($O,$D){

		if( !$this->verificacion_Estaciones($O,$D) ){

			$this->db->query("select * from Viajes v
							where v.Fecha_de_viaje >= CONVERT(DATE, GETDATE()) 
							and v.Fecha_de_viaje <= CONVERT(DATE, GETDATE() + 30 ) 
							and v.Destino = '" . $D . "' and v.Origen = '" . $O ."'");

			return $this->db->fetchALL();
		}
		
		else{
			return false;
		}
	}


	public function getViajes_day($O,$D,$F){

		if( !$this->Verificacion_Day($O,$D,$F) ){

			$Hoy = getdate();

			$Hoy = $Hoy['mday'] .'/'.  $Hoy['mon'] ;
		
			if($F == $Hoy){
				$Hoy = "select * from Viajes v
						where CONVERT(varchar,v.Fecha_de_viaje,3) like '".$F."/20'
						and v.Horario_de_embarcacion > CONVERT(TIME,GETDATE())
						and v.Destino = '" . $D . "' and v.Origen = '" . $O ."'
						order by v.Horario_de_embarcacion";
			}
			else{
				$Hoy = "select * from Viajes v
						where CONVERT(varchar,v.Fecha_de_viaje,3) like '".$F."/20'
						and v.Destino = '" . $D . "' and v.Origen = '" . $O ."'
						order by v.Horario_de_embarcacion";

			}

		
			$this->db->query($Hoy); 

			return $this->db->fetchALL();
		}

		else{
			return false;
		}


	}

	public function getViajes_time($O,$D,$F,$HE,$HL){

		if($this->Verificacion_Time($O,$D,$F,$HE,$HL) <> false){

			$this->db->query("select * from Viajes v
							where CONVERT(varchar,v.Fecha_de_viaje,3) like '".$F."/20' 
							and v.Destino = '" . $D . "' and v.Origen = '" . $O ."'
							and v.Horario_de_embarcacion = '".$HE."' 
							and v.horario_de_llegada= '".$HL."'" );


			return $this->db->fetchALL();
		
		}

		else{
			return false;
		}

	}



	public function getViajes_ID(){
		$this->db->query("select v.id_viaje from Viajes v
							where v.Fecha_de_viaje >= CONVERT(DATE, GETDATE()) 
							and v.Fecha_de_viaje <= CONVERT(DATE, GETDATE() + 30 )" );

		return $this->db->fetchALL();
	}

	public function Verificacion_Day($O,$D,$F){

		$AUX = $this->getViajes_now($O,$D);
				
		if( $AUX <> false){

			$VEN  = array();

			foreach ($AUX as $V ){
				$VEN[] = $V['Fecha_de_viaje']->format('d/m');
			}

			$VEN = array_unique($VEN);
			sort($VEN);

			$AUX = array($F);

			$AUX = ( count(array_diff($VEN,$AUX)) == count($VEN) );

		}

		return $AUX;
	}

	public function Verificacion_Time($O,$D,$F,$HE,$HL){

		$AUX = $this->getViajes_day($O,$D,$F);
		
		if ( $AUX <> false){
			
			$AUX_HE = array();
			$AUX_HL = array();

			foreach ($AUX as $V ){
				$AUX_HE[] = $V['Horario_de_embarcacion']->format('H:i');
				$AUX_HL[] = $V['Horario_de_llegada']->format('H:i');
			}

			$AUX = array($HE);

			$AUX_HE = (count(array_diff($AUX_HE,$AUX)) == count($AUX_HE));

			$AUX = array($HL);

			$AUX_HL = (count(array_diff($AUX_HL,$AUX)) == count($AUX_HL));
		 
			$AUX =  (int)($AUX_HE) . "::" . (int)($AUX_HL);
		}
		
		return $AUX;
	}

	public function verificacion_Id($ID){

		$query = $this->getViajes_ID();
		$AUX = array();

		foreach ($query as $V ){
			$AUX[] = $V['id_viaje'];
		}

		$query = array($ID);

		$AUX = (count(array_diff($AUX,$query)) == count($AUX));
		
		return $AUX; 

	}


	public function verificacion_Estaciones($O,$D){
		
		$AUX_1 = new Boleterias();
		$AUX_2 = $AUX_1->Verificacion_Estacion($D);
		$AUX_1 = $AUX_1->Verificacion_Estacion($O);
		
		$AUX_1 = ($AUX_1 and $AUX_2);

		return $AUX_1;
	}

}?>