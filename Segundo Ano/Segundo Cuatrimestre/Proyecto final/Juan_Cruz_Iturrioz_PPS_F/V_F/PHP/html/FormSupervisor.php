<!DOCTYPE html>
<html>
<head>
	<title>FormSupervisor</title>
</head>
<body>
	 <h1>FormSupervisor</h1> 

	<form action="" method="post">
		

		<input type="hidden" name="Id_viaje" id="Id_viaje" value="<?= $this->ID ?>">

		<label for ="Clase_vagones"> Clase vagones: </label>

		<select name = "Clase_vagones" id = "Clase_vagones">
			<option selected disabled hidden>Elige</option>

			<?php foreach ($this->Clase as $V ) { ?>
				<option value="<?= $V ?>"> <?= $V ?> </option>						
			
			<?php  } ?>
		</select> 
		
	<input type="submit" name="Buscar" value="Buscar">
	
	</form>

</body>
</html>