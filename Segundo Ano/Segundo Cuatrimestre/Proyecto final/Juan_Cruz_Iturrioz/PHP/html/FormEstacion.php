<!DOCTYPE html>
<html>
<head>
	<title>FromEstacion</title>
</head>
<body>
	<h1>Select Estacion</h1>

	<form action="" method="post">
		<label for ="Origen"> Origen: </label>

		<select name = "Origen" id = "Origen">
			<option selected disabled hidden>Elige</option>

			<?php foreach ($this->Estacion as $E ) { ?>
				<option value="<?=$E ?>"> <?= $E ?>	</option>						
			
			<?php  } ?>
		</select>
		
		<label for ="Destino"> Destino: </label>
		
		<select name = "Destino" id = "Destino">
			<option selected disabled hidden>Elige</option>

			<?php foreach ($this->Estacion as $E ) { ?>
				<option value="<?=$E ?>"> <?= $E ?>	</option>						
			
			<?php  } ?>
		</select>
		<input type="submit" name="buscar">
	</form>

</body>
</html>