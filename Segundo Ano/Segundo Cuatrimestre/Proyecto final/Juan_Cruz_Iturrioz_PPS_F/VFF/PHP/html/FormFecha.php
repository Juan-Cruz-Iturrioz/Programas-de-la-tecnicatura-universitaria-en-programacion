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
	 
	<h1>Seleccione la Fecha para el viaje</h1>

	<form action="" method="post">
		<label for ="Fecha"> Fecha: </label>

		<select name = "Fecha" id = "Fecha">
			<option selected disabled hidden>Elige</option>

			<?php foreach ($this->VIA as $V ) { ?>
				<option value="<?= $V ?>"> <?= $V ?> </option>						
			
			<?php  } ?>
		</select> 
		
	<input type="hidden" name="Data" id="Data" value="<?=$this->ORI?>::<?=$this->DES?>">
	
	<br>

	<input type="submit" value="Continuar" >
	</form>

</body>
</html>