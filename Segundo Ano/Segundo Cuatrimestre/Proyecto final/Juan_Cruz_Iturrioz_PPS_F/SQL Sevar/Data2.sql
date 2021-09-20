use Trenes_del_Nilo
------ Paso 1 -------
/*
exec SetPasajeros @Nombre = 'Pasajeros_P1', @DNI = '42000001';
exec SetPasajeros @Nombre = 'Pasajeros_P2', @DNI = '42000002';
exec SetPasajeros @Nombre = 'Pasajeros_P3', @DNI = '42000003';
exec SetPasajeros @Nombre = 'Pasajeros_P4', @DNI = '42000004';

exec SetPasajeros @Nombre = 'Pasajeros_P5', @DNI = '42000005';
exec SetPasajeros @Nombre = 'Pasajeros_P6', @DNI = '42000006';
exec SetPasajeros @Nombre = 'Pasajeros_P7', @DNI = '42000007';
exec SetPasajeros @Nombre = 'Pasajeros_P8', @DNI = '42000008';

select * from Pasajeros
*/
------ Paso 2 -------
/*
DECLARE @cnt_total int = (select max(v.Id_viaje) from Viajes v);

DECLARE @cnt INT = (select min(v.Id_viaje) from Viajes v);

WHILE @cnt < @cnt_total
BEGIN
   exec SetBoletos @Id_viaje = @cnt, @Id_pas = '1', @PRE = '2640', @N_A = '1', @N_V = '1';
   exec SetBoletos @Id_viaje = @cnt, @Id_pas = '2', @PRE = '2640', @N_A = '2', @N_V = '2';
   exec SetBoletos @Id_viaje = @cnt, @Id_pas = '3', @PRE = '2640', @N_A = '3', @N_V = '3';
   exec SetBoletos @Id_viaje = @cnt, @Id_pas = '4', @PRE = '2640', @N_A = '4', @N_V = '4';

   exec SetBoletos @Id_viaje = @cnt, @Id_pas = '5', @PRE = '2440', @N_A = '5', @N_V = '5';
   exec SetBoletos @Id_viaje = @cnt, @Id_pas = '6', @PRE = '2440', @N_A = '6', @N_V = '6';
   exec SetBoletos @Id_viaje = @cnt, @Id_pas = '7', @PRE = '2440', @N_A = '7', @N_V = '7';
   exec SetBoletos @Id_viaje = @cnt, @Id_pas = '8', @PRE = '2440', @N_A = '8', @N_V = '8';

   SET @cnt = @cnt + 1;
END;
*/
select * from Boletos b where b.Id_viaje = 15