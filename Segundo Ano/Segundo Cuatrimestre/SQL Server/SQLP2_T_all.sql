

/*
puntos 1

tema 1



tema 2

create procedure bonos_fechas(
@mes as int ,
@anio as int
)
as 
declare @idpersonal as int;
declare @nombre_completo as varchar(50);
declare @bono as real;

declare list_personal cursor for
	 select alq.idpersonal, (per.nombre + ' ' + per.apellido) as nombre_completo ,(sum(pel.costoalquiler)*0.1) as bono from peliculas pel
        join alquileres alq on alq.idpelicula = pel.idpelicula
        join personal per on per.idpersonal = alq.idpersonal
	where month(alq.fecha) = @mes and year(alq.fecha) = @anio
	GROUP by alq.idpersonal,per.nombre,per.apellido

open list_personal

fetch Next From list_personal into @idpersonal, @nombre_completo, @bono

while @@Fetch_Status = 0begin
	
	insert into bonos (mes, anio, idpersonal, nombrepersonal, importe)
    values (@mes, @anio, @idpersonal, @nombre_completo, @bono)
fetch Next From list_personal into @idpersonal, @nombre_completo, @bono
end

close list_personal
DEALLOCATE list_personal

RETURN


*/


/*
puntos 2

tema 1

select distinct c.nombre,c.apellido,s.direccion from alquileres a
join peliculas p on p.idpelicula = a.idpelicula
join clientes c on c.idcliente = a.idcliente
join sucursales s on s.idsucursal = c.idsucursal
where a.fechadevolucion > (a.fecha + DAY(p.duracionalquiler))

tema 2

select  p.titulo,s.direccion from idiomas i
join idiomasdepeliculas idp on i.ididioma = idp.ididioma
join peliculas p on p.idpelicula = idp.idpelicula
join inventario iv on iv.idpelicula = idp.idpelicula
join sucursales s on s.idsucursal = iv.idsucursal
where i.idioma like 'aleman' and iv.cantejemplares >= 1

*/

