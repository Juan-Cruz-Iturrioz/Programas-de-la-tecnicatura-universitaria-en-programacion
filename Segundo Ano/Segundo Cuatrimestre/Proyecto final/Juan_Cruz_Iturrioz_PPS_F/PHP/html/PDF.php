<!DOCTYPE html>
<html>
<head>
	<title>Boletos</title>

  <?php 
  $uri   = rtrim(dirname($_SERVER['PHP_SELF'],2), '/\\');
  $uri   .="/CSS/Train_Ticket.css";
  ?>

  <style type="text/css">
    body {
  background: #f2f2f2;
  font-family: "Questrial", sans-serif;
}

aside.context {
  text-align: center;
  color: #333;
  line-height: 1.7;
}
aside.context a {
  text-decoration: none;
  color: #333;
  padding: 3px 0;
  border-bottom: 1px dashed;
}
aside.context a:hover {
  border-bottom: 1px solid;
}
aside.context .explanation {
  max-width: 700px;
  margin: 4em auto 0;
}

footer {
  text-align: center;
  margin: 4em auto;
  width: 100%;
}
footer a {
  text-decoration: none;
  display: inline-block;
  width: 45px;
  height: 45px;
  border-radius: 50%;
  background: transparent;
  border: 1px dashed #333;
  color: #333;
  margin: 5px;
}
footer a:hover {
  background: rgba(255, 255, 255, 0.1);
}
footer a .icons {
  margin-top: 12px;
  display: inline-block;
  font-size: 20px;
}

.main-content {
  margin: 4em auto 0;
  width: 740px;
  text-transform: uppercase;
}

.ticket {
  
  grid-template-columns: auto 5px;
  background: #f3f1c9;
  border-radius: 10px;
  border: 2px solid #222;
  cursor: default;
}

.ticket__main {
  
  grid-template-columns: repeat(1, 1fr) 5px;
  grid-template-rows: repeat(2, min-content) auto;
  padding: 10px;
}

.header {
  
  grid-area: title;
  grid-column: span 7;
  grid-row: 1;
  font: 900 38px "Montserrat", sans-serif;
  padding: 5px 0 5px 20px;
  letter-spacing: 6px;
  background: #111; 
  color: #f3f1c9; 
}

.info {
  text-align: center;
  border: 3px solid;
  border-width: 3px 3px 3px 3px;
  padding: 1px;
}
.info__item {
  font: 400 13px "Questrial", sans-serif;
  letter-spacing: 0.5px;
}
.info__detail {
  font: 400 20px/1 "Jura";
  letter-spacing: 1px;
  margin: 4px 0;
}

.passenger {
  grid-column: 1/span 6;
}



.departure, .arrival {
  grid-column-start: span 1;
}

.passenger, .departure, .date {
  border-left: 3px solid;
}

.date, .time {
  grid-column-start: span 1;
}

.fineprint {
  grid-column-start: span 5;
  font-size: 14px;
  font-family: "Inconsolata";
  line-height: 1;
  margin-top: 10px;
  padding-right: 5px;
}
.fineprint p:nth-child(2) {
  margin: 4px 4px 0 0;
  padding-top: 4px;
  border-top: 1.5px dotted;
  font: 11px/1 "Inconsolata";
}

.snack {
  grid-column: 6/span 1;
  width: 65px;
  margin: 10px 10px 0 0;
  position: relative;
  background: #000;
  padding: 6px 0 2px;
  text-align: center;
  border-radius: 5px;
}
.snack svg {
  fill: #f3f1c9;
  width: 36px;
}
.snack__name {
  color: #f3f1c9;
  font-size: 12px;
}

  </style>

  <!-- <link rel="stylesheet" type="text/css" href="<?= $uri ?>"> -->

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
        <div class="info__item">Numero de tren</div>
        <div class="info__detail"><?= $this->N_T ?></div>
      </div>

      <div class="info arrival">
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