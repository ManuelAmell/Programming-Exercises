/*Industrias Food Ligth, desarrolla una línea de servicios de comidas a domicilio, 
para lo cual cuenta con las siguientes operaciones:
1.      Activar Cliente : Se debe Ingresar los siguientes datos del cliente, ID, nombre, 
dirección, teléfono
2.      Recibir Pedido: Ingresar el documento de identificación del cliente 
(Si el cliente no existe se debe enviar al módulo de activar cliente)

Una vez creado el cliente se debe generar el número del pedido, asignar la fecha, 
seleccionar del menú de opciones el menú que desea el cliente,
lo cual se debe verificar en el archivo de precio del menú y extraer el valor y 
generar el valor a cancelar por parte del cliente

Opciones del menú
OPCION       DESCRIPCION                                                                VALOR
Antojitos    sándwich, jugo natural, porción de fruta)                                  7500
Super lunch  ensalada cesar, jugo natural, Filete de pescado a la plancha, croquetas 
	         de plátano )                                                      			15000
Happy lunch Sopa de vegetales, pollo a la plancha, ensalada primavera, jugo natural)    12500
Lunch relax (bebida de té verde, galletas de avena, ensalada de frutas tropicales)      10000
Lunch   flash (yogurt griego con frutas y cereal)                                       12500

3.      Ingresar menú (Se debe registrar el código del menú, descripción el menú, valor)
4.      Consultar Pedidos listar todos los pedidos realizados (indicar el cliente, pedido, 
fecha, valor pagado)
5. Consultar Cliente listar todos los pedidos de un cliente*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <locale>
using namespace std;

//tipos definidos por el usuario
struct menu
{
	char opc[50];
	char desc[150];
	int valor;
};

struct cli
{
	long id;
	char nombre[50];
	char dir[100];
	long tel;		
};

//función predefinida para tomar la fecha y hora del sistema 
time_t tiempo = time(0); 
struct tm *tlocal = localtime(&tiempo);

struct pedi
{
	long id; //id del cliente
	int np; // consecutivo del número del pedido
	char opc[50];
	int vlr;
	int cant;
	char fecha_hora[128];
};

//DECLARACION PROTOTIPOS FUNCIONES
void archivos();
int val_cli(long id_c, char* name);
int val_menu(char* opc_m, char* desc_m );
void activar();
void recibir();
void ingresar(); 
void cons_pedidos();
void cons_cliente();
int valor_menu(char* opc_m);
//******************************************************************************************
int main()
{
	int opc;
	archivos(); //crear los archivos
	setlocale(LC_ALL, "spanish");
	do
	{
		system("cls");
		cout<<"Industrias Food Ligth"<<endl;
		cout<<"1. Activar Cliente "<<endl;
		cout<<"2. Recibir Pedido"<<endl;
		cout<<"3. Ingresar menú "<<endl;
		cout<<"4. Consultar Pedidos "<<endl;
		cout<<"5. Consultar Cliente "<<endl;
		cout<<"6. Salir "<<endl;
		cout<<"Seleccione el proceso a realizar:  ";
		cin>>opc;
		switch(opc)
		{
			case 1:activar(); break;
			case 2:recibir(); break;
			case 3:ingresar(); break;
			case 4:cons_pedidos(); break;
			case 5:cons_cliente(); break;
			case 6: exit(0);
			default: cout<<"Proceso seleccionado no está en el menú"<<endl; 
		}
		system("pause");
	}while(opc !=6);
}
//******************************************************************************************
//PROTOTIPOS FUNCIONES
void archivos()
{
	ofstream a1 ("clientes.txt", ios::app | ios::binary);
	if(a1.fail())
	{
		cout<<"Error al crear el archivo clientes.txt" <<endl;
		system("pause");
		exit(0);
	}
	a1.close();
	
	ofstream a2 ("menus.txt", ios::app | ios::binary);
	if(a2.fail())
	{
		cout<<"Error al crear el archivo menus.txt" <<endl;
		system("pause");
		exit(0);
	}
	a2.close();
	
	ofstream a3 ("pedidos.txt", ios::app | ios::binary);
	if(a3.fail())
	{
		cout<<"Error al crear el archivo pedidos.txt" <<endl;
		system("pause");
		exit(0);
	}
	a3.close();
}
//******************************************************************************************
int val_cli(long id_c, char* name)
{
	int sw=0;
	cli cliente;
	//leer el archivo de clientes.txt
	ifstream archivo("clientes.txt", ios::in |ios::binary);
	if(archivo.fail())
	{
		cout<<"Error al abrir el archivo clientes.txt para lectura" <<endl;
		system("pause");
		exit(0);
	}
	//hacemos la primera lectura para ubicar el puntero en el primer registro del archivo clientes
	archivo.read(reinterpret_cast<char*>(&cliente), sizeof(cli));
	//recorrer el archivo mientras que no se haya alcanzado el fin de archivo
	while(!archivo.eof())
	{
		if (id_c == cliente.id)
		{
			sw=1;
			strcpy(name, cliente.nombre);
			break;
		}
		archivo.read(reinterpret_cast<char*>(&cliente), sizeof(cli));
	}
	archivo.close();
	return sw;		
}
//******************************************************************************************
int val_menu(char* opc_m, char* desc_m )
{
	menu menus;
	int sw=0;
	//leer el archivo de menus.txt
	ifstream archivo("menus.txt", ios::in |ios::binary);
	if(archivo.fail())
	{
		cout<<"Error al abrir el archivo menus.txt para lectura" <<endl;
		system("pause");
		exit(0);
	}
	//hacemos la primera lectura para ubicar el puntero en el primer registro del archivo clientes
	archivo.read(reinterpret_cast<char*>(&menus), sizeof(menu));
	//recorrer el archivo mientras que no se haya alcanzado el fin de archivo
	while(!archivo.eof())
	{
		if (strcmp(strupr(menus.opc), strupr(opc_m) )==0)
		{
			sw=1;
			strcpy(desc_m, menus.desc);
			break;
		}
		archivo.read(reinterpret_cast<char*>(&menus), sizeof(menu));
	}
	archivo.close();
	return sw;		
}
//******************************************************************************************
void activar()
{
	system("cls");
	ofstream archivo("clientes.txt", ios::app | ios::binary);
	if (archivo.fail())
	{
		cout<<"Error al abrir el archivo clientes.txt para escritura" <<endl;
		system("pause");
		exit(0);
	}
	long id_c;
	char name[50];
	cout<<"Id del cliente: ";
	cin>>id_c;
	
	cli cliente;
	if(val_cli(id_c, name) == 0)
	{
		cliente.id = id_c;
		cout<<"Nombre: "; fflush(stdin); gets(cliente.nombre);
		cout<<"Dirección: "; fflush(stdin); gets(cliente.dir);
		cout<<"Teléfono: "; cin>>cliente.tel;
	}
	else
	{
		cout<<"Cliente "<<name <<" Ya se encuentra registrado";
	}
	
	archivo.write(reinterpret_cast<char *>(&cliente), sizeof(cli));
	archivo.close();
}
//******************************************************************************************
void recibir()
{
	int opc;
	long id_c;
	char opc_m[50];
	char name[50];
	char desc_m[100];
	static int num_pedido=0;
	do
	{
		system("cls");
		cout<<"ID del cliente: "; cin>>id_c;
		if(val_cli(id_c, name) == 0)
		{
			cout<<"Cliente no está registrado, se procedera a realizar registro"<<endl;
			system("pause");
			activar();
		}
		
		//Mostrar las opciones que están del menu
		menu menus;
		system("cls");
		ifstream archivo ("menus.txt", ios::in | ios::binary);
		if (archivo.fail())
		{
			cout<<"Error al abrir archivo menus.txt para lectura"<<endl;
			system("pause");
			exit(0);
		}
		cout<<setw(30)<<"INDUSTRIAS FOOD LIGTH - LISTA PRECIOS"<<endl;
		cout<<setw(20)<<"OPCIÓN" <<setw(40)<<"DESCRIPCIÓN" <<setw(10)<<"VALOR"<<endl;
		archivo.read(reinterpret_cast<char*>(&menus), sizeof(menu));
		while(!archivo.eof())
		{
			cout<<setw(20)<<menus.opc <<setw(40)<<menus.desc <<setw(10)<<menus.valor <<endl;
			archivo.read(reinterpret_cast<char*>(&menus), sizeof(menu));	
		}
		archivo.close();
		cout<<"Seleccione la opción del menu para el pedido: "; fflush(stdin); gets(opc_m);
		
		if(val_menu(opc_m, desc_m) == 1)//encontró la opción del menú a pedir registrada
		{
			pedi pedidos;
			ofstream archivo_ped("pedidos.txt", ios::app | ios::binary);
			if(archivo_ped.eof())
			{
				cout<<"Error para abrir el archivo pedidos.txt para escritua"<<endl;
				system("pause");
				exit(0);
			}
			system("cls");
			cout<<"Nombre del cliente: "<<name <<endl;
			pedidos.id = id_c;
			strcpy(pedidos.opc, opc_m);
			cout<<"Opción menu: "<<opc_m <<"(" <<desc_m <<")" <<endl;
			cout<<"Número del pedido: "<<++num_pedido <<endl;
			pedidos.np = num_pedido;
			pedidos.vlr = valor_menu(opc_m);
			cout<<"Valor: $"<<pedidos.vlr <<endl;
			cout<<"Cantidad: "; cin>>pedidos.cant;
			
			//asignar la fecha y hora del sistema en el campo del struct pedidos 
			strftime(pedidos.fecha_hora, 128, "%d/%m/%y %H:%M:%S",tlocal);
			cout<<"Total a cancelar: $"<<pedidos.cant * pedidos.vlr <<endl;
			cout<<"Fecha de facturación: "<<pedidos.fecha_hora <<endl;
			
			//escribir todos los datos del pedido a registrar en el archivo de pedidos
			archivo_ped.write(reinterpret_cast<char*>(&pedidos), sizeof(pedi));
			archivo_ped.close();
		}
		else// no se encontró la opción de menú pedida
		{
			cout<<"Opción de menú indicada no está disponible"<<endl;
		}
		cout<<"1. Registrar el pedido de otro cliente, cualquier otro valor para terminar: ";
		cin>>opc;
	}while(opc == 1);
}
void ingresar()//INGRESAR UN MENÚ
{
	menu menus;
	char opc_m[50];
	char desc_m[100];
	int opc;
	do
	{
		system("cls");
		cout<<"Opción del menú a registrar: ";
		fflush(stdin); gets(opc_m);
		if(val_menu(opc_m, desc_m) == 0)
		{
			ofstream archivo("menus.txt", ios::app | ios::binary);
			if (archivo.fail())
			{
				cout<<"Error al abrir el archivo menus.txt para escritura"<<endl;
				system("pause");
				exit(0);
			}
			strcpy(menus.opc, opc_m);
			cout<<"Descripción del menú: ";  fflush(stdin); gets(menus.desc);
			cout<<"Valor: "; cin>>menus.valor;
			//una vez se tiene toda la información del menú se escibe en el archivo
			archivo.write(reinterpret_cast<char* >(&menus), sizeof(menu));
			archivo.close();
		}
		else
		{
			cout<<opc_m <<"	Ya se encuentra registrado ("<<desc_m<<")\n";
		}
		cout<<"1.Para registrar otro menú, cualquier valor finalizar: ";
		cin>>opc;
	}while(opc == 1);	
} 
//***********************************************************************************
int valor_menu(char* opc_m)
{
	menu menus;
	ifstream archivo("menus.txt",ios::in | ios::binary);
	if(archivo.fail())
	{
		cout<<"Error para abrir el archivo menus.txt para lectura" <<endl;
		system("pause");
		exit(0);
	}
	archivo.read (reinterpret_cast<char *>(&menus), sizeof(menu));
	while(!archivo.eof())
	{
		if( strcmp(strupr(menus.opc), strupr(opc_m) )  == 0)
		{
			return menus.valor;
		}
		archivo.read (reinterpret_cast<char *>(&menus), sizeof(menu));
	}
	archivo.close();
}
//******************************************************************************************
void cons_pedidos()
{
	pedi pedidos;
	char name[50];
	ifstream archivo("pedidos.txt",ios::in |ios::binary);
	if	(archivo.fail())
	{
		cout<<"Error al abrir el archivo pedidos.txt para lectura"<<endl;
		system("pause");
		exit(0);
	}
	system("cls");
	cout<<setw(50)<<"REPORTE DE PEDIDOS REALIZADOS"<<endl;
	cout<<setw(10)<<"ID" <<setw(30)<<"CLIENTE" <<setw(10)<<"# PEDIDO"  <<setw(20)<<"FECHA" <<setw(20)<<"VALOR CANCELADO"<<endl;
	
	archivo.read(reinterpret_cast<char*>(&pedidos), sizeof(pedi));
	while(!archivo.eof())
	{
		cout<<setw(10)<<pedidos.id;
		if(val_cli(pedidos.id, name));
		cout<<setw(30)<<name  <<setw(10) <<pedidos.np <<setw(20)<<pedidos.fecha_hora <<setw(20)<<pedidos.cant * pedidos.vlr <<endl;
		archivo.read(reinterpret_cast<char*>(&pedidos), sizeof(pedi));
	}
	archivo.close();
}
//******************************************************************************************
void cons_cliente()
{
	pedi pedidos;
	int sw=0;
	long id_c;
	int opc;
	char name[50];
	do
	{
		system("cls");
		cout<<"Id del cliente a consultar: "; cin>>id_c;
		if(val_cli(id_c, name) == 1)
		{
			cout<<"CLIENTE: " <<name <<endl;
			ifstream archivo ("pedidos.txt",ios::in | ios::binary);
			if(archivo.fail())
			{
				cout<<"Error al abrir el archivo pedidos.txt para lectura"<<endl;
				system("pause");
				exit(0);
			}
			
			//encabezado del reporte
			cout<<setw(10)<<"# PEDIDO" <<setw(20)<<"OPCIÓN MENU" <<setw(20)<<"FECHA"  <<setw(10)<<"CANTIDAD" <<setw(10)<<"VALOR" <<setw(20)<<"TOTAL CANCELADO"<<endl;
			archivo.read(reinterpret_cast<char *>(&pedidos), sizeof(pedi));
			while(!archivo.eof())
			{
				if(pedidos.id == id_c)
				{
					cout<<setw(10)<<pedidos.np <<setw(20)<<pedidos.opc <<setw(20)<<pedidos.fecha_hora <<setw(10)<<pedidos.cant <<setw(10)<<pedidos.vlr <<setw(20)<<pedidos.cant*pedidos.vlr <<endl;
				}
				archivo.read(reinterpret_cast<char*>(&pedidos), sizeof(pedi));
			}
			archivo.close();
		}
		else //no encontró al cliente 
		{
			cout<<"Cliente No está registrado" <<endl;	
		}
		cout<<"1.Realizar consulta de otro cliente, Cualquier valor para terminar "<<endl;
		cin>>opc;
	}while(opc == 1);
}
