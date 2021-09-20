<?php 



if(isset( $_POST['empleados'] ) ){
	
	$empleado_id = $_POST['empleados'];
	
	if( is_numeric($empleado_id) ) die("error 1");

		/*$cn = mysqli_connect("localhost","root", "" , "empresa");

		$res = mysqli_query( $cn , 'SELECT MAX(empleados.empleado_id) as Max FROM empleados');

		echo mysqli_error($cn);

		while ( $fila = mysqli_fetch_assoc($res) ){
			echo $fila['Max'];
		}*/
	//if( range(1, high))
}


?>