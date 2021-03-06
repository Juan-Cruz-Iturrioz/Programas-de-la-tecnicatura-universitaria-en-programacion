<!DOCTYPE html>
<html>
<head>
	<title>Boletos</title>

  <?php 
  $uri   = rtrim(dirname($_SERVER['PHP_SELF'],2), '/\\');
  $uri   .="/CSS/Train_Ticket.css";
  ?>

  <link rel="stylesheet" type="text/css" href="<?= $uri ?>">

</head>
<body>

 
<div  class="main-content">
  <div class="ticket">
    <div class="ticket__main">
      <div class="header">Trenes del Nilo</div>
      
      <div class="info passenger">
        
        <div class="info__item">Pasajero</div>
        <div class="info__detail"><?= $this->P_NOM ?></div>

      </div>

      <div class="info departure">
        <div class="info__item">Salir</div>
        <div class="info__detail"><?= $this->ORI ?></div>
      </div>

      <div class="info arrival">
        <div class="info__item">Llegar</div>
        <div class="info__detail"><?= $this->DES ?></div>
      </div>

      <div class="info arrival">
        <div class="info__item">Precio</div>
        <div class="info__detail"><?= $this->PRECIO ?></div>
      </div>
      
      <div class="info date">
        <div class="info__item">Dia</div>
        <div class="info__detail"><?= $this->FEC ?></div>
      </div>

      <div class="info time">
        <div class="info__item">Embarcacion</div>
        <div class="info__detail"><?= $this->HE ?></div>
      </div>
      
      <div class="info time">
        <div class="info__item">Llegada</div>
        <div class="info__detail"><?= $this->HL ?></div>
      </div>

      <br>

      <div class="info departure">
        <div class="info__item">Clase</div>
        <div class="info__detail"><?= $this->CLA ?></div>
      </div>

      <div class="info arrival">
        <div class="info__item">Plaza</div>
        <div class="info__detail"><?= $this->PLA ?></div>
      </div>

      <div class="info carriage">
        <div class="info__item">Vagon</div>
        <div class="info__detail"><?= $this->VAGON ?></div>
      </div>
      
      <div class="info seat">
        <div class="info__item">Asiento</div>
        <div class="info__detail"><?= $this->ASIENTO ?></div>
      </div>
       
    </div>
    
  
  </div>
</div>

</body>
</html>