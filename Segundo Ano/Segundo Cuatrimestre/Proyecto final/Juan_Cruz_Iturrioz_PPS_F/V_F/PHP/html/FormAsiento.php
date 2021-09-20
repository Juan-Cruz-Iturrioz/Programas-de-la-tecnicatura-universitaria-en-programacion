<!DOCTYPE html>
<html>
<head>
	<title><?= $this->Title ?></title>
</head>
<body>
	 <h1>FormAsiento</h1> 

	<form action="" method="post">		
		<label for ="Tipo_asiento"> Tipo asiento: </label>

		<select name = "Tipo_asiento" id = "Tipo_asiento">
			<option selected disabled hidden>Elige</option>

			<?php foreach ($this->Tipos as $V ) { ?>
				<option value="<?= $V ?>"> <?= $V ?> </option>						
			
			<?php  } ?>
		</select> 
		
		<label for ="Vagones"> Número de vagones: </label>

		<select name = "Vagones" id = "Vagones">
			<option selected disabled hidden>Elige</option>

			<?php foreach ($this->Vag as $V ) { ?>
				<option value="<?= $V ?>"> <?= $V ?> </option>						
			
			<?php  } ?>
		</select>

	<input type="submit" name="Buscar" value="Buscar">
	
	</form>

</body>
</html>