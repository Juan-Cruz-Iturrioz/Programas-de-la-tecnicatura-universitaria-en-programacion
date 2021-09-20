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
	<h1>Formulario de Pasajero</h1>

	<form action="" method="post">
		<label for ="Nombre"> Nombre completo del Pasajero: </label>

		<input type="text" name="Nombre" id="Nombre">
		
		<br>

		<label for ="DNI"> DNI del Pasajero: </label>
		
		<input type="text" name="DNI" id="DNI">

		<br>

		<input type="submit" value="Continuar" >
	</form>

</body>
</html>