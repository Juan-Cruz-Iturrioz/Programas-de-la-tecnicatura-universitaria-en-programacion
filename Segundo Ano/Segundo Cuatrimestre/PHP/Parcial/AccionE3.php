<?php

$Tipo = $_POST['tipos'];

switch ($Tipo) {
	case $Tipo == 1:
		$Pes = $_POST['Pesos'];
		$Dol = $_POST['Dolares'];

		echo '<P> Pesos = ' . $Pes . '</p>';
		echo '<P> Dolares = ' . $Dol . '</p>';
		echo '<P> Tasa de cambio = ' . ($Pes/$Dol) . '</p>';

		break;

	case $Tipo == 2:
		$Pes = $_POST['Pesos'];
		$Dol = $_POST['Dolares'];

		echo '<P> Dolares = ' . $Dol . '</p>';
		echo '<P> Pesos = ' . $Pes . '</p>';
		echo '<P> Tasa de cambio = ' . ($Dol/$Pes) . '</p>';

		break;
	
	case $Tipo == 3:
		$Pes = $_POST['Pesos'];
		$Tas = $_POST['Tasa'];

		echo '<P> Pesos = ' . $Pes . '</p>';
		echo '<P> Tasa de cambio = ' . $Tas . '</p>';
		echo '<P> Dolares = ' . ($Pes*$Tas) . '</p>';
		break;

	case $Tipo == 4:
		$Dol = $_POST['Dolares'];
		$Tas = $_POST['Tasa'];

		echo '<P> Dolares = ' . $Dol . '</p>';
		echo '<P> Tasa de cambio = ' . $Tas . '</p>';
		echo '<P> Pesos = ' . ($Dol*$Tas) . '</p>';
		break;

	default:
		# code...
		break;
}


echo " <a href='E3.php'>Volver</a>" ;

?>

