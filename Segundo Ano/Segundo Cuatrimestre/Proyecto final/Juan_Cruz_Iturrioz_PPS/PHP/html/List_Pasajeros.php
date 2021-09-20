<!DOCTYPE html>
<html>
<head>
	<title>List Pasajeros</title>
</head>
<body>
	<h1>Lista Pasajeros</h1>

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