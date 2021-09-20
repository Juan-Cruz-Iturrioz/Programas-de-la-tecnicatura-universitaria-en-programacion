--- punto 1create procedure bus_categoría_cliente (@categoria as varchar (25) )asdeclare @idpelicula as int
declare @nombre as varchar (45)
declare @apellido as varchar (45)
declare @direccion as varchar (50)

declare list_categoria cursor for 
	select p.idpelicula from categorias c
		join categoriasdepeliculas cp on cp.idcategoria = c.idcategoria		join peliculas p on p.idpelicula = cp.idpelicula	where c.categoria like @categoriaopen list_categoriafetch Next From list_categoria into @idpeliculawhile @@Fetch_Status = 0begindeclare list_clientes cursor for 
	select c.nombre,c.apellido, s.direccion from alquileres a		join clientes c on c.idcliente = a.idcliente		join sucursales s on s.idsucursal = c.idsucursal	where a.idpelicula like @idpelicula

	open list_clientes

	fetch Next From list_clientes into @nombre, @apellido,@direccion
		while @@Fetch_Status = 0
		Begin
			print (CAST(@idpelicula as varchar (50))+ ' ' +@nombre +' '+ @apellido + ' ' + @direccion)
			fetch Next From list_clientes into @nombre, @apellido,@direccion
		end
	close list_clientes
	deallocate list_clientesfetch Next From list_categoria into @idpeliculaendclose list_categoria
deallocate list_categoria
return

exec bus_categoría_cliente @categoria = 'accion'



