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
 
	<h1>Seleccione del Trenes</h1>

	<form action="" method="post">
		<label for ="ID"> Número de Trenes: </label>

		<select name = "ID" id = "ID">
			<option selected disabled hidden>Elige</option>

			<?php foreach ($this->VIA as $V ) { ?>
				<option value="<?= $V ?>"> <?= $V ?> </option>						
			
			<?php  } ?>
		</select> 
		
	<input type="hidden" name="Data" id="Data" value="<?=$this->ORI?>::<?=$this->DES?>::<?=$this->FECHA?>::<?=$this->HE?>::<?=$this->HL?>">

	<br>

	<input type="submit" value="Continuar" >
	</form>

</body>
</html>