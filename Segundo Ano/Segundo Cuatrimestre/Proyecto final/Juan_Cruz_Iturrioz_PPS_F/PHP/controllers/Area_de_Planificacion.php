<!DOCTYPE html>
<html>
<head>
	<title>Área de Planificación</title>
	<link rel="stylesheet" type="text/css" href="../CSS/Buttons.css">
</head>
<body>

<?php

$host  = $_SERVER['HTTP_HOST'];
$uri   = rtrim(dirname($_SERVER['PHP_SELF']), '/\\');
$extra = 'Altas.php';
?>

<div class="buttons">
	<a href="<?= "http://$host$uri/$extra"?>" class="btn red"  > Altas de viajes</a>

	<?php $extra = 'Bajas.php'?>
	<a href="<?= "http://$host$uri/$extra"?>" class="btn red" > Bajas de viajes</a>

	<?php $extra = 'Modificaciones_P1.php'?>
	<a href="<?= "http://$host$uri/$extra"?>" class="btn red" > Modificaciones de viajes</a>

</div>

</body>
</html>