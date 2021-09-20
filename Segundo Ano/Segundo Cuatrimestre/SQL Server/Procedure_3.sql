
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



