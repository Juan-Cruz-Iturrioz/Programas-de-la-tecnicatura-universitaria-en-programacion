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
	 <h1>Seleccione la Clase del vagon</h1> 

	<form action="" method="post">
		

		<input type="hidden" name="Id_viaje" id="Id_viaje" value="<?= $this->ID ?>">

		<label for ="Clase_vagones"> Clase vagones: </label>

		<select name = "Clase_vagones" id = "Clase_vagones">
			<option selected disabled hidden>Elige</option>

			<?php foreach ($this->Clase as $V ) { ?>
				<option value="<?= $V ?>"> <?= $V ?> </option>						
			
			<?php  } ?>
		</select> 
		<br>
		
	<input type="submit" value="Continuar" >
	
	</form>

</body>
</html>