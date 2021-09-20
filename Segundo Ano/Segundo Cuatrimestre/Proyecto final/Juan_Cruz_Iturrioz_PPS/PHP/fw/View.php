<?php

abstract class View {

	public function renden() {
		include '../html/' .get_class($this). '.php';
	}
}

?>