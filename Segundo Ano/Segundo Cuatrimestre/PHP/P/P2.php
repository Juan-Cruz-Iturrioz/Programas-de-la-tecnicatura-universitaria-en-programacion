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
</head>
<body>

<h2>Centered Pagination</h2>

<?php  	
  	$AUX = $_GET["Vagon"];

  	if($AUX < 1 or $AUX > 8){
		die(" Error N modificacion del pagination");
	}

  	$host  = $_SERVER['HTTP_HOST'];
	$uri   = rtrim(dirname($_SERVER['PHP_SELF']), '/\\');
	$extra = 'P2.php';
	
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

</body>
</html>