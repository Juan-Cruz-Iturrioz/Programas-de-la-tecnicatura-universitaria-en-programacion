<!DOCTYPE html>
<html>
<head>
	<title>Boletos</title>

	<style>
		table {
   			width: 100%;
   			border: 2px solid #000;
		}
		
		th, td {
   			width: 25%;
   			text-align: left;
   			vertical-align: top;
   			border: 1px solid #000;
   			border-collapse: collapse;
   			padding: 0.3em;
   			caption-side: bottom;
		}

		caption {
   			padding: 0.3em;
   			font-weight: bold;
  			font-style: italic;
  			border: 2px solid #000;
   			/*color: #fff;
    		background: #000;*/
		}

		th {
   			/*background: #eee;*/
		}

	</style>

</head>
<body>
	<?php 
	$B_N = 10;

	$AUX = 8 - strlen($B_N);
	$N = null;
	for($I = 0 ; $I < $AUX ; $I++){
		$N .= "0";
	}
	$N .= $B_N;
	$PRE = "2650";

	$VAG = 5;
	$ASI = 13;

	$C = "Turista";
	$Plaza = "Fumador";

	$P_NOM = "Juan Cruz Iturrioz";
	$DNI = "42831065";

	?>

	<table>

		<caption>Trenes del Nilo</caption>
		
		<tr>		
			<th>Número de boletos: <?= $N ?> </th>
			<th>Precio: $<?= $PRE ?> </th>
		</tr>	

		<tr>
			<th>Clase: <?= $C ?> </th>
			<th>Plaza: <?= $Plaza ?></th>
		</tr>

		<tr>
			<th>Numero de vagon: <?= $VAG ?> </th>		
			<th>Numero de asiento: <?= $ASI ?> </th>
		</tr>

		<tr>
			<th>Nombre de pasajero: <?= $P_NOM ?> </th>		
			<th>DNI: <?= $DNI ?> </th>
		</tr>

	</table>

</body>
</html>