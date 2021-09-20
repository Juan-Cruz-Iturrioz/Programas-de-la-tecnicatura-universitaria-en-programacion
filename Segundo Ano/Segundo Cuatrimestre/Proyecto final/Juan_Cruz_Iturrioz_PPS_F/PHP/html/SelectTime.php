<!DOCTYPE html>
<html>
<head>
	<title><?= $this->Title ?></title>

	<?php 
	$uri   = rtrim(dirname($_SERVER['PHP_SELF'],2), '/\\');
	$uri   .="/CSS/Input.css";
	?>

	<link rel="stylesheet" type="text/css" href="<?= $uri ?>">

</head>
<body>

	<?php if($this->V){ ?>
		<h1>Ingrese el horario para los trenes que circulan en la fecha de hoy</h1>
	<?php }else{ ?>
		<h1>Ingrese los datos de Horarios para el viaje</h1>
	<?php } ?>

	<form action="" method="post">
		<?php if($this->V){?>
			<label for ="Horario">Horario para determinada circulan de trenes </label>
			<input type="time" name="Horario">	
		
		<?php } else {?>
			<label for ="Horario_de_embarcacion"> Horario de embarcacion: </label>
			<input type="time" name="Horario_de_embarcacion">

			<label for ="Horario_de_llegada"> Horario de llegada: </label>
			<input type="time" name="Horario_de_llegada">

			<input type="hidden" name="Data" id="Data" value="<?=$this->ORI?>::<?=$this->DES?>::<?= $this->FEC?>">
		
		<?php }?>
		<br>
		
		<input type="submit" value="Continuar" >
	</form>
	
</body>
</html>