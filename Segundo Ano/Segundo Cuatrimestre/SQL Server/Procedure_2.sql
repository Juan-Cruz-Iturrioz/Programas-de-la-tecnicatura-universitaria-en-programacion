
create procedure SetVagones as

declare @AUX as int  

select @AUX = count(v.Numero_vagon)  from Vagones v

if(@AUX = 0)

begin

insert into Vagones values (1,'Pulman','Fumador')
insert into Vagones values (2,'Pulman','No_fumador')
insert into Vagones values (3,'Pulman','No_fumador')
insert into Vagones values (4,'Pulman','No_fumador')
insert into Vagones values (5,'Turista','No_fumador')
insert into Vagones values (6,'Turista','No_fumador')
insert into Vagones values (7,'Turista','No_fumador')
insert into Vagones values (8,'Turista','Fumador')

end

else

begin
	if(@AUX = 8)
	begin
		print 'Ya fueron asignados'
	end

	else

	begin
		print 'Hay un error en Vagones, puede haber más o menos vagones'
	end
end




