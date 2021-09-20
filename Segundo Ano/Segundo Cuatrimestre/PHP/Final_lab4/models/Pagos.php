<?php

class Pagos extends Model{

	public function getId_departamento($P , $L){
		$this->db->query("SELECT `id_departamento` FROM `departamentos` 
							WHERE piso = $P AND letra = '$L'");

		return $this->db->fetchALL();

	}

	public function setPago($Id,$F,$M){
		$this->db->query("INSERT INTO Pagos (id_departamento,fecha,monto) 
							VALUES ($Id,$F,$M)");

	}
}

?>
