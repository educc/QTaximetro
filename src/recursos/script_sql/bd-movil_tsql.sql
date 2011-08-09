PRAGMA foreign_keys = ON;

CREATE TABLE auto(
	id_aut		INTEGER PRIMARY KEY AUTOINCREMENT,
	nombre_aut 	varchar not null,
	placa_aut	varchar not null,
	estado_aut	boolean not null default true
)

CREATE TABLE servicio(
	id_ser			INTEGER PRIMARY KEY AUTOINCREMENT,
	precio_ser		float not null,
	origen_ser		varchar not null,
	destino_ser		varchar not null,
	id_aut			integer not null,
	fecha_ser		datetime not null,
	FOREIGN KEY(id_aut) REFERENCES auto(id_aut)
)

/*CONSULTAS*/

/*nuevo codigo*/
select max(id_aut) from auto

/*INSERCIONES*/

INSERT INTO auto(nombre_aut,placa_aut) values('','')
INSERT INTO servicio(precio_ser,origen_ser,destino_ser,id_aut, fecha_aut) values(x,'','',y,'dd/MM/yyyy hh:mm')

INSERT INTO servicio(precio_ser,origen_ser,destino_ser,id_aut, fecha_aut) values(15.5,'balta','real plaza',1,'05/06/2011 06:32')
