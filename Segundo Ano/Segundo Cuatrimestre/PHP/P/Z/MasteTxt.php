<?php 
$AUX = "E:\lol\Riot Games\Data\Koikatsu\Link";
$VEN = array("\Artists","\B","\Characters","\Outfits","\W");
$path = $AUX . $VEN[2] . ".txt";

$AUX = substr_count($path,'.txt');

?>

<!DOCTYPE html>
<html>
<head>
	<title></title>
</head>
<body>
		
			<?php 
			$myfile = fopen($path, "r") or die("Unable to open file!");
			while(!feof($myfile)) {
 			 	$V = fgets($myfile);
 			 	$AUX = ((bool)substr_count($V,'https://'));
				
				if($AUX){?>

					<h4> <a href="<?= $V ?>"> <?= $V ?> </a> </h4>	
				<?php } 
				else {?>
					<h4> <?= $V ?> </h4>	
				<?php } ?>
			<?php } 
			fclose($myfile); 
			?>
			
</body>
</html>