<!DOCTYPE html>
<html>
<head>
	<title>Programas</title>
</head>
<body>

<?php

$host  = $_SERVER['HTTP_HOST'];
$uri   = rtrim(dirname($_SERVER['PHP_SELF']), '/\\');
$extra = 'Boleterias.php';

?>

<a href="<?= "http://$host$uri/$extra"?>"> Boleterias </a>

<br>
<br>
<br>

<?php $extra = 'Seguridad de vías.php'?>
<a href="<?= "http://$host$uri/$extra"?>"> Seguridad de vías </a>

<br>
<br>
<br>

<?php $extra = 'Supervisor del viaje.php'?>
<a href="<?= "http://$host$uri/$extra"?>"> Supervisor del viaje </a>

</body>
</html>