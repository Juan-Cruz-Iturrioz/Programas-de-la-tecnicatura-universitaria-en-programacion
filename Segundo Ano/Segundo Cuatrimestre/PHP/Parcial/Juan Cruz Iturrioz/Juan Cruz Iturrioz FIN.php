<?php

$provincias = array(3=>"Córdoba", 9=>"Catamarca", 1=>"Misiones"); //tengo 3 provincias
$cargos = array(1=>"Gobernador", 2=>"Senador");

$personas = array();
$personas[] = array("provincia"=>3, "cargo"=>1, "nombre"=>"Juan Perez"); //estos son los 3 gobernadores
$personas[] = array("provincia"=>1, "cargo"=>1, "nombre"=>"Maria Gomez");
$personas[] = array("provincia"=>9, "cargo"=>1, "nombre"=>"Lola Garcia");

$personas[] = array("provincia"=>3, "cargo"=>2, "nombre"=>"Veronica"); //y ahora los 2 senadores de cada provincia
$personas[] = array("provincia"=>3, "cargo"=>2, "nombre"=>"Pepe");

$personas[] = array("provincia"=>9, "cargo"=>2, "nombre"=>"Nancy");
$personas[] = array("provincia"=>9, "cargo"=>2, "nombre"=>"Martin");

$personas[] = array("provincia"=>1, "cargo"=>2, "nombre"=>"Ana");
$personas[] = array("provincia"=>1, "cargo"=>2, "nombre"=>"Sebastian");

?>



<!DOCTYPE html>
<html lang="es">
<head>
	<title>Juan Cruz Iturrioz</title>

	<style>
		table, th, td {
  			border: 1px solid black;
		}
	</style>
</head>
<body>

<?php if( !( isset($_POST['Provincia']) ) && !(isset($_POST['Cargo'])) ) { ?>

<h1>Elegir una provincia</h1>

<form action="" method="post">
	
	<select name="Provincia">
		<option selected disabled hidden>Elige</option>
		<?php
			foreach ($provincias as  $I => $value) { ?>
			
				<option value="<?= $I ?>"> <?= $value ?> </option>

			<?php }?>
	</select>

<br/>

	<input type="submit" value="Buscar">
</form>

<?php } 
elseif (isset($_POST['Provincia']) && !(isset($_POST['Cargo'])) ) { ?>

	<h1>Elegir una Cargo</h1>

	<form action="" method="post">
	
	<input type="hidden" name="Provincia2" value="<?= $_POST['Provincia'] ?> ">
	
	<select name="Cargo"  >
		<option selected disabled hidden>Elige</option>
		<?php
			foreach ($cargos as  $I => $value) { ?>
			
				<option value="<?= $I ?>"> <?= $value ?> </option>

			<?php }?>
	</select>

	<br/>

	<input type="submit" value="Buscar">
	
	</form>

	<br/>
	
	<a href="Juan Cruz Iturrioz FIN.php">Retroceder</a>

<?php } 
elseif (isset($_POST['Provincia2']) && isset($_POST['Cargo'])) { 
	
	$Prov = (int)$_POST['Provincia2'] ;
	$Car = $_POST['Cargo'];
	?> 
	
	<table>
		<tr>
			<th>Nombre:</th>		
			<th>Cargo:</th>
			<th>Provincia:</th>
		</tr>
	

	<?php
	foreach ($personas as $columns ) {

		if ( ($columns["provincia"] == $Prov) && ($columns["cargo"] == $Car) ) {
			
			echo "<tr>";
				echo "<td>". $columns["nombre"] . "</td>";
				echo "<td>". $cargos[$Car] . "</td>";
				echo "<td>". $provincias[$Prov] . "</td>";
			echo "</tr>";
		}
	
	}
	?>
	</table>
	
	
	
	<br/>
 	<a href="Juan Cruz Iturrioz FIN.php">Retroceder</a>

<?php } ?>


</body>