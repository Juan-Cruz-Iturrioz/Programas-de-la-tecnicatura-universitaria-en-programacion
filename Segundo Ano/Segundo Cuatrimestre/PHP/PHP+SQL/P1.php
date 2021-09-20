<!--

<!DOCTYPE html>
<html lang="es">
<head>
	<title>P1</title>
</head>
<body>

<h1>hola</h1>

</body> 

-->

<?php

$cn = mysqli_connect("localhost","root", "" , "empresa");

$res = mysqli_query( $cn , 'SELECT nombre FROM empleados');

echo mysqli_error($cn);


while ( $fila = mysqli_fetch_assoc($res) ){
	echo $fila['nombre'] . '<br/>' ;

}
 
echo "N = ";
echo mysqli_num_rows($res);


$buscar = "";

if(isset($buscar) && ( strlen($buscar) >= 1) ){
	
	$res = mysqli_query( $cn , "SELECT nombre FROM empleados WHERE nombre LIKE '%$buscar%' ");

	//$fila = mysqli_fetch_assoc($res);

	while ( $fila = mysqli_fetch_assoc($res) ){
		echo $fila['nombre'] . '<br/>' ;

	}
}
else{
	echo "Error 404";
}









