#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include <iostream>

/*Modulo de Administracion: 
	*Alta veterinario sistema
	*Borrar al veterinario del sistema, junto a sus datos
	*borrar al empleado del sistema
	*Dar de alta a masocta ya curada
	*Se otorga un bono al veterinario que mas turnos haya atendido
			
modulo recepcion:
	*Se hace el ingreso de las mascotas, datos necesarios:Apellido y Nombres de la mascota (el
apellido corresponde al due�o o familia), DNI del due�o, Localidad, Edad (calculada con la fecha de nacimiento
registrada), Peso.
	* Debemos permitir obtener el informe de la historia clinica de la mascot
	
modulo consultorio:
	el vetereniario ingresa con su numero de matricula y contrase�a 
	se habre un menu de opciones:
		1. llama por apellido y nombre a la mascota que atendera 
		 *poner estado evolucion de la mascota maximo 380
		 * (historia clinica, comun a todos)
		  se debe dejar registro del veterinario que escribio el estado de evolucion junto a la fecha
	   	*se borra la mascota del listado
		   */
 /*Bueno yo creo que nos falta esto lo digo por pasos
M�dulo recepci�n 
Ingresar a la mascota *
Darle un turno a la mascota *
M�dulo consultorio
Poder visualizar los turnos seg�n el d�a (necesita ingresar matricular para verlo) *
Dar la evoluci�n de la mascota y borrar el turno  
M�dulo recepci�n 
Pod�s visualizar las atenciones por fecha y veterinario
M�dulo administraci�n
Visualizar las atenciones dadas en el mes 
Dar bono mensual*/
		   
////============================================================FUNCIONES Y ESTRUCTURAS============================================================

struct Usuarios
{
	char usuario[10];
	char contra[10];
	char Apenom[60];
	int matricula;
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
	char apenom[60];
	int Dni_due;
	char domicilio[60];
	char localidad[100];
	fechaN FechaNac;
	char telefono[25];
	char evolucion[380];
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
	char apenom[60];
	
};

void administracion(Usuarios admi,FILE*altaveterinarios,veterinarios altav);

void recepcionista(Mascota masc, FILE*altaveterinarios,Usuarios admi,turnos turnos_ok,FILE *turnosok);
void regrecepcionista(FILE*altaveterinarios,Usuarios admi);
void regmascota(Mascota masc, FILE*altaveterinarios);
void registrarturno(Mascota masc, FILE*altaveterinarios,turnos turnos_ok,FILE *turnosok,Usuarios admi);

void atencionvet(Mascota masc, FILE*altaveterinarios,Usuarios admi,FILE *turnosok,turnos turnos_ok);
void regvet(FILE*altaveterinarios,Usuarios admi);
void espera_mascota(turnos turnos_ok,FILE *turnosok,FILE*altaveterinarios, Usuarios admi);
void evolucionmascota(turnos turnos_ok,FILE *turnosok,FILE*altaveterinarios, Usuarios admi,Mascota masc);
 
//============================================================PRINCIPAL============================================================
using namespace std;
main()
{
	int opcion	;
	Usuarios admi;
	Mascota masc;
	veterinarios altav;
	turnos turnos_ok;
	FILE *altaveterinarios;
	FILE *turnosok;

	do
	{
system("cls");
printf("\n**********************************************************************");	
printf("\n**********************************************************************");	
printf("\n**                                                                  **");
printf("\n**                                                                  **");
printf("\n**                         Menu principal                           **");
printf("\n**                   =========================                      **");
printf("\n**                    1> Modulo Administracion                      **");
printf("\n**                    2> Modulo Asistente                           **");
printf("\n**                    3> Modulo Veterinarios                        **");
printf("\n**                    4> cerrar programa                            **"); 
printf("\n**                                                                  **");
printf("\n**                                                                  **");
printf("\n**                                                                  **"); 
printf("\n**                                                                  **");
printf("\n**                         @@@         @@@                          **");
printf("\n**                       @@@@@@@    @@@@@@@                         **");
printf("\n**                      @@@@@@@@   @@@@@@@@                         **");
printf("\n**                 @@@   @@@@@@@   @@@@@@@@  @@@@                   **");
printf("\n**                @@@@@@   @@@@      @@@@   @@@@@@                  **");
printf("\n**                 @@@@@@    @@@@@@@@@@    @@@@@@                   **");
printf("\n**                         @@@@@@@@@@@@@@                           **");
printf("\n**                      @@@@@@@@@@@@@@@@@@@                         **");
printf("\n**                     @@@@@@@@@@@@@@@@@@@@@@                       **");
printf("\n**                    @@@@@@@@@@@@@@@@@@@@@@@                       **");
printf("\n**                     @@@@@@@@@@@@@@@@@@@@@                        **");
printf("\n**                       @@@@@@@@@@@@@@@@@@                         **");               
printf("\n**************                @@@@@@@@                       *********");    
printf("\n**********************************************************************");	   
printf("\n\nIngrese una opcion: ");  
scanf("%d", &opcion);
	
 	switch(opcion)
	 {
	 	case 1: administracion(admi,altaveterinarios,altav);
	 	
	 	system("pause");
	 	break;
	 	
	 	case 2: recepcionista(masc,altaveterinarios,admi,turnos_ok,turnosok);
	 	
	 	system("pause");
	 	break;
	 	
	 	case 3: atencionvet(masc,altaveterinarios,admi,turnosok,turnos_ok);

	 	system("pause");
	 	break;
	 	
	 	case 4:// mejorveterinario();
system("cls");
printf("\n\n");
printf("\n@@@@@@@        @@@@@@@       @@@@@@@     @@@     @@@@ @@@@@@@@@@@@  @@@      @@@");
printf("\n @@@@@@@       @@@@@@@      @@@@@@@      @@@     @@@@ @@@@@@@@@@@@  @@@@@    @@@");
printf("\n  @@@@@@@@     @@@@@@@     @@@@@@@       @@@     @@@@     @@@@      @@@@@@   @@@");
printf("\n    @@@@@@@@@  @@@@@@@ @@@@@@@@@@        @@@     @@@@     @@@@      @@@ @@@  @@@");
printf("\n     @@@@@@@@@@@@@@@@@@@@@@@@            @@@     @@@@     @@@@      @@@  @@@ @@@");
printf("\n         @@@@@@@@@@@@@@@@@@              @@@@    @@@@     @@@@      @@@   @@@@@@");
printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@      @@@@@@@@@@      @@@@      @@@     @@@@");
printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                                            ");
printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     @@@@@@@@@@@  @@@@@@@@@@@  @@@@@@@@@@@@@");
printf("\n            @@@@@@@@@@@@@                @@@@         @@@@    @@@@      @@@@    ");
printf("\n       @@@@@@@@@@@@@@@@@@@@@@            @@@@         @@@@     @@@      @@@@    ");
printf("\n     @@@@@@@@@@@@@@@@@@@@@@@@@@@         @@@@@@@@@@   @@@@@@@@@@@       @@@@    ");
printf("\n   @@@@@@@@    @@@@@@@   @@@@@@@@@       @@@@         @@@@   @@@@       @@@@    ");
printf("\n  @@@@@@@      @@@@@@@      @@@@@@@      @@@@         @@@@    @@@@      @@@@    ");
printf("\n @@@@@@@       @@@@@@@       @@@@@@@     @@@@         @@@@     @@@@     @@@@    ");
printf("\n\n                                PARTICIPANTES:");
printf("\n                                -Navarro Jorge");
printf("\n                                -Martinez Lucas");
printf("\n                                -Olivares Clara");
printf("\n                                -Lopez Camila");
printf("\n                                -Abril Moreno\n\n\n");
system("pause");
	 	break;
	 		
	}

	}while(opcion!=4);
		
}

//============================================================ADMINISTRACION=======================================================	
void administracion(Usuarios admi,FILE*altaveterinarios,veterinarios altav)
{	
	char usuario[10], contra[10],aux[10],auxcontra[10];
	bool login=false,error=false,contrase=false;
	int opcion=0,compara=0,compara2=0,longitud=0;
	
	altaveterinarios=fopen("Usuario.dat","a+b");
	
	fseek(altaveterinarios, 0, SEEK_END );
	
	if (ftell(altaveterinarios ) == 0 )
	{
  		// fichero vacio	
  		system("cls");
		printf("\n\nBienvenido, cree su cuenta por unica vez!!\n\n");
		
	do{
		int digito=0,mayus=0,c=0;
		printf("------------- * -------------");
		printf("\nSu usuario debe:\n-Contener entre 6 y 10 caracteres\n-Comenzar con una letra minuscula\n-Tener al menos 2 letras mayusculas\n-Tener como maximo 3 digitos");
		printf("\n------------- * -------------");
		printf("\n\n>>Ingrese su nuevo usuario: ");
		_flushall();
		gets(admi.usuario);
		
	//	printf("\n");
	//	printf("--Ingreso: ");
	//	puts(admi.usuario);
		
		
		longitud = strlen(admi.usuario);
	//	printf("\n--Tiene %d longitud",longitud);
		
		for(int i=0;i<=longitud;i++)
		{
			aux[i]=admi.usuario[i];
		}
		int i=0;
		while(aux[i]!='\0')
     	{
	     	if((aux[i]>='0') && (aux[i]<='9'))
	     	{digito++;}
			if((aux[i]>='A') && (aux[i]<='Z'))
			{mayus++;}
			i++;
     	}
     	
     //	printf("\n--Tiene %d digitos y %d mayusculas",digito,mayus);
	//	printf("\n--Primer caracter %c",aux[0]);
		
			if((aux[0]>='a') && (aux[0]<='z') && (longitud>5) && (longitud<11) && (digito<4) && (mayus>1))
				{
					error=true;
				}
			else
				{
					printf("\n");
					printf("\n------------- * -------------");
					printf("\n  No cumple alguna condicion ");
					printf("\n------------- * -------------");
					printf("\n\nSi desea salir presione 1, si quiere volver a intentar presione otra tecla: ");
					scanf("%d", &c);
					if(c==1)
					{
						printf("\n");
						fclose(altaveterinarios);
						printf("\n");
						return;
					}
					system("cls");
					
			    }
		}while(error!=true);
		
		printf("\n\nSe registro correctamente,continuemos con la contrase�a....\n\n");
		printf("\n");
		system("pause");
				
		
		do
		{
			int digitcon=0,maycon=0,caracterespecial=0,longitudcontra=0,mincon=0,c=0;
			bool consecutivo=false;
			printf("\n\n");
			printf("------------- * -------------");
			printf ("\nSu contrasena debe: \n-Debe contener al menos una letra mayuscula, una minuscula y un numero\n-No puede contener caracteres especiales\n-Debe tener entre 6 y 10 caracteres\n-No debe tener mas de 3 numeros consecutivos\n-No debe tener 2 letras consecutivas");
			printf("\n------------- * -------------");
			printf ("\n\n>>Elija una contraseNa: ");
			_flushall();
			gets(admi.contra);
			
		//	printf("\n--Lo ingresado fue:");
		//	puts(admi.contra);
			longitudcontra = strlen(admi.contra);
			for(int j=0;j<=longitudcontra;j++)
			{
				auxcontra[j]=admi.contra[j];
			}
			int j=0;
			while(auxcontra[j]!='\0')
	     	{
		     	if((auxcontra[j]>='0') && (auxcontra[j]<='9'))
		     	{digitcon++;}
				if((auxcontra[j]>='A') && (auxcontra[j]<='Z'))
				{maycon++;}
				if((auxcontra[j]>='a') && (auxcontra[j]<='z'))
				{mincon++;}
				if(((auxcontra[j]>=32) && (auxcontra[j]<=47)) || ((auxcontra[j]>=58) && (auxcontra[j]<=64)) || ((auxcontra[j]>=91) && (auxcontra[j]<=96)) || ((auxcontra[j]>=123) && (auxcontra[j]<=255)))
				{caracterespecial++;}
				j++;
	     	}
	     	
	     	int auxnova;
	     	
			 for(int j=0;j<longitudcontra;j++)
			 {
			 	if(((auxcontra[j]>=65) && (auxcontra[j]<=90)) || ((auxcontra[j]>=97) && (auxcontra[j]<=122)))
			 	{
			 		auxnova=auxcontra[j];
					if(auxnova==auxcontra[j])
					{
						if(auxnova+1==auxcontra[j+1])
						{
							consecutivo=true;
							printf("\nERROR  - No debe tener dos caracteres consecutivos -  ERROR");
							printf("\n\n");
							break;
						}
					}
				}
			 	if(((auxcontra[j]>=48) && (auxcontra[j]<=57))) 
			 	{
				 	auxnova=auxcontra[j];
					if(auxnova==auxcontra[j])
					{
						if(auxnova+1==auxcontra[j+1])
						{
							if(auxnova+2==auxcontra[j+2])
							{
								consecutivo=true;
								printf("\nERROR  - No debe tener 3 caracteres numericos -  ERROR");
								printf("\n");
								break;
							}
						}
					}
				}	
			 }	
	
	//	printf("\n--El numero digitos es %d, el numero de mayus es %d",digitcon,maycon);	
	//	printf("\n--El numero minus es %d",mincon);	
	//	printf("\n--El numero de caracteres especiales es %d",caracterespecial);
	//	printf("\n--La longitud es %d",longitudcontra );
		
		if((consecutivo==false)&&(digitcon>0)&&(maycon>0)&&(mincon>0)&&(caracterespecial==0)&&(longitudcontra>5)&&(longitudcontra<11))
		{contrase=true;}
		else
		{
					printf("\n\n----------------------- * -----------------------");
					printf("\n  No cumple alguna condicion, ingrese nuevamente ");
					printf("\n----------------------- * -----------------------");
					printf("\n\nSi desea salir presione 1, si quiere volver a intentar presione otra tecla: ");
					scanf("%d", &c);
					if(c==1)
					{
						printf("\n");
						fclose(altaveterinarios);
						printf("\n");
						return;
					}	
					
					system("cls");
					
		}
		}while(contrase!=true);
		
		printf("\n>>Ingrese su nombre y apellido: ");
		_flushall();
		gets(admi.Apenom);
		
		fwrite(&admi,sizeof(admi),1,altaveterinarios);//esto escribe el usuario en el archivo
		
		printf("\n\nSu usuario fue registrado satisfactoriamente!!!!\n\n\n");
		system("pause");
	}
	fclose(altaveterinarios);
	
	
	altaveterinarios=fopen("Usuario.dat","rb");
	
	system("cls");
	printf("\n=====Iniciar sesion=====");	
	printf("\n>>Ingrese su usuario: ");
	_flushall();
	gets(usuario);
	
	printf("\n>>Ingrese su contrase�a: ");
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
	
	
	if(login==true)
	{   printf("\n");
	    printf("\n>>-------- * --------<<");
		printf("\n      Bienvenido       ");
		printf("\n>>-------- * --------<<");
		printf("\n");
		printf("\n Logro ingresar correctamente\n");
		printf("\n");
		system("pause");
		
		do
		{
system("cls");
printf("\n**********************************************************************");	
printf("\n**********************************************************************");
printf("\n**                                                                  **");
printf("\n**                                                                  **");	
printf("\n**                  M�dulo Administracion                           **");
printf("\n**                =========================                         **");
printf("\n**                1> Registrar Veterinario                          **");
printf("\n**                2> Registrar Usuario Asistente                    **");
printf("\n**                3> Atenciones por Veterinarios                    **");
printf("\n**                4> Ranking de Veterinarios por Atenciones         **");
printf("\n**                5> Volver al menu anterior                        **");
printf("\n**                                                                  **");
printf("\n**                                                                  **");
printf("\n**                                                                  **");
printf("\n**                                                                  **");
printf("\n**                                                                  **");
printf("\n**                                                                  **");
printf("\n**                                                                  **");
printf("\n**                                                                  **");
printf("\n**                                                                  **");
printf("\n**                                                                  **");
printf("\n**                                                                  **");
printf("\n**                                                                  **");
printf("\n**                                                                  **");
printf("\n**                                                                  **");
printf("\n**                                                                  **");
printf("\n**                                                                  **");               
printf("\n**********************************************************************");    
printf("\n**********************************************************************");	
printf("\n Ingrese una opcion: ");
scanf("%d", &opcion);
			 switch(opcion)
			 {
			 	case 1: regvet(altaveterinarios,admi); 
			
			 	system("pause");
			 	break;
			 	
			 	case 2: regrecepcionista(altaveterinarios,admi);
			
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
			 	printf("\n");
				printf("\nERROR  - Ingreso una opcion incorrecta, ingrese nuevamente -  ERROR");
				printf("\n\n");
				break;
			 		
			 }
		 
		}while(opcion!=5);
	}
	else
	{
		printf("\n-------------------------- * --------------------------");
		printf("\nIngreso mal su usuario o contrase�a, intente nuevamente");
		printf("\n-------------------------- * --------------------------");
		printf("\n\n");
	}
	fclose(altaveterinarios);

}

void regvet(FILE*altaveterinarios,Usuarios admi)
{
	int longitud,repite;
	char usuario[10], contra[10],aux[10],auxcontra[10];
	bool login=false,error=false,contrase=false;
	altaveterinarios=fopen("Veterinarios.dat","a+b");
	
	do{
		bool repeticion=false;
		int digito=0,mayus=0,c=0;
		system("cls");
		printf("\n");
		printf("\n------------- * -------------");
		printf("\nEl usuario del veterinario debe:\n-Contener entre 6 y 10 caracteres\n-Comenzar con una letra minuscula\n-Tener al menos 2 letras mayusculas\n-Tener como maximo 3 digitos");
		printf("\n------------- * -------------");
		printf("\n\n>>Ingrese usuario del veterinario: ");
		_flushall();
		gets(admi.usuario);
		
	//	printf("\n");
	//	printf("--Ingreso: ");
	//	puts(admi.usuario);
		
		
		longitud = strlen(admi.usuario);
	//	printf("\n--Tiene %d longitud",longitud);
		
		for(int i=0;i<=longitud;i++)
		{
			aux[i]=admi.usuario[i];
		}
		int i=0;
		while(aux[i]!='\0')
     	{
	     	if((aux[i]>='0') && (aux[i]<='9'))
	     	{digito++;}
			if((aux[i]>='A') && (aux[i]<='Z'))
			{mayus++;}
			i++;
     	}
     	
     //	printf("\n--Tiene %d digitos y %d mayusculas",digito,mayus);
	//	printf("\n--Primer caracter %c",aux[0]);
		
		rewind(altaveterinarios);
		fread(&admi.usuario,sizeof(admi),1,altaveterinarios);
		
	while (!feof(altaveterinarios))
		{
			repite=strcmp(aux,admi.usuario);
			printf("\nAux: %s,admi.usuario: %s\n",aux,admi.usuario);
			
			if (repite==0)
			{
				repeticion=true;
				printf("\n");
				printf("\nERROR  - El nombre de usuario ingresado, ya esta registrado -  ERROR");
				printf("\n");
				break;
			}
			
			fread(&admi.usuario,sizeof(admi),1,altaveterinarios);
		}
		
			for(int i=0;i<=longitud;i++)
		{
			admi.usuario[i]=aux[i];
		}
	
			if((aux[0]>='a') && (aux[0]<='z') && (longitud>5) && (longitud<11) && (digito<4) && (mayus>1) && (repeticion==false))
				{
					error=true;
				}
			else
				{
					printf("\n----------------------- * -----------------------");
					printf("\n  No cumple alguna condicion, ingrese nuevamente ");
					printf("\n----------------------- * -----------------------");
					printf("\nSi desea salir presione 1, si quiere volver a intentar presione otra tecla: ");
					scanf("%d", &c);
					if(c==1)
					{
						fclose(altaveterinarios);
						return;
					}
					system("cls");
					
			    }
	}while(error!=true);
		
		printf("\n\nSe registro correctamente,continuemos con la contrase�a....\n\n");
		system("pause");			
	
	
		do
		{
			int digitcon=0,maycon=0,caracterespecial=0,longitudcontra=0,mincon=0,c=0;
			bool consecutivo=false;
			printf("\n");
			printf("\n------------- * -------------");
			printf ("\nLa contrase�a del veterinario debe tener: \n-Al menos una letra mayuscula, una minuscula y un numero\n-No puede contener caracteres especiales\n-Debe tener entre 6 y 10 caracteres\n-No debe tener mas de 3 numeros consecutivos\n-No debe tener 2 letras consecutivas");
			printf("\n------------- * -------------");
			printf ("\n\n>>Elija una contrase�a: ");
			_flushall();
			gets(admi.contra);
			
	//		printf("\n-Lo ingresado fue:");
	//		puts(admi.contra);
			longitudcontra = strlen(admi.contra);
			for(int j=0;j<=longitudcontra;j++)
			{
				auxcontra[j]=admi.contra[j];
			}
			int j=0;
			while(auxcontra[j]!='\0')
	     	{
		     	if((auxcontra[j]>='0') && (auxcontra[j]<='9'))
		     	{digitcon++;}
				if((auxcontra[j]>='A') && (auxcontra[j]<='Z'))
				{maycon++;}
				if((auxcontra[j]>='a') && (auxcontra[j]<='z'))
				{mincon++;}
				if(((auxcontra[j]>=32) && (auxcontra[j]<=47)) || ((auxcontra[j]>=58) && (auxcontra[j]<=64)) || ((auxcontra[j]>=91) && (auxcontra[j]<=96)) || ((auxcontra[j]>=123) && (auxcontra[j]<=255)))
				{caracterespecial++;}
				j++;
	     	}
	     	
	     	int auxnova;
	     	
			 for(int j=0;j<longitudcontra;j++)
			 {
			 	if(((auxcontra[j]>=65) && (auxcontra[j]<=90)) || ((auxcontra[j]>=97) && (auxcontra[j]<=122)))
			 	{
			 		auxnova=auxcontra[j];
					if(auxnova==auxcontra[j])
					{
						if(auxnova+1==auxcontra[j+1])
						{
							consecutivo=true;
							printf("\nERROR  - No debe tener dos caracteres consecutivos -  ERROR");
							printf("\n");
							break;
						}
					}
				}
			 	if(((auxcontra[j]>=48) && (auxcontra[j]<=57))) 
			 	{
				 	auxnova=auxcontra[j];
					if(auxnova==auxcontra[j])
					{
						if(auxnova+1==auxcontra[j+1])
						{
							if(auxnova+2==auxcontra[j+2])
							{
								consecutivo=true;
								printf("\nERROR  - No debe tener 3 caracteres numericos -  ERROR");
								printf("\n");
								break;
							}
						}
					}
				}	
			 }	
	
	//	printf("\n--El numero digitos es %d, el numero de mayus es %d",digitcon,maycon);	
	//	printf("\n--El numero minus es %d",mincon);	
	//	printf("\n--El numero de caracteres especiales es %d",caracterespecial);
	//	printf("\n--La longitud es %d",longitudcontra );
		
		if((consecutivo==false)&&(digitcon>0)&&(maycon>0)&&(mincon>0)&&(caracterespecial==0)&&(longitudcontra>5)&&(longitudcontra<11))
		{contrase=true;}
		else
		{
				
					printf("\n----------------------- * -----------------------");
					printf("\n  No cumple alguna condicion, ingrese nuevamente ");
					printf("\n----------------------- * -----------------------");	
					printf("\nSi desea salir presione 1, si quiere volver a intentar presione otra tecla: ");
					scanf("%d", &c);
					if(c==1)
					{
						printf("\n");
						fclose(altaveterinarios);
						printf("\n");
						return;
					}
					system("cls");
					
		}
		}while(contrase!=true);
		
		printf("\n>>Ingrese el Nombre y apellido del profesional: ");
		_flushall();
		gets(admi.Apenom);
		
		printf("\n>>Ingrese Matricula del profesional: ");
		scanf("%d", &admi.matricula);
		
		fwrite(&admi,sizeof(admi),1,altaveterinarios);//esto escribe el usuario en el archivo
		
		printf("\n\nSu usuario fue registrado satisfactoriamente!!!!\n");
		
	    fclose(altaveterinarios);
	
	
}


void regrecepcionista(FILE*altaveterinarios,Usuarios admi)
{
	int longitud,repite;
	char usuario[10], contra[10],aux[10],auxcontra[10];
	bool login=false,error=false,contrase=false;
	altaveterinarios=fopen("Recepcionistas.dat","a+b");
	
	
	do{
		bool repeticion=false;
		int digito=0,mayus=0,c=0;
		system("cls");
		printf("\n");
	    printf("\n------------- * -------------");
		printf("\nEl usuario del recepcionista debe:\n-Contener entre 6 y 10 caracteres\n-Comenzar con una letra minuscula\n-Tener al menos 2 letras mayusculas\n-Tener como maximo 3 digitos");
		printf("\n------------- * -------------");
		printf("\n\n>>Ingrese usuario del recepcionista: ");
		_flushall();
		gets(admi.usuario);
		
	//	printf("\n");
	//	printf("--Ingreso: ");
	//	puts(admi.usuario);
		
		
		longitud = strlen(admi.usuario);
	//	printf("\n--Tiene %d longitud",longitud);
		
		for(int i=0;i<=longitud;i++)
		{
			aux[i]=admi.usuario[i];
		}
		int i=0;
		while(aux[i]!='\0')
     	{
	     	if((aux[i]>='0') && (aux[i]<='9'))
	     	{digito++;}
			if((aux[i]>='A') && (aux[i]<='Z'))
			{mayus++;}
			i++;
     	}
     	
     //	printf("\n--Tiene %d digitos y %d mayusculas",digito,mayus);
	//	printf("\n--Primer caracter %c",aux[0]);
		
		rewind(altaveterinarios);
		fread(&admi,sizeof(char),1,altaveterinarios);
		
		while (!feof(altaveterinarios))
		{
			repite=strcmp(aux,admi.usuario);
			
			if (repite==0)
			{
				repeticion=true;
				printf("\nERROR  - El nombre de usuario ingresado, ya esta registrado -  ERROR");
				printf("\n");
				break;
			}
			
			fread(&admi,sizeof(char),1,altaveterinarios);
		}
		
			for(int i=0;i<=longitud;i++)
		{
			admi.usuario[i]=aux[i];
		}
		
			if((aux[0]>='a') && (aux[0]<='z') && (longitud>5) && (longitud<11) && (digito<4) && (mayus>1) && (repeticion==false))
				{
					error=true;
				}
			else
				{
					
					printf("\n----------------------- * -----------------------");
					printf("\n  No cumple alguna condicion, ingrese nuevamente ");
					printf("\n----------------------- * -----------------------");
					printf("\nSi desea salir presione 1, si quiere volver a intentar presione otra tecla: ");
					scanf("%d", &c);
					if(c==1)
					{
						printf("\n");
						fclose(altaveterinarios);
						printf("\n");
						return;
					}
					system("cls");
					
			    }
			    
	}while(error!=true);
		
		printf("\n\nSe registro correctamente,continuemos con la contrase�a...\n");
		system("pause");			
	
	
		do
		{
			int digitcon=0,maycon=0,caracterespecial=0,longitudcontra=0,mincon=0,c=0;
			bool consecutivo=false;
					printf("\n");
	        printf("\n------------- * -------------");
			printf ("\nLa contrase�a del recepcionista debe: \n-Tener al menos una letra mayuscula, una minuscula y un numero\n-No puede contener caracteres especiales\n-Debe tener entre 6 y 10 caracteres\n-No debe tener mas de 3 numeros consecutivos\n-No debe tener 2 letras consecutivas"); 
	        printf("\n------------- * -------------");
			printf ("\n\n>>Elija una contrase�a: ");
			_flushall();
			gets(admi.contra);
			
	//		printf("\n--Lo ingresado fue: ");
	//		puts(admi.contra);
			longitudcontra = strlen(admi.contra);
			for(int j=0;j<=longitudcontra;j++)
			{
				auxcontra[j]=admi.contra[j];
			}
			int j=0;
			while(auxcontra[j]!='\0')
	     	{
		     	if((auxcontra[j]>='0') && (auxcontra[j]<='9'))
		     	{digitcon++;}
				if((auxcontra[j]>='A') && (auxcontra[j]<='Z'))
				{maycon++;}
				if((auxcontra[j]>='a') && (auxcontra[j]<='z'))
				{mincon++;}
				if(((auxcontra[j]>=32) && (auxcontra[j]<=47)) || ((auxcontra[j]>=58) && (auxcontra[j]<=64)) || ((auxcontra[j]>=91) && (auxcontra[j]<=96)) || ((auxcontra[j]>=123) && (auxcontra[j]<=255)))
				{caracterespecial++;}
				j++;
	     	}
	     	
	     	int auxnova;
	     	
			 for(int j=0;j<longitudcontra;j++)
			 {
			 	if(((auxcontra[j]>=65) && (auxcontra[j]<=90)) || ((auxcontra[j]>=97) && (auxcontra[j]<=122)))
			 	{
			 		auxnova=auxcontra[j];
					if(auxnova==auxcontra[j])
					{
						if(auxnova+1==auxcontra[j+1])
						{
							consecutivo=true;
							printf("\nERROR  - No debe tener dos caracteres consecutivos - ERROR");
							printf("\n");
							break;
						}
					}
				}
			 	if((auxcontra[j]>=48) && (auxcontra[j]<=57)) 
			 	{
				 	auxnova=auxcontra[j];
					if(auxnova==auxcontra[j])
					{
						if(auxnova+1==auxcontra[j+1])
						{
							if(auxnova+2==auxcontra[j+2])
							{
								consecutivo=true;
								printf("\nERROR  - No debe tener 3 caracteres numericos -  ERROR");
								printf("\n");
								break;
							}
						}
					}
				}	
			 }	
	
	//	printf("\n--El numero digitos es %d, el numero de mayus es %d",digitcon,maycon);	
	//	printf("\n--El numero minus es %d",mincon);	
	//	printf("\n--El numero de caracteres especiales es %d",caracterespecial);
	//	printf("\n--La longitud es %d",longitudcontra );
		
		if((consecutivo==false)&&(digitcon>0)&&(maycon>0)&&(mincon>0)&&(caracterespecial==0)&&(longitudcontra>5)&&(longitudcontra<11))
		{contrase=true;}
		else
		{
				
					printf("\n----------------------- * -----------------------");
					printf("\n  No cumple alguna condicion, ingrese nuevamente ");
					printf("\n----------------------- * -----------------------");	
					printf("\nSi desea salir presione 1, si quiere volver a intentar presione otra tecla: ");
					scanf("%d", &c);
					if(c==1)
					{
						printf("\n");
						fclose(altaveterinarios);
						return;
						printf("\n");
					}
					system("cls");
					
		}
		}while(contrase!=true);
		
		printf("\n>>Ingrese el Nombre y apellido del Recepcionista: ");
		_flushall();
		gets(admi.Apenom);
		
		fwrite(&admi,sizeof(admi),1,altaveterinarios);//esto escribe el usuario en el archivo
		
		printf("\n\nEl usuario del recepcionista fue registrado satisfactoriamente!!!!\n");
		
	    fclose(altaveterinarios);
	
}


//============================================================RECEPCION============================================================
void recepcionista(Mascota masc, FILE*altaveterinarios,Usuarios admi,turnos turnos_ok,FILE *turnosok)
{
	int opcion,compara,compara2;
	bool login=false;
	char usuario[10],contra[10];
	
	altaveterinarios=fopen("Recepcionistas.dat","rb");
	if (altaveterinarios== NULL)
	{
	system("cls");
	printf("\n------------ ATENCION ------------");
	printf("\n No hay recepcionistas registrados");
	printf("\n------------ ATENCION ------------");
	printf("\n");
	return;
	}
	system("cls");
	printf("\n=====Iniciar sesion=====");	
	printf("\n>>Ingrese su usuario: ");
	_flushall();
	gets(usuario);
	
	printf("\n>>Ingrese su contrase�a: ");
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
	
	
	if(login==true)
	{
		printf("\nLogro ingresar, bienvenido!!!!\n");
		printf("\n");	
		system("pause");
		do
		{
system("cls");			
printf("\n**********************************************************************");	
printf("\n**********************************************************************");
printf("\n**                                                                  **");
printf("\n**                                                                  **");	
printf("\n**                 Modulo del Recepcionista                         **");
printf("\n**                =========================                         **");
printf("\n**                1> Registrar Mascota                              **");
printf("\n**                2> Registrar Turno                                **");
printf("\n**                3> Listado de Atenciones por Veterinario y Fecha  **");
printf("\n**                4> Volver al menu anterior                        **");
printf("\n**                                                                  **");
printf("\n**                                                                  **");
printf("\n**                                                                  **");
printf("\n**           @@@@                                       @@@@        **");
printf("\n**         @@@@@@@@@@                               @@@@@@@@@@      **");    
printf("\n**         @@@@@@@@@@@@@@                        @@@@@@@@@@@@@@     **");      
printf("\n**        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     **"); 
printf("\n**         @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@      **");
printf("\n**          @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@      **");           
printf("\n**           @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@       **");
printf("\n**            @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@        **");
printf("\n**          @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@      **");
printf("\n**         @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@     **");
printf("\n**         @@@@@@@@@@@@@@@@@@@@@@@@   @@@@@@@@@@@@@@@@@@@@@@@@@     **");
printf("\n**       @@@@@@@@@@@     @@@@@@@@@     @@@@@@@      @@@@@@@@@@@     **");
printf("\n**      @@@@@@@@@@       @@@@@@@@       @@@@@@        @@@@@@@@@@    **");
printf("\n**      @@@@@@@@@@@@     @@@@@@          @@@@@@     @@@@@@@@@@@@@   **");
printf("\n**      @@@@@@@@@@@@@@@@@@@@@@   @@@@@@    @@@@@@@@@@@@@@@@@@@@@    **");
printf("\n**       @@@@@@@@@@@@@@@          @@@@             @@@@@@@@@@@@@    **");      
printf("\n**********************************************************************");    
printf("\n**********************************************************************");	 
printf("\n\nIngrese una opcion: ");
scanf("%d", &opcion);
			
			switch(opcion)
		 {
		 	case 1: regmascota(masc,altaveterinarios);
		 	
		 	system("pause");
		 	break;
		 	
		 	case 2: registrarturno(masc,altaveterinarios,turnos_ok,turnosok,admi);
		 	
		 		system("pause");
		 	break;
		 	
		 	case 3: //atencionvet();
		 
		 	system("pause");
		 	break;
		 	
		 	case 4: 
		 	
		 	printf("\nGracias por utilizar nuestros servicios.");
		 	
		 	break;
		 	
		 	
		 	default:
			printf("\n");
			printf("\nERROR  - Ingreso una opcion incorrecta, ingrese nuevamente -  ERROR");
			printf("\n\n");
			break;
		 		
		 }
	 
	}while(opcion!=4);
}	
else
{
		printf("\n-------------------------- * --------------------------");
		printf("\nIngreso mal su usuario o contrase�a, intente nuevamente");
		printf("\n-------------------------- * --------------------------");
		printf("\n\n");
}	
	fclose(altaveterinarios);
	
}

void regmascota(Mascota masc, FILE*altaveterinarios)
{
	int aux2,compara,c,longitud;
	char aux[60];
	
	
	altaveterinarios=fopen("Mascotas.dat","a+b");
	
	do
	{
	bool repite=false;
	system("cls");
	printf("\n======Registro de la mascota======");
	printf("\n>>Ingrese el nombre y apellido de la mascota (apellido de familia): ");
	_flushall();
	gets(masc.apenom);
	strlwr(masc.apenom);
	
	longitud = strlen(masc.apenom);
	
	for(int i=0;i<=longitud;i++)
		{
			aux[i]=masc.apenom[i];
		}
	
	printf("\n>>DNI del due�o: ");
	scanf("%d", &masc.Dni_due);
	aux2=masc.Dni_due;
	
	
	rewind(altaveterinarios);
	fread(&masc,sizeof(masc),1,altaveterinarios);
    
	while (!feof(altaveterinarios))
	{
		compara=strcmp(aux,masc.apenom);
		printf("\nAux: %s,masc.apenom: %s\n",aux,masc.apenom);
	
		if (compara==0 && aux2==masc.Dni_due)
		{
			repite=true;
			printf("Mascota ya registrada");
			break;
		}
		
		fread(&masc,sizeof(masc),1,altaveterinarios);
	}   
	
		for(int i=0;i<=longitud;i++)
		{
			masc.apenom[i]=aux[i];
		}
		
		masc.Dni_due=aux2;
		
	if(repite==false)
	{
		fwrite(&masc,sizeof(masc),1,altaveterinarios);
	}
	
	if(repite!=true)
	{
	printf("\n>>Domicilio del due�o: ");
	_flushall();
	gets(masc.domicilio);
	
	printf("\n>>Localidad: ");
	_flushall();
	gets(masc.localidad);
	
	printf("\n--Fecha de nacimiento de la mascota:");
        printf("\n>>Dia: ");
        scanf("%d",&masc.FechaNac.dia);
        printf("\n>>Mes: ");
        scanf("%d",&masc.FechaNac.mes);
        printf("\n>>Anio: ");
        scanf("%d",&masc.FechaNac.year);
        
    printf("\n>>Telefono del due�o: ");
	_flushall();
	gets(masc.telefono);	
	}
	
	
	printf("Quiere registrar otra mascota?\n 1: Si\n 2: No\n ");
	scanf("%d", &c);
	
	}while(c!=2);
	
	fclose(altaveterinarios);
	
}

void registrarturno(Mascota masc, FILE*altaveterinarios,turnos turnos_ok,FILE *turnosok,Usuarios admi)
{
FILE *auxiliarvet;
int Matricula,DNI,dia,mes,year,repiteturno=0,compara,longitud;
bool existe=false,existe2=false, repite=false;
char nombrem[60];



auxiliarvet=fopen("Veterinarios.dat","rb");
altaveterinarios=fopen("Mascotas.dat","rb");	
if (altaveterinarios== NULL)
{
	system("cls");
    printf("\n------------ ATENCION ------------");
    printf("\n    No hay mascotas registradas   ");
    printf("\n------------ ATENCION ------------");
    printf("\n");
  	fclose(auxiliarvet);	
 	fclose(altaveterinarios);
 return;
}
system("cls");
printf("\n");
printf("\n************************************************************************");
printf("\n**                      LISTADO   DE   MASCOTAS                       **");
printf("\n************************************************************************");
printf("\n\n");
	
rewind(altaveterinarios); 
fread(&masc,sizeof(masc),1,altaveterinarios);
 while (!feof(altaveterinarios))
 {
 printf("--->");
 puts(masc.apenom);
 printf("\n");
 fread(&masc,sizeof(masc),1,altaveterinarios);
 }
	
turnosok=fopen("Turnos.dat","a+b");

printf("\n--Ingrese fecha del turno: ");
        printf("\n>>Dia: ");
        scanf("%d",&turnos_ok.fechaturno.dia);
        dia=turnos_ok.fechaturno.dia;
        printf("\n>>Mes: ");
        scanf("%d",&turnos_ok.fechaturno.mes);
        mes=turnos_ok.fechaturno.mes;
        printf("\n>>Anio: ");
        scanf("%d",&turnos_ok.fechaturno.year);
        year=turnos_ok.fechaturno.year;
        
	rewind(turnosok);
	fread(&turnos_ok,sizeof(turnos_ok),1,turnosok);
    
	while (!feof(turnosok))
	{	
		

		if (dia==turnos_ok.fechaturno.dia &&  mes==turnos_ok.fechaturno.mes && year==turnos_ok.fechaturno.year)
		{
			repiteturno++;
		}
			
		fread(&turnos_ok,sizeof(turnos_ok),1,turnosok);
	}   
	if(repiteturno>1)
	{
		printf("\n");
		printf("ERROR  - No se puede registrar mas de 2 turnos por dia -  ERROR");
		printf("\n");
		fclose(auxiliarvet);	
	 	fclose(altaveterinarios);
	 	fclose(turnosok);
		return;
	}
	turnos_ok.fechaturno.dia=dia;
	turnos_ok.fechaturno.mes=mes;
	turnos_ok.fechaturno.year=year;
	
printf("\n>>Ingrese Matricula del veterinario: ");
scanf("%d",&Matricula);

	rewind(auxiliarvet);
	fread(&admi,sizeof(admi),1,auxiliarvet);
    
	while (!feof(auxiliarvet))
	{

		if (Matricula==admi.matricula)
		{
			existe=true;
			turnos_ok.Matriculavet=admi.matricula;
			break;
		}
			
		fread(&admi,sizeof(admi),1,auxiliarvet);
	}   
 if(existe==false)
 {
 	printf("\nERROR  - La matricula no existe - ERROR\n\n");
 	fclose(auxiliarvet);	
 	fclose(altaveterinarios);
 	fclose(turnosok);
 	return;
 }

//IF QUE TRABAJE EN CASO DE QUE EXISTA

printf("\n>>Ingrese DNI del due�o: ");
scanf("%d",&DNI);
	
	rewind(altaveterinarios);
	fread(&masc,sizeof(masc),1,altaveterinarios);
    
		while (!feof(altaveterinarios))
		{
		
			if (DNI==masc.Dni_due)
			{
				existe2=true;
				turnos_ok.Dni_due==DNI;
				printf("\nEL dni existe\n");
				break;
			}
		
			
			fread(&masc,sizeof(masc),1,altaveterinarios);
		}   
		 if(existe2==false)
		 {
		 	printf("\nERROR  - El dni no existe -  ERROR\n\n");
		 	fclose(auxiliarvet);	
 			fclose(altaveterinarios);
 			fclose(turnosok);
		 	return;
		 }
		 
printf("\n>>Ingrese Nombre y apellido de la mascota: ");
_flushall();
gets(nombrem);
strlwr(nombrem);

	rewind(altaveterinarios);
	fread(&masc,sizeof(masc),1,altaveterinarios);

	while (!feof(altaveterinarios))
	{
		compara=strcmp(nombrem,masc.apenom);
		printf("\nAux: %s,masc.apenom: %s\n",nombrem,masc.apenom);
	
		if (compara==0)
		{
			repite=true;
			printf("\nLa mascota esta registrada\n");
			break;
		}
		
		fread(&masc,sizeof(masc),1,altaveterinarios);
	}   
	if(repite==false)
	{
			printf("\nERROR  - La mascota no esta registrada -  ERROR\n\n");
			fclose(auxiliarvet);	
 			fclose(altaveterinarios);
 			fclose(turnosok);
		 	return;
	}	
		longitud = strlen(masc.apenom);
	
		for(int i=0;i<=longitud;i++)
		{
			turnos_ok.apenom[i]=masc.apenom[i];
		}
	


printf("\n>>Evolucion: ");
puts(masc.evolucion);

fwrite(&turnos_ok,sizeof(turnos_ok),1,turnosok);

 fclose(auxiliarvet);	
 fclose(altaveterinarios);
 fclose(turnosok);
}


//============================================================VETERINARIO==========================================================
void atencionvet(Mascota masc, FILE*altaveterinarios,Usuarios admi,FILE *turnosok,turnos turnos_ok)
{
	int opcion,compara,compara2;
	bool login=false;
	char usuario[10],contra[10];
	
	altaveterinarios=fopen("Veterinarios.dat","rb");
	
	if (altaveterinarios== NULL)
	{
	system("cls");
    printf("\n------------ ATENCION ------------");
	printf("\n  No hay Veterinarios registrados ");
    printf("\n------------ ATENCION ------------");
	 return;
	}
	
	system("cls");
	printf("=====Iniciar sesion=====");
	printf("\n>>Ingrese su usuario: ");
	_flushall();
	gets(usuario);
	
	printf("\n>>Ingrese su contrase�a: ");
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
	
	
	if(login==true)
	{
		printf("\nLogro ingresar, bienvenido\n");
		printf("\n\n");
		system("pause");
		do
		{
system("cls");		
printf("\n**********************************************************************");	
printf("\n**********************************************************************");	
printf("\n**                                                                  **");
printf("\n**                                                                  **");
printf("\n**              Modulo Consultorio Veterinario                      **");
printf("\n**              ==============================                      **");
printf("\n**        1> Visualizar Lista de Espera de Turnos (informe)         **");
printf("\n**        2> Registrar Evolucion de la Mascota                      **");
printf("\n**        3> Volver al menu anterior                                **");   
printf("\n**                                                                  **");
printf("\n**                                                                  **");
printf("\n**                                                                  **");
printf("\n**                                                                  **");
printf("\n**                                                                  **");
printf("\n**                                                                  **");
printf("\n**                                                                  **");
printf("\n**          @@@@@@@@@@                         @@@@@@@@@@           **");     
printf("\n**        @@@@@@@@@@@@@@                     @@@@@@@@@@@@@@         **");     
printf("\n**       @@@@@@@@@@@@@@@@                  @@@@@@@@@@@@@@@@@        **");     
printf("\n**        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@        **");     
printf("\n**        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@         **");   
printf("\n**          @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@           **");   
printf("\n**        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@         **");     
printf("\n**       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@        **");     
printf("\n**       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@        **");     
printf("\n**        @@@@@@@@@@@@@@@                   @@@@@@@@@@@@@@@         **");   
printf("\n**          @@@@@@@@@@@@                       @@@@@@@@@@@@         **");      
printf("\n**              @@@@@                             @@@@@             **");
printf("\n**********************************************************************");
printf("\n**********************************************************************");    
printf("\n\nIngrese una opcion: "); 
scanf("%d",&opcion);
							
			switch(opcion)
		 {
		 	
		 	case 1: espera_mascota(turnos_ok,turnosok,altaveterinarios,admi);
		 	
		 	system("pause");
		 	break;
		 	
		 	case 2: evolucionmascota(turnos_ok,turnosok,altaveterinarios,admi,masc);
		 	
		 		system("pause");
		 	break;
		 	
		 	case 3:	printf("\nGracias por utilizar nuestros servicios.\n");
		 	break;
		 	
		 	default:
			printf("\n");
			printf("\nERROR  - Ingreso una opcion incorrecta, ingrese nuevamente -  ERROR");
			printf("\n\n");
			break;
		 		
		 }
	 
		}while(opcion!=3);
	}
	else
	{
		printf("\n-------------------------- * --------------------------");
		printf("\nIngreso mal su usuario o contrase�a, intente nuevamente");
		printf("\n-------------------------- * --------------------------");
		printf("\n\n");
	}	
		fclose(altaveterinarios);
		
}	

void espera_mascota(turnos turnos_ok,FILE *turnosok,FILE*altaveterinarios, Usuarios admi)
{
	int openmat,compara;
	bool acceso=false;
	char contra[10];

	
		 
	altaveterinarios=fopen("Veterinarios.dat","rb");
	
	system("cls");
	printf("\n=====Ver Turnos====");
	printf("\n>>Ingrese su matricula: ");
	scanf("%d", &openmat);
	printf("\n>>Ingrese su contrase�a: ");
	_flushall();
	gets(contra);
	
	rewind(altaveterinarios);
	fread(&admi,sizeof(admi),1,altaveterinarios);
	
  	while (!feof(altaveterinarios))
	{
		
		compara=strcmp(admi.contra,contra);
		
		if (compara==0 && openmat==admi.matricula)
		{
			acceso=true;
		};
		
		fread(&admi,sizeof(admi),1,altaveterinarios);
	};
	
	 if(acceso==false)
		 {
		printf("\n--------------------------- * ---------------------------");
		printf("\nIngreso mal su contrase�a o matricula, intente nuevamente");
		printf("\n--------------------------- * ---------------------------");
		printf("\n\n");
		fclose(altaveterinarios);
		 	return;
		 }
		 
	 printf("\nLogro ingresar correctamente!!!!\n\n\n");
	 system("pause");
	 system("cls");
	 
	turnosok=fopen("Turnos.dat","rb");
	printf("\n=====Ver Turnos====");
	rewind(turnosok);
	fread(&turnos_ok,sizeof(turnos_ok),1,turnosok);
    
	while (!feof(turnosok))
	{
		if(openmat==turnos_ok.Matriculavet)
		{
			printf("\nMascota: %s",turnos_ok.apenom);
			printf("\nDia: %d",turnos_ok.fechaturno.dia);
			printf("\nMes: %d",turnos_ok.fechaturno.mes);
			printf("\nAnio: %d",turnos_ok.fechaturno.year);
			printf("\n=======================\n");
		}
		fread(&turnos_ok,sizeof(turnos_ok),1,turnosok);
	};
	
	fclose(altaveterinarios);
	fclose(turnosok);
	
	
	
}

void evolucionmascota(turnos turnos_ok,FILE *turnosok,FILE*altaveterinarios, Usuarios admi,Mascota masc)
{
	int openmat,compara=1,continuar;
	bool acceso=false;
	char contra[10];
	
	altaveterinarios=fopen("Veterinarios.dat","rb");
	
	system("cls");
	printf("\n====Evolucion Mascota====");
	printf("\n>>Ingrese su matricula: ");
	scanf("%d", &openmat);
	printf("\n>>Ingrese su contrase�a: ");
	_flushall();
	gets(contra);
	
	rewind(altaveterinarios);
	fread(&admi,sizeof(admi),1,altaveterinarios);
	
  	while (!feof(altaveterinarios))
	{
		
		compara=strcmp(admi.contra,contra);
		
		if (compara==0 && openmat==admi.matricula)
		{
			acceso=true;
		};
		
		fread(&admi,sizeof(admi),1,altaveterinarios);
	}
	
	 if(acceso==false)
		 {
		printf("\n--------------------------- * ---------------------------");
		printf("\nIngreso mal su contrase�a o matricula, intente nuevamente");
		printf("\n--------------------------- * ---------------------------");
		printf("\n\n");
		 	fclose(altaveterinarios);
		 	return;
		 }
		 
	printf("\nLogro ingresar correctamente!!!!\n\n\n");
	system("pause");
	system("cls");
	fclose(altaveterinarios);	 
	
	//======================================================== YA DENTRO ==============
	turnosok=fopen("Turnos.dat","r+b");
	altaveterinarios=fopen("Mascotas.dat","r+b");
	bool encontrado;
	encontrado=false;
	FILE *ArchTemp;
	ArchTemp = fopen("Turnosaux.dat","w+b"); //Se crea un archivo de respaldo.
	rewind(turnosok);
	fread(&turnos_ok,sizeof(turnos_ok),1,turnosok);
    
	while (!feof(turnosok))
	{
		if(openmat==turnos_ok.Matriculavet)
		{
			printf("\nLa matricula esta\n");
			rewind(altaveterinarios);
			fread(&masc,sizeof(masc),1,altaveterinarios);
					    
				while (!feof(altaveterinarios))
					{						
							compara=strcmp(turnos_ok.apenom,masc.apenom);
							printf("\n aux: %s,masc.apenom: %s\n",turnos_ok.apenom,masc.apenom);
							if(compara==1)
							{
								fwrite(&turnos_ok, sizeof(turnos_ok), 1, ArchTemp); //archivo temporal el registro le�do
							}
							
							if (compara==0)
							{
								printf("\n--Mascota: %s",turnos_ok.apenom);
								printf("\n--Dia: %d",turnos_ok.fechaturno.dia);
								printf("\n--Mes: %d",turnos_ok.fechaturno.mes);
								printf("\n--A�o: %d",turnos_ok.fechaturno.year);
								printf("\n\nEste fue el turno de la atencion? \n 1: Si\n 2: No\n opcion: ");
								scanf("%d", &continuar);
								system("cls");								
								
								if(continuar==1)
								{
									printf("\n\n>>Ingrese la evolucion de la mascota: ");
									_flushall();
									gets(masc.evolucion);
									fwrite(&masc,sizeof(masc),1,altaveterinarios);
									encontrado=true;
									if(encontrado==true)
									{
										fclose(ArchTemp);
										fclose(turnosok);
										remove("Turnos.dat");
										rename("Turnosaux.dat","Turnos.dat");
										printf("\n\nSe ha eliminado el turno");
										turnosok=fopen("Turnos.dat","r+b");
										ArchTemp = fopen("Turnosaux.dat","w+b");
									}
								}
									
							}
							
							fread(&masc,sizeof(masc),1,altaveterinarios);
					}   	
		}
		fread(&turnos_ok,sizeof(turnos_ok),1,turnosok);
	}
	
	fclose(altaveterinarios);
	fclose(turnosok);
	
}
