--Iturrioz Juan Cruz 25160 24/11/2020

-- punto 1

create procedure inventario_por_sucursal
as 
declare @idpelicula as int
declare @titulo as varchar (50)
declare @direccion varchar (50)
declare @cantejemplares as int

declare list_peliculas cursor for
	select p.idpelicula, p.titulo from peliculas p

open list_peliculas

fetch Next From list_peliculas into @idpelicula, @titulo

while @@Fetch_Status = 0begin
	declare list_sucursales cursor for
	select s.direccion, i.cantejemplares from inventario i
	join sucursales s on s.idsucursal = i.idsucursal
		where i.idpelicula = @idpelicula and i.cantejemplares > 0

		open list_sucursales
		fetch Next From list_sucursales into @direccion, @cantejemplares
			
			if (@@Fetch_Status = 0)
			begin
				print ''
				print @titulo
			end
		
		while @@Fetch_Status = 0
		begin
			
			print '		' + @direccion + '		' + cast(@cantejemplares as varchar)
		
			fetch Next From list_sucursales into @direccion, @cantejemplares
		end
		

		close list_sucursales
		deallocate list_sucursales

fetch Next From list_peliculas into @idpelicula, @titulo

end

close list_peliculas
deallocate list_peliculas

return


exec inventario_por_sucursal



-- punto 2

use casablanca

select c.categoria, a.idcliente, cl.nombre, cl.apellido, count(a.idcliente) as  alquilere_realizados from categorias c
join categoriasdepeliculas cp on cp.idcategoria = c.idcategoria
join alquileres a on a.idpelicula = cp.idpelicula
join clientes cl on cl.idcliente = a.idcliente
where c.categoria = 'Drama' 
GROUP by c.categoria,a.idcliente,cl.nombre,cl.apellido
HAVING COUNT(*) >=2

