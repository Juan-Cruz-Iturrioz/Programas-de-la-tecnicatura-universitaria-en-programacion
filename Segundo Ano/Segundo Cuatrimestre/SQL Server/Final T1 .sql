use LINSA

--select * from proveedores p where p.razon_social in (SELECT p.razon_social FROM proveedores p GROUP BY p.razon_social HAVING COUNT(p.razon_social) >= '1')

--select * from articulo a where a.cod_proveedor =

--select * from articulo_deposito

/*
select DISTINCT dp.cod_articulo from pedido p join detalle_de_pedido dp on dp.nro_pedido = p.nro_pedido 
where p.fecha_real_entrega is null
*/

select sum(ad.stock_actual) from articulo_deposito ad where ad.cod_articulo = 7


select sum(dp.cantidad) from pedido p join detalle_de_pedido dp on dp.nro_pedido = p.nro_pedido 
where p.fecha_real_entrega is null and dp.cod_articulo = 7

select ad.precio_costo from articulo ad where ad.cod_articulo = 7

select DISTINCT dp.cod_articulo from pedido p join detalle_de_pedido dp on dp.nro_pedido = p.nro_pedido 
where p.fecha_real_entrega is null