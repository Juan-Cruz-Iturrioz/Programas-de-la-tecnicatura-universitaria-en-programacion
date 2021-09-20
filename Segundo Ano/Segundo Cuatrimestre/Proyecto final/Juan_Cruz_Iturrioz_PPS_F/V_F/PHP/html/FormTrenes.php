<!DOCTYPE html>
<html>
<head>
	<title>FromTrenes</title>
</head>
<body>
	 <h1> <?=$this->ORI?>---<?=$this->DES?>---<?=$this->FECHA?>---<?=$this->HE?>---<?=$this->HL?> </h1> 
	<h2>Select Trenes</h2>

	<form action="" method="post">
		<label for ="ID"> ID Trenes: </label>

		<select name = "ID" id = "ID">
			<option selected disabled hidden>Elige</option>

			<?php foreach ($this->VIA as $V ) { ?>
				<option value="<?= $V ?>"> <?= $V ?> </option>						
			
			<?php  } ?>
		</select> 
		
	<input type="hidden" name="Data" id="Data" value="<?=$this->ORI?>::<?=$this->DES?>::<?=$this->FECHA?>::<?=$this->HE?>::<?=$this->HL?>">

	<input type="submit" name="buscar">
	</form>

</body>
</html>