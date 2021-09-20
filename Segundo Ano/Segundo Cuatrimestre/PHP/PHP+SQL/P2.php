<?php

if (count($_POST)>0 ) {
	
	if(!isset($_POST['empleados'])  ) die("error 1");
	if (!ctype_digit($_POST['empleados'])) die("error 2");

	$cn = mysqli_connect("localhost","root", "" , "empresa");	
	
	$aux = mysqli_query( $cn , 'SELECT MAX(empleados.empleado_id) as Max , 
										MIN(empleados.empleado_id) as Min
								
								FROM empleados');

	echo mysqli_error($cn);

	$fila = mysqli_fetch_assoc($aux);
		 
	$MIN = $fila['Min'];	 
	$MAX = $fila['Max'];
	

	if ( $_POST['empleados'] < $MIN || $_POST['empleados'] > $MAX ) die("error 3");
		
		$aux = mysqli_query( $cn , 'SELECT empleados.empleado_id 
									FROM empleados
									WHERE empleado_id = '.$_POST['empleados'].'
									LIMIT 1');

	if (mysqli_num_rows($aux) != 1) die ("error 4");

	if (!isset($_POST['monto'])) die("error 5");
	if (!is_numeric($_POST['monto'])) die("error 6");

	$eid = $_POST['empleados'];
	$monto = $_POST['monto'];

	mysqli_query( $cn , "INSERT INTO adelantos (empleado_id, fecha, monto)
									 VALUES ($eid, NOW(), $monto) ");
	
}

?>

<!DOCTYPE html>
<html lang="es">
<head>
	<title>P2</title>
</head>
<body>

<h1>Registrar nuevo adelanto</h1>
	
<form action="" method="post">
	<label> Quien: </label>

	<select name="empleados">
		
		<option selected disabled hidden>Elige</option>
		<?php

		$cn = mysqli_connect("localhost","root", "" , "empresa");

		$res = mysqli_query( $cn , 'SELECT empleados.empleado_id , empleados.nombre, cargos.descripción
							FROM empleados
							LEFT JOIN cargos on cargos.cargo_id = empleados.cargo_id'
						);

		echo mysqli_error($cn);


		while ( $fila = mysqli_fetch_assoc($res) ) { ?>

		<option value="<?= $fila['empleado_id'] ?>"> <?= "{$fila['nombre']} 
		 ({$fila['descripción']})"; ?> </option>
		
		<?php } ?>

	</select>

	<br/>

	<label>Monto: $</label>
	<input type="number" name="monto" > 

	<!--<input type="hidden" name="fecha" value="<?php echo date("Y-m-d") ?>"> -->

	<input type="submit" value="Crear" >

</form>
	
	


</body> 















