Ejercicio 1

create procedure con_cat @categoria  as varchar(255)=null  
	as		
	declare   @nombre varchar(50),@apellido varchar(50), @dirsuc  varchar(50), @idcate int,
	          @nomcate varchar(50)
			 
	if @categoria is null
	 begin
		declare catego cursor for
			  select  idcategoria, categoria
				 from categorias

     end
	 else
		begin
			declare catego cursor for
			  select idcategoria, categoria
				 from categorias
					where
					   categoria = @categoria
		end

	 open catego 
	 fetch catego into @idcate, @nomcate
     While @@Fetch_Status = 0
		begin
		  print 'categoría:' + ' ' +rtrim(ltrim(@nomcate))
		  print ' '
		  declare client cursor for
			  select  distinct cl.nombre, cl.apellido, su.direccion
				 from clientes cl, alquileres al, categoriasdepeliculas cp, categorias ca, sucursales su
					where
					   cl.idsucursal= su.idsucursal and
					   cl.idcliente= al.idcliente and
					   al.idpelicula= cp.idpelicula  and
					   cp.idcategoria = @idcate 
                      order by  nombre, apellido;
 		   open client
		  
		   fetch client into @nombre, @apellido,@dirsuc
		   While @@Fetch_Status = 0
		    begin
			
		      print  rtrim(ltrim(@nombre)) +','+ rtrim(ltrim(@apellido))+'      '+ rtrim(ltrim(@dirsuc))
              fetch client into @nombre, @apellido,@dirsuc
            end 
			close client
			deallocate client
			print ' '
         fetch catego into @idcate, @nomcate
		end
close catego
deallocate catego
return

exec con_cat @categoria = 'Accion';
exec con_cat;

Ejercicio 2

select cl.idcliente, cl.nombre, cl.apellido, ci.ciudad,  sum(pe.costoalquiler) as Importe , count(a.idpelicula) as 'Cant de alquileres' 

   from clientes cl, alquileres a, peliculas pe, ciudades ci
       
	    where 
		   cl.idcliente = a.idcliente and
		   a.idpelicula = pe.idpelicula and
		   cl.idciudad= ci.idciudad  and 
		   year(fecha) = 2009 and
		   a.fechadevolucion is null
		    group by cl.idcliente, cl.nombre, cl.apellido, ci.ciudad
			  having count(a.idpelicula) >=2
			  order by cl.idcliente


Ejercicio 3

create trigger control_inventario on alquileres  for insert
as
    declare @stock int
	 declare @idpel int
	declare @idsuc int
    select @stock= inventario.cantejemplares, @idpel= inserted.idpelicula, @idsuc= inserted.idsucursal from inventario  join inserted
              on inserted.idpelicula =  inventario.idpelicula and
                 inserted.idsucursal = inventario.idsucursal

    if (@stock>=1)
       update inventario set cantejemplares=cantejemplares -1
	     where idpelicula =@idpel and idsucursal = @idsuc
	 else
       begin
       print 'No hay ejemplares disponibles'
       rollback transaction
    end

