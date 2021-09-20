<!DOCTYPE html>
<html>
<head>
	<title>FormVagones</title>
</head>
<body>
	 <h1>FormVagones</h1> 

	<form action="" method="post">
		
		<label for ="Clase_vagones"> Clase vagones: </label>

		<select name = "Clase_vagones" id = "Clase_vagones">
			<option selected disabled hidden>Elige</option>

			<?php foreach ($this->Clase as $V ) { ?>
				<option value="<?= $V ?>"> <?= $V ?> </option>						
			
			<?php  } ?>
		</select> 
		
		<label for ="Plaza"> Plaza: </label>

		<select name = "Plaza" id = "Plaza">
			<option selected disabled hidden>Elige</option>

			<?php foreach ($this->Plaza as $V ) { ?>
				<option value="<?= $V ?>"> <?= $V ?> </option>						
			
			<?php  } ?>
		</select>

	<input type="submit" name="Buscar" value="Buscar">
	

	<p> El Precio del Turista es $<?=  $this->Precio['Turista']  ?> </p>
	<p> El Precio del Pulmanes $<?= $this->Precio['Pulman']  ?> </p>

	</form>

</body>
</html>