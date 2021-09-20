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

	public function getVagones_Clase(){

		$this->db->query("select distinct Clase_vagones from Vagones");

		return $this->db->fetchALL();
	}

	public function getVagones_Plaza(){

		$this->db->query("select distinct Plaza from Vagones");

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
		

		$AUX =  (int)($this->Verificacion_Clase($C)) . "::" . (int)($this->Verificacion_Plaza($P));

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

	public function Verificacion_Clase($C){
		
		$AUX = $this->getVagones_Clase();
		
		$AUX_C = array();

		foreach ($AUX as $V ) {
			$AUX_C[] = $V['Clase_vagones'];
		}

		sort($AUX_C);

		$AUX = array($C);

		$AUX_C = (count(array_diff($AUX_C,$AUX)) == count($AUX_C));

		return $AUX_C;
	}

	public function Verificacion_Plaza($P){
		
		$AUX = $this->getVagones_Plaza();
		
		$AUX_P = array();

		foreach ($AUX as $V ) {
			$AUX_P[] = str_replace('_', " ",$V['Plaza']);
		}

		sort($AUX_P);

		$AUX = array($P);

		$AUX_P = (count(array_diff($AUX_P,$AUX)) == count($AUX_P));

		return $AUX_P;
	}
}

?>