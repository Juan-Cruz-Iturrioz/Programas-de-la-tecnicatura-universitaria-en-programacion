-- tema 2 ejercicio 1

create procedure calcular_bono(@mes int, @anio int) AS

declare @idper as int;
declare @nom as varchar(45), @ap as varchar(45);
declare @nomap as varchar(100);
declare @importe as money;

declare curPersonal cursor FOR
    select per.idpersonal, per.nombre, per.apellido from personal per
        order by per.idpersonal

open curPersonal

fetch next from curPersonal into @idper, @nom, @ap
while @@FETCH_STATUS = 0 BEGIN

    set @nomap = @nom + ' ' + @ap
    
    select @importe=sum(pel.costoalquiler)*0.1 from peliculas pel
        join alquileres alq on alq.idpelicula = pel.idpelicula
        where alq.idpersonal = @idper
            and month(alq.fecha) = @mes
            and year(alq.fecha) = @anio

    if (@importe is not null) BEGIN
        print @nomap + ' ' + CAST(@importe as VARCHAR)

        insert into bonos (mes, anio, idpersonal, nombrepersonal, importe)
            values (@mes, @anio, @idper, @nomap, @importe)

    END

    fetch next from curPersonal into @idper, @nom, @ap
end

close curPersonal
DEALLOCATE curPersonal

RETURN
