<!DOCTYPE html>
<html lang="es">
<head>
	<title>TP de Juan Cruz Iturrioz.net</title>
<style>

	body{ 
  		font-size: 150%;
	} 

	#Andreu , #Berto , #letras_elegida_2 , #Whatsapp ,#Boton{
		font-size: 80%;
	}

	#Image_Pregunta_2 {	
		display: none;
		padding: 10px;
  		width: 300px;
	}

	#letras_elegida_1 , #letras_elegida_2{
		visibility: hidden;
		position: relative;
		left: 20px;
	}
	input.letras { 
		position: relative;
		top: 20px; left: 22px;}
	
	#Pregunta_1_Puntos , #Pregunta_2_Puntos, #Pregunta_3_Puntos, #Pregunta_4_Puntos, #Pregunta_5_Puntos, #Pregunta_6_Puntos{
		text-align: right;
		width:700px;
	}
	

	#Link_Pregunta_1, #Link_Pregunta_3, #Link_Pregunta_4, #Link_Pregunta_5, #Link_Pregunta_6{
		display: none;
	}

	img#Image_1{
		
  		padding: 10px;
  		width: 450px;
	}


</style>

</head>
<body>

<h1 id="Titulo">Cuestionario sobre Nadie Sabe Nada</h1>

<form method="Get">	
	
	<ol>
		<li>
		<div id="Pregunta_1"> 
			
				<p>En la presentación del programa, cual es el orden de los presentadores?</p> 
					<img src="Image_1.jpg" id="Image_1" alt="Presentadores">
					<br>
				
					<label>Berto Romero</label>

						<select id="Berto" onclick='Funcion_Pregunta_1("Berto");' >
  							<option selected disabled hidden>Elige</option>
  							<!--Esto (selected disabled hidden) lo saqué de 
  								https://stackoverflow.com/questions/3518002/how-can-i-set-the-default-value-for-an-html-select-element -->
  							<option value="1" >Primero</option>
 							<option value="2" >Segundo</option>					
						</select>
				

					<label>&nbsp;&nbsp;Andreu Buenafuente</label>
					
						<select id="Andreu" onclick='Funcion_Pregunta_1("Andreu");' >
  							<option selected disabled hidden>Elige</option>  						  							
  							<option value="1" > Primero </option>
 							<option value="2" > Segundo </option>						
						</select>
					
						<p id="Pregunta_1_Puntos">10 Puntos</p>
					<a href="https://www.youtube.com/watch?v=_bnnxn6ZqH8" id="Link_Pregunta_1">Link de verificacion</a>	
				
			</div>	
		</li>

		<!--                          Javascript                          -->	

		<script>
				"use strict"

				function Funcion_Pregunta_1(Nombre_1){
				
					var Nombre_2

					if (Nombre_1 == "Andreu") {
				
						Nombre_2 = "Berto"
					}
				
					else{
				
						Nombre_2 = "Andreu"
					}


					if(document.getElementById(Nombre_1).selectedIndex == 1){
					
						document.getElementById(Nombre_2).selectedIndex = 2;
					
						/*Esto (.selectedIndex) lo saqué de 
						https://www.w3schools.com/jsref/prop_select_selectedindex.asp#:~:text=The%20selectedIndex%20property%20sets%20or,all%20options%20(if%20any).*/
					}

					if(document.getElementById(Nombre_1).selectedIndex == 2){
					
						document.getElementById(Nombre_2).selectedIndex = 1;
					}
				
				};
				
		</script>

		<!--                          Fin del Javascript                          -->
		
		<!--                          Final de la Pregunta 1                          -->
			
		<li>	 
			<div id="Pregunta_2">
			
				<p> El nombre del programa, que letra cambio durante la cuarentena de COVID-19? </p>
					 <br> 
							
						<?php 
					$VEC = array("N","a","d","i","e &nbsp;&nbsp;","S","a","b","e &nbsp;&nbsp;","N","a","d","a");
					
						for ($i=1; $i < count($VEC)+1; $i++) { ?>
						
							<input type="radio" name="Nombre_en_COVID_19" value="letra_<?=$i?>" id="letra_<?=$i?>" class ="letras" onclick="Funcion_Pregunta_2();">
							<label for="letra_<?=$i?>" id="Lugar_<?=$i?>"><?=$VEC[$i-1]?></label>

						<?php }	?>
				
					<br> <br> <br>

					<label id="letras_elegida_1">Ingese una letra &nbsp;</label> 
					<select name="letras_elegida" id="letras_elegida_2">
						<option selected disabled hidden>Elige</option>
											
						<?php 
					
							for ($i='A'; $i <'Z' ; $i++) { ?>
						
								<option value="<?=$i?>"> <?=$i?> </option>
						
							<?php } ?> 
								<option value="<?=$i?>"> <?=$i?> </option>
					
					</select>

					<p id="Pregunta_2_Puntos">10 Puntos</p>
					<img src="Image_2.png" id="Image_Pregunta_2" alt="Nombre en COVID 19">

					<!--                          Javascript                          -->

					<script>
						"use strict"
						function Funcion_Pregunta_2(){

							document.getElementById("letras_elegida_1").style.visibility = "visible";

							/* Esto ( .style.visibility  ) lo saqué de 
							https://www.w3schools.com/jsref/prop_style_visibility.asp */

							document.getElementById("letras_elegida_2").style.visibility = "visible";
						};	
					</script>

					<!--                          Fin de Javascript                          -->
			
					<br> <br>
			</div>
		</li>
	
		<!--                          Final de la Pregunta 2                          -->

		<li>
			<div id="Pregunta_3"> 
			
				<label id="Camellos">En la historia del "Camellos por Whatsapp", cuando estaba al final?</label> 
					<select name="Camellos" id="Whatsapp">
						<option selected disabled hidden>Elige</option>
							
							<?php $VEC = array(45,35,20); 
					
								for ($i= 0; $i < count($VEC) ; $i++) { ?>
						
									<option value="<?=$VEC[$i]?>"> <?=$VEC[$i]?> </option>
						
								<?php } ?>
					</select>
					<br> <br> 
					<p id="Pregunta_3_Puntos">10 Puntos</p>
					<a href="https://www.youtube.com/watch?v=s51gRUv_qOo" id="Link_Pregunta_3">Link de verificacion</a>
			
			</div>
		</li>

		<!--                          Final de la Pregunta 3                          -->
		
		<li>
			<div id="Pregunta_4">
			
			<p>Un dia en el programa conocimos a un geólogo, que cosas dijo?</p>
			<br>

			<?php $VEC = array("Por qué crees que la gente no le interesan","Ando detrás de hacerme de una piedad de riñón","Me escucha un geólogo me pega","Levanta una roca la huele y chupa","Con la geólogo que es diertida"); 
					/*falsa,true,true,falsa,true*/
					$Boolean;
						for ($i= 1; $i < count($VEC)+1 ; $i++) { 
							if($i == 2 || $i == 3 || $i == 5)
								$Boolean = "true";
							else
								$Boolean = "falsa";
							?>
							
							<input type="checkbox" name="Geólogo" id="dijo_<?=$i?>" value="<?=$Boolean?>" >
							<label for="dijo_<?=$i?>" id="Geólog_<?=$i?>" > <?=$VEC[$i-1]?> </label>
							<br>
						<?php } ?>

					<p id="Pregunta_4_Puntos">10 Puntos</p>
					<a href="https://www.youtube.com/watch?v=p1WQw-xfJ2A" id="Link_Pregunta_4">Link de verificacion</a>
				<br> 
			
			</div>
		</li>
		<!--                          Final de la Pregunta 4                          -->
		<li>
			<div id="Pregunta_5">
			
			<p>Un dia en el programa subió un cantante de ópera al escenario, de que nacionalidad tiene/s?</p>
				<br>
					<?php $VEC = array("Argentino","Italiano","Español","Chileno"); 
					/*true,true,falsa,falsa*/
					$Boolean;
						
						for ($i= 1; $i < count($VEC)+1 ; $i++) { 
					
							if($i == 1 || $i == 2)
								$Boolean = "True";
							else
								$Boolean = "Falsa";
							?>
							
							<input type="checkbox" name="Opera" id="Nacionalidad_<?=$i?>" value="<?=$Boolean?>">
							<label for="Nacionalidad_<?=$i?>" id="Opera_<?=$i?>"> <?=$VEC[$i-1]?> </label>
							<br>
						<?php } ?>
					
					<p id="Pregunta_5_Puntos">10 Puntos</p>
					<a href="https://www.youtube.com/watch?v=ep1zh3-jW2Q&t=175s" id="Link_Pregunta_5">Link de verificacion</a>
				<br> 			
			</div>
		</li>
		<!--                          Final de la Pregunta 5                          -->
		<li>	
			<div id="Pregunta_6">
			
			<p id="PUN_6">Cuál fue la pregunta que comienzo la "Crisis de la urna" ?</p>
	
				<?php $VEC = array(" Vbaca es con V o con B?","Ustedes creen que se puedan pelear?","En Teatro Lola Membrives debería haber 4 Garcías cala 100 personas"); 
					/*true,falsa,falsa*/
					$Boolean;
						for ($i= 1; $i < count($VEC)+1 ; $i++) { 
							if($i == 1)
								$Boolean = "True";
							else
								$Boolean = "Falsa";

							?>
							
							
							<input type="radio" name="Crisis" id="Preguntas_<?=$i?>" value="<?=$Boolean?>">
							<label for="Preguntas_<?=$i?>" id="Crisis_<?=$i?>"> <?=$VEC[$i-1]?> </label>
							<br>
					<?php } ?>

					<p id="Pregunta_6_Puntos">10 Puntos</p>
					<a href="https://www.youtube.com/watch?v=ugZNSGkk3ys" id="Link_Pregunta_6">Link de verificacion</a>		
			</div>
		</li>

		<!--                          Final de la Pregunta 6                          -->
	
	</ol>
		
		<!--                          Javascript para los Resutado                          -->
		
		<script>
			
			"use strict"
			function Resutado_Pregunta_1 (){
				var Resutado = 0;
				var Orden = document.getElementById("Andreu").value;

				if (Orden == 1) {					
					document.getElementById("Andreu").style.color = "#32CD32";
					document.getElementById("Berto").style.color = "#32CD32";
					document.getElementById("Pregunta_1").style.color = "#32CD32";
					document.getElementById("Pregunta_1_Puntos").innerHTML = 10 + "/10 Puntos";
					Resutado = 10;
				}
				
				else { 
					document.getElementById("Andreu").style.color = "red";
					document.getElementById("Berto").style.color = "red";
					document.getElementById("Pregunta_1").style.color = "red";
					document.getElementById("Pregunta_1_Puntos").innerHTML ="0/10 Puntos";
				}
			
			return Resutado;
			
			};

			/*--------------------- fin de Resutado_Pregunta_1-----------------------*/

			function Resutado_Pregunta_2 (){
				var Resutado = 0;
				var AUX = document.getElementsByName("Nombre_en_COVID_19");
				var DATO = -1;
				var NUM = 0;
                	

                	for (var i = 1; i < AUX.length+1; i++) { 

           				if (AUX[i-1].checked) {
           					DATO = AUX[i-1].value;
           					NUM = i;
           				}

           				else{
           					document.getElementById("Lugar_" + i).style.color = "black"
           				}

           			}
						
       				if (DATO != -1 ) {
       					
       					if (DATO == "letra_8" ) {
       			
       						Resutado += 4;
       						document.getElementById("Lugar_" + NUM).style.color = "#32CD32";

       							if (document.getElementById("letras_elegida_2").value == "L") {
       								Resutado += 6;
									document.getElementById("letras_elegida_2").style.color = "#32CD32";
									document.getElementById("Pregunta_2").style.color = "#32CD32"; 
       							}
       							
       							else {
       								document.getElementById("letras_elegida_2").style.color = "red";
       								document.getElementById("Pregunta_2").style.color = "red"; 
       							}
       					}
       				
       					else {
       						document.getElementById("letras_elegida_2").style.color = "red";
       						document.getElementById("Pregunta_2").style.color = "red"; 
       						document.getElementById("Lugar_" + NUM).style.color = "red";
       					}
       				
       				}

       				else{
       					document.getElementById("Pregunta_2").style.color = "red";
       					document.getElementById("letras_elegida_2").style.color = "red";	
       					
       					for (var i = 1; i < AUX.length+1; i++) {
       						document.getElementById("Lugar_" + i).style.color = "red"
       					}
       				}

       			document.getElementById("Pregunta_2_Puntos").innerHTML = Resutado + "/10 Puntos";
       			      	                    	
				return Resutado;
				};

			/*--------------------- fin de Resutado_Pregunta_2-----------------------*/

			function Resutado_Pregunta_3 (){
				
				var Resutado = 0;
				var DATO = document.getElementById("Whatsapp").value;
					
				if (DATO == 45) {
					document.getElementById("Whatsapp").style.color = "#32CD32";
					document.getElementById("Pregunta_3").style.color = "#32CD32";
					Resutado += 10 ;
				}
				
				if (DATO == 20) {
					document.getElementById("Whatsapp").style.color = "#FFD700";
					document.getElementById("Pregunta_3").style.color = "#FFD700";
					Resutado += 5;
				}

				if (Resutado == 0) {
					document.getElementById("Whatsapp").style.color = "red";
					document.getElementById("Pregunta_3").style.color = "red";
				}

				document.getElementById("Pregunta_3_Puntos").innerHTML = Resutado + "/10 Puntos";

				return Resutado;
			}

			/*--------------------- fin de Resutado_Pregunta_3-----------------------*/

			function Resutado_Pregunta_4 (){
				var Resutado = 0;
				var AUX = document.getElementsByName("Geólogo");
				var True = 0;
				var Falsa = 0;

					for (var i = 1; i < AUX.length+1; i++) { 


           				if (AUX[i-1].checked) {
           					
           					if (AUX[i-1].value == "true") {
           						True++;
           						document.getElementById("Geólog_" + i  ).style.color = "#32CD32";
           					}
           					else{
           						Falsa++;
           						document.getElementById("Geólog_" + i  ).style.color = "red";
           					}
           				}
           				else {
           					document.getElementById("Geólog_" + i  ).style.color = "black";
           				}

           				
           			}

           			if (True == 3) {
           				Resutado = 1;
           			}

           			Resutado += True*3 - Falsa*4;

           			if (Resutado < 0) {
           				Resutado = 0;
           			
           			}


           			if (True == 0 && Falsa == 0) {
           				for (var i = 1; i < AUX.length+1; i++) {
           				
           					document.getElementById("Geólog_" + i  ).style.color = "red";
           				}
           			}

           			if (Resutado == 10) {
           				document.getElementById("Pregunta_4").style.color = "#32CD32";
           			}
           			else{
           				document.getElementById("Pregunta_4").style.color = "red";
           			}

           		document.getElementById("Pregunta_4_Puntos").innerHTML = Resutado + "/10 Puntos";
				return Resutado;
			}

			/*--------------------- fin de Resutado_Pregunta_4-----------------------*/

			function Resutado_Pregunta_5 (){
				
				var Resutado = 0;
				var AUX = document.getElementsByName("Opera");
				var True = 0;
				var Falsa = 0;

					for (var i = 1; i < AUX.length+1; i++) { 

           				if (AUX[i-1].checked) {
           					
           					if (AUX[i-1].value == "True") {
           						True++;
           						document.getElementById("Opera_" + i  ).style.color = "#32CD32";
           					}
           					else{
           						Falsa++;
           						document.getElementById("Opera_" + i  ).style.color = "red";
           					}
           				}
           				else {
           					document.getElementById("Opera_" + i  ).style.color = "black";
           				}

           				
           			}

           			if (True == 2) {
           				Resutado = 2;
           			}

           			Resutado += True*4 - Falsa*4;

           			if (Resutado < 0) {
           				Resutado = 0;
           			
           			}


           			if (True == 0 && Falsa == 0) {
           				for (var i = 1; i < AUX.length+1; i++) {
           				
           					document.getElementById("Opera_" + i  ).style.color = "red";
           				}

           			}

           			if (Resutado == 10) {
           				document.getElementById("Pregunta_5").style.color = "#32CD32";
           			}
           			else{
           				document.getElementById("Pregunta_5").style.color = "red";
           			}

           		document.getElementById("Pregunta_5_Puntos").innerHTML = Resutado + "/10 Puntos";
				return Resutado;
			}

			/*--------------------- fin de Resutado_Pregunta_5-----------------------*/

			function Resutado_Pregunta_6 (){
				
				var Resutado = 0;
				var AUX = document.getElementsByName("Crisis");
				var V = "Falsa";
					for (var i = 1; i < AUX.length+1; i++) { 

           				if (AUX[i-1].checked) {
           					V = "True";
           					if (AUX[i-1].value == "True") {
           						Resutado = 10;
           						document.getElementById("Crisis_" + i  ).style.color = "#32CD32";
           					}
           					else{
           						document.getElementById("Crisis_" + i  ).style.color = "red";
           					}
           				}
						else{
           						document.getElementById("Crisis_" + i  ).style.color = "black";
           					}
           				
           			}

           			if (V == "Falsa") {
           				for (var i = 1; i < AUX.length+1; i++) { 
           					document.getElementById("Crisis_" + i  ).style.color = "red";
           				}
           			}

           			if (Resutado == 10) {
           				document.getElementById("Pregunta_6").style.color = "#32CD32";
           			}
           			else{
           				document.getElementById("Pregunta_6").style.color = "red";
           			}

           		document.getElementById("Pregunta_6_Puntos").innerHTML = Resutado + "/10 Puntos";
				return Resutado;
			}

			/*--------------------- fin de Resutado_Pregunta_6-----------------------*/

			function DIOS(){
				/*Dios sugon nietzsche es la idea de un cosa que todo el mundo toma como una verdad absoluta
				Este video "habla" de esto https://www.youtube.com/watch?v=2X9bxRwULiY */
				var MAX = 10*6;
				var Puntos = 0;

				Puntos += Resutado_Pregunta_1();
				
				Puntos += Resutado_Pregunta_2();
				
				Puntos += Resutado_Pregunta_3();

				Puntos += Resutado_Pregunta_4();
				
				Puntos += Resutado_Pregunta_5();

				Puntos += Resutado_Pregunta_6();
				
				if (Puntos == MAX) {
					document.getElementById("Link_Pregunta_1").style.display = "block";
					document.getElementById("Image_Pregunta_2").style.display = "block";
					document.getElementById("Link_Pregunta_3").style.display = "block";
					document.getElementById("Link_Pregunta_4").style.display = "block";
					document.getElementById("Link_Pregunta_5").style.display = "block";
					document.getElementById("Link_Pregunta_6").style.display = "block";
				}


				var AUX = (Puntos*100)/MAX ; 
				document.getElementById("Resutado").innerHTML = "Tu Resutado "+ Puntos + "/" + MAX + " con un porcentaje de asiento del %" + AUX.toPrecision(4);

				/* Esto ( toPrecision() ) lo saqué de 
				https://www.w3schools.com/jsref/jsref_toprecision.asp */
			}


			</script>

			<!--                          Final del Javascript para los Resutado                          -->

			<P id="Resutado"></P>
	
	<input type="button" value="Enviar" id="Boton" onclick="DIOS();">
</form>

</body>
</html>