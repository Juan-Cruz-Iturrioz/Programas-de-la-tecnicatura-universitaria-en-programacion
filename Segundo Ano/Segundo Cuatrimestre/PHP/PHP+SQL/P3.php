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

	if (isset($_POST['hoy'])) {
		
		mysqli_query( $cn , "INSERT INTO adelantos (empleado_id, fecha, monto)
									 VALUES ($eid, NOW(), $monto) ");
	}
	else{

		if (!isset($_POST['dia'])) die("error 7");
		if (!ctype_digit($_POST['dia'])) die("error 8"); 
		if ($_POST['dia'] < 1 || $_POST['dia'] > 31) die("error 9");
		$dia = $_POST['dia'];

		if (!isset($_POST['mes'])) die("error 10");
		if (!ctype_digit($_POST['mes'])) die("error 11"); 
		if ($_POST['mes'] < 1 || $_POST['mes'] > 12) die("error 12");
		$mes = $_POST['mes'];

		if (!isset($_POST['anio'])) die("error 13");
		if (!ctype_digit($_POST['anio'])) die("error 14"); 
		if ($_POST['anio'] < ( date("Y")-1 ) || $_POST['anio'] > date("Y") ) die("error 15");
		$anio = $_POST['anio'];

		if (!checkdate($mes, $dia, $anio)) die("error 16");
			
		mysqli_query( $cn , "INSERT INTO adelantos (empleado_id, fecha, monto)
									 VALUES ($eid, '$anio-$mes-$dia', $monto) ");
	}
	
	
}

?>

<!DOCTYPE html>
<html lang="es">
<head>
	<title>P3</title>
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

	<br/>

	<label>Fecha: hoy</label>
	<input type="checkbox" name="hoy" value="1">

	<label for="d">Dia:</label>
	<input type="number" name="dia" id="d" min="1" max="31">

	<label for="m">Mes:</label>
	<input type="number" name="mes" id="m" min="1" max="12">

	<label for="a">Año:</label>
	<input type="number" name="anio" id="a" min="<?= date("Y")-1?> max = <?= date("Y")?>">

	<br/> <br/>

	<input type="submit" value="Crear" >

</form>
	
	


</body> 















