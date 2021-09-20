<?php

abstract class View {

	public function renden() {
		include '../html/' .get_class($this). '.php';
	}

	public $Title;
	
	public function AutoTitle(){
		$AUX = basename ( rtrim($_SERVER['PHP_SELF'], '/\\') );
		$AUX = rtrim ( $AUX, '.php');
		$AUX = rtrim ( $AUX, '_P1');
		$AUX = rtrim ( $AUX, '_P2');
		$this->Title = $AUX;
	}

	public function ManualTitle($T){
		$this->Title = $T;
	}
	
}

?>