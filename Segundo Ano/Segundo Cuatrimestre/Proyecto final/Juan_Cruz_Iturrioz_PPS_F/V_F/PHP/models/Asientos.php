<?php

class Asientos extends Model
{	

	public function getAsientos($N_V){
		
		$AUX = new Vagones;
		if(!$AUX->Verificacion_Num($N_V)){
			
			$this->db->query("select a.Numero_de_asiento,a.Tipo_asiento from Asientos a
								where a.Numero_vagon = ".$N_V."");


			return $this->db->fetchALL();
		
		}
		else{
			return false;
		}

	}

	public function getAsientos_Tipo(){

		$this->db->query("select distinct Tipo_asiento from Asientos");

		return $this->db->fetchALL();
	}

	public function getAsientos_Num(){

		$this->db->query("select distinct Numero_de_asiento from Asientos");

		return $this->db->fetchALL();
	}

	public function Verificacion_Tipo($T){

		$AUX = $this->getAsientos_Tipo();

		$AUX_T = array();
	
		foreach ($AUX as $V) {
			$AUX_T[] = $V['Tipo_asiento'];
		}
	
		$AUX = array($T);

		$AUX_T = (count(array_diff($AUX_T,$AUX)) == count($AUX_T));

		return $AUX_T;
	}

	public function Verificacion_Num($N){

		$AUX = $this->getAsientos_Num();

		$AUX_T = array();
	
		foreach ($AUX as $V) {
			$AUX_T[] = $V['Numero_de_asiento'];
		}
	
		$AUX = array($N);

		$AUX_T = (count(array_diff($AUX_T,$AUX)) == count($AUX_T));

		return $AUX_T;
	}


}

?>