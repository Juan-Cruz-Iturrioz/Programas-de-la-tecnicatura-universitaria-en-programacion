<!DOCTYPE html>
<html>
<head>
	<title>FromFecha</title>
</head>
<body>
	 <h1> <?= $this->ORI ?>---<?= $this->DES  ?> </h1> 
	<h2>Select Fecha</h2>

	<form action="" method="post">
		<label for ="Fecha"> Fecha: </label>

		<select name = "Fecha" id = "Fecha">
			<option selected disabled hidden>Elige</option>

			<?php foreach ($this->VIA as $V ) { ?>
				<option value="<?=$this->ORI?>::<?=$this->DES?>::<?= $V ?>"> <?= $V ?> </option>						
			
			<?php  } ?>
		</select> 
	<input type="submit" name="buscar">
	</form>

</body>
</html>