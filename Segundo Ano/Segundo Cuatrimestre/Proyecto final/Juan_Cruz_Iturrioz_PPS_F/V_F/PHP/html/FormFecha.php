<!DOCTYPE html>
<html>
<head>
	<title><?= $this->Title ?></title>
</head>
<body>
	 <h1> <?= $this->ORI ?>---<?= $this->DES  ?> </h1> 
	<h2>Select Fecha</h2>

	<form action="" method="post">
		<label for ="Fecha"> Fecha: </label>

		<select name = "Fecha" id = "Fecha">
			<option selected disabled hidden>Elige</option>

			<?php foreach ($this->VIA as $V ) { ?>
				<option value="<?= $V ?>"> <?= $V ?> </option>						
			
			<?php  } ?>
		</select> 
		
	<input type="hidden" name="Data" id="Data" value="<?=$this->ORI?>::<?=$this->DES?>">

	<input type="submit" name="buscar">
	</form>

</body>
</html>