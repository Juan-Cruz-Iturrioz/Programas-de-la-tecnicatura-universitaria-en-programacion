<!DOCTYPE html>
<html>
<head>
	<title>SelectTime</title>
</head>
<body>

	<h1>SelectTime</h1>
	<form action="" method="post">
		<?php if($this->V){?>
			<label for ="Horario">Horario para determinada circulan de trenes </label>
			<input type="time" name="Horario">	
		
		<?php } else {?>
			<label for ="Horario_de_embarcacion"> Horario de embarcacion: </label>
			<input type="time" name="Horario_de_embarcacion">

			<label for ="Horario_de_llegada"> horario de llegada: </label>
			<input type="time" name="Horario_de_llegada">

			<input type="hidden" name="Data" id="Data" value="<?=$this->ORI?>::<?=$this->DES?>::<?= $this->FEC?>">
		
		<?php }?>
		<input type="submit" name="buscar">
	</form>
	
</body>
</html>