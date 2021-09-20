create procedure SetAsiento as

declare @AUX as int  

select @AUX = count(a.Numero_de_asiento)  from Asientos a

if(@AUX = 0)

begin

	declare @Bool as Bit;
	declare @N as int;
	declare @Num as nvarchar(20);

	declare @I as int
	declare @J as int
	declare @K as int 

	set @I = 1;
		while @I <= 8
		begin
			set @N = 1
			set @J = 1;
			set @K = 2;
		
			while @J <= 60 and @K <= 60
			begin
				set @Num = @N/2.0;
			
				SELECT @Bool = CASE WHEN ISNUMERIC(@Num) = 1 
				THEN CASE WHEN ROUND(@Num,0,1) = @Num
					THEN 1 
					ELSE 0 
				END 
					ELSE null 
				END 
			
				insert into Asientos (Numero_de_asiento,Tipo_asiento,Numero_vagon) values (@J,'Ventanilla',@I)
				insert into Asientos (Numero_de_asiento,Tipo_asiento,Numero_vagon) values (@K,'Pasillo',@I)

				if(@Bool = 0)
				begin 
					set @J = @J + 3
					set @K = @K + 1
				end
			
				else
				begin 
					set @J = @J + 1
					set @K = @K + 3
				end

				set @N = @N + 1

			
			end	
		set @I = @I + 1
		end

end
else

begin
	if(@AUX = 480)
	begin
		print 'Ya fueron asignados'
	end

	else

	begin
		print 'Hay un error en asientos, puede haber más o menos asignados'
	end
end



