<?php

	$cn = mysqli_connect("localhost","root", "" , "empresa");

	if(!isset($_GET['nombre'])) die("error 1");
	if(strlen($_GET['nombre']) < 1 ) die("error 2");

	$_GET['nombre'] = substr($_GET['nombre'], 0, 20);

	$_GET['nombre'] = mysqli_escape_string($cn, $_GET['nombre']);

	$_GET['nombre'] = str_replace('%', '\%', $_GET['nombre']);

	$_GET['nombre'] = str_replace('_', '\_', $_GET['nombre']);

	$nombre = $_GET['nombre']; 

	$res = mysqli_query( $cn , "SELECT empleados.nombre, empleados.empleado_id 
								FROM empleados
								WHERE empleados.nombre LIKE '%$nombre%'");

	$resultados =mysqli_num_rows($res);

	if($resultados == 1){

		$datos = mysqli_fetch_assoc($res);
		header("Location: Lista_ad.php?e=" . $datos['empleado_id'] );
	}

?>

<!DOCTYPE html>
<html>
<head>
	<title>Resultados busqueda</title>
</head>
<body>

<?php  if($resultados > 1) { ?>
	<h1>Lista de buscadar</h1>
	<?php while ($fila = mysqli_fetch_assoc($res)  ) { ?>
		<a href="lista_ad.php?e=<?= $fila['empleado_id'] ?>"> <?= $fila['nombre'] ?> </a> 
		<br/> 
	<?php } ?>
<?php } ?>




<?php  if($resultados == 0) { ?>

<p> No existe <?=  htmlentities($_GET['nombre'])  ?> </p>

<?php }?>

<br/> <br/>

<a href="Listado.php">Volver</a>


</body>
</html>