<!DOCTYPE html>
<html>
<head>

	<style>
	.center {
  		text-align: center;
	}

	.pagination {
  		display: inline-block;
	}

	.pagination a {
  		color: black;
  		float: left;
  		padding: 8px 16px;
  		text-decoration: none;
  		transition: background-color .3s;
  		border: 1px solid #ddd;
  		margin: 0 4px;
	}

	.pagination a.active {

  		background-color: #00CCFF;
 		color: white;
  		border: 1px solid #00CCFF;
	}

	.pagination a:hover:not(.active) {background-color: #ddd;}
	
	</style>
	
	<title>SelectBoleto</title>

</head>
<body>

	<?php  	
  	$AUX = $_GET["Vagon"];

  	if($AUX < 1 or $AUX > 8){
		die(" Error N modificacion del pagination");
	}

  	$host  = $_SERVER['HTTP_HOST'];
	$uri   = rtrim(dirname($_SERVER['PHP_SELF']), '/\\');
	$extra = 'Disposicion.php';
	
	$laquo = $AUX-1;	
	$raquo = $AUX+1;

	if ($laquo == 0) {
		$laquo = 8;
	}

	if ($raquo == 9) {
		$raquo = 1;
	}

	?>
	<div class="center">
	  <div class="pagination">
  		<a href="<?= "http://$host$uri/$extra?Vagon=$laquo"?>" >&laquo;</a>
  
		<?php
		for($I = 1; $I <= 8 ; $I++){
		?>

		<a href= 
			<?php 
			echo "http://$host$uri/$extra?Vagon=$I" ;

			if($AUX == $I){
				echo ' class="active" ';
			}

			?>
		> <?= $I ?> </a>
	
		<?php }	?>

 	 <a href="<?= "http://$host$uri/$extra?Vagon=$raquo"?>">&raquo;</a>
 
  		</div>
	</div>

	<h1>SelectBoleto</h1>

	<div style=' <?php 
			if($this->Clase == 'Pulman'){
				echo "color:#FF6633;";
			}
			else {
				echo "color:#CC3300;";
			}
		?>'> Pulman = <?= ($this->CAN[0] + $this->CAN[1] + $this->CAN[2] + $this->CAN[3])?> </div>

	<div style=' <?php 
			if($this->Clase == 'Turista'){
				echo "color:#FF6633;";
			}
			else {
				echo "color:#CC3300";
			}
		?>'> Turista = <?= ($this->CAN[4] + $this->CAN[5] + $this->CAN[6] + $this->CAN[7])?> </div>

	<div> Total = <?= array_sum($this->CAN) ?></div>

	<h3 style='line-height:50px; 
		<?php 
			if($this->Bool){
				echo " color:#FF6633;";
			}
		?> 
		'> Vagon <?= $AUX . "&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp" . $this->Clase . "---". $this->Plaza ?>
		 
	</h3>
	
	<table>
	<?php
	
	$I = 0;
	
	for ($J = 1; $J <= 15; $J++){ ?>
		
		<tr>

		<?php for($K = 1; $K <= 5; $K++){ 
			
			if($K <> 3){ ?>
				<td>
					 <div style='border:1px solid black; width:50px; height:50px; text-align:center; line-height:50px;
					 	 
					 	<?php
					 		if ( $this->ASI[$I]['Venta'] and $this->Bool) {
					 			echo " background-color:#FF6633;";
					 		}
					 		elseif ($this->ASI[$I]['Venta']) {
					 			echo " background-color:#CC3300;";
					 		}
					 		else{
					 			echo " background-color:#00FF00;";
					 		}
					 	?>

					 '>
					 	<?= $this->ASI[$I++]['Numero_de_asiento'] ?>
					 	
					 </div> 
				</td>
			<?php } 
			
			else { ?>
				
				<td>
					<div style= 'margin-right:50px;'> </div>
				</td>
			
			<?php } ?>
		
		<?php } ?>
				
		</tr>
	<?php } ?>
	
	</table>
	<br>
	<br>
	<form action="" method="post">

		<label for="Asiento">Ingresar uno asiento</label>
		<input type="number" name="Asiento" id="Asiento" min="1" max ="60">

		<input type="submit" name="buscar" >

	</form>
</body>
</html>