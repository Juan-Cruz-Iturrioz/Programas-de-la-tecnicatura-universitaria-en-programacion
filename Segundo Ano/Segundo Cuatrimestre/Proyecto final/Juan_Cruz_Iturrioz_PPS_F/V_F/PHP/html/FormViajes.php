<!DOCTYPE html>
<html>
<head>
	<title>FromViajes</title>
</head>
<body>
	
	<?php if(is_null($this->Viajes) and is_null($this->Datos) ) {?>
		<h1>Viaje borrado</h1>
	
	<?php }else {?>
		
		<h1>Lista De Datos</h1>

		<?php if(is_array($this->Viajes)) {?>
			<table>
				<tr><th>Id tren</th> <th>Origen</th> <th>Destino</th> <th>Fecha de viaje</th> <th>Horario de embarcacion</th> <th>Horario de llegada</th> <th>Id viaje</th> </tr> 
				<?php foreach ($this->Viajes as $V) { ?>
				<tr> 
					<td><?= $V['Id_tren']?></td>  
					<td><?= $V['Origen']?></td> 
					<td><?= $V['Destino']?></td>  
					<td><?= $V['Fecha_de_viaje']->format('d/m/y') ?> </td>
					<td><?= $V['Horario_de_embarcacion']->format('H:i') ?> </td>
					<td><?= $V['Horario_de_llegada']->format('H:i') ?> </td>
					<td><?= $V['Id_viaje']?></td>
				</tr>
				<?php }?>
			</table>
		<?php }?>

		<?php if(is_array($this->Datos)) {?>
			<table>
				<tr> <th>Id tren</th> <th>Origen</th> <th>Destino</th> <th>Fecha de viaje</th> <th>Horario de embarcacion</th> <th>Horario de llegada</th> </tr> 
				<?php foreach ($this->Datos as $V) { ?>
				<tr> 
					<td><?= $V['Id_tren']?></td> 
					<td><?= $V['Origen']?></td> 
					<td><?= $V['Destino']?></td>  
					<td><?= $V['Fecha_de_viaje'] ?> </td>
					<td><?= $V['Horario_de_embarcacion'] ?> </td>
					<td><?= $V['Horario_de_llegada'] ?> </td>
				</tr>
				<?php }?>
			</table>
		<?php }?>

		<?php if($this->From ){?>
			<form action="" method="post">	
				<?php if(is_array($this->Viajes)) {?>
					<input type="hidden" name="Id_viaje" id="Id_viaje" value="<?=$this->Viajes[0]['Id_viaje']?>">
				<?php }?>

				<?php if(is_array($this->Datos)) {?>
					<input type="hidden" name="Datos" id="Datos" value="<?=$this->Datos[0]['Origen']?>::<?=$this->Datos[0]['Destino']?>::<?=$this->Datos[0]['Fecha_de_viaje']?>::<?=$this->Datos[0]['Horario_de_embarcacion']?>::<?=$this->Datos[0]['Horario_de_llegada']?>||<?=$this->Datos[0]['Id_tren']?>">
				<?php }?>

			<input type="submit" name="Buscar" value="Buscar">
		<?php }?>
	<?php }?>
</body>
</html>