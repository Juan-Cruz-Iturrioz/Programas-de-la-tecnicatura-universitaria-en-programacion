use Trenes_del_Nilo

select * from Viajes v
where v.Fecha_de_viaje ='2020-11-10' and v.Horario_de_embarcacion < CONVERT(TIME,'13:00') and v.horario_de_llegada > CONVERT(TIME,'13:00')