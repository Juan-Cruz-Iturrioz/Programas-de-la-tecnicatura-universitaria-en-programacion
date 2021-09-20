
<!DOCTYPE html>
<html lang="es">
<head>
	<title>E3</title>
</head>

<body>

<?php

$Tipos = array(1=>"Pesos a Dolares = Tasa de cambio", 2=>"Dolares a Pesos = Tasa de cambio", 3=>"Pesos Y Tasa de cambio = Dolares", 4=>"Dolares Y Tasa de cambio = Pesos");

?>

<h1>Selecciona un formula</h1>

<form action="AccionE3.php" id="myform" method="post">
	<label>Formula</label> 

	<select name="tipos" id="tipo" onchange="Resutado();">
		<option selected disabled hidden>Elige</option>

		<?php

			foreach ($Tipos as  $I => $value) { ?>
			
				<option value="<?= $I ?>"> <?= $value ?> </option>

			<?php }?>
	</select>

<br/>
<br id="Br" />

<script>
"use strict"
	function Resutado() {
		var NUM = document.getElementById("tipo").value;

					
		switch  (NUM) {
			
			case '1':
				Remove();
				Create("Pesos","Dolares");
			break;

			case '2':
				Remove();
				Create("Dolares","Pesos");
			break;


			case '3':
				Remove();
				Create("Pesos","Tasa");
			break;

			case '4':
				Remove();
				Create("Dolares","Tasa");
			break;


			default:
			//break;
		}

	}

	function Remove (){

		if (document.getElementById("Pes") != null) {
			var AUX = document.getElementById("Pes");
			AUX.parentNode.removeChild(AUX);
			AUX = document.getElementById("L_Pes");
			AUX.parentNode.removeChild(AUX); 
		}

		if (document.getElementById("Dol") != null) {
			var AUX = document.getElementById("Dol");
			AUX.parentNode.removeChild(AUX);
			AUX = document.getElementById("L_Dol");
			AUX.parentNode.removeChild(AUX); 
		}

		if (document.getElementById("Tas") != null) {
			var AUX = document.getElementById("Tas");
			AUX.parentNode.removeChild(AUX);
			AUX = document.getElementById("L_Tas");
			AUX.parentNode.removeChild(AUX); 
		}
	}


	function Create (X,Y){

		switch (X){

			case 'Pesos':
			var AUX = document.createElement("INPUT");
  				AUX.setAttribute("type", "number");
  				AUX.setAttribute("name", "Pesos");
  				AUX.setAttribute("id", "Pes");
  				AUX.setAttribute("min","0");
  				document.getElementById("myform").insertBefore(AUX,document.getElementById("Br"));

  				AUX = document.createElement("LABEL");
  				var AUXX = document.createTextNode("Pesos");
  				AUX.setAttribute("for","Pes");
  				AUX.setAttribute("id","L_Pes");
  				AUX.appendChild(AUXX);

  				document.getElementById("myform").insertBefore(AUX,document.getElementById("Pes"));

			break;

			case 'Dolares':
				
				var AUX = document.createElement("INPUT");
  				AUX.setAttribute("type", "number");
  				AUX.setAttribute("name", "Dolares");
  				AUX.setAttribute("id", "Dol");
  				AUX.setAttribute("min","0");
  				document.getElementById("myform").insertBefore(AUX,document.getElementById("Br"));

  				AUX = document.createElement("LABEL");
  				var AUXX = document.createTextNode("Dolares");
  				AUX.setAttribute("for","Dol");
  				AUX.setAttribute("id","L_Dol");
  				AUX.appendChild(AUXX);

  				document.getElementById("myform").insertBefore(AUX,document.getElementById("Dol"));

			break;

			case 'Tasa':
				
				var AUX = document.createElement("INPUT");
  				AUX.setAttribute("type", "number");
  				AUX.setAttribute("name", "Tasa");
  				AUX.setAttribute("id", "Tas");
  				AUX.setAttribute("min","0");
  				document.getElementById("myform").insertBefore(AUX,document.getElementById("Br"));

  				AUX = document.createElement("LABEL");
  				var AUXX = document.createTextNode("Tasa de cambio");
  				AUX.setAttribute("for","Tas");
  				AUX.setAttribute("id","L_Tas");
  				AUX.appendChild(AUXX);

  				document.getElementById("myform").insertBefore(AUX,document.getElementById("Tas"));

			break;

			default:
		}


		switch (Y){

			case 'Pesos':
			var AUX = document.createElement("INPUT");
  				AUX.setAttribute("type", "number");
  				AUX.setAttribute("name", "Pesos");
  				AUX.setAttribute("id", "Pes");
  				AUX.setAttribute("min","0");
  				document.getElementById("myform").insertBefore(AUX,document.getElementById("Br"));

  				AUX = document.createElement("LABEL");
  				var AUXX = document.createTextNode("Pesos");
  				AUX.setAttribute("for","Pes");
  				AUX.setAttribute("id","L_Pes");
  				AUX.appendChild(AUXX);

  				document.getElementById("myform").insertBefore(AUX,document.getElementById("Pes"));

			break;

			case 'Dolares':
				
				var AUX = document.createElement("INPUT");
  				AUX.setAttribute("type", "number");
  				AUX.setAttribute("name", "Dolares");
  				AUX.setAttribute("id", "Dol");
  				AUX.setAttribute("min","0");
  				document.getElementById("myform").insertBefore(AUX,document.getElementById("Br"));

  				AUX = document.createElement("LABEL");
  				var AUXX = document.createTextNode("Dolares");
  				AUX.setAttribute("for","Dol");
  				AUX.setAttribute("id","L_Dol");
  				AUX.appendChild(AUXX);

  				document.getElementById("myform").insertBefore(AUX,document.getElementById("Dol"));

			break;

			case 'Tasa':
				
				var AUX = document.createElement("INPUT");
  				AUX.setAttribute("type", "number");
  				AUX.setAttribute("name", "Tasa");
  				AUX.setAttribute("id", "Tas");
  				AUX.setAttribute("min","0");
  				document.getElementById("myform").insertBefore(AUX,document.getElementById("Br"));

  				AUX = document.createElement("LABEL");
  				var AUXX = document.createTextNode("Tasa de cambio");
  				AUX.setAttribute("for","Tas");
  				AUX.setAttribute("id","L_Tas");
  				AUX.appendChild(AUXX);

  				document.getElementById("myform").insertBefore(AUX,document.getElementById("Tas"));

			break;

			default:
		}


	}


</script>


<input type="submit" value="Calcular" id="Boton">

</form>



</body>
</html>
