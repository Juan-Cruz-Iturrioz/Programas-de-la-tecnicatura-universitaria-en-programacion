<?php

		$cn = mysqli_connect("localhost","root", "" , "empresa");

		$res = mysqli_query( $cn , 'SELECT empleados.nombre, cargos.descripción , empleados.empleado_id,
									SUM(adelantos.monto) AS Monto_total, 
									COUNT(adelantos.monto) AS Adelantos
									
									FROM empleados
									LEFT JOIN adelantos ON adelantos.empleado_id = empleados.empleado_id
									LEFT JOIN cargos ON cargos.cargo_id = empleados.cargo_id
									GROUP BY empleados.empleado_id');

		echo mysqli_error($cn);

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

	<br/>

	<form action="Buscador.php" method="get">
		<label for="nombre">Buscar:</label>
		<input type="text" name="nombre" id="nombre" maxlength="20">
		<input type="submit" value="Buscar">

	</form>

	<h1>Listado de Adelantos</h1>

	<table>
		<tr>
			<th>Empleado</th>
			<th>Cargo</th>
			<th>Monto total</th>
			<th>Adelantos</th>
		</tr>

		<?php  while ($fila = mysqli_fetch_assoc($res)  ) { ?>
			<tr>
				<td><a href="lista_ad.php?e=<?= $fila['empleado_id'] ?>"> <?= $fila['nombre'] ?> </a>  </td>
				<td> <?= $fila['descripción'] ?> </td>
				<td> $ <?= 0 + $fila['Monto_total'] ?> </td>
				<td> <?= $fila['Adelantos'] ?> </td>
			</tr>
		<?php } ?>

	</table>


</body>
</html>