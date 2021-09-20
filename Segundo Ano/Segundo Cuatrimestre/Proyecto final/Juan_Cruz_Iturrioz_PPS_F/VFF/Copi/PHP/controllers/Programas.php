<!DOCTYPE html>
<html>
<head>
	<title>Programas</title>
	<link rel="stylesheet" type="text/css" href="../CSS/Buttons.css">
</head>
<body>

<?php

$host  = $_SERVER['HTTP_HOST'];
$uri   = rtrim(dirname($_SERVER['PHP_SELF']), '/\\');
$extra = 'Boleterias.php';

?>

<div class="buttons">
	
	<a href="http://localhost:8080/Juan_Cruz_Iturrioz_PPS_F/Boleterias" class="btn red"> Boleterias </a> 

	<?php $extra = 'Area_de_Planificacion.php'?>
	<a href="<?= "http://$host$uri/$extra"?>" class="btn red" > Área de Planificación </a> 

	<?php $extra = 'Seguridad de vías.php'?>
	<a href="<?= "http://$host$uri/$extra"?>" class="btn red" > Seguridad de vías </a>

	<?php $extra = 'Supervisor del viaje.php'?>
	<a href="<?= "http://$host$uri/$extra"?>" class="btn red"> Supervisor del viaje </a>
</div>

</body>
</html>