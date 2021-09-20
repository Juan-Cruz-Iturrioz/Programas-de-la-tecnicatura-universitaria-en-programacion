--Iturrioz Juan Cruz, Legajo: 25160, Fecha: 23/02/2021 , Tema: 1
use LINSA

go
create procedure Alta_Stock (
@cod_art as int,
@des as varchar(255),
@tipo as varchar(255),
@Razon_social as varchar(255),
@Per_cos as float,
@stock as int
)
as

declare @cod_pro as int

set @cod_pro = (select p.cod_proveedor from proveedores p where p.razon_social like @Razon_social)

if( @cod_pro is null or @cod_pro = '')
begin

declare @MAX as int
set @MAX = ((select max(p.cod_proveedor) from proveedores p) + 1)

insert into proveedores (cod_proveedor ,porcentaje_ganancia, razon_social ) values (@MAX,10,@Razon_social)

set @cod_pro = (select p.cod_proveedor from proveedores p where p.razon_social like @Razon_social)

end

declare @Per_ven as float

set @Per_ven = (select p.porcentaje_ganancia from proveedores p where p.razon_social like @Razon_social)

set @Per_ven = (@Per_ven + 100) / 100

set @Per_ven = @Per_cos * @Per_ven

insert into articulo (cod_articulo,cod_proveedor,descripcion,precio_costo,precio_venta,tipo_articulo) values (@cod_art,@cod_pro,@des,@Per_cos,@Per_ven,@tipo)

declare @cod_dep as int

declare CUR_cod_dep cursor scroll for (select d.cod_deposito from deposito d)

open CUR_cod_dep
fetch next from CUR_cod_dep into @cod_dep

while @@FETCH_STATUS=0
		begin 

		insert into articulo_deposito (cod_articulo,cod_deposito,stock_actual) values (@cod_art,@cod_dep,@stock)

		fetch next from CUR_cod_dep into @cod_dep
		end

close CUR_cod_dep
deallocate CUR_cod_dep

go

-- Pruedas --

-- Prueda 1--
use LINSA

exec Alta_Stock  @cod_art = 101, @des = ' Linterna de dos elementos' ,@tipo = 'A',@Razon_social = 'San Telmo SA', @Per_cos = 32.50 , @stock = 120

select * from proveedores p where p.razon_social like 'San Telmo SA'
select * from articulo a where a.cod_articulo = 101
select * from articulo_deposito a where a.cod_articulo = 101

-- Prueda 2 --

exec Alta_Stock  @cod_art = 111, @des = 'Algo' ,@tipo = 'C',@Razon_social = 'Juan', @Per_cos = 100 , @stock = 90

select * from proveedores p where p.razon_social like 'Juan'
select * from articulo a where a.cod_articulo = 111
select * from articulo_deposito a where a.cod_articulo = 111