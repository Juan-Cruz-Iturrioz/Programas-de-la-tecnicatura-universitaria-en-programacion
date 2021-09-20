use Trenes_del_Nilo

exec SetVagones
select * from Vagones

exec SetAsiento
select * from Asientos



insert into Trenes (Id_tren) values (1)
insert into Trenes (Id_tren) values (2)
insert into Trenes (Id_tren) values (3)
insert into Trenes (Id_tren) values (4)
insert into Trenes (Id_tren) values (5)

select * from Trenes



insert into Viajes (Id_tren,Destino,Origen,Fecha_de_viaje,Horario_de_embarcacion,Horario_de_llegada) values (1,'Cairo','Luxor',GETDATE(),'14:30','16:30')
insert into Viajes (Id_tren,Destino,Origen,Fecha_de_viaje,Horario_de_embarcacion,Horario_de_llegada) values (2,'Cairo','Luxor',GETDATE(),'13:30','15:30')
insert into Viajes (Id_tren,Destino,Origen,Fecha_de_viaje,Horario_de_embarcacion,Horario_de_llegada) values (3,'Luxor','Cairo',GETDATE(),'13:30','15:30')
insert into Viajes (Id_tren,Destino,Origen,Fecha_de_viaje,Horario_de_embarcacion,Horario_de_llegada) values (4,'Luxor','Cairo',GETDATE(),'10:30','12:30')
insert into Viajes (Id_tren,Destino,Origen,Fecha_de_viaje,Horario_de_embarcacion,Horario_de_llegada) values (5,'Luxor','Cairo',GETDATE(),'15:30','17:30')
insert into Viajes (Id_tren,Destino,Origen,Fecha_de_viaje,Horario_de_embarcacion,Horario_de_llegada) values (1,'Cairo','Luxor',GETDATE()+1,'14:30','16:30')
insert into Viajes (Id_tren,Destino,Origen,Fecha_de_viaje,Horario_de_embarcacion,Horario_de_llegada) values (1,'Cairo','Luxor',GETDATE()+2,'14:30','16:30')

select * from Viajes 

select * from Boletos