
SET DATEFORMAT dmy

CREATE DATABASE LINSA
USE LINSA


CREATE TABLE [dbo].[empleado] (
	[cod_empleado] [int]  NOT NULL ,
	[nombre] [varchar] (50) ,
	[apellido] [varchar] (50) ,
	[cod_departamento] [int] not null ,
	[suelod_basico] [money]  NOT NULL ,
	[fecha_ingreso] [datetime] NULL ,
	[fecha_nacimiento] [datetime] NULL ,
	[jefe] [int]  NULL
)
GO

CREATE TABLE [dbo].[proveedores] (
	[cod_proveedor] [int] NOT NULL ,
	[razon_social] [varchar] (50),
        [porcentaje_ganancia] [decimal] (5,2)
)
GO

CREATE TABLE [dbo].[articulo] (
	[cod_articulo] [int]  NOT NULL ,
	[descripcion] [varchar] (50) ,
	[tipo_articulo] [char] (1) ,
	[cod_proveedor] [int],
	[precio_costo] [money],
	[precio_venta] [money] NULL
)
GO

CREATE TABLE [dbo].[articulo_deposito] (
	[cod_articulo] [int] NULL ,
	[cod_deposito] [int] NULL ,
	[stock_actual] [int] NULL ,
	[punto_reorden] [int] NULL 
)
GO

CREATE TABLE [dbo].[cliente] (
	[cod_cliente] [int]  NOT NULL ,
	[razon_social] [varchar] (50)  ,
	[direccion] [varchar] (50)
)
GO

CREATE TABLE [dbo].[departamento] (
	[cod_departamento] [int]  NOT NULL ,
	[descripcion] [varchar] (50)  ,
	[gerente] [int] NULL ,
	[cod_dep_padre] [int] NULL 
)
GO

CREATE TABLE [dbo].[deposito] (
	[cod_deposito] [int]  NOT NULL ,
	[ubicacion_deposito] [varchar] (50)
)
GO

CREATE TABLE [dbo].[detalle_de_pedido] (
	[nro_pedido] [int] NULL ,
	[cod_articulo] [int] NULL ,
	[cantidad] [int]
)
GO

CREATE TABLE [dbo].[pedido] (
	[nro_pedido] [int]  NOT NULL ,
	[cod_cliente] [int] NULL ,
	[cod_empleado] [int] NULL ,
	[fecha_pactada_entrega] [datetime] NULL ,
	[fecha_real_entrega] [datetime] NULL ,
	[deposito_entrega] [int] NULL 
)
GO




insert into empleado values(1,'Andres','Paez',1,1200,'01-01-1998','20-05-1960',null)
insert into empleado values(2,'Mariana','Renado',1,1100,'01-02-2000','20-05-1960',1)
insert into empleado values(3,'Ariel','Linares',1,1100,'01-11-2001','28-05-1970',1)
insert into empleado values(4,'Florencia','Linares',2,1050,'01-09-2002','12-03-1971',2)
insert into empleado values(5,'Esteban','Baez',2,1050,'01-07-2002','10-06-1980',2)
insert into empleado values(6,'Fernando','Diciana',2,1100,'01-05-2005','02-07-1981',3)


insert into proveedores values(1,'Distribuidora del Sur',15)
insert into proveedores values(2,'San Telmo SA',12)
insert into proveedores values(3,'Materelectri',16)

insert into articulo values(1,'Lampara 25W','A',1,1.20,1.38)
insert into articulo values(2,'Lampara 40W','A',1,1.40,1.61)
insert into articulo values(3,'Lampara 60W','A',1,1.60,1.84)
insert into articulo values(4,'Lampara 75W','A',1,1.80,2.07)
insert into articulo values(5,'Lampara 100W','A',1,2.20,2.53)

insert into articulo values(6,'Modulo 1 punto','B',2,1.50,1.68)
insert into articulo values(7,'Modulo 1 punto y toma','B',2,3.50,3.92)
insert into articulo values(8,'Modulo 1 toma','B',2,4.50,5.04)
insert into articulo values(9,'Modulo 1 toma c neutro','B',2,4.50,5.04)
insert into articulo values(10,'Modulo 1 punto y toma c neutro','B',2,3.50,3.92)

insert into articulo values(11,'Portalamparas con chicote','C',3,1.80,2.08)
insert into articulo values(12,'Portalamparas con cadena','C',3,7.80,9.04)
insert into articulo values(13,'Portalamparas bronce con arandela porc','C',3,3.80,4.40)
insert into articulo values(14,'Portalamparas porcelana','C',3,2.80,3.24)
insert into articulo values(15,'Portalamparas baquelita negro','C',3,2.50,2.90)
insert into articulo values(16,'Portalamparas baquelita blanco','C',3,3.00,3.48)


/* sentencia para actualizar el precio de venta de la tabla articulos*/

update articulo set precio_venta = precio_costo + (precio_costo *  15/100)
       where cod_proveedor = 1;
       
update articulo set precio_venta = precio_costo + (precio_costo *  12/100)
       where cod_proveedor = 2;

update articulo set precio_venta = precio_costo + (precio_costo *  16/100)
       where cod_proveedor = 3;


insert into cliente values(1,'Electricidad Suipacha','Lamadrid 123')
insert into cliente values(2,'El Foquito','Independencia 1234')
insert into cliente values(3,'La Candela','San Juan 3456')
insert into cliente values(4,'Distribuidora Argentina','Larrea 1234')
insert into cliente values(5,'Darluz','La Rioja 4321')
insert into cliente values(6,'Electrolux','Lima 123')

insert into deposito values(1,'Aeroparque')
insert into deposito values(2,'Avellaneda')
insert into deposito values(3,'Quilmes')

insert into departamento values(1,'Administracion',1,null)
insert into departamento values(2,'Ventas',2,1)


insert into articulo_deposito values(1,1,45,50)
insert into articulo_deposito values(2,1,60,50)
insert into articulo_deposito values(3,1,55,50)
insert into articulo_deposito values(4,1,35,50)
insert into articulo_deposito values(5,1,78,50)
insert into articulo_deposito values(6,1,23,100)
insert into articulo_deposito values(7,1,56,100)
insert into articulo_deposito values(8,1,80,100)
insert into articulo_deposito values(9,1,78,100)
insert into articulo_deposito values(10,1,65,100)
insert into articulo_deposito values(11,1,12,50)
insert into articulo_deposito values(12,1,45,50)
insert into articulo_deposito values(13,1,100,50)
insert into articulo_deposito values(14,1,90,50)
insert into articulo_deposito values(15,1,100,50)
insert into articulo_deposito values(16,1,100,50)


insert into articulo_deposito values(1,2,0,50)
insert into articulo_deposito values(2,2,60,50)
insert into articulo_deposito values(3,2,34,50)
insert into articulo_deposito values(4,2,80,50)
insert into articulo_deposito values(5,2,8,50)
insert into articulo_deposito values(6,2,23,100)
insert into articulo_deposito values(7,2,68,100)
insert into articulo_deposito values(8,2,125,100)
insert into articulo_deposito values(9,2,60,100)
insert into articulo_deposito values(10,2,65,100)
insert into articulo_deposito values(11,2,19,50)
insert into articulo_deposito values(12,2,65,50)
insert into articulo_deposito values(13,2,100,50)
insert into articulo_deposito values(14,2,80,50)
insert into articulo_deposito values(15,2,100,50)
insert into articulo_deposito values(16,2,0,50)


insert into articulo_deposito values(1,3,10,50)
insert into articulo_deposito values(2,3,0,50)
insert into articulo_deposito values(3,3,4,50)
insert into articulo_deposito values(4,3,8,50)
insert into articulo_deposito values(5,3,18,50)
insert into articulo_deposito values(6,3,29,100)
insert into articulo_deposito values(7,3,68,100)
insert into articulo_deposito values(8,3,0,100)
insert into articulo_deposito values(9,3,0,100)
insert into articulo_deposito values(10,3,65,100)
insert into articulo_deposito values(11,3,19,50)
insert into articulo_deposito values(12,3,65,50)
insert into articulo_deposito values(13,3,10,50)
insert into articulo_deposito values(14,3,8,50)
insert into articulo_deposito values(15,3,10,50)
insert into articulo_deposito values(16,3,0,50)

insert into pedido(nro_pedido,cod_cliente,cod_empleado,fecha_pactada_entrega,deposito_entrega) values(1,1,1,'06-11-2020',1)
insert into pedido(nro_pedido,cod_cliente,cod_empleado,fecha_pactada_entrega,fecha_real_entrega,deposito_entrega) values(2,1,1,'06-10-2020','23-10-2020',1)
insert into pedido(nro_pedido,cod_cliente,cod_empleado,fecha_pactada_entrega,fecha_real_entrega,deposito_entrega) values(3,1,1,'06-10-2020','06-10-2020',1)
insert into pedido(nro_pedido,cod_cliente,cod_empleado,fecha_pactada_entrega,fecha_real_entrega,deposito_entrega) values(4,1,2,'30-11-2020','01-12-2020',1)
insert into pedido(nro_pedido,cod_cliente,cod_empleado,fecha_pactada_entrega,deposito_entrega) values(5,1,2,'30-11-2020',1)
insert into pedido(nro_pedido,cod_cliente,cod_empleado,fecha_pactada_entrega,deposito_entrega) values(6,1,3,'01-12-2020',1)
insert into pedido(nro_pedido,cod_cliente,cod_empleado,fecha_pactada_entrega,deposito_entrega) values(7,1,3,'29-11-2020',1)

insert into pedido(nro_pedido,cod_cliente,cod_empleado,fecha_pactada_entrega,fecha_real_entrega,deposito_entrega) values(8,2,5,'05-11-2020','10-11-2020',1)
insert into pedido(nro_pedido,cod_cliente,cod_empleado,fecha_pactada_entrega,fecha_real_entrega,deposito_entrega) values(9,2,5,'20-10-2020','20-10-2020',1)
insert into pedido(nro_pedido,cod_cliente,cod_empleado,fecha_pactada_entrega,fecha_real_entrega,deposito_entrega) values(10,2,5,'15-10-2020','10-11-2020',1)
insert into pedido(nro_pedido,cod_cliente,cod_empleado,fecha_pactada_entrega,fecha_real_entrega,deposito_entrega) values(11,2,5,'10-11-2020','10-11-2020',1)
insert into pedido(nro_pedido,cod_cliente,cod_empleado,fecha_pactada_entrega,deposito_entrega) values(12,2,2,'28-11-2020',1)
insert into pedido(nro_pedido,cod_cliente,cod_empleado,fecha_pactada_entrega,deposito_entrega) values(13,2,3,'03-12-2020',1)
insert into pedido(nro_pedido,cod_cliente,cod_empleado,fecha_pactada_entrega,deposito_entrega) values(14,2,3,'03-10-2020',1)


insert into pedido(nro_pedido,cod_cliente,cod_empleado,fecha_pactada_entrega,fecha_real_entrega,deposito_entrega) values(15,3,5,'18-11-2020','18-11-2020',2)
insert into pedido(nro_pedido,cod_cliente,cod_empleado,fecha_pactada_entrega,fecha_real_entrega,deposito_entrega) values(16,3,5,'15-11-2020','15-11-2020',2)
insert into pedido(nro_pedido,cod_cliente,cod_empleado,fecha_pactada_entrega,fecha_real_entrega,deposito_entrega) values(17,3,5,'01-12-2020','01-12-2020',2)
insert into pedido(nro_pedido,cod_cliente,cod_empleado,fecha_pactada_entrega,fecha_real_entrega,deposito_entrega) values(18,3,4,'28-11-2020','28-11-2020',2)
insert into pedido(nro_pedido,cod_cliente,cod_empleado,fecha_pactada_entrega,deposito_entrega) values(19,3,2,'29-11-2020',2)
insert into pedido(nro_pedido,cod_cliente,cod_empleado,fecha_pactada_entrega,deposito_entrega) values(20,3,1,'10-12-2020',2)
insert into pedido(nro_pedido,cod_cliente,cod_empleado,fecha_pactada_entrega,deposito_entrega) values(21,3,1,'10-12-2020',2)

insert into pedido(nro_pedido,cod_cliente,cod_empleado,fecha_pactada_entrega,fecha_real_entrega,deposito_entrega) values(22,4,6,'10-10-2020','10-10-2020',3)
insert into pedido(nro_pedido,cod_cliente,cod_empleado,fecha_pactada_entrega,fecha_real_entrega,deposito_entrega) values(23,4,6,'10-10-2020','15-10-2020',3)
insert into pedido(nro_pedido,cod_cliente,cod_empleado,fecha_pactada_entrega,fecha_real_entrega,deposito_entrega) values(24,5,6,'05-11-2020','10-11-2020',3)
insert into pedido(nro_pedido,cod_cliente,cod_empleado,fecha_pactada_entrega,fecha_real_entrega,deposito_entrega) values(25,5,6,'18-11-2020','23-11-2020',3)
insert into pedido(nro_pedido,cod_cliente,cod_empleado,fecha_pactada_entrega,deposito_entrega) values(26,6,5,'05-12-2020',3)
insert into pedido(nro_pedido,cod_cliente,cod_empleado,fecha_pactada_entrega,deposito_entrega) values(27,6,5,'15-12-2020',3)
insert into pedido(nro_pedido,cod_cliente,cod_empleado,fecha_pactada_entrega,deposito_entrega) values(28,6,5,'10-12-2020',3)


insert into detalle_de_pedido values(1,1,10)
insert into detalle_de_pedido values(1,2,10)
insert into detalle_de_pedido values(1,3,10)
insert into detalle_de_pedido values(1,4,3)
insert into detalle_de_pedido values(2,1,15)
insert into detalle_de_pedido values(2,3,20)
insert into detalle_de_pedido values(2,5,40)
insert into detalle_de_pedido values(3,2,15)
insert into detalle_de_pedido values(3,3,16)
insert into detalle_de_pedido values(3,1,12)
insert into detalle_de_pedido values(4,6,8)
insert into detalle_de_pedido values(4,7,10)
insert into detalle_de_pedido values(5,9,50)

insert into detalle_de_pedido values(6,11,20)
insert into detalle_de_pedido values(6,12,10)
insert into detalle_de_pedido values(6,13,15)
insert into detalle_de_pedido values(6,14,13)
insert into detalle_de_pedido values(7,11,5)
insert into detalle_de_pedido values(7,13,30)
insert into detalle_de_pedido values(8,15,45)
insert into detalle_de_pedido values(8,12,45)
insert into detalle_de_pedido values(8,13,36)
insert into detalle_de_pedido values(9,11,22)
insert into detalle_de_pedido values(10,16,18)
insert into detalle_de_pedido values(10,15,10)
insert into detalle_de_pedido values(10,9,60)


insert into detalle_de_pedido values(11,12,10)
insert into detalle_de_pedido values(11,13,10)
insert into detalle_de_pedido values(11,4,3)
insert into detalle_de_pedido values(12,1,15)
insert into detalle_de_pedido values(12,3,20)
insert into detalle_de_pedido values(12,15,40)
insert into detalle_de_pedido values(13,2,15)
insert into detalle_de_pedido values(13,13,16)
insert into detalle_de_pedido values(13,11,12)
insert into detalle_de_pedido values(14,16,8)
insert into detalle_de_pedido values(14,7,10)
insert into detalle_de_pedido values(15,9,50)


insert into detalle_de_pedido values(16,2,16)
insert into detalle_de_pedido values(16,12,15)
insert into detalle_de_pedido values(16,3,10)
insert into detalle_de_pedido values(17,14,23)
insert into detalle_de_pedido values(17,11,15)
insert into detalle_de_pedido values(18,13,20)
insert into detalle_de_pedido values(18,5,10)
insert into detalle_de_pedido values(18,2,15)
insert into detalle_de_pedido values(19,3,76)
insert into detalle_de_pedido values(19,1,22)
insert into detalle_de_pedido values(19,16,8)
insert into detalle_de_pedido values(19,7,30)
insert into detalle_de_pedido values(19,9,50)


insert into detalle_de_pedido values(20,1,10)
insert into detalle_de_pedido values(20,2,10)
insert into detalle_de_pedido values(20,3,10)
insert into detalle_de_pedido values(21,1,10)
insert into detalle_de_pedido values(21,2,10)
insert into detalle_de_pedido values(21,3,10)
insert into detalle_de_pedido values(21,4,3)
insert into detalle_de_pedido values(22,1,15)
insert into detalle_de_pedido values(22,3,20)
insert into detalle_de_pedido values(22,5,40)
insert into detalle_de_pedido values(23,2,15)
insert into detalle_de_pedido values(23,3,16)
insert into detalle_de_pedido values(23,1,12)
insert into detalle_de_pedido values(24,6,8)
insert into detalle_de_pedido values(24,7,10)
insert into detalle_de_pedido values(25,9,50)

insert into detalle_de_pedido values(26,2,16)
insert into detalle_de_pedido values(26,12,15)
insert into detalle_de_pedido values(26,3,10)
insert into detalle_de_pedido values(27,14,23)
insert into detalle_de_pedido values(27,11,15)
insert into detalle_de_pedido values(28,13,20)
insert into detalle_de_pedido values(28,5,10)
insert into detalle_de_pedido values(28,2,15)
insert into detalle_de_pedido values(28,3,76)
insert into detalle_de_pedido values(28,1,22)
insert into detalle_de_pedido values(28,16,8)
insert into detalle_de_pedido values(28,7,30)
insert into detalle_de_pedido values(28,9,50)