<?php


class Database 
{
	private $cn = false;
	private $res;
	private static $instance = false;
	private $serverName = "MSI"; // \SQLEXPRESS
	private $connectionInfo = array("Database"=>"Trenes_del_Nilo");

	private function __construct(){}

	public static function getInstance () {
	
		if (!self::$instance) {
			self::$instance = new Database();
		}
	return self::$instance;
	}	
	

	private function connect() {
		$this->cn = sqlsrv_connect($this->serverName,$this->connectionInfo);

	}

	public function query ($q) {
		if(!$this->cn){
			$this->connect();
			
		}

		$this->res = sqlsrv_query($this->cn, $q);

		if (!$this->res) {

			die(sqlsrv_error($this->cn) . " -- Consulta: ". $q);
		}
	}

	public function numRows(){
		return sqlsrv_num_rows($this->res);
	}

	public function fetch() {
		return sqlsrv_fetch_array($this->res,SQLSRV_FETCH_ASSOC);
	}

	public function fetchALL(){
		$aux = array();

		while ( $fila = $this->fetch()) {
			$aux[] = $fila; 
		}

		return $aux;
	}

	public function escape($str) {

		return addslashes($str);
	}

	public function escapeWildcard($str){
		$str = str_replace('%', "\%", $str);
		$str = str_replace('_', "\_", $str);
		return $str;
	}

	public function Prepare($SP,$V){
		if(!$this->cn){
			$this->connect();
			
		}

		$AUX = sqlsrv_prepare($this->cn,$SP,$V);

		return $AUX;

	}

	public function Execute ($SP){
		
		$AUX = sqlsrv_execute($SP);

		return $AUX;
	}

	public function __destruct()
	{
		sqlsrv_close ( $this->cn );
	}


}


?>