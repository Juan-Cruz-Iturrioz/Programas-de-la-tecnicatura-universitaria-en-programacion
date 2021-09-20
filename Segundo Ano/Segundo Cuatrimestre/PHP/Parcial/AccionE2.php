<?php


if (isset($_POST['marcas']) && isset($_POST['provincias'])) {

	$marcas = array(1=>"Ford", 2=>"Renault", 5=>"Ferrari");
	$provincia =  array(1 => "CABA", 7=>"Cordoba" , 2=> "Misiones");
	$detalles =  array(20 => "Aire", 30 => "ABS", 33 => "Gas" );

	$autos =  array();
	$autos[25] = array( "marca" => 1, "prov" => 2, "det" => array(20) );
	$autos[4] = array( "marca" => 2, "prov" => 1, "det" => array(20,30) );
	$autos[14] = array( "marca" => 1, "prov" => 2, "det" => array(30) );
	$autos[1] = array( "marca" => 5, "prov" => 7, "det" => array(20,30,33) );
	
	$marca = $_POST['marcas']; 
	$provin = $_POST['provincias'];


	switch (true) {
		case ($marca == 0 && $provin == 0):
			
			foreach ($marcas as $I => $Q) {
				foreach ($provincia as $Y => $R) {
				Buscador($I,$Y);
				}				
			}

			break;
		
		case ($marca == 0 && $provin != 0):
			
			foreach ($marcas as $I => $Q) {				
				Buscador($I,$provin);
								
			}

			break;

		case ($marca != 0 && $provin == 0):
			
			foreach ($provincia as $Y => $Q) {				
				Buscador($marca,$Y);
								
			}

			break;

		default:
			Buscador($marca, $provin);
			break;
	}

}

function Buscador ($M , $P) {

	global $marcas , $provincia , $detalles, $autos;
	
	$AUX = "H";

	foreach ($autos as $columns ) {
		
		if ( ($columns["marca"] == $M) && ($columns["prov"] == $P  ) ) {
			
			echo "{$AUX}ay un auto el marca {$marcas[$M]} , provincia {$provincia[$P]} y con estas caracteristicas " ; 

			$AUX = "(";

			foreach ($columns["det"] as $I) {
			echo $AUX , $detalles[$I];
			$AUX = ", ";
			}
			echo ")<br/> <br/>";
			$AUX = "Tambien h";

		}
	
	}
	

}

echo " <a href='E2.php'>Volver</a>" ;


/*foreach ($autos as $columns ) {
	echo "marca =";
	echo $columns["marca"] . "<br/> prov = ";
	echo $columns["prov"] . "<br/> det = (";

		foreach ($columns["det"] as $I) {
			echo $detalles[$I] . ", ";
		}
	
	echo ") <br/> <br/> <br/>";
}*/

?>