<?php

$cn = mysqli_connect("localhost","root", "" , "empresa");

if (!isset($_GET['e'])) die("error 1");
if (!ctype_digit($_GET['e'])) die("error 2");	

$aux = mysqli_query( $cn , 'SELECT MAX(empleados.empleado_id) as Max , 
								   MIN(empleados.empleado_id) as Min
							FROM empleados');

$fila = mysqli_fetch_assoc($aux);
		 
	$MIN = $fila['Min'];	 
	$MAX = $fila['Max'];
	

	if ( $_GET['e'] < $MIN || $_GET['e'] > $MAX ) die("error 3");


$empleado = $_GET['e'];

		$res = mysqli_query( $cn , "SELECT *
									FROM adelantos
									WHERE empleado_id=$empleado "
						);

		echo mysqli_error($cn)

?>



<!DOCTYPE html>
<html lang="es">
<head>
	<title>Listado de Adelantos</title>

	<style type="text/css">
		table th, table td{
			border: 1px solid black;
		}
	</style>
</head>
<body>
	<h1>Listado de Adelantos</h1>

	<table>
		
		<tr>
			<th>Id</th>
			<th>Fecha</th>
			<th>Monto</th>
		</tr>
		
		<?php  while ($fila = mysqli_fetch_assoc($res)  ) { ?>
			<tr>
				<td> <?=  $fila['adelanto_id'] ?> </td>
				<td> <?=  $fila['fecha'] ?> </td>
				<td> $ <?=  $fila['monto'] ?> </td>
			</tr>
		<?php } ?>

	</table>

	<br/> <br/>

	<a href="Listado.php">Ir al Listado</a>

</body>
</html>