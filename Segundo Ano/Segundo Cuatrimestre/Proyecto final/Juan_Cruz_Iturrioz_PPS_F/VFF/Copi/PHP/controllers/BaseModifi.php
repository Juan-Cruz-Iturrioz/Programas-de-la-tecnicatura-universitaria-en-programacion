<?php
/*
require '../fw/FW.php';
require '../controllers/BasaSelect.php';

require '../models/ABM.php';
require '../models/Viajes.php';
require '../models/Boleterias.php';
require '../views/FormEstacion.php';
require '../views/FormViajes.php';
require '../views/FormFecha.php';
require '../views/FormHoras.php';

require '../views/FormTrenes.php';
require '../views/SelectTime.php';
*/
class BaseModifi {

	public function ALLForm(){

		if(count($_POST) > 1){
		
			if( isset($_POST['Origen']) and isset($_POST['Destino']) ){
	
				$ORI = $_POST['Origen'];
				$DES = $_POST['Destino'];
		
				$AUX = new BasaSelect();
				$AUX->verificacion_Origen_y_Destino($ORI,$DES);

				$AUX = new FormFecha();
				$AUX->Setdatos_2($ORI,$DES);
				$AUX->renden();
			}

			if(isset($_POST['Fecha']) and isset($_POST['Data'])){
		
				$Fecha = $_POST['Fecha'];
				$AUX = $_POST['Data'];
		
				if(strlen($AUX) <> 12 or substr_count($AUX,'::') <> 1){
					die("Error 9 modificacion del hidden");
				}

				list($ORI,$DES) = explode("::", $AUX);
		
				$AUX = new ABM();
				$AUX->verificacion_Fecha($ORI,$DES,$Fecha);
		
				$AUX = new SelectTime();
				$AUX->Setdatos($ORI,$DES,$Fecha);
				$AUX->AutoTitle();
				$AUX->renden();
			}

			if(isset($_POST['Horario_de_embarcacion']) and isset($_POST['Horario_de_llegada']) 
			and isset($_POST['Data'])){
		
				$EMB = $_POST['Horario_de_embarcacion'];
				$LLE = $_POST['Horario_de_llegada'];
				$AUX = $_POST['Data'];

				if(strlen($AUX) <> 22 or substr_count($AUX,'::') <> 2){
					die("Error 4 modificacion del select");
				}

				list($ORI,$DES,$FECHA) = explode("::", $AUX);
		
				$AUX = new ABM();
				$AUX->verificacion_Horarios($ORI,$DES,$FECHA,$EMB,$LLE);
				
		
				if(isset($_COOKIE['id_viaje'])){

					$ID = $_COOKIE['id_viaje'];
					$AUX = new Trenes();
					$AUX = $AUX->GetId_tren_2($ORI,$DES,$FECHA,$EMB,$LLE,$ID);
				}
				else{
					
					$AUX = new Trenes();
					$AUX = $AUX->GetId_tren_1($ORI,$DES,$FECHA,$EMB,$LLE);
				}
				
				$F_Tren = new FormTrenes();
				$F_Tren->Setdatos($ORI,$DES,$FECHA,$EMB,$LLE,$AUX);
				$F_Tren->AutoTitle();
				$F_Tren->renden();

			}

			if(isset($_POST['ID']) and isset($_POST['Data'])){
		
				$ID = $_POST['ID'];
				$Data = $_POST['Data'];
		
				if(strlen($Data) <> 36 or substr_count($Data,'::') <> 4){
					die("Error 4 modificacion del select");
				}

				list($ORI,$DES,$FECHA,$EMB,$LLE) = explode("::", $Data);

				$ABM = new Trenes();
				$AUX = $ABM->verificacion_Trene_1($ORI,$DES,$FECHA,$EMB,$LLE,$ID);

				if(isset($_COOKIE['id_viaje']) ){
					
					$ID_V = $_COOKIE['id_viaje'];

					$AUX = new Trenes();
					$AUX->verificacion_Trene_2($ORI,$DES,$FECHA,$EMB,$LLE,$ID,$ID_V);
				}
				else{
					$AUX = new Trenes();
					$ABM->verificacion_Trene_1($ORI,$DES,$FECHA,$EMB,$LLE,$ID);
				}


				$AUX = ($Data . "||" . $ID);
				return $AUX;
			}

		}

		else{
		$Est = new Boleterias ();
		$Est = $Est->getEstacion();
		
		$F_est = new FormEstacion();
		$F_est->Setdatos_2($Est);
		$F_est->AutoTitle();
		$F_est->renden();
		}
	}
}



?>