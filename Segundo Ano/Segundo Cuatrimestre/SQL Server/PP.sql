use Trenes_del_Nilo

--select distinct * from Viajes v where CONVERT(varchar,v.Fecha_de_viaje,3) like '06/02/21'


--select distinct t.Id_tren from Trenes t where t.Id_tren not in (select distinct v.Id_tren from Viajes v where CONVERT(varchar,v.Fecha_de_viaje,3) like '06/02/21')

--select * from Viajes v where CONVERT(varchar,v.Fecha_de_viaje,3) like '06/02/21' and 
--( v.Horario_de_embarcacion > CONVERT(TIME,'16:30') and v.horario_de_llegada > CONVERT(TIME,'16:30') )

/*
select * from Viajes v where CONVERT(varchar,v.Fecha_de_viaje,3) like '06/02/21' and 
( v.horario_de_llegada < CONVERT(TIME,'18:30') and v.Horario_de_embarcacion > CONVERT(TIME,'20:30') ) 
*/

-- 13:30 || 15:50

/*
select * from Viajes v where CONVERT(varchar,v.Fecha_de_viaje,3) like '06/02/21' and 
( v.horario_de_llegada < CONVERT(TIME,'13:30') and CONVERT(TIME,'15:30') > v.Horario_de_embarcacion)
*/


/*
select * from Viajes v where  
( v.horario_de_llegada > CONVERT(TIME,'11:30') and v.Horario_de_embarcacion > CONVERT(TIME,'13:30'))
*/

/*
select distinct t.Id_tren from Trenes t where t.Id_tren not in (
	select distinct v.Id_tren from Viajes v where 
	CONVERT(varchar,v.Fecha_de_viaje,3) like '06/02/21' and
	( v.horario_de_llegada > CONVERT(TIME,'11:30') and v.Horario_de_embarcacion > CONVERT(TIME,'13:30'))
)
*/

/*
select distinct * from Viajes v where ( CONVERT(varchar,v.Fecha_de_viaje,3) like '06/02/21' and v.Origen = 'Luxor' and v.Destino = 'Cairo') 
	and (
		( v.horario_de_llegada >= CONVERT(TIME,'15:30') and v.Horario_de_embarcacion <= CONVERT(TIME,'15:30') )
		or
		( v.horario_de_llegada >= CONVERT(TIME,'17:30') and v.Horario_de_embarcacion <= CONVERT(TIME,'17:30') )	
	)
order by v.Id_tren
*/

-- ( CONVERT(varchar,v.Fecha_de_viaje,3) like '10/02/21'  and v.Origen = 'Luxor' and v.Destino = 'Cairo' ) 

select distinct t.Id_tren from Trenes t where 
t.Id_tren not in (
	
	select distinct v.Id_tren from Viajes v where ( CONVERT(varchar,v.Fecha_de_viaje,3) like '10/02/21'  ) 
	and (
		( v.horario_de_llegada >= CONVERT(TIME,'15:30') and v.Horario_de_embarcacion <= CONVERT(TIME,'15:30') )
		or
		( v.horario_de_llegada >= CONVERT(TIME,'17:30') and v.Horario_de_embarcacion <= CONVERT(TIME,'17:30') )	
	)	
)
order by t.Id_tren

