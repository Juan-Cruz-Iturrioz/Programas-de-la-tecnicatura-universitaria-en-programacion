<!DOCTYPE html>
<html>
<head>

</head>
<body>

<?php 
$hoy = getdate();

$hoy = $hoy['mday'].'/'.  $hoy['mon'] ;

var_dump($hoy);

?>

</body>
</html>