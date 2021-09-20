
<?php 

if (isset($_POST['Resutado']) && isset($_POST['Number'])) {
	
	$R = $_POST['Resutado'];
	$NUM = $_POST['Number'];

	if ($R == $NUM) {
		echo "Bien";
	}
	else{
		echo "Mal";
	}

}

?>

<!DOCTYPE html>
<html lang="es">
<head>
	<title>E4</title>
</head>
<body>

<?php 

$Operador = array("+" ,"-","*");

$NUM1 = rand(1,9);
$NUM2 = rand(1,9);
$I = rand(0,2);

switch ($I) {
	case $I == 0:
		$R = $NUM1 + $NUM2;
		break;
	case $I == 1:
		$R = $NUM1 - $NUM2;
		break;
	case $I == 2:
		$R = $NUM1 * $NUM2;
		break;

	default:
		# code...
		break;
}

?>

<form method="post">
<?php
echo '<label id = "Mate"> ' . $NUM1 .$Operador[$I] . $NUM2 .' = </label>';

?>

<input type="text" name="Number">
<input type="hidden" name="Resutado" value="<?= $R ?>">
<input type="submit" value="Buscar" >

</form>

</body>
</html>
