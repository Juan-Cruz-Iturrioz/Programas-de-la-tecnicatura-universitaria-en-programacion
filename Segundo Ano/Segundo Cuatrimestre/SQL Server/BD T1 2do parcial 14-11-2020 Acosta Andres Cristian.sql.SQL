/*

Acosta Andres Cristian

Legajo 25218

14/11/2020


*/

-- EJERCICIO 1
create procedure devolver_alquiler (@nombre_pelicula varchar(255), @dir_sucursal varchar(50), @email_cliente varchar(50), @monto_pago numeric(5,2)=null)
as
  begin

    declare @id_cliente int, @id_pelicula int, @id_sucursal int, @id_encargado int, @id_empleado_alquilo int, @fecha_alquilo datetime;

    set @id_cliente = (select idcliente from clientes where email = @email_cliente);
    set @id_pelicula = (select idpelicula from peliculas where titulo = @nombre_pelicula);
    set @id_sucursal = (select idsucursal from sucursales where direccion = @dir_sucursal);

    if (@id_cliente is null or @id_pelicula is null or @id_sucursal is null)
      print 'No se ha encontrado alquileres para devolver con esos parametros';
    else
      begin
        select @id_empleado_alquilo = idpersonal, @fecha_alquilo = fecha from alquileres 
          where idcliente = @id_cliente and idpelicula = @id_pelicula and idsucursal = @id_sucursal;

        if (@id_empleado_alquilo is null or @id_cliente is null)
          begin
            print 'No se ha encontrado alquileres para devolver con esos parametros';   
            return;
          end;
        
        update alquileres set fechadevolucion = GETDATE() where idcliente = @id_cliente and idpelicula = @id_pelicula and idsucursal = @id_sucursal;
        
        if ( @monto_pago is not null)
          begin
            set @id_encargado = (select idencargado from sucursales where idsucursal = @id_sucursal);
            INSERT INTO [pagos]
                 ([idpeliculaalquilo]
                 ,[idclientealquilo]
                 ,[idsucursalalquilo]
                 ,[idpersonalalquilo]
                 ,[fechaalquilo]
                 ,[idpersonalrecibepago]
                 ,[monto]
                 ,[fecha])
             VALUES
                 (@id_pelicula,
                 @id_cliente,
                 @id_sucursal,
                 @id_empleado_alquilo,
                 @fecha_alquilo,
                 @id_encargado,
                 @monto_pago,
                 getdate())
          end
      end
  end

-- EJERCICIO 2

SELECT c.idcliente, 
       c.nombre, 
       c.apellido, 
       s.direccion AS direccion_sucursal, 
       Count(*)    AS devoluciones_vencidads 
FROM   clientes c 
       JOIN sucursales s 
         ON s.idsucursal = c.idsucursal 
       JOIN (SELECT * 
             FROM   alquileres 
             WHERE  fechadevolucion IS NOT NULL) a 
         ON a.idcliente = c.idcliente 
       JOIN peliculas p 
         ON p.idpelicula = a.idpelicula 
WHERE  p.duracionalquiler < Datediff(day, a.fecha, a.fechadevolucion) -- Si la duracion permitida de alquiler son menores a los que se alquilo
GROUP  BY c.idcliente, 
          c.nombre, 
          c.apellido, 
          s.direccion 
ORDER  BY c.idcliente; 

--EJERCICIO 3
  
CREATE TRIGGER insertar_alquiler_validar_sucursal on alquileres for insert 
as
  begin

    if (not exists (select * from clientes c, inserted i where c.idcliente = i.idcliente and c.idsucursal = i.idsucursal ))
      begin
          raiserror('No se puede alquilar en una sucursal diferente a la registrada',16,1);
          rollback transaction;
      end 
    else
      begin
      if (exists (select * from inventario i, inserted ins where i.idpelicula = ins.idpelicula and i.idsucursal = ins.idsucursal and i.cantejemplares >=1 ))
        return
      else
        begin
          raiserror('No hay peliculas en la sucursal seleccionada',16,1);
          rollback transaction;
        end   
    end
  end

