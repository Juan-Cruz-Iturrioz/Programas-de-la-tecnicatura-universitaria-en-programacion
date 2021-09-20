create TRIGGER stock_alquier on alquileres for insert
as

declare @bandera as int
begin
	select @bandera = iv.cantejemplares from inventario iv
	join inserted ins on ins.idpelicula = iv.idpelicula
	where ins.idsucursal = iv.idsucursal
end

if(@bandera >= 1)
begin
	update inventario set cantejemplares = (@bandera-1) from inventario iv
	join inserted ins on ins.idpelicula = iv.idpelicula
	where ins.idsucursal = iv.idsucursal
end 

else
begin
raiserror ('No hay disponibilidad', 16, 1)
rollback transaction
end

insert into alquileres values (434,2,4,GETDATE(),4, '2020-11-11')

select * from inventario


