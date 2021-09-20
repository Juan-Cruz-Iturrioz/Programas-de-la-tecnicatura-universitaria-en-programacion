
create procedure SetBoletos(
@Id_viaje int,
@Id_pas int,
@PRE money,
@N_A int, 
@N_V int
)
as
begin
	declare @AUX int
	declare @Bool bit
	set @Bool = 1
	select @AUX = count(v.id_viaje) from Viajes v where v.id_viaje = @Id_viaje 

	if(@AUX = 0)
	begin
		set @bool = 0 
	end

	select @AUX = count(b.id_pasajero) from Boletos b where b.id_pasajero = @Id_pas and b.id_viaje = @Id_viaje 

	if(@AUX = 1)
	begin
		set @bool = 0
	end

	select distinct @AUX = count(b.Numero_de_asiento) from Boletos b where b.Numero_vagon = @N_V and b.Numero_de_asiento = @N_A and b.id_viaje = @Id_viaje 

	if(@AUX = 1)
	begin
		set @bool = 0
	end

	if(@bool = 1)
	begin 
		select @AUX = v.id_tren from Viajes v where v.id_viaje = @Id_viaje

		insert into Boletos (id_tren,id_viaje,id_pasajero,Precio,Numero_de_asiento,Numero_vagon) values (@AUX,@Id_viaje,@Id_pas,@PRE,@N_A,@N_V)	
	end

	
end

