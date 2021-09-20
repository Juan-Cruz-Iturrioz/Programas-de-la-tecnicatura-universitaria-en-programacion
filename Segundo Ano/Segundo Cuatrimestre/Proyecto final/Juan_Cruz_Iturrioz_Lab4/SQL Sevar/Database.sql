------ Paso 1 -------

SET DATEFORMAT ymd
CREATE DATABASE Trenes_del_Nilo

------ Paso 2 -------

use Trenes_del_Nilo

create table Trenes (
Id_tren int not null primary key,
)

create table Boletería (

Estacion varchar(5) not NULL,
Jornada_laboral time(0) not null,
PRIMARY KEY (Estacion),

check ( Estacion = 'Cairo' or  Estacion = 'Luxor'),

)

create table Vagones(

Numero_vagon int not null primary key,
Clase_vagones varchar (7) not null,
Plaza varchar (10) not null,


check (Numero_vagon BETWEEN 1 and 8), 
check (Clase_vagones = 'Turista' or Clase_vagones = 'Pulman' ), 
check (Plaza = 'Fumador' or Plaza = 'No_fumador'),

)

create table Pasajeros(

id_pasajero int IDENTITY(1,1) primary key,
nombre_completo varchar (255) not null,
DNI int not null unique,
)

create table Asientos(

Numero_de_asiento int not null,
Tipo_asiento varchar(10) not null,
Numero_vagon int not null FOREIGN KEY REFERENCES Vagones(Numero_vagon),

CONSTRAINT PK_Asientos PRIMARY KEY (Numero_de_asiento,Numero_vagon),

check (Numero_de_asiento BETWEEN 1 and 60), 
check (Numero_vagon BETWEEN 1 and 8),
check (Tipo_asiento = 'Ventanilla' or Tipo_asiento = 'Pasillo'),

)

create table Viajes(

Id_viaje int IDENTITY(1,1) primary key,
Id_tren int not null FOREIGN KEY REFERENCES Trenes(id_tren),

Origen varchar (5),
Destino varchar (5),

Fecha_de_viaje date,
Horario_de_embarcacion time(0),
Horario_de_llegada  time(0),

check ( Destino = 'Cairo' or  Destino = 'Luxor'),
check ( Origen = 'Cairo' or  Origen = 'Luxor'),

)

create table Boletos (

Id_boleto int IDENTITY(1,1) primary key,
Id_viaje int not null FOREIGN KEY REFERENCES Viajes(id_viaje),
Id_tren int not null FOREIGN KEY REFERENCES Trenes(id_tren),

Numero_de_asiento int not null ,
Numero_vagon int not null ,

Id_pasajero int not null FOREIGN KEY REFERENCES Pasajeros(id_pasajero),
Precio money not null,

CONSTRAINT FK_Asientos FOREIGN KEY(Numero_de_asiento,Numero_vagon) REFERENCES Asientos(Numero_de_asiento,Numero_vagon),

)