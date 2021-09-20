<!DOCTYPE html>
<html>
<head>
	<title>Área de Planificación</title>
</head>
<body>

<?php

$host  = $_SERVER['HTTP_HOST'];
$uri   = rtrim(dirname($_SERVER['PHP_SELF']), '/\\');
$extra = 'Altas.php';
?>

<a href="<?= "http://$host$uri/$extra"?>"> Altas </a>

<br>
<br>
<br>

<?php $extra = 'Bajas.php'?>
<a href="<?= "http://$host$uri/$extra"?>"> Bajas </a>

<br>
<br>
<br>

<?php $extra = 'Modificaciones_P1.php'?>
<a href="<?= "http://$host$uri/$extra"?>"> Modificaciones </a>

</body>
</html>