use Trenes_del_Nilo

------ Paso 1 -------

exec SetVagones
select * from Vagones

------ Paso 2 -------

exec SetAsiento
select * from Asientos

------ Paso 3 -------

insert into Boleteria (Estacion,Jornada_laboral_inicio,Jornada_laboral_fin) values ('Cairo','12:00','20:00')
insert into Boleteria (Estacion,Jornada_laboral_inicio,Jornada_laboral_fin) values ('Luxor','13:00','21:00')
select * from Boleteria

------ Paso 4 -------

insert into Trenes (Id_tren) values (1)
insert into Trenes (Id_tren) values (2)

select * from Trenes

------ Forma de ver los datos de los boletos y su pasajero  -------

select * from Boletos b
left join Pasajeros p on p.id_pasajero = b.Id_pasajero