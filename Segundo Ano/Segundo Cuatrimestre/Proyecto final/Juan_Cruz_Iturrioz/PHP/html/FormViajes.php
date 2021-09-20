<!DOCTYPE html>
<html>
<head>
	<title>FromViajes</title>
</head>
<body>
	<h1>Lista Viajes</h1>

	<table>
		<tr><th>Id viaje</th> <th>Id tren</th> <th>Origen</th> <th>Destino</th> <th>Fecha de viaje</th> <th>Horario de embarcacion</th> <th>horario de llegada</th> </tr> 
		<?php foreach ($this->Viajes as $V) { ?>
		<tr> <td><?= $V['Id_viaje']?></td>  
			<td><?= $V['Id_tren']?></td> 
			<td><?= $V['Origen']?></td> 
			<td><?= $V['Destino']?></td>  
			<td><?= $V['Fecha_de_viaje']->format('Y/m/d') ?> </td>
			<td><?= $V['Horario_de_embarcacion']->format('H:i') ?> </td>
			<td><?= $V['Horario_de_llegada']->format('H:i') ?> </td>
		</tr>
		<?php }?>
	</table>

</body>
</html>