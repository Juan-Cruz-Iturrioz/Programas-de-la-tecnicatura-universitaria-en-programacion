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
						where CONVERT(varchar,v.Fecha_de_viaje,3) like '".$F."'
						and v.Horario_de_embarcacion > CONVERT(TIME,GETDATE())
						and v.Destino = '" . $D . "' and v.Origen = '" . $O ."'
						order by v.Horario_de_embarcacion";
			}
			else{
				$Hoy = "select * from Viajes v
						where CONVERT(varchar,v.Fecha_de_viaje,3) like '".$F."'
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
							where CONVERT(varchar,v.Fecha_de_viaje,3) like '".$F."' 
							and v.Destino = '" . $D . "' and v.Origen = '" . $O ."'
							and v.Horario_de_embarcacion = '".$HE."' 
							and v.horario_de_llegada= '".$HL."'" );


			return $this->db->fetchALL();
		
		}

		else{
			return false;
		}

	}

	public function getViajes_now_time($time){
		if( preg_match("/^(?:2[0-3]|[01][0-9]):[0-5][0-9]$/", $time) ){
			
			$this->db->query(" select * from Viajes v
							where v.Fecha_de_viaje = CONVERT(DATE, GETDATE()) 
							and v.Fecha_de_viaje <= CONVERT(DATE, GETDATE() + 30 ) 
							and v.Horario_de_embarcacion < CONVERT(TIME,'".$time."') 
							and v.horario_de_llegada > CONVERT(TIME,'".$time."')");

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

	public function getViajes_For_ID($ID){

		if(!$this->verificacion_Id($ID) ){
			
			$this->db->query("Select * from Viajes v where v.Id_viaje = '".$ID."'" );

			return $this->db->fetchALL();
		}
		return false;

	}

	public function Verificacion_Day($O,$D,$F){

		$AUX = $this->getViajes_now($O,$D);
				
		if( $AUX <> false){

			$VEN  = array();

			foreach ($AUX as $V ){
				$VEN[] = $V['Fecha_de_viaje']->format('d/m/y');
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

		public function verificacion_Trene($O,$D,$F,$HE,$HL,$ID){

		$AUX = $this->getId_tren($O,$D,$F,$HE,$HL);

		$VEN  = array();

			foreach ($AUX as $V ){
				$VEN[] = $V['Id_tren'];
			}

		$AUX = array($ID);
		$AUX = ( count(array_diff($VEN,$AUX)) <> count($VEN) );
		return $AUX;
	}
}?>