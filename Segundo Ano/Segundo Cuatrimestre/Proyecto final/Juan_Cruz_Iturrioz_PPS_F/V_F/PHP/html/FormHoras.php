<!DOCTYPE html>
<html>
<head>
	<title><?= $this->Title ?></title>
</head>
<body>
	<h1> <?= $this->ORI ?>---<?= $this->DES  ?>---<?=$this->FEC?> </h1>  
	<h2>Select Hora </h2>

	<form action="" method="post">

		<label for ="Horario_de_embarcacion"> Horario de embarcacion: </label>

		<select name = "Horario_de_embarcacion" id = "Horario_de_embarcacion" onclick="myFunction(1)">
			<option selected disabled hidden>Elige</option>

			<?php foreach ($this->Viajes as $V ) { ?>
				<option value="<?= $V['Horario_de_embarcacion']->format('H:i')?>"><?= $V['Horario_de_embarcacion']->format('H:i') ?></option>
			<?php  } ?>
		</select> 

		<label for ="Horario_de_llegada"> horario de llegada: </label>

		<select name = "Horario_de_llegada" id = "Horario_de_llegada" onclick="myFunction(2)" >
			<option selected disabled hidden>Elige</option>

			<?php foreach ($this->Viajes as $V ) { ?>
				<option value="<?= $V['Horario_de_llegada']->format('H:i') ?>"><?= $V['Horario_de_llegada']->format('H:i') ?></option>
			<?php  } ?>
		</select> 

	<input type="hidden" name="Data" id="Data" value="<?=$this->ORI?>::<?=$this->DES?>::<?= $this->FEC?>">

	<input type="submit" name="buscar">
	</form>

	<script>
				"use strict"

				function myFunction(NUM){
				

					if(NUM == 1){

					var x = document.getElementById("Horario_de_embarcacion").selectedIndex;
					document.getElementById("Horario_de_llegada").selectedIndex = x;

					}
					else{

					var x = document.getElementById("Horario_de_llegada").selectedIndex;
					document.getElementById("Horario_de_embarcacion").selectedIndex = x;
					
					}

					
				};
				
		</script>
</body>
</html>