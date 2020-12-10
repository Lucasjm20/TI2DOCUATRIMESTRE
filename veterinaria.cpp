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
void regrecepcionista(FILE*altaveterinarios,Usuarios admi);
//void atencionvet();
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
	printf("\nMenu principal\n");
 	printf("\n=========================\n");
 	printf("\n1.- Modulo Administracion\n");
 	printf("\n2.- Modulo Asistente\n");
 	printf("\n3.- Modulo Veterinarios\n");
 	printf("\n4.- cerrar programa\n");
 	printf("\nIngrese una opción: ");
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
	char usuario[10], contra[10],aux[10],auxcontra[32];
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
		int digito=0,mayus=0;
		
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
					
					printf("\n\nNo cumple alguna condicion, intente nuevamente");
					printf("\n=====================================================\n");
					system("pause");
					system("cls");
					
			    }
		}while(error!=true);
		
		printf("\n\nSe registro correctamente,continuemos con la contraseña\n");
		system("pause");
		system("cls");			
		
		do
		{
			int digitcon=0,maycon=0,caracterespecial=0,longitudcontra=0,mincon=0;
			bool consecutivo=false;
			printf ("\nSu contraseña: \nDebe contener al menos una letra mayuscula, una minuscula y un numero\nNo puede contener caracteres especiales\nDebe tener entre 6 y 32 caracteres\nNo debe tener mas de 3 numeros consecutivos\nNo debe tener 2 letras consecutivas");
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
		
		if((consecutivo==false)&&(digitcon>0)&&(maycon>0)&&(mincon>0)&&(caracterespecial==0)&&(longitudcontra>5)&&(longitudcontra<33))
		{contrase=true;}
		else
		{
				
					printf("\n\nNo cumple alguna condicion, ingrese su nueva contraseña\n");
					printf("\n=====================================================\n");	
					system("pause");
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
	char usuario[10], contra[10],aux[10],auxcontra[32];
	bool login=false,error=false,contrase=false;
	altaveterinarios=fopen("Veterinarios.dat","a+b");
	
		
	printf("Ingrese el Nombre y apellido del profesional: ");
	_flushall();
	gets(admi.Apenom);
	
	do{
		bool repeticion=false;
		int digito=0,mayus=0;
		
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
		fread(&admi,sizeof(admi),1,altaveterinarios);
		
		while (!feof(altaveterinarios))
		{
			repite=strcmp(aux,admi.usuario);
			
			if (repite==0)
			{
				repeticion=true;
				printf("\n>>El nombre de usuario ingresado, ya esta registrado");
				break;
			}
			
			fread(&admi,sizeof(admi),1,altaveterinarios);
		}
		
			if((aux[0]>='a') && (aux[0]<='z') && (longitud>5) && (longitud<11) && (digito<4) && (mayus>1) && (repeticion==false))
				{
					error=true;
				}
			else
				{
					
					printf("\n\nNo cumple alguna condicion, intente nuevamente");
					printf("\n=====================================================\n");
					system("pause");
					system("cls");
					
			    }
	}while(error!=true);
		
		printf("\n\nSe registro correctamente,continuemos con la contraseña\n");
		system("pause");
		system("cls");			
	
	
		do
		{
			int digitcon=0,maycon=0,caracterespecial=0,longitudcontra=0,mincon=0;
			bool consecutivo=false;
			printf ("\nLa contraseña del veterinario: \nDebe contener al menos una letra mayuscula, una minuscula y un numero\nNo puede contener caracteres especiales\nDebe tener entre 6 y 32 caracteres\nNo debe tener mas de 3 numeros consecutivos\nNo debe tener 2 letras consecutivas");
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
		
		if((consecutivo==false)&&(digitcon>0)&&(maycon>0)&&(mincon>0)&&(caracterespecial==0)&&(longitudcontra>5)&&(longitudcontra<33))
		{contrase=true;}
		else
		{
				
					printf("\n\nNo cumple alguna condicion, ingrese su nueva contraseña\n");
					printf("\n=====================================================\n");	
					system("pause");
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
	char usuario[10], contra[10],aux[10],auxcontra[32];
	bool login=false,error=false,contrase=false;
	altaveterinarios=fopen("Recepcionistas.dat","a+b");
	
		
	printf("Ingrese el Nombre y apellido del Recepcionista: ");
	_flushall();
	gets(admi.Apenom);
	
	do{
		bool repeticion=false;
		int digito=0,mayus=0;
		
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
		fread(&admi,sizeof(admi),1,altaveterinarios);
		
		while (!feof(altaveterinarios))
		{
			repite=strcmp(aux,admi.usuario);
			
			if (repite==0)
			{
				repeticion=true;
				printf("\n>>El nombre de usuario ingresado, ya esta registrado");
				break;
			}
			
			fread(&admi,sizeof(admi),1,altaveterinarios);
		}
			if((aux[0]>='a') && (aux[0]<='z') && (longitud>5) && (longitud<11) && (digito<4) && (mayus>1))
				{
					error=true;
				}
			else
				{
					
					printf("\n\nNo cumple alguna condicion");
					printf("\n=====================================================\n");
					system("pause");
					system("cls");
					
			    }
			    
	}while(error!=true);
		
		printf("\n\nSe registro correctamente,continuemos con la contraseña\n");
		system("pause");
		system("cls");			
	
	
		do
		{
			int digitcon=0,maycon=0,caracterespecial=0,longitudcontra=0,mincon=0;
			bool consecutivo=false;
			printf ("\nLa contraseña del recepcionista: \nDebe contener al menos una letra mayuscula, una minuscula y un numero\nNo puede contener caracteres especiales\nDebe tener entre 6 y 32 caracteres\nNo debe tener mas de 3 numeros consecutivos\nNo debe tener 2 letras consecutivas");
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
		
		if((consecutivo==false)&&(digitcon>0)&&(maycon>0)&&(mincon>0)&&(caracterespecial==0)&&(longitudcontra>5)&&(longitudcontra<33))
		{contrase=true;}
		else
		{
				
					printf("\n\nNo cumple alguna condicion, ingrese su nueva contraseña\n");
					printf("\n=====================================================\n");	
					system("pause");
					system("cls");
					
		}
		}while(contrase!=true);
		
	
		
		fwrite(&admi,sizeof(admi),1,altaveterinarios);//esto escribe el usuario en el archivo
		
		printf("\n\nEl usuario del recepcionista fue registrado satisfactoriamente\n");
		
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
