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
	
	<title>SelectAsiento</title>

</head>
<body>

	<?php  	
  	$AUX = $_GET["Vagon"];

  	if($AUX < 1 or $AUX > 8){
		die(" Error N modificacion del pagination");
	}

  	$host  = $_SERVER['HTTP_HOST'];
	$uri   = rtrim(dirname($_SERVER['PHP_SELF']), '/\\');
	$extra = 'Boletos.php';
	
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

	<h1>SelectAsiento</h1>

	<h2 style='line-height:50px; 
		<?php 
			if($this->Vagon_Boll){
				echo " color:#4CAF50;";
			}
		?> 
		'> Vagon <?= $AUX . "&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp" . $this->Clase . "---". $this->Plaza?>
		 
	</h2>
	
	<table>
	<?php
	
	$I = 0;
	
	for ($J = 1; $J <= 15; $J++){ ?>
		
		<tr>

		<?php for($K = 1; $K <= 5; $K++){ 
			
			if($K <> 3){ ?>
				<td>
					 <div style='border:1px solid black; width:50px; height:50px; text-align:center; line-height:50px; <?php
					 
					 		if ( $this->ASI[$I]['Venta']) {
					 			echo " background-color:#CC3300;";
					 		}
					 		elseif ($this->ASI[$I]['Tipo_asiento'] == $this->Tipo) {
					 			echo " background-color:#0099FF;";
					 		}
					 		else{
					 			echo " background-color:#00FF00;";
					 		}
					 	?>'> <?= $this->ASI[$I++]['Numero_de_asiento'] ?> </div> 
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