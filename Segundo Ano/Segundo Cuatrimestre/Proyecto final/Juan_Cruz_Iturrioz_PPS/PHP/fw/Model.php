<?php

abstract class Model {

	protected $db;	

	function __construct()
	{
		$this->db = Database::getInstance();
	}
}

?>