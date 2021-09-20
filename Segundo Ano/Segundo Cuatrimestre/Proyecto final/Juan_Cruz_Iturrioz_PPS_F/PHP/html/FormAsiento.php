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
	 <h1>Seleccione Tipo asiento y Número de vagones</h1> 

	<form action="" method="post">		
		<label for ="Tipo_asiento"> Tipo asiento: </label>

		<select name = "Tipo_asiento" id = "Tipo_asiento">
			<option selected disabled hidden>Elige</option>

			<?php foreach ($this->Tipos as $V ) { ?>
				<option value="<?= $V ?>"> <?= $V ?> </option>						
			
			<?php  } ?>
		</select> 
			
		<br>	

		<label for ="Vagones"> Número de vagones: </label>
		
		<select name = "Vagones" id = "Vagones">
			<option selected disabled hidden>Elige</option>

			<?php foreach ($this->Vag as $V ) { ?>
				<option value="<?= $V ?>"> <?= $V ?> </option>						
			
			<?php  } ?>
		</select>

	<br>

	<input type="submit" value="Continuar" >		
	<br>

	
	</form>

</body>
</html>