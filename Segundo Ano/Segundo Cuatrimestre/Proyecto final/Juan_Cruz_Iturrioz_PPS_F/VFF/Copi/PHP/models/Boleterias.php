<?php

class Boleterias extends Model
{
	public function getEstacion(){

		$this->db->query("select * from Boleteria");

		return $this->db->fetchALL();
	}

	public function Verificacion_Estacion($EST){
		$query = $this->getEstacion();

		$AUX = array();
		foreach ($query as $V) {
			$AUX[] = $V['Estacion'];
		}

		$query = array($EST);
		
		$AUX = (count(array_diff($AUX,$query)) == count($AUX)); 
		
		return $AUX;		
	}

}

?>