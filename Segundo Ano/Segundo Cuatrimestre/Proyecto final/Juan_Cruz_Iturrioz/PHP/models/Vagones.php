<?php

class Vagones extends Model
{	
	public function getVagones($N_V){

		if( !$this->Verificacion_Num($N_V) ){
	
			$this->db->query("select v.Clase_vagones, v.Plaza from Vagones v
								where v.Numero_vagon = ".$N_V."");


			return $this->db->fetchALL();
		}
		else{
			return false;	
		}

	}

	
	public function getVagones_Tipo(){

		$this->db->query("select distinct Clase_vagones, Plaza from Vagones");

		return $this->db->fetchALL();
	}

	public function getVagones_Num($C,$P){
		
		if($this->Verificacion_Vagones($C,$P) <> false){

			$P = str_replace(' ', "_",$P);
		
			$this->db->query("select v.Numero_vagon from Vagones V
							where V.Clase_vagones = '$C' and v.Plaza = '$P'");

		
			return $this->db->fetchALL();
		}

		else{
			return false;
		}


	}

	public function getVagones_Num_ALL(){

		$this->db->query("select Numero_vagon from Vagones");

		return $this->db->fetchALL();
	}

	
	public function Verificacion_Vagones($C,$P){
		
		$AUX = $this->getVagones_Tipo();
		
		$AUX_C = array();
		$AUX_P = array();

		foreach ($AUX as $V ) {
			$AUX_C[] = $V['Clase_vagones'];
			$AUX_P[] = str_replace('_', " ",$V['Plaza']);
		}

		$AUX_C = array_unique($AUX_C);
		$AUX_P = array_unique($AUX_P);

		sort($AUX_C);
		sort($AUX_P);
		
		$AUX = array($C);

		$AUX_C = (count(array_diff($AUX_C,$AUX)) == count($AUX_C));

		$AUX = array($P);

		$AUX_P = (count(array_diff($AUX_P,$AUX)) == count($AUX_P));
		 
		$AUX =  (int)($AUX_C) . "::" . (int)($AUX_P);

		return $AUX;		
	}

	public function Verificacion_Num($N){

		$AUX = $this->getVagones_Num_ALL();

		$AUX_Vag = array();

		foreach ($AUX as $V) {
			$AUX_Vag[] = $V['Numero_vagon'];
		}

		$AUX = array($N);

		$AUX_Vag = (count(array_diff($AUX_Vag,$AUX)) == count($AUX_Vag));
		
		return $AUX_Vag;
	}


}

?>