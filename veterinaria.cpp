#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

/*Modulo de Administracion: 
	*Alta veterinario sistema
	*Borrar al veterinario del sistema, junto a sus datos
	*borrar al empleado del sistema
	*Dar de alta a masocta ya curada
	*Se otorga un bono al veterinario que mas turnos haya atendido
			
modulo recepcion:
	*Se hace el ingreso de las mascotas, datos necesarios:Apellido y Nombres de la mascota (el
apellido corresponde al dueño o familia), DNI del dueño, Localidad, Edad (calculada con la fecha de nacimiento
registrada), Peso.
	* Debemos permitir obtener el informe de la historia clinica de la mascota
	
	
	
modulo consultorio:
	el vetereniario ingresa con su numero de matricula y contraseña 
	se habre un menu de opciones:
		1. llama por apellido y nombre a la mascota que atendera 
		 *poner estado evolucion de la mascota maximo 380
		 * (historia clinica, comun a todos)
		  se debe dejar registro del veterinario que escribio el estado de evolucion junto a la fecha
	   	*se borra la mascota del listado
		   */
		   
			
////============================================================FUNCIONES Y ESTRUCTURAS============================================================

struct Usuarios
{
	char usuario[10];
	char contra[10];
	char Apenom[60];
	//bool borrado=false; // siempre vamos a agregar el campo borrado porque a este campo lo vamos a utilizar para hacer borrados logicos
    			            // el borrado logico es como cuando se borra un archivo y se va la papelera, el borrado fisico es cuando ya se borra lo que hay en la papelera xd
};

struct fechaN
{
	int dia;
	int mes;
	int year;
};

struct Mascota
{
	char Apenom[60];
	char domicilio[60];
	int Dni_due;
	char localidad[100];
	fechaN FechaNac;
	char telefono[25];
};

struct veterinarios
{
	char Apenom[60];
	int Matricula;
	int Dni;
	char telefono[25];
};

struct fechaT
{
	int dia;
	int mes;
	int year;
};

struct turnos
{
	int Matriculavet;
	fechaT fechaturno;
	int Dni_due;
	char evolucion[380];
};

void administracion(Usuarios admi,FILE*altaveterinarios,veterinarios altav);
void recepcionista(Mascota masc);
//void atencionvet();
void regvet(FILE*altaveterinarios,Usuarios admi); 
//============================================================PRINCIPAL============================================================
main()
{
	int opcion	;
	Usuarios admi;
	Mascota masc;
	veterinarios altav;
	FILE *altaveterinarios;

	
	
	do
	{
		system("cls");
	printf("\nMenu principal\n");
 	printf("\n=========================\n");
 	printf("\n1.- Modulo Administracion\n");
 	printf("\n2.- Modulo Asistente\n");
 	printf("\n3.- Modulo Veterinarios\n");
 	printf("\n4.- cerrar programa\n");
 	printf("\nIngrese una opción: _");
	scanf("%d", &opcion);
	
 	switch(opcion)
	 {
	 	case 1: administracion(admi,altaveterinarios,altav);
	 	
	 	system("pause");
	 	break;
	 	
	 	case 2: recepcionista(masc);
	 	
	 	system("pause");
	 	break;
	 	
	 	case 3: //atencionvet();
	 		printf("3.- Atenciones por Veterinarios\n");
	 		system("pause");
	 	break;
	 	
	 	case 4:// mejorveterinario();
	 	printf("4.- Ranking de Veterinarios por Atenciones\n");
	 	system("pause");
	 	break;
	 	
 	
		
	}
	
	
	
	

	}while(opcion!=4);
	
	
}

//============================================================ADMINISTRACION============================================================	
void administracion(Usuarios admi,FILE*altaveterinarios,veterinarios altav)
{	
	char usuario[10], contra[10];
	bool login=false;
	int opcion,compara,compara2;
	
	altaveterinarios=fopen("Usuario.dat","a+b");
	
	fseek( altaveterinarios, 0, SEEK_END );
	
	if (ftell( altaveterinarios ) == 0 )
	{
  		// fichero vacio	
  
		printf("\nBienvenido, cree su cuenta por unica vez: \n\n");
		printf("\nIngrese su nombre y apellido: ");
		_flushall();
		gets(admi.Apenom);
		printf("\nIngrese su nuevo usuario: ");
		_flushall();
		gets(admi.usuario);
		printf ("\nElija una contraseña: ");
		_flushall();
		gets(admi.contra);
		
		fwrite(&admi,sizeof(admi),1,altaveterinarios);
		
		printf("\nSu usuario fue registrado\n");
	}
	fclose(altaveterinarios);
	
	system("pause");
	
	altaveterinarios=fopen("Usuario.dat","rb");
	
	system("cls");
	
	printf("\nIngrese su usuario: ");
	_flushall();
	gets(usuario);
	
	printf("\nIngrese su contraseña: ");
	_flushall();
	gets(contra);
	
	rewind(altaveterinarios);
	fread(&admi,sizeof(admi),1,altaveterinarios);
    
	while (!feof(altaveterinarios))
	{
		compara=strcmp(admi.usuario,usuario);
		compara2=strcmp(admi.contra,contra);
		
		if (compara+compara2==0)
		{
			login=true;
		};
		
		fread(&admi,sizeof(admi),1,altaveterinarios);
	};
	
	if(login)
	{
		printf("\nBienvenido\n\n");
	
		do
		{
			system("cls");
			printf("\nMódulo Administracion\n");
		 	printf("\n=========================\n");
		 	printf("\n1.- Registrar Veterinario\n");
		 	printf("\n2.- Registrar Usuario Asistente\n");
		 	printf("\n3.- Atenciones por Veterinarios\n");
			printf("\n4.- Ranking de Veterinarios por Atenciones\n");
		 	printf("\n5.- Cerrar la aplicación.\n");
		 	printf("\nIngrese una opción: _");
			 scanf("%d", &opcion);
			 switch(opcion)
			 {
			 	case 1: regvet(altaveterinarios,admi); 
			 	printf("1.- Registrar Veterinario\n");
			 	system("pause");
			 	break;
			 	
			 	case 2: //regrecepcionista();
			 	printf("2.- Registrar Usuario Asistente\n");
			 	system("pause");
			 	break;
			 	
			 	case 3: //atencionvet();
			 		printf("3.- Atenciones por Veterinarios\n");
			 		system("pause");
			 	break;
			 	
			 	case 4:// mejorveterinario();
			 	printf("4.- Ranking de Veterinarios por Atenciones\n");
			 	system("pause");
			 	break;
			 	
			 	case 5: 
			 	
			 	printf("\nGracias por utilizar nuestros servicios.");
			 	
			 	break;
			 	
			 	
			 	default:
				printf("Ingreso una opcion incorrecta, ingrese nuevamente");
				break;
			 		
			 }
		 
		}while(opcion!=5);
	}
	else
	{
		printf("\n\nIngreso mal su usuario o contraseña, vuelva a intentarlo\n");
	}
	fclose(altaveterinarios);

}

void regvet(FILE*altaveterinarios,Usuarios admi)
{
	altaveterinarios=fopen("Veterinarios.dat","a+b");
	
		
	printf("Ingrese el Nombre y apellido del profesional: ");
	_flushall();
	gets(admi.Apenom);
	
	printf("Ingrese su usuario para el inicio de sesion");
	_flushall();
	gets(admi.usuario);
	
	printf("Ingrese su contraseña");
	gets(admi.contra);
	
	fwrite(&admi,sizeof(Usuarios),1,altaveterinarios);

	 


	

	
	fclose(altaveterinarios);
}



//============================================================RECEPCION============================================================
void recepcionista(Mascota masc)
{
	int opcion;
	do
	{
		
		printf("\n		Modulo del Asistente\n");
		printf("\n	 =========================\n");
		printf("\n	 1.- Iniciar Sesión\n");
		printf("\n	 2.- Registrar Mascota\n");
		printf("\n	 3.- Registrar Turno\n");
		printf("\n	 4.- Listado de Atenciones por Veterinario y Fecha\n");
		printf("\n	 5.- Cerrar la aplicación.\n");
		printf("\n	 Ingrese una opción: _\n");
		scanf("%d", &opcion);
		
		switch(opcion)
	 {
	 	case 1:// iniciosesion(); 
	 	
	 	system("pause");
	 	break;
	 	
	 	case 2: //regmascota();
	 	
	 	system("pause");
	 	break;
	 	
	 	case 3: //registrarturno();
	 	
	 		system("pause");
	 	break;
	 	
	 	case 4: //atencionvet();
	 
	 	system("pause");
	 	break;
	 	
	 	case 5: 
	 	
	 	printf("\nGracias por utilizar nuestros servicios.");
	 	
	 	break;
	 	
	 	
	 	default:
		printf("Ingreso una opcion incorrecta, ingrese nuevamente");
		break;
	 		
	 }
 
}while(opcion!=5);
		
		
}


//============================================================VETERINARIO============================================================
/*void atencionvet()
{
	
	do
	{
			printf("\nModulo Consultorio Veterinario\n");
			printf("\n =========================\n");
			printf("\n 1.- Iniciar Sesión\n");
			printf("\n 2.- Visualizar Lista de Espera de Turnos (informe)\n");
			printf("\n 3.- Registrar Evolución de la Mascota\n");
			printf("\n 4.- Cerrar la aplicación.\n");
			printf("\n Ingrese una opción: _ \n");
			scanf("%d",&opcion);
			
	
		
		switch(opcion)
	 {
	 	case 1:// iniciosesion(); 
	 	
	 	system("pause");
	 	break;
	 	
	 	case 2: //espera_mascota();
	 	
	 	system("pause");
	 	break;
	 	
	 	case 3: //evolucionmascota();
	 	
	 		system("pause");
	 	break;
	 	
	 	case 4:	printf("\nGracias por utilizar nuestros servicios.");
	 	
	 
	 	system("pause");
	 	break;
	 	
	
	 	default:
		printf("Ingreso una opcion incorrecta, ingrese nuevamente");
		break;
	 		
	 }
 
	}while(opcion!=4);

		
}	
	*/
