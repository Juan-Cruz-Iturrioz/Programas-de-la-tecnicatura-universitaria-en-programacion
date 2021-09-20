<?php
/*
$data = "\All.txt";

$file = "E:\lol\Riot Games\Koikatsu\Link";

$data = $file . $data;
*/

$path = "E:\lol\Riot Games\Data";
 
// Arreglo con todos los nombres de los archivos
$files = array_diff(scandir($path), array('.', '..')); 

//var_dump($files);
$code = $_GET['codigo'];

foreach($files as $file){
    // Divides en dos el nombre de tu archivo utilizando el . 
    $data          = explode(".", $file);
    // Nombre del archivo
    $fileName      = $data[0];
    // Extensión del archivo 
    //$fileExtension = $data[1];

    if($code == $fileName){
        echo $fileName;
        // Realizamos un break para que el ciclo se interrumpa
        break;
    }
}

?>

<!DOCTYPE html>
<html>
<head>
	<title></title>
</head>
<body>
<!--
<h1>Ingrese los datos del Trene</h1>

	<form action="" method="post">
		<label for ="ID"> Número de Trenes: </label>

		<select name = "ID" id = "ID">
			<option selected disabled hidden>Elige</option>
			
			<?php 
			$myfile = fopen($data, "r") or die("Unable to open file!");
			while(!feof($myfile)) {
 			 	$V = fgets($myfile);
			
			?>

			<option value="<?= $V ?>"> <?= $V ?> </option>	
			<?php } 
			fclose($myfile); ?>
			
		</select>
-->
</body>
</html>