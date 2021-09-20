--Iturrioz Juan Cruz, Legajo : 25160, Fecha : 23/02/2021 
use LINSA
exec Alta_Stock  @cod_art = 131, @des = 'Algo' ,@tipo = 'A',@Razon_social = 'Juan', @Per_cos = 100 , @stock = 100

select * from articulo a where a.cod_articulo = 131
select * from proveedores
select * from articulo_deposito a where a.cod_articulo = 131
/*
select * from 
/*
select distinct
*/

/*
where distinct

(select p.a from  p group by p.a having count(p.a) >= '1')

*/


go
create procedure (
)
as

/*
declare @ as varchar(255) 
declare @ as int
declare @ as float
*/

/*
declare CUR_ cursor scroll for (select)
*/


/*
open CUR_
fetch next from CUR_ into @

while @@FETCH_STATUS=0
		begin 

		fetch next from CUR_ into @
		end

close CUR_
deallocate CUR_

*/

/*
print '' + CAST(@ as CHAR(100))
*/

go
*/
