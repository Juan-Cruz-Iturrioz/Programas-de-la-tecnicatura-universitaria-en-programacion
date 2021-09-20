<!DOCTYPE html>
<html>
<head>
	<title><?= $this->Title ?></title>

	<?php 
	$uri   = rtrim(dirname($_SERVER['PHP_SELF'],2), '/\\');
	$uri   .="/CSS/Table.css";
	?>

	<link rel="stylesheet" type="text/css" href="<?= $uri ?>">

</head>
<body>
	<h1>Listado de Pasajeros</h1>

	<table>
		<tr><th>id de pasajero</th> <th>Nombre completo</th> <th>DNI</th> </tr> 
		<?php foreach ($this->PAS as $V) { ?>
		<tr> <td><?= $V['id_pasajero']?></td>  
			<td><?= $V['nombre_completo']?></td> 
			<td><?= $V['DNI']?></td> 
		</tr>
		<?php }?>
	</table>

</body>
</html>