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
		<h1>Seleccione la Estacion de Origen y Destino del viaje</h1>
	<?php }else{ ?>
		<h1>Ingrese los datos de Estacion de Origen y Destino para el viaje</h1>
	<?php } ?>


	<form action="" method="post">
		<label for ="Origen"> Origen: </label>

		<select name = "Origen" id = "Origen">
			<option selected disabled hidden>Elige</option>

			<?php foreach ($this->Estacion as $E ) { ?>
				<option value="<?=$E ?>"> <?= $E ?>	</option>						
			
			<?php  } ?>
		</select>
		
		<br>

		<label for ="Destino"> Destino: </label>
		
		<select name = "Destino" id = "Destino">
			<option selected disabled hidden>Elige</option>

			<?php foreach ($this->Estacion as $E ) { ?>
				<option value="<?=$E ?>"> <?= $E ?>	</option>						
			
			<?php  } ?>
		</select>

		<br>

		<input type="submit" value="Continuar" >
	</form>

</body>
</html>