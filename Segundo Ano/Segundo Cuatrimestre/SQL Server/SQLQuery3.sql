--- punto 1
declare @nombre as varchar (45)
declare @apellido as varchar (45)
declare @direccion as varchar (50)

declare list_categoria cursor for 
	select p.idpelicula from categorias c
		join categoriasdepeliculas cp on cp.idcategoria = c.idcategoria


	open list_clientes

	fetch Next From list_clientes into @nombre, @apellido,@direccion
		while @@Fetch_Status = 0
		Begin
			print (CAST(@idpelicula as varchar (50))+ ' ' +@nombre +' '+ @apellido + ' ' + @direccion)
			fetch Next From list_clientes into @nombre, @apellido,@direccion
		end
	close list_clientes
	deallocate list_clientes
deallocate list_categoria
return

exec bus_categor�a_cliente @categoria = 'accion'


