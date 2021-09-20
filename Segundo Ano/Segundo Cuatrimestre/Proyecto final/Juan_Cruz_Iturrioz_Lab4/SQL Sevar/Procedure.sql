
------------------- Paso 1 -------------------

create procedure SetVagones as

declare @AUX as int  

select @AUX = count(v.Numero_vagon)  from Vagones v

if(@AUX = 0)

begin

insert into Vagones values (1,'Pulman','Fumador')
insert into Vagones values (2,'Pulman','No_fumador')
insert into Vagones values (3,'Pulman','No_fumador')
insert into Vagones values (4,'Pulman','No_fumador')
insert into Vagones values (5,'Turista','No_fumador')
insert into Vagones values (6,'Turista','No_fumador')
insert into Vagones values (7,'Turista','No_fumador')
insert into Vagones values (8,'Turista','Fumador')

end

else

begin
	if(@AUX = 8)
	begin
		print 'Ya fueron asignados'
	end

	else

	begin
		print 'Hay un error en Vagones, puede haber más o menos vagones'
	end
end

------------------- Paso 2 -------------------

create procedure SetAsiento as

declare @AUX as int  

select @AUX = count(a.Numero_de_asiento)  from Asientos a

if(@AUX = 0)

begin

	declare @Bool as Bit;
	declare @N as int;
	declare @Num as nvarchar(20);

	declare @I as int
	declare @J as int
	declare @K as int 

	set @I = 1;
		while @I <= 8
		begin
			set @N = 1
			set @J = 1;
			set @K = 2;
		
			while @J <= 60 and @K <= 60
			begin
				set @Num = @N/2.0;
			
				SELECT @Bool = CASE WHEN ISNUMERIC(@Num) = 1 
				THEN CASE WHEN ROUND(@Num,0,1) = @Num
					THEN 1 
					ELSE 0 
				END 
					ELSE null 
				END 
			
				insert into Asientos (Numero_de_asiento,Tipo_asiento,Numero_vagon) values (@J,'Ventanilla',@I)
				insert into Asientos (Numero_de_asiento,Tipo_asiento,Numero_vagon) values (@K,'Pasillo',@I)

				if(@Bool = 0)
				begin 
					set @J = @J + 3
					set @K = @K + 1
				end
			
				else
				begin 
					set @J = @J + 1
					set @K = @K + 3
				end

				set @N = @N + 1

			
			end	
		set @I = @I + 1
		end

end
else

begin
	if(@AUX = 480)
	begin
		print 'Ya fueron asignados'
	end

	else

	begin
		print 'Hay un error en asientos, puede haber más o menos asignados'
	end
end


------------------- Paso 3 -------------------

create procedure SetPasajeros (
@Nombre as varchar(255),
@DNI as int
)
as
begin

	declare @AUX as int

	select @AUX = count(p.DNI) from Pasajeros p where p.DNI = @DNI 

	if(@AUX = 0)

	begin
		insert into Pasajeros (nombre_completo , DNI) values (@Nombre, @DNI)
	end

	else

	begin
		rollback transaction
	end 

end

------------------- Paso 4 -------------------

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