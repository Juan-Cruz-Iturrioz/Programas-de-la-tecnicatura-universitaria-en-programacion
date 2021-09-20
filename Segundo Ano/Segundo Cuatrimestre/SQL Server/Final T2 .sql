use LINSA

go
CREATE PROCEDURE Estado_Pedido (
@Cod_Pro as int
)
AS
DECLARE @NOM as varchar(255)

DECLARE @Cant_Req as int
DECLARE @Cant_Stock as int 
DECLARE @Cant_Apedir  as int
DECLARE @Importe as float
DECLARE @Costo as float

DECLARE @Cod_art as int

DECLARE CUR_Cod_art CURSOR SCROLL FOR 
select DISTINCT a.cod_articulo from articulo a where a.cod_proveedor = 2 and a.cod_articulo in 
(select DISTINCT dp.cod_articulo from pedido p join detalle_de_pedido dp on dp.nro_pedido = p.nro_pedido 
where p.fecha_real_entrega is null)

set @NOM = (select p.razon_social from proveedores p where p.cod_proveedor = @Cod_Pro)

print @NOM

		OPEN CUR_Cod_art
		FETCH NEXT FROM CUR_Cod_art INTO @Cod_art
			WHILE @@FETCH_STATUS=0
			BEGIN
		
			set @Cant_Req = (select sum(dp.cantidad) from pedido p join detalle_de_pedido dp on dp.nro_pedido = p.nro_pedido 
				where p.fecha_real_entrega is null and dp.cod_articulo = @Cod_art)

			set @Cant_Stock = (select sum(ad.stock_actual) from articulo_deposito ad where ad.cod_articulo = @Cod_art)

			set @Cant_Apedir = @Cant_Req - @Cant_Stock

			set @Costo = (select ad.precio_costo from articulo ad where ad.cod_articulo = @Cod_art )

			set @Importe = @Cant_Apedir * @Costo

			set @NOM = (select a.descripcion from articulo a where a.cod_articulo = @Cod_art)

			if(@Cant_Req > @Cant_Stock)
			begin
				print 'Articulo :' + @NOM
				print '		Cant. Requerida : ' + CAST(@Cant_Req as CHAR(100))
 				print '		Cant. Stock  : ' + CAST(@Cant_Stock as CHAR(100)) 
				print '		A pedir : ' + CAST(@Cant_Apedir as CHAR(100))
				print '		Importe : ' + CAST(@Importe as CHAR(100))
				print ''
			end
			
			
			FETCH NEXT FROM CUR_Cod_art INTO @Cod_art
			END
	
		CLOSE CUR_Cod_art
		DEALLOCATE CUR_Cod_art
		
GO

go
CREATE PROCEDURE Litado_Pedido as
DECLARE @Cod_P as int


	DECLARE CUR_Cod_P CURSOR SCROLL FOR 
	select p.cod_proveedor from proveedores p where p.razon_social in (SELECT p.razon_social FROM proveedores p GROUP BY p.razon_social HAVING COUNT(p.razon_social) >= '1')

	OPEN CUR_Cod_P
	FETCH NEXT FROM CUR_Cod_P INTO @Cod_P

	WHILE @@FETCH_STATUS=0
	BEGIN
		exec Estado_Pedido @Cod_PRO = @Cod_P 
	FETCH NEXT FROM CUR_Cod_P INTO @Cod_P
	end

GO

use LINSA
go
CREATE PROCEDURE Litado_Pedido (
@Razon_social as varchar(255) = null 
)
as

DECLARE @Cod_P as int

if(@Razon_social is null)
begin
DECLARE CUR_Cod_P CURSOR SCROLL FOR 
	select p.cod_proveedor from proveedores p where p.razon_social in (SELECT p.razon_social FROM proveedores p GROUP BY p.razon_social HAVING COUNT(p.razon_social) >= '1')

	OPEN CUR_Cod_P
	FETCH NEXT FROM CUR_Cod_P INTO @Cod_P

	WHILE @@FETCH_STATUS=0
	BEGIN
		exec Estado_Pedido @Cod_PRO = @Cod_P 
	FETCH NEXT FROM CUR_Cod_P INTO @Cod_P
	end
end

else 
begin 
set @Cod_P = (select p.cod_proveedor from proveedores p where p.razon_social like @Razon_social)
exec Estado_Pedido @Cod_PRO = @Cod_P 
end

go

exec Litado_Pedido @Razon_social = 'San Telmo SA'