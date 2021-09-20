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
	 <h1>Seleccione la Clase y la Plaza para el Vagones</h1> 

	<form action="" method="post">
		
		<label for ="Clase_vagones"> Clase vagones: </label>

		<select name = "Clase_vagones" id = "Clase_vagones">
			<option selected disabled hidden>Elige</option>

			<?php foreach ($this->Clase as $V ) { ?>
				<option value="<?= $V ?>"> <?= $V ?> </option>						
			
			<?php  } ?>
		</select> 
		
		<br>

		<label for ="Plaza"> Plaza: </label>

		<select name = "Plaza" id = "Plaza">
			<option selected disabled hidden>Elige</option>

			<?php foreach ($this->Plaza as $V ) { ?>
				<option value="<?= $V ?>"> <?= $V ?> </option>						
			
			<?php  } ?>
		</select>

		<br>

	<input type="submit" value="Continuar" >
	

	<p> El Precio del Turista es $<?=  $this->Precio['Turista']  ?> </p>
	<p> El Precio del Pulmanes $<?= $this->Precio['Pulman']  ?> </p>

	</form>

</body>
</html>