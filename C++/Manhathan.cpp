#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <iomanip>
#include <clocale>
using namespace std;
int main ()
{	 
	cout<<"Este programa es un juego de adivina el numero con ciertas caracteristicas especiales, mostradas a traves de diversos menus coloridos y dinamicos "<<endl:
	cout<<"ademas, esta diseñado para que cualquiera pueda utilizarlo :DDD "<<endl;
	cout<<"---INTEGRANTES---"<<endl;
		 
	setlocale(LC_ALL, "Spanish");	 

	long opc,opc_primos, vidas, jugador=0, menu_opc, divisores_numerito=0; // jugador es el numero que estan ingresando intentando adiviar a numerito
	
	long numerito, limite;  // numerito es el valor a adivinar
	
	long intento=1; // contador de intentos
	
	long resultado_mersenne=1,mersenne, cant_divisores_mersenne=0 ;
	
	double cant_mersenne=0, cant_wagstaff=0, cant_sophie=0;
	
	double cant_numeros=0,numero_max=0,numero_min=999999999, aciertos=0, fallos=0, perdio=0; // se declara double para no truncar el calculo de porcentajes
	
	double primos=0, compuestos=0, suma_compuestos=0, par=0, impar=0;
	
	srand(time(0)); // para que el numero cambie

	
	
	do
	{
		cout<<"\033[1;37;41m--- PANEL DEL DOCENTE ---\033[0m"<<endl;
		do
		{
			cout<<"Ingrese limite: ";
			cin>>limite; // el rango de el numero aleatorio
			if(limite<=0)
			{
				system("cls");
				cout<<"Ingrese un numero mayor a 0 porfavor....."<<endl;
			}
		}while(limite<=0);
		do
		{
			system("cls");
			cout<<"Ingrese la cantidad de vidas que el usuario tendra: "<<endl;
			cin>>vidas;
			if (vidas<=0)
			{
				cout<<"ingrese una cantidad de vidas positiva..."<<endl;
				system("pause");
			}
		}while(vidas<=0);
		
		numerito = ( rand()%limite) + 1; // numerito es el numero aleatorio
			
		
		cout<<"el numero es: "<<numerito<<endl; // esta linea es temporal, debe ser borrada en la entrega final
		cout<<"La cantidad de vidas es de: "<<vidas<<endl;
		Sleep(3000); // esto tambien, es para que podamos ver cual es el numero a adivinar
		cout<<endl; // fines esteticos con el cout del numero, tambien para borrar
		
	
		
		intento=1; // reiniciar el contador de intentos
		do
		{
			system("cls");
			cout<<" !!!! GAMES PRIME NUMBERS !!!!"<<endl;
			cout<<"1. INICIAR JUEGO "<<endl;
			cout<<"2. MOSTRAR ESTADISTICAS DEL JUEGO"<<endl; 
			cout<<"3. SALIR "<<endl;
			cout<<endl;
			cout<<"-----> " ;
			cin>>opc;
			if(opc<1 or opc>3)
			{
				cout<<"Error! si desea salir del programa seleccione la opcion 3!"<<endl; 
				cout<<"Seleccione una opcion dentro del rango porfavor....."<<endl;
				cout<<"PRESIONE ENTER PARA VOLVER AL MENU" << endl;
				system("pause");
			}
		}while(opc< 1 or opc>3);
		
		switch (opc)
		{
			case 1:
			{
				cant_numeros++;
				system("cls");
				cout<<endl;
				cout<<"Hola Jugador , tienes "<<vidas<<" vidas, ?podras adivinar el numero?"<<endl;
				cout<<endl;
				cout<<"Intento # "<<intento<<" ingresa un numero: "<<endl;
				cin>>jugador; // eleccion de el usuario
				//ciclos para determinar si el numero generado, es primo o compuesto 
				divisores_numerito=0;
				for (int divisores=1; divisores<=numerito;divisores++)
				{
					if(numerito%divisores==0)
					{
						divisores_numerito++;
					}	
				}
					
				if(jugador>numero_max) // numero mas grande 
				{
					numero_max=jugador;
				}
				if(jugador<numero_min) // numero mas peque?o
				{
					numero_min=jugador;
				}
			
				system("cls");
				while(jugador != numerito && vidas>0)
			    {
		        	fallos++;
		        	vidas--;
		        	if(vidas >= 1) 
			    	{
		        		cout<<"ERROR!!!, te quedan "<<vidas<<" vidas, ingresa otro numero"<<endl<<endl;
						intento++;
						if(jugador > numerito)
						{	
				        	cout<<"PISTA !!!!, el numero es menor!!"<<endl;
				        }
						else
						{
		            		cout<<"PISTA !!!!, el numero es mayor!!"<<endl;
						}
						
			        	cout<<endl;
			        	cout<<"Intento # "<<intento<<" ingresa un numero"<<endl;
			        	cin>>jugador;
					}
					else
					{
		        	Beep(1000, 1000); // aca puedes colocar la pista de audio que desee
		        	perdio++;
		        	cout<<"Has perdido... el numero era: "<<numerito<<"..."<< endl;
		        	system("color 04");
		        	Sleep(1000);
					system("color 0F");
					}
				}//cuando sale del bucle, se verifica si adivino
				
				if (jugador == numerito) 
				{
				    aciertos++;
				    Beep(1000, 1000);
				    cout<<endl;
				    cout<<"Felicidades!, lograste adivinar el numero "<<numerito<<" en el intento "<<intento<<" faltandote "<<vidas<<" vidas!!"<<endl;
				    system("color 0A");
				    Sleep(290);
				    system("color 0F");
				}//se confirma si era o no el numero y se celebra
				
				if(divisores_numerito==2) // si numerito era primo
				{
					primos++;
					cout<<endl;
					cout<<"Dato Curioso, el numero era primo!!"<<endl;
					cout<<"Presione enter para ver la explicacion del que son los numeros primos" << endl; 
					system("pause");
					system("cls");
					cout<<endl;
					cout<<"Los numeros primos Los n?meros primos son aquellos mayores que 1 que solo tienen dos divisores: 1 y ellos mismos."<<endl;
					cout<<endl;
					cout<<"Son importantes porque son los bloques de construccion de todos los numeros enteros, y juegan un papel clave en areas como la criptografia, la teoria de numeros y la informatica."<<endl;
					cout<<endl;
					cout<<"A continuacion te daremos unas opciones con algunos tipos de numeros primos, para que puedas probar estas categorias especiales de los primos!"<< endl;
					do
					{
						do
						{
							cout<<"\033[1;37;41m--------MENU PRIMOS--------\033[0m"<<endl;
							cout<<"1. PRIMOS DE WAGSTAFF "<<endl;
							cout<<"2. PRIMOS DE SOPHIE GERMAIN "<<endl;
							cout<<"3. PRIMOS DE MERSENNE "<<endl;
							cout<<"4. SAlIR"<<endl; 
							cout<<endl;
							cout<<"Seleccione una opcion para verificar si el numero primo "<<numerito<<" cumple alguna de las cualidades de la lista "<<endl;
							cout<<endl;
							cout<<"----->";
							cin>>opc_primos;
							if(opc_primos<1 or opc_primos>4)
							{
								cout<<"Error! si desea salir del menu de primos seleccione la opcion 4!"<<endl; 
								cout<<"Seleccione una opcion dentro del rango porfavor....."<<endl;
								cout<<"PRESIONE ENTER PARA VOLVER AL MENU" << endl;
								system("pause");
								system("cls");
							}
						}while(opc_primos < 1 or opc_primos>4);
						
						switch(opc_primos)
						{
							case 1: // evaluar si es primo de wagstaff
							{	cout<<" Se dice que un n?mero primo (Pw) es de Wagstaff si se puede expresar como: Pw = (2^p + 1) / 3."<<endl;
								cout<<endl;
								cout<<"donde p es un n?mero primo y P tambi?n debe resultar ser un n?mero primo"<<endl;
								cout<<endl;
								cout<<"La potenciaci?n: es una operaci?n que consiste en multiplicar por s? mismo un n?mero principal  llamado base, tantas veces como lo indique otro n?mero que se llama exponente."<<endl;
								cout<<endl;
								cout<<"Para calcular la potencia de un n?mero lo que hacemos es multiplicar dicho n?mero por s? mismo tantas veces como indique el exponente."<<endl;
								cout<<endl;
								long int potencia_numerito=1, numerito_wagstaff, primo_wagstaff, divisor=0;
								for(int x=1;x<=numerito;x++)
								{
									potencia_numerito = potencia_numerito * 2;
								}
								numerito_wagstaff = (potencia_numerito+1)/3;
								for(int x=1;x<=numerito_wagstaff;x++)
								{
							    	primo_wagstaff = numerito_wagstaff%x;
							    	if(primo_wagstaff==0)
							    	{
							    		divisor++;//se calcula la cantidad de divisores para saber si es primo o comp...
									}
								}
								if(divisor == 2)
								{
									cout<<"El numero "<<numerito<<" cumple con los requisitos para ser un numero primo de Wagstaff"<<endl;
									cant_wagstaff++;
								}
								if(divisor != 2)
								{
									cout<<"El numero "<<numerito<<" NO cumple con los requisitos para ser un numero primo de Wagstaff"<<endl;
								}
								break;
							} // <---- si era primo de wagstaff
					 
							case 2: // evaluar si es primo de sophie germain
							{
								cout<<"Se dice que un n?mero primo es de Sophie Germain si se puede  expresar como: Pg = 2p + 1"<<endl;
								cout<<endl;
								cout<<"donde p es un n?mero primo y P tambi?n debe resultar ser un n?mero primo"<<endl;
								cout<<endl;
								long int numerito_sophie, primo_sophie, divisor=0;
								numerito_sophie = (numerito*2)+1;
								for(int x=1;x<=numerito_sophie;x++)
								{
							    	primo_sophie = numerito_sophie%x;
							    	if(primo_sophie==0)
							    	{
							    		divisor++;//se calcula la cantidad de divisores para saber si es primo o comp...
									}
								}
								if(divisor == 2)
								{
									cout<<"El numero "<<numerito<<" cumple con los requisitos para ser un numero primo de Sophie Germain"<<endl;
									cant_sophie++;
								}
								if(divisor != 2)
								{
									cout<<"El numero "<<numerito<<" NO cumple con los requisitos para ser un numero primo de Sophie Germain"<<endl;
								}
								break;	
							} // <---- si era primo de sophie germain
						
							case 3: // evaluar si es primo de mersenne
							{
								cout<<"Se dice que un n?mero primo (Pm) es de Mersenne si se puede expresar como:  Pm = 2p ? 1"<<endl;
								cout<<endl;
								cout<<"donde p es un n?mero primo y P tambi?n debe resultar ser un n?mero primo"<<endl;
								cout<<endl;
								resultado_mersenne=1; // reiniciar acumulador
								cant_divisores_mersenne=0; // reiniciar contador
								//ciclo para  2^numerito 
								
								for(int expo=1; expo<=numerito;expo++)
								{
									resultado_mersenne*=2;
								}
								
								mersenne=resultado_mersenne-1;
								
								// se cuentan los divisores de mersenne para determinar si es primo o no
								for (int divisores_mersenne=1; divisores_mersenne<=mersenne; divisores_mersenne++)
								{
									if(mersenne%divisores_mersenne==0)
									{
										cant_divisores_mersenne++;
									}
								}
								if(cant_divisores_mersenne==2)
								{
									cant_mersenne++;
									cout<<"El numero "<<numerito<<" cumple con los requisitos para ser un numero primo de Mersenne"<<endl;
								}
								else
								{
									cout<<"El numero "<<numerito<<" NO cumple con los requisitos para ser un numero primo de Mersenne"<<endl;
								}
								break;
							} // <--- evaluar si era primo de mersenne
							
							case 4:
							{
								cout<<"Saliendo. . ." << endl;
								system("pause");
								break;
							}
						}//saliendo siwtch oopc primos 
						if(opc_primos != 4)
						{
						    cout<<"Presione ENTER para volver al men?..." << endl;
						    system("pause");
						}
						system("cls");
					}while(opc_primos!=4);
				} // <---- si el numero era primo
					
				else 
				{
					cout<<endl;
					cout<<"Ademas, el numero era compuesto!!"<<endl;
					cout<<"Presione enter para ver la explicacion del que son los numeros compuestos"<<endl; 
					system("pause");
					system("cls");
					cout<<endl;
					cout<<"Los n?meros compuestos son aquellos n?meros naturales mayores que 1 que tienen m?s de dos divisores distintos."<<endl;
					cout<<"Es decir, adem?s de ser divisibles entre 1 y ellos mismos, tambi?n lo son entre al menos otro n?mero."<<endl;
					cout<<endl;
					cout<<"Los n?meros compuestos son importantes porque permiten descomponer cualquier n?mero en factores primos."<<endl;
					cout<<"lo que es fundamental para hacer c?lculos como el m?nimo com?n m?ltiplo (MCM) y el m?ximo com?n divisor (MCD)."<<endl;
					cout<<endl;
					cout<<"Acontinuacion mostraremos los divisores del numero y su descomposicion en factores primos!"<<endl;
					if (numerito%2==0)
					{
						par++;
					}else 
					{
						impar++;
					}
					suma_compuestos+=numerito;
					compuestos++;
					cout<<endl;
					cout<<"Divisores de el numero "<<numerito<<" :"<<endl;
					for (int x=1; x<=numerito; x++)
					{
						if (numerito%x == 0)
						{
							cout<<x<<endl;
						}
					}
					// descomponer en factores primos
					cout<<endl;
					cout<<"Descomposicion en factores primos: "<<endl;
					int copia_numerito=numerito, numerita=numerito, y=2;//variables para comparar y guardar numerito && y la variable "y" para dividir y aumentar.
					cout<<numerito<<" = ";
					for(int i=2; i<=copia_numerito; i++) 
					{
					 while(copia_numerito% i == 0) 
						{
						cout<<i;
    					copia_numerito /= i;
    					if(copia_numerito > 1) cout<<" x ";
						}
					}
					cout<<endl;
					while(numerita!=1)
					{
					    if(numerita%y==0)
						{
							cout<<numerita<<" | "<<y<<endl;
							numerita=numerita/y;
						}
				    	else
				    	{
				    		y++;
						}
					}
					cout<<numerita<<" | "<<endl;
					system("pause");
				}
				break;
			}
			
			case 2: // mostrar estadisiticas
			{
				if(cant_numeros==0) // si no ha ingresado al menos 1 vez al juego
				{
					system("cls");
					cout<<"Error, Debe ingresar almenos una vez al juego para guardar registro de sus estadisticas... "<<endl;
					system("pause");
					break;	
				}
				else
				{
					cout<<fixed<<setprecision(2); // que ahora muestre los numeros con 2 decimales extras :DDDD
					system("cls");
					cout<<"\033[1;37;41m----ESTADISTICAS DEL JUEGO----\033[0m"<<endl;
					cout<<endl;
					cout<<"Cantidad de numeros ingresados: "<<cant_numeros<<endl;
					cout<<"El valor Maximo ingresado fue: "<<numero_max<<endl;
					cout<<"El valor Minimo ingresado fue: "<<numero_min<<endl;
					cout<<"Porcentaje de aciertos: "<<aciertos/cant_numeros *100.0<<"%"<<endl; 
					cout<<"Porcnetaje de fallos "<<fallos/cant_numeros*100.0<<"%"<<endl;
					cout<<"Porcentaje de Fallos por partida [perdidas]: "<<perdio/cant_numeros *100.0<<"%"<<endl; 
					cout<<endl;
					cout<<"PAGINA 1/3 [Estadisticas del juego]"<<endl;
					cout<<"Desea volver al inicio o avanzar pagina?"<<endl;
					cout<<"[ 1 volver inicio ]"<<endl;
					cout<<"[ 2 avanzar pagina ]"<<endl;
					cin>>menu_opc;
					if(menu_opc == 1)
					{
						break;
					}
					else if (menu_opc == 2)
					{
						system("cls");
						if (primos>0)
						{
						cout<<"\033[1;37;41m----ESTADISTICAS PRIMOS----\033[0m"<<endl;
						cout<<endl;
						cout<<"Cantidad de numeros primos: "<<primos<<endl;
						cout<<"Cantidad de numeros primos de Wagstaff "<<cant_wagstaff<<endl; // cant_wagstaff o como quieran llamar a la variable
						cout<<"Porcentaje de numeros primos de Wagstaff "<<cant_wagstaff/ primos*100.0<<"%"<<endl; // lo mismo de arriba
						cout<<"Cantidad de numeros primos de Sophie Germain "<<cant_sophie<<endl; // lo mismo
						cout<<"Porcentaje de numeros primos de Sophie Germain "<<cant_sophie/ primos*100.0<<"%"<<endl;// otra vez lo mismo
						cout<<"Cantidad de numeros primos de Mersenne "<<cant_mersenne<<endl;
						cout<<"Porcentaje de numeros primos de Mersenne "<<cant_mersenne/ primos*100.0<<"%"<<endl;	
						cout<<"PAGINA 2/3 [Estadisticas Primos]"<<endl;
						cout<<"Desea volver al inicio o avanzar pagina?"<<endl;
						cout<<"[ 1 volver inicio ]"<<endl;
						cout<<"[ 2 avanzar pagina ]"<<endl;
						}else
						{
							cout<<"aun no se han ingresado numeros primos......"<<endl;
							system("pause");
							menu_opc=2;
						}
						
						cin>>menu_opc;	
					
						if(menu_opc == 1)
						{
							break;
						}
						else if( menu_opc==2)
						{
							if (compuestos>0)
							{
								system("cls");
								cout<<"\033[1;37;41m----ESTADISTICAS COMPUESTOS----\033[0m"<<endl;
								cout<<"Promedio de la totalidad de numeros compuestos: "<<suma_compuestos/compuestos<<endl;
								cout<<"el porcentaje de numeros pares es: "<<par/compuestos*100.0<<"%"<<endl;
								cout<<"el porcentaje de numeros impares es: "<<impar/compuestos*100.0<<"%"<<endl;
								cout<<"PAGINA 3/3 [ESTADISTICAS COMPUESTOS]"<<endl;
								cout<<"Presione un boton para salir"<<endl;
								cout<<endl;
							}
							else
							{
								cout<<"aun no se han ingresado numeros compuestos...."<<endl;
								system("pause");
								break;
							}
						}
					}
					system("pause"); 
				}
				break;
			}
			case 3:
			{
				cout<<"Saliendo del programa... ?Hasta pronto!"<<endl;
				break;
			}		
		}
		if(opc != 3) 
		{
    		system("cls");
			cout<<"Presione enter para regresar al panel de docente y reiniciar el juego!!" << endl; 
			system("pause");
			system("cls");
		}
	}while(opc!=3);
}


