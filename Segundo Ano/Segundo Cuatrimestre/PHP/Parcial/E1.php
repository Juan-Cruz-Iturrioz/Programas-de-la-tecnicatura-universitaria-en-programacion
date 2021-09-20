
<!DOCTYPE html>
<html lang="es">
<head>
	<title>E1</title>
</head>
<body>

<?php

$marcas = array(1=>"Ford", 2=>"Renault", 5=>"Ferrari");
$provincia =  array(1 => "CABA", 7=>"Cordoba" , 2=> "Misiones");


/*foreach ($marcas as  $I => $value) {
	echo "{$value} {$I}   ";
}*/


/*foreach ($autos as $columns ) {
	echo "marca =";
	echo $columns["marca"] . "<br/> prov = ";
	echo $columns["prov"] . "<br/> det = (";

		foreach ($columns["det"] as $I) {
			echo $detalles[$I] . ", ";
		}
	
	echo ") <br/> <br/> <br/>";
}*/


?>

<h1>Selecciona una marca y provincia</h1>

<form action="AccionE1.php" method="post">
	<label id="marcas">Marcas </label> 

	<select name="marcas" id="sel_marcas" >
		<option selected disabled hidden>Elige</option>

		<?php

			foreach ($marcas as  $I => $value) { ?>
			
				<option value="<?= $I ?>"> <?= $value ?> </option>

			<?php }?>
	</select>

<br/>

<label id="provincias">Provincias </label> 

	<select name="provincias" id="sel_provincias" >
		<option selected disabled hidden>Elige</option>

		<?php

			foreach ($provincia as  $I => $value) { ?>
			
				<option value="<?= $I ?>"> <?= $value ?> </option>

			<?php }?>
	</select>
	
</select>

<br/>

<input type="submit" value="Buscar" >

</form>



</body>
</html>
