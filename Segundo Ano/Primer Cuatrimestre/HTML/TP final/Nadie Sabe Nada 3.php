<!DOCTYPE html>
<html lang="es">
<head>
	<title>TP final de Juan Cruz Iturrioz.net</title>
<style type="text/css">
	

	#oculto {		
		visibility : hidden;
	}

	/*#letras_elegida_1 , #letras_elegida_2{
		visibility:  collapse;
		position: relative;
		left: 20px;
	}*/
	input.letras { 
		position: relative;
		top: 20px; left: 18px;}

	input#letras{ 
		position: relative;
		top: 20px; left: 18px;}


</style>

</head>
<body>

<h1 id="Titulo">Cuestionario sobre Nadie Sabe Nada</h1>
<form>	
	<ol id="PUNS">
		<li id="PUN 1">En la presentación del programa cual es el orden de los presentadores?
			
				<br>
				<br>
				<label for="Andreu Buenafuente">Andreu Buenafuente</label>
					
					<select name="Andreu Buenafuente" id="Andreu" onclick='FUN_PUN_1("Andreu");' >
  						<option value="1" >Primero</option>
 						<option value="2" >Segundo</option>
						<option selected="true"></option>
					</select>

				<label for="Berto Romero">Berto Romero</label>

					<select name="Berto Romero" id="Berto" onclick='FUN_PUN_1("Berto");' value = "">
  						<option value="1" >Primero</option>
 						<option value="2" >Segundo</option>
 						<option selected="true"></option>
					</select>

			
			
			<script type="text/javascript">
				"use strict"

				function FUN_PUN_1(Nombre_1){
				
				var Nombre_2

				if (Nombre_1 == "Andreu") {
				
					Nombre_2 = "Berto"
				}
				else{
				
					Nombre_2 = "Andreu"
				}


				if(document.getElementById(Nombre_1).selectedIndex == 0){
					
					document.getElementById(Nombre_2).selectedIndex = 1;
				}

				if(document.getElementById(Nombre_1).selectedIndex == 1){
					
					document.getElementById(Nombre_2).selectedIndex = 0;
				}
				
				};
				
				
			</script>
		</li>
		<br>
		<li id="PUN 2">Que letra cambio durante la cuarentena de COVID-19 de su nombre del programa, por cual ? 
			
				<br> </br>
				

				<input type="radio" name="Nombre en COVID-19" value="letra_1" id="letras" onclick="FUN_PUN2();">
				<label for="letra_1">N</label>
				
				<input type="radio" name="Nombre en COVID-19" value="letra_2" id="letras" onclick="FUN_PUN2();">
				<label for="letra_2">a</label>
				
				<input type="radio" name="Nombre en COVID-19" value="letra_3" id="letras" onclick="FUN_PUN2();">
				<label for="letra_3">d</label>
				
				<input type="radio" name="Nombre en COVID-19" value="letra_4" id="letras" onclick="FUN_PUN2();">
				<label for="letra_4">i</label>
				
				<input type="radio" name="Nombre en COVID-19" value="letra_5" id="letras" onclick="FUN_PUN2();">
				<label for="letra_5">e</label>

				<input type="radio" name="Nombre en COVID-19" value="letra_6" id="letras" onclick="FUN_PUN2();">
				<label for="letra_6">s</label>

				<input type="radio" name="Nombre en COVID-19" value="letra_7" id="letras" onclick="FUN_PUN2();">
				<label for="letra_7">a</label>

				<input type="radio" name="Nombre en COVID-19" value="letra_8" id="letras" onclick="FUN_PUN2();">
				<label for="letra_8">b</label>

				<input type="radio" name="Nombre en COVID-19" value="letra_9" id="letras" onclick="FUN_PUN2();">
				<label for="letra_9">e</label>

				<input type="radio" name="Nombre en COVID-19" value="letra_10" id="letras" onclick="FUN_PUN2();">
				<label for="letra_10"> n</label>

				<input type="radio" name="Nombre en COVID-19" value="letra_11" id="letras" onclick="FUN_PUN2();">
				<label for="letra_11">a</label>

				<input type="radio" name="Nombre en COVID-19" value="letra_12" id="letras" onclick="FUN_PUN2();">
				<label for="letra_12">d</label>

				<input type="radio" name="Nombre en COVID-19" value="letra_13" id="letras" onclick="FUN_PUN2();">
				<label for="letra_13">a</label>
				
				<br> </br>
				<label id="letras_elegida_1">ingese una letra  </label> 
				<select name="letras_elegida" id="letras_elegida_1">
					<?php

				</select>
				
				<script type="text/javascript">
					
					function FUN_PUN2 (){

						document.getElementById("letras_elegida_1").style.visibility = "visible";
						document.getElementById("letras_elegida_2").style.visibility = "visible";
					};

					
					
				</script>
					

		</li>

	</ol>
	<input type="submit">
</form>
</body>
</html>