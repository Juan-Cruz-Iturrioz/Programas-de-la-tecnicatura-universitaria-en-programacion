--Iturrioz Juan Cruz 25160 10/11/2020



--- punto 1
-- nota el punto no dije que no se pueda duplicados los nombre 
create procedure bus_categoría_cliente (
@categoria as varchar (25) 
)
as
declare @idpelicula as int
declare @nombre as varchar (45)
declare @apellido as varchar (45)
declare @direccion as varchar (50)

declare list_categoria cursor for 
	select p.idpelicula from categorias c
		join categoriasdepeliculas cp on cp.idcategoria = c.idcategoria
		join peliculas p on p.idpelicula = cp.idpelicula
	where c.categoria like @categoria

open list_categoria

fetch Next From list_categoria into @idpelicula

while @@Fetch_Status = 0
begin

declare list_clientes cursor for 

	select c.nombre,c.apellido, s.direccion from alquileres a
		join clientes c on c.idcliente = a.idcliente
		join sucursales s on s.idsucursal = c.idsucursal
	where a.idpelicula like @idpelicula

	open list_clientes

	fetch Next From list_clientes into @nombre, @apellido,@direccion
		while @@Fetch_Status = 0
		Begin
			print (CAST(@idpelicula as varchar (50))+ ' ' +@nombre +' '+ @apellido + ' ' + @direccion)
			fetch Next From list_clientes into @nombre, @apellido,@direccion
		end

	close list_clientes
	deallocate list_clientes


fetch Next From list_categoria into @idpelicula
end

close list_categoria
deallocate list_categoria

return

exec bus_categoría_cliente @categoria = 'accion'


--- punto 2 inconreto 

SELECT a.idcliente,COUNT(a.idcliente) as RecuentoFilas FROM alquileres a
join clientes cli on cli.idcliente = a.idcliente
join ciudades ciny on ciny.idciudad = cli.idciudad
where YEAR(a.fecha) = 2009 and a.fechadevolucion is null
GROUP by a.idcliente
HAVING COUNT(*) >=2


--- punto 3

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

