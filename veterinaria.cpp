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
apellido corresponde al dueño o familia), DNI del dueño, Localidad, Edad (calculada con la fecha de nacimiento
registrada), Peso.
	* Debemos permitir obtener el informe de la historia clinica de la mascot
	
modulo consultorio:
	el vetereniario ingresa con su numero de matricula y contraseña 
	se habre un menu de opciones:
		1. llama por apellido y nombre a la mascota que atendera 
		 *poner estado evolucion de la mascota maximo 380
		 * (historia clinica, comun a todos)
		  se debe dejar registro del veterinario que escribio el estado de evolucion junto a la fecha
	   	*se borra la mascota del listado
		   */
 /*Bueno yo creo que nos falta esto lo digo por pasos

Módulo recepción 
Ingresar a la mascota 
Darle un turno a la mascota

Módulo consultorio
Poder visualizar los turnos según el día (necesita ingresar matricular para verlo) 

Dar la evolución de la mascota y borrar el turno 

Módulo recepción 
Podés visualizar las atenciones por fecha y veterinario

Módulo administración
Visualizar las atenciones dadas en el mes 

Dar bono mensual*/
		   
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
	char apenom[60];
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

void recepcionista(Mascota masc, FILE*altaveterinarios,Usuarios admi);
void regrecepcionista(FILE*altaveterinarios,Usuarios admi);
void regmascota(Mascota masc, FILE*altaveterinarios);

void atencionvet(Mascota masc, FILE*altaveterinarios,Usuarios admi);
void regvet(FILE*altaveterinarios,Usuarios admi); 
//============================================================PRINCIPAL============================================================
using namespace std;
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
	printf("\n Menu principal\n");
 	printf("\n =========================\n");
 	printf("\n 1.- Modulo Administracion\n");
 	printf("\n 2.- Modulo Recepcionista\n");
 	printf("\n 3.- Modulo Veterinarios\n");
 	printf("\n 4.- cerrar programa\n");
 	printf("\n Ingrese una opción: ");
	scanf("%d", &opcion);
	
 	switch(opcion)
	 {
	 	case 1: administracion(admi,altaveterinarios,altav);
	 	
	 	system("pause");
	 	break;
	 	
	 	case 2: recepcionista(masc,altaveterinarios,admi);
	 	
	 	system("pause");
	 	break;
	 	
	 	case 3: atencionvet(masc,altaveterinarios,admi);

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
	char usuario[10], contra[10],aux[10],auxcontra[10];
	bool login=false,error=false,contrase=false;
	int opcion=0,compara=0,compara2=0,longitud=0;
	
	altaveterinarios=fopen("Usuario.dat","a+b");
	
	fseek(altaveterinarios, 0, SEEK_END );
	
	if (ftell(altaveterinarios ) == 0 )
	{
  		// fichero vacio	
  
		printf("\nBienvenido, cree su cuenta por unica vez: \n\n");
		printf("\nIngrese su nombre y apellido: ");
		_flushall();
		gets(admi.Apenom);
		
	do{
		int digito=0,mayus=0,c=0;
		
		printf("\nSu usuario debe:\nContener entre 6 y 10 caracteres\ncomenzar con una letra minuscula\nTener al menos 2 letras mayusculas\nTener como maximo 3 digitos");
		printf("\n\nIngrese su nuevo usuario: ");
		_flushall();
		gets(admi.usuario);
		
		printf("\n");
		printf(">>Ingreso: ");
		puts(admi.usuario);
		
		
		longitud = strlen(admi.usuario);
		printf("\n>>Tiene %d longitud",longitud);
		
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
     	
     	printf("\n>>Tiene %d digitos y %d mayusculas",digito,mayus);
		printf("\n>>Primer caracter %c",aux[0]);
		
			if((aux[0]>='a') && (aux[0]<='z') && (longitud>5) && (longitud<11) && (digito<4) && (mayus>1))
				{
					error=true;
				}
			else
				{
					
					printf("\n\nNo cumple alguna condicion");
					printf("\n=====================================================\n");
					printf("\nSi desea salir presione 1, si quiere volver a intentar presione otra tecla: ");
					scanf("%d", &c);
					if(c==1)
					{
						return;
					}
					system("cls");
					
			    }
		}while(error!=true);
		
		printf("\n\nSe registro correctamente,continuemos con la contraseña\n");
		system("pause");
		system("cls");			
		
		do
		{
			int digitcon=0,maycon=0,caracterespecial=0,longitudcontra=0,mincon=0,c=0;
			bool consecutivo=false;
			printf ("\nSu contraseña: \nDebe contener al menos una letra mayuscula, una minuscula y un numero\nNo puede contener caracteres especiales\nDebe tener entre 6 y 10 caracteres\nNo debe tener mas de 3 numeros consecutivos\nNo debe tener 2 letras consecutivas");
			printf ("\n\nElija una contraseña: ");
			_flushall();
			gets(admi.contra);
			
			printf("\nLO INGRESADO FUE:");
			puts(admi.contra);
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
							printf("No debe tener dos caracteres consecutivos");
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
								printf("No debe tener 3 caracteres numericos");
								break;
							}
						}
					}
				}	
			 }	
	
		printf("\n>>El numero digitos es %d, el numero de mayus es %d",digitcon,maycon);	
		printf("\n>>El numero minus es %d",mincon);	
		printf("\n>>El numero de caracteres especiales es %d",caracterespecial);
		printf("\n>>La longitud es %d",longitudcontra );
		
		if((consecutivo==false)&&(digitcon>0)&&(maycon>0)&&(mincon>0)&&(caracterespecial==0)&&(longitudcontra>5)&&(longitudcontra<11))
		{contrase=true;}
		else
		{
				
					printf("\n\nNo cumple alguna condicion, ingrese su nueva contraseña\n");
					printf("\n=====================================================\n");
					printf("\nSi desea salir presione 1, si quiere volver a intentar presione otra tecla: ");
					scanf("%d", &c);
					if(c==1)
					{
						return;
					}	
					
					system("cls");
					
		}
		}while(contrase!=true);
		
	
		
		fwrite(&admi,sizeof(admi),1,altaveterinarios);//esto escribe el usuario en el archivo
		
		printf("\n\nSu usuario fue registrado satisfactoriamente\n");
		system("pause");
	}
	fclose(altaveterinarios);
	
	
	
	
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
	
	
	if(login==true)
	{
		printf("\nLogro ingresar correctamente\n");
		system("pause");
		printf("\nBienvenido\n\n");
	
		do
		{
			system("cls");
			printf("\n Módulo Administracion\n");
		 	printf("\n =========================\n");
		 	printf("\n 1.- Registrar Veterinario\n");
		 	printf("\n 2.- Registrar Usuario Asistente\n");
		 	printf("\n 3.- Atenciones por Veterinarios\n");
			printf("\n 4.- Ranking de Veterinarios por Atenciones\n");
		 	printf("\n 5.- Volver al menu anterior.\n");
		 	printf("\n Ingrese una opción: ");
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
	int longitud,repite;
	char usuario[10], contra[10],aux[10],auxcontra[10];
	bool login=false,error=false,contrase=false;
	altaveterinarios=fopen("Veterinarios.dat","a+b");
	
		
	printf("Ingrese el Nombre y apellido del profesional: ");
	_flushall();
	gets(admi.Apenom);
	
	do{
		bool repeticion=false;
		int digito=0,mayus=0,c=0;
		
		printf("\nEl usuario del veterinario debe:\nContener entre 6 y 10 caracteres\ncomenzar con una letra minuscula\nTener al menos 2 letras mayusculas\nTener como maximo 3 digitos");
		printf("\n\nIngrese usuario del veterinario: ");
		_flushall();
		gets(admi.usuario);
		
		printf("\n");
		printf(">>Ingreso: ");
		puts(admi.usuario);
		
		
		longitud = strlen(admi.usuario);
		printf("\n>>Tiene %d longitud",longitud);
		
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
     	
     	printf("\n>>Tiene %d digitos y %d mayusculas",digito,mayus);
		printf("\n>>Primer caracter %c",aux[0]);
		
		rewind(altaveterinarios);
		fread(&admi.usuario,sizeof(admi),1,altaveterinarios);
		
	while (!feof(altaveterinarios))
		{
			repite=strcmp(aux,admi.usuario);
			printf("\nAux: %s,admi.usuario: %s\n",aux,admi.usuario);
			
			if (repite==0)
			{
				repeticion=true;
				printf("\n>>El nombre de usuario ingresado, ya esta registrado");
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
					
					printf("\n\nNo cumple alguna condicion, intente nuevamente");
					printf("\n=====================================================\n");
					printf("\nSi desea salir presione 1, si quiere volver a intentar presione otra tecla: ");
					scanf("%d", &c);
					if(c==1)
					{
						return;
					}
					system("cls");
					
			    }
	}while(error!=true);
		
		printf("\n\nSe registro correctamente,continuemos con la contraseña\n");
		system("pause");
		system("cls");			
	
	
		do
		{
			int digitcon=0,maycon=0,caracterespecial=0,longitudcontra=0,mincon=0,c=0;
			bool consecutivo=false;
			printf ("\nLa contraseña del veterinario: \nDebe contener al menos una letra mayuscula, una minuscula y un numero\nNo puede contener caracteres especiales\nDebe tener entre 6 y 10 caracteres\nNo debe tener mas de 3 numeros consecutivos\nNo debe tener 2 letras consecutivas");
			printf ("\n\nElija una contraseña: ");
			_flushall();
			gets(admi.contra);
			
			printf("\nLO INGRESADO FUE:");
			puts(admi.contra);
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
							printf("No debe tener dos caracteres consecutivos");
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
								printf("No debe tener 3 caracteres numericos");
								break;
							}
						}
					}
				}	
			 }	
	
		printf("\n>>El numero digitos es %d, el numero de mayus es %d",digitcon,maycon);	
		printf("\n>>El numero minus es %d",mincon);	
		printf("\n>>El numero de caracteres especiales es %d",caracterespecial);
		printf("\n>>La longitud es %d",longitudcontra );
		
		if((consecutivo==false)&&(digitcon>0)&&(maycon>0)&&(mincon>0)&&(caracterespecial==0)&&(longitudcontra>5)&&(longitudcontra<11))
		{contrase=true;}
		else
		{
				
					printf("\n\nNo cumple alguna condicion, ingrese su nueva contraseña\n");
					printf("\n=====================================================\n");	
					printf("\nSi desea salir presione 1, si quiere volver a intentar presione otra tecla: ");
					scanf("%d", &c);
					if(c==1)
					{
						return;
					}
					system("cls");
					
		}
		}while(contrase!=true);
		
	
		
		fwrite(&admi,sizeof(admi),1,altaveterinarios);//esto escribe el usuario en el archivo
		
		printf("\n\nSu usuario fue registrado satisfactoriamente\n");
		
	    fclose(altaveterinarios);
	
	
	


}

void regrecepcionista(FILE*altaveterinarios,Usuarios admi)
{
	int longitud,repite;
	char usuario[10], contra[10],aux[10],auxcontra[10];
	bool login=false,error=false,contrase=false;
	altaveterinarios=fopen("Recepcionistas.dat","a+b");
	
		
	printf("Ingrese el Nombre y apellido del Recepcionista: ");
	_flushall();
	gets(admi.Apenom);
	
	do{
		bool repeticion=false;
		int digito=0,mayus=0,c=0;
		
		printf("\nEl usuario del recepcionista debe:\nContener entre 6 y 10 caracteres\ncomenzar con una letra minuscula\nTener al menos 2 letras mayusculas\nTener como maximo 3 digitos");
		printf("\n\nIngrese usuario del recepcionista: ");
		_flushall();
		gets(admi.usuario);
		
		printf("\n");
		printf(">>Ingreso: ");
		puts(admi.usuario);
		
		
		longitud = strlen(admi.usuario);
		printf("\n>>Tiene %d longitud",longitud);
		
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
     	
     	printf("\n>>Tiene %d digitos y %d mayusculas",digito,mayus);
		printf("\n>>Primer caracter %c",aux[0]);
		
		rewind(altaveterinarios);
		fread(&admi,sizeof(char),1,altaveterinarios);
		
		while (!feof(altaveterinarios))
		{
			repite=strcmp(aux,admi.usuario);
			
			if (repite==0)
			{
				repeticion=true;
				printf("\n>>El nombre de usuario ingresado, ya esta registrado");
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
					
					printf("\n\nNo cumple alguna condicion");
					printf("\n=====================================================\n");
					printf("\nSi desea salir presione 1, si quiere volver a intentar presione otra tecla: ");
					scanf("%d", &c);
					if(c==1)
					{
						return;
					}
					system("cls");
					
			    }
			    
	}while(error!=true);
		
		printf("\n\nSe registro correctamente,continuemos con la contraseña\n");
		system("pause");
		system("cls");			
	
	
		do
		{
			int digitcon=0,maycon=0,caracterespecial=0,longitudcontra=0,mincon=0,c=0;
			bool consecutivo=false;
			printf ("\nLa contraseña del recepcionista: \nDebe contener al menos una letra mayuscula, una minuscula y un numero\nNo puede contener caracteres especiales\nDebe tener entre 6 y 10 caracteres\nNo debe tener mas de 3 numeros consecutivos\nNo debe tener 2 letras consecutivas");
			printf ("\n\nElija una contraseña: ");
			_flushall();
			gets(admi.contra);
			
			printf("\nLO INGRESADO FUE:");
			puts(admi.contra);
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
							printf("No debe tener dos caracteres consecutivos");
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
								printf("No debe tener 3 caracteres numericos");
								break;
							}
						}
					}
				}	
			 }	
	
		printf("\n>>El numero digitos es %d, el numero de mayus es %d",digitcon,maycon);	
		printf("\n>>El numero minus es %d",mincon);	
		printf("\n>>El numero de caracteres especiales es %d",caracterespecial);
		printf("\n>>La longitud es %d",longitudcontra );
		
		if((consecutivo==false)&&(digitcon>0)&&(maycon>0)&&(mincon>0)&&(caracterespecial==0)&&(longitudcontra>5)&&(longitudcontra<11))
		{contrase=true;}
		else
		{
				
					printf("\n\nNo cumple alguna condicion, ingrese su nueva contraseña\n");
					printf("\n=====================================================\n");	
					printf("\nSi desea salir presione 1, si quiere volver a intentar presione otra tecla: ");
					scanf("%d", &c);
					if(c==1)
					{
						return;
					}
					system("cls");
					
		}
		}while(contrase!=true);
		
	
		
		fwrite(&admi,sizeof(admi),1,altaveterinarios);//esto escribe el usuario en el archivo
		
		printf("\n\nEl usuario del recepcionista fue registrado satisfactoriamente\n");
		
	    fclose(altaveterinarios);
	
}


//============================================================RECEPCION============================================================
void recepcionista(Mascota masc, FILE*altaveterinarios,Usuarios admi)
{
	int opcion,compara,compara2;
	bool login=false;
	char usuario[10],contra[10];
	
	altaveterinarios=fopen("Recepcionistas.dat","rb");
	
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
	
	
	if(login==true)
	{
		system("cls");
		printf("\nLogro ingresar, bienvenido\n");
		do
		{
			
			printf("\n	Modulo del Recepcionista\n");
			printf("\n =========================\n");
			printf("\n 1.- Registrar Mascota\n");
			printf("\n 2.- Registrar Turno\n");
			printf("\n 3.- Listado de Atenciones por Veterinario y Fecha\n");
			printf("\n 4.- Volver al menu anterior.\n");
			printf("\n	 Ingrese una opción: \n");
			scanf("%d", &opcion);
			
			switch(opcion)
		 {
		 	case 1: regmascota(masc,altaveterinarios);
		 	
		 	system("pause");
		 	break;
		 	
		 	case 2: //registrarturno();
		 	
		 		system("pause");
		 	break;
		 	
		 	case 3: //atencionvet();
		 
		 	system("pause");
		 	break;
		 	
		 	case 4: 
		 	
		 	printf("\nGracias por utilizar nuestros servicios.");
		 	
		 	break;
		 	
		 	
		 	default:
			printf("Ingreso una opcion incorrecta, ingrese nuevamente");
			break;
		 		
		 }
	 
	}while(opcion!=4);
}	
else
{
	printf("\n\nIngreso mal su usuario o contraseña, vuelva a intentarlo\n");
}	
	fclose(altaveterinarios);
	
}
/*struct Mascota
{
	char apenom[60];
	char domicilio[60];
	int Dni_due;
	char localidad[100];
	fechaN FechaNac;
	char telefono[25];
};*/
void regmascota(Mascota masc, FILE*altaveterinarios)
{
	int aux2,compara,c,longitud;
	char aux[60];
	
	
	altaveterinarios=fopen("Mascotas.dat","a+b");
	
	do
	{
		
	
	bool repite=false;
	printf("\nIngrese el nombre y apellido de la mascota (apellido de familia): ");
	_flushall();
	gets(masc.apenom);
	
	longitud = strlen(masc.apenom);
	
	for(int i=0;i<=longitud;i++)
		{
			aux[i]=masc.apenom[i];
		}
	
	printf("\nDomicilio del dueño: ");
	_flushall();
	gets(masc.domicilio);
	
	printf("\nDNI del dueño: ");
	scanf("%d", &masc.Dni_due);
	aux2=masc.Dni_due;
	
	printf("\nLocalidad: ");
	_flushall();
	gets(masc.localidad);
	
	printf("\nFecha de nacimiento de la mascota:");
        printf("\nDia: ");
        scanf("%d",&masc.FechaNac.dia);
        printf("\nMes: ");
        scanf("%d",&masc.FechaNac.mes);
        printf("\nAnio: ");
        scanf("%d",&masc.FechaNac.year);
        
    printf("\nTelefono del dueño: ");
	_flushall();
	gets(masc.telefono);
	
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
	
	printf("Quiere registrar otra mascota?\n 1: Si\n 2: No\n ");
	scanf("%d", &c);
	

	
	}while(c!=2);
	
	fclose(altaveterinarios);
	
    
}

//============================================================VETERINARIO============================================================
void atencionvet(Mascota masc, FILE*altaveterinarios,Usuarios admi)
{
	int opcion,compara,compara2;
	bool login=false;
	char usuario[10],contra[10];
	
	altaveterinarios=fopen("Veterinarios.dat","rb");
	
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
	
	
	if(login==true)
	{
		system("cls");
		printf("\nLogro ingresar, bienvenido\n");
		do
		{
				printf("\nModulo Consultorio Veterinario\n");
				printf("\n =========================\n");
				printf("\n 1.- Visualizar Lista de Espera de Turnos (informe)\n");
				printf("\n 2.- Registrar Evolución de la Mascota\n");
				printf("\n 3.- Volver al menu anterior.\n");
				printf("\n Ingrese una opción: ");
				scanf("%d",&opcion);
				
		
			
			switch(opcion)
		 {
		 	
		 	case 1: //espera_mascota();
		 	
		 	system("pause");
		 	break;
		 	
		 	case 2: //evolucionmascota();
		 	
		 		system("pause");
		 	break;
		 	
		 	case 3:	printf("\nGracias por utilizar nuestros servicios.\n");
		 	
		 
		 	break;
		 	
		
		 	default:
			printf("Ingreso una opcion incorrecta, ingrese nuevamente");
			break;
		 		
		 }
	 
		}while(opcion!=3);
	}
	else
	{
		printf("\n\nIngreso mal su usuario o contraseña, vuelva a intentarlo\n");
	}	
		fclose(altaveterinarios);
		
}	

