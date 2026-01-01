#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
#include<conio.h>

using namespace std;

struct EmpleadoInfo{
	int id;
	char nombre[50];
	char cargo[50];
	int dependencia;
};

struct EmpleadoHoras{
	int id;
	int horas;
	double valor;
	int tardanza;
	bool registrado;
};

// Declaraciones de funciones
void crear();
int menuPrincipal();
bool validar(int id);
void registrarInfo();
void registrarHoras();
void menuConsultas();
void consultarEmpleado();
void consultarDependencia();
void menuReportes();
void reporteGeneral();
void reporteEmpleadosrt();
void reporteEmpleadopt();
void reporteDescuento();
void mostrarPresentacion();
void limpiarPantalla();
void mostrarDescripcionPrograma();
void salirAnimado();

int main(){
	// Mostrar presentación inicial
	mostrarPresentacion();
	getch();
	limpiarPantalla();
	// Mostrar descripción del programa
	mostrarDescripcionPrograma();
	
	// Esperar que el usuario presione una tecla
	cout << "\n\nPresione cualquier tecla para continuar al menu principal...";
	getch();
	
	// Inicializar archivos
	crear();
	
	// Entrar al ciclo principal del menú
	int opc = 0;
	
	while(opc != 5){
		limpiarPantalla();
		opc = menuPrincipal();
		
		switch(opc){
			case 1: registrarInfo(); break;
			case 2: registrarHoras(); break;
			case 3: menuConsultas(); break;
			case 4: menuReportes(); break;
			case 5: salirAnimado(); break;
		}
	}
	return 0;
}

void mostrarPresentacion(){
	limpiarPantalla();
	cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n";
	cout << "               UNIVERSIDAD DE CARTAGENA\n";
	cout << "         FACULTAD DE INGENIERIA - SISTEMAS\n";
	cout << "             PROGRAMACION BASICA - 2025\n";
	cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n\n";
	
	cout << "         PROYECTO FINAL - SISTEMA DE CONTROL DE TARDANZAS\n\n";
	
	cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n";
	cout << "                    EQUIPO DE DESARROLLO:\n";
	cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n\n";
	
	cout << setw(35) << left << "JULIAN ALEJANDRO GUZMAN MORALES" << "0222420038\n";
	cout << setw(35) << left << "ALAN PEREIRA ESTRADA" << "0222420030\n";
	cout << setw(35) << left << "MIGUEL JOSE PARDO" << "0222420039\n";
	cout << setw(35) << left << "MANUEL FRANCISCO AMELL" << "0222421001\n";
	cout << setw(35) << left << "SAMUEL COGOLLO VILLARREAL" << "0222420018\n";
	cout << setw(35) << left << "MANUEL ESTEBAN ARCIA PASTRANA" << "\n\n";
	
	cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n";
	cout << "             DOCENTE: ING. NOHEMY CASTRO GENES\n";
	cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n";
}

void mostrarDescripcionPrograma(){
	limpiarPantalla();
	cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n";
	cout << "        SISTEMA DE CONTROL DE TARDANZAS - EMPRESA LS\n";
	cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n\n";
	
	cout << "DESCRIPCION DEL SISTEMA:\n";
	cout << "------------------------\n";
	cout << "Este sistema permite a la empresa LS (Logistics Service) llevar un control\n";
	cout << "preciso de las tardanzas de sus empleados. El jefe del Departamento de\n";
	cout << "Recursos Humanos podra gestionar registros, consultar informacion y generar\n";
	cout << "reportes estadisticos sobre la puntualidad del personal.\n\n";
	
	cout << "FUNCIONES PRINCIPALES:\n";
	cout << "---------------------\n";
	cout << "[1] Registro de informacion de empleados\n";
	cout << "[2] Registro de horas trabajadas y minutos de tardanza\n";
	cout << "[3] Consultas por empleado y por dependencia\n";
	cout << "[4] Reportes estadisticos y de descuentos\n";
	cout << "[5] Salir del programa\n\n";
	
	cout << "FUNCIONES ESPECIFICAS:\n";
	cout << "----------------------\n";
	cout << "- Validacion de IDs unicos para empleados\n";
	cout << "- Calculo automatico de descuentos por tardanza\n";
	cout << "- Generacion de reportes en archivos de texto\n";
	cout << "- Consultas por dependencia (Contabilidad, Sistemas, Logistica)\n";
	cout << "- Estadisticas de puntualidad y tardanza\n";
	cout << "- Almacenamiento en archivos binarios para persistencia de datos\n\n";
	
	cout << "DEPENDENCIAS SOPORTADAS:\n";
	cout << "------------------------\n";
	cout << "- Contabilidad\n";
	cout << "- Sistemas\n";
	cout << "- Logistica\n\n";
	
	cout << "REQUERIMIENTOS TECNICOS CUMPLIDOS:\n";
	cout << "---------------------------------\n";
	cout << "- Modularizacion del codigo en funciones\n";
	cout << "- Validaciones de datos de entrada\n";
	cout << "- Persistencia de datos en archivos\n";
	cout << "- Reportes con buena presentacion\n";
	cout << "- Manejo de errores en operaciones de archivos\n";
}

void salirAnimado() {
    limpiarPantalla();
    cout << "\nSaliendo del sistema";
    for (int i = 0; i < 4; i++) {
        cout << ".";
        cout.flush();
    }
    cout << "\n\n--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n";
    cout << "              SISTEMA DE REGISTRO DE TARDANZAS\n";
    cout << "                     EMPRESA LS\n";
    cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n\n";
    cout << "             Gracias por utilizar nuestro sistema\n";
    cout << "                     Hasta pronto!\n\n";
    cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n";
    cout << "\nPresione cualquier tecla para salir...";
    getch();
}

void limpiarPantalla(){
	system("cls");
}

void crear(){
	ofstream empleados("empleados.txt", ios::app | ios::binary);
	if(empleados.fail()){
		cout << "Error al crear archivo de empleados.\n";
		exit(0);
	}
	empleados.close();
	
	ofstream registro_horas("registro_horas.txt", ios::app | ios::binary);
	if(registro_horas.fail()){
		cout << "Error al crear archivo de registro de horas.\n";
		exit(0);
	}
	registro_horas.close();
}

int menuPrincipal(){
	cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n";
	cout << "                     MENU PRINCIPAL\n";
	cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n\n";
	
	cout << setw(5) << " " << "1. Registra informacion de empleados\n";
	cout << setw(5) << " " << "2. Registrar horas trabajadas y tardanza\n";
	cout << setw(5) << " " << "3. Consultas\n";
	cout << setw(5) << " " << "4. Reportes\n";
	cout << setw(5) << " " << "5. Salir\n";
	cout << "\n--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n";
	
	int opc = 0;
	cout << "\nSeleccione una opcion: ";
	while(!(cin >> opc) || opc < 1 || opc > 5){
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Opcion invalida. Ingrese un numero entre 1 y 5: ";
	}
	
	return opc;
}

bool validar(int id){
	EmpleadoInfo buffer;
	ifstream empleados("empleados.txt", ios::in | ios::binary);
	
	if(empleados.fail()){
		return false;
	}
	
	while(!empleados.eof()){
		empleados.read(reinterpret_cast<char *>(&buffer), sizeof(EmpleadoInfo));
		
		if(!empleados.eof() && buffer.id == id){
			empleados.close();
			return true;
		}
	}
	
	empleados.close();
	return false;
}

void registrarInfo(){
	EmpleadoInfo buffer;
	bool end = false;
	
	while(!end){
		limpiarPantalla();
		cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n";
		cout << "            REGISTRO DE INFORMACION DE EMPLEADOS\n";
		cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n\n";
		
		cout << "ID del empleado: ";
		cin >> buffer.id;
		
		if(!validar(buffer.id)){
			cout << "Nombre del empleado: ";
			cin.ignore();
			cin.getline(buffer.nombre, 50);
			
			cout << "Cargo del empleado: ";
			cin.getline(buffer.cargo, 50);
			
			cout << "\nDEPENDENCIAS DISPONIBLES:\n";
			cout << "1. Contabilidad\n";
			cout << "2. Sistemas\n";
			cout << "3. Logistica\n\n";
			
			buffer.dependencia = 0;
			while(buffer.dependencia < 1 || buffer.dependencia > 3){
				cout << "Seleccione dependencia (1-3): ";
				cin >> buffer.dependencia;
				
				if(buffer.dependencia < 1 || buffer.dependencia > 3){
					cout << "Opcion invalida. Intente nuevamente.\n";
				}
			}
			
			ofstream empleados("empleados.txt", ios::app | ios::binary);
			
			if(empleados.fail()){
				cout << "Error al guardar datos.\n";
				getch();
				return;
			}
			
			empleados.write(reinterpret_cast<char *>(&buffer), sizeof(EmpleadoInfo));
			empleados.close();
			
			cout << "\n--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n";
			cout << "         ¡Empleado registrado exitosamente!\n";
			cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n";
		}else{
			cout << "\n--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n";
			cout << "         ¡Error! Esta ID ya esta registrada.\n";
			cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n";
		}
		
		char opcion;
		cout << "\n¿Desea registrar otro empleado? (S/N): ";
		cin >> opcion;
		
		if(toupper(opcion) != 'S'){
			end = true;
		}
	}
	
	cout << "\nPresione cualquier tecla para continuar...";
	getch();
}

void registrarHoras(){
	EmpleadoHoras buffer;
	bool end = false;
	
	while(!end){
		limpiarPantalla();
		cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n";
	cout << "           REGISTRO DE HORAS Y TARDANZAS\n";
	cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n\n";
		
		cout << "ID del empleado: ";
		cin >> buffer.id;
		
		if(validar(buffer.id)){
			buffer.registrado = true;
			
			cout << "\n--- DATOS DEL EMPLEADO ---\n";
			cout << "Horas semanales trabajadas: ";
			cin >> buffer.horas;
			
			cout << "Minutos de tardanza semanal: ";
			cin >> buffer.tardanza;
			
			cout << "Valor por hora ($): ";
			cin >> buffer.valor;
			
			ofstream registro_horas("registro_horas.txt", ios::app | ios::binary);
			
			if(registro_horas.fail()){
				cout << "Error al guardar datos.\n";
				getch();
				return;
			}
			
			registro_horas.write(reinterpret_cast<char *>(&buffer), sizeof(EmpleadoHoras));
			registro_horas.close();
			
			cout << "\n--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n";
			cout << "         ¡Horas registradas exitosamente!\n";
			cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n";
		}else{
			cout << "\n--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n";
			cout << "         ¡Error! Empleado no encontrado.\n";
			cout << "   Primero registre al empleado en la opcion 1.\n";
			cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n";
		}
		
		char opcion;
		cout << "\n¿Desea registrar horas de otro empleado? (S/N): ";
		cin >> opcion;
		
		if(toupper(opcion) != 'S'){
			end = true;
		}
	}
	
	cout << "\nPresione cualquier tecla para continuar...";
	getch();
}

void menuConsultas(){
	int opt = 0;
	
	do{
		limpiarPantalla();
		cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n";
		cout << "                   MENU DE CONSULTAS\n";
		cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n\n";
		
		cout << setw(5) << " " << "1. Consultar un empleado\n";
		cout << setw(5) << " " << "2. Consultar una dependencia\n";
		cout << setw(5) << " " << "3. Volver al menu principal\n";
		cout << "\n--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n";
		
		cout << "\nSeleccione una opcion: ";
		cin >> opt;
		
		switch(opt){
			case 1: consultarEmpleado(); break;
			case 2: consultarDependencia(); break;
			case 3: cout << "\nRegresando al menu principal...\n"; break;
			default: 
				cout << "\nOpcion invalida. Intente nuevamente.\n";
				getch();
		}
	}while(opt != 3);
	
	cout << "\nPresione cualquier tecla para continuar...";
	getch();
}

void consultarEmpleado(){
	limpiarPantalla();
	cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n";
	cout << "                 CONSULTA DE EMPLEADO\n";
	cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n\n";
	
	EmpleadoInfo bufferInfo;
	EmpleadoHoras bufferHoras;
	int id;
	
	cout << "Ingrese la ID del empleado: ";
	cin >> id;
	
	ifstream empleados("empleados.txt", ios::in | ios::binary);
	ifstream registro_horas("registro_horas.txt", ios::in | ios::binary);
	
	if(empleados.fail()){
		cout << "\nError al abrir archivo de empleados.\n";
		getch();
		return;
	}
	
	bool infoID = false;
	bool horasID = false;
	
	while(!empleados.eof()){
		empleados.read(reinterpret_cast<char *>(&bufferInfo), sizeof(EmpleadoInfo));
		
		if(!empleados.eof() && bufferInfo.id == id){
			infoID = true;
			break;
		}
	}
	
	while(!registro_horas.eof()){
		registro_horas.read(reinterpret_cast<char *>(&bufferHoras), sizeof(EmpleadoHoras));
		
		if(!registro_horas.eof() && bufferHoras.id == id){
			horasID = true;
			break;
		}
	}
	
	if(!horasID){
		bufferHoras.horas = 0;
		bufferHoras.valor = 0;
		bufferHoras.tardanza = 0;
	}
	
	if(infoID){
		cout << "\n--------------------------------------------------------------------------------\n";
		cout << "                 DATOS DEL EMPLEADO\n";
		cout << "--------------------------------------------------------------------------------\n\n";
		
		cout << setw(20) << left << "ID:" << bufferInfo.id << "\n";
		cout << setw(20) << left << "Nombre:" << bufferInfo.nombre << "\n";
		cout << setw(20) << left << "Cargo:" << bufferInfo.cargo << "\n";
		cout << setw(20) << left << "Horas semanales:" << bufferHoras.horas << "\n";
		cout << setw(20) << left << "Valor por hora:" << "$" << bufferHoras.valor << "\n";
		cout << setw(20) << left << "Dependencia:";
		
		switch(bufferInfo.dependencia){
			case 1: cout << "Contabilidad\n"; break;
			case 2: cout << "Sistemas\n"; break;
			case 3: cout << "Logistica\n"; break;
		}
		
		cout << setw(20) << left << "Minutos de tardanza:" << bufferHoras.tardanza << "\n";
		cout << "\n--------------------------------------------------------------------------------\n";
	}else{
		cout << "\nEsta ID no esta relacionada con ningun empleado.\n";
	}
	
	empleados.close();
	registro_horas.close();
	
	cout << "\nPresione cualquier tecla para continuar...";
	getch();
}

void consultarDependencia(){
	limpiarPantalla();
	cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n";
	cout << "                CONSULTA POR DEPENDENCIA\n";
	cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n\n";
	
	EmpleadoInfo bufferInfo;
	EmpleadoHoras bufferHoras;
	int dep = 0;
	bool enHoras = false;
	
	cout << "Seleccione la dependencia:\n";
	cout << "1. Contabilidad\n";
	cout << "2. Sistemas\n";
	cout << "3. Logistica\n\n";
	
	while(dep < 1 || dep > 3){
		cout << "Opcion: ";
		cin >> dep;
		
		if(dep < 1 || dep > 3){
			cout << "Opcion invalida.\n";
		}
	}
	
	ifstream empleados("empleados.txt", ios::in | ios::binary);
	
	if(empleados.fail()){
		cout << "Error al abrir archivo.\n";
		getch();
		return;
	}
	
	cout << "\n--------------------------------------------------------------------------------\n";
	cout << "           EMPLEADOS EN LA DEPENDENCIA: ";
	
	string depNombre;
	switch(dep){
		case 1: depNombre = "Contabilidad"; break;
		case 2: depNombre = "Sistemas"; break;
		case 3: depNombre = "Logistica"; break;
	}
	
	cout << depNombre << "\n";
	cout << "--------------------------------------------------------------------------------\n\n";
	
	int maxTardanza = -1;
	string nombreMaxTardanza;
	int idMaxTardanza;
	
	int contEmpleados = 0;
	
	while(!empleados.eof()){
		empleados.read(reinterpret_cast<char *>(&bufferInfo), sizeof(EmpleadoInfo));
		
		if(empleados.fail()){
			break;
		}
		
		if(!empleados.eof()){
			if(bufferInfo.dependencia == dep){
				contEmpleados++;
				ifstream registro_horas("registro_horas.txt", ios::in | ios::binary);
				
				if(registro_horas.fail()){
					cout << "Error al abrir archivo de horas.\n";
					empleados.close();
					getch();
					return;
				}
				
				enHoras = false;
				
				while(!registro_horas.eof()){
					registro_horas.read(reinterpret_cast<char *>(&bufferHoras), sizeof(EmpleadoHoras));
					
					if(registro_horas.fail()){
						break;
					}
					
					if(!registro_horas.eof()){
						if(bufferHoras.id == bufferInfo.id){
							enHoras = true;
							break;
						}
					}
				}
				
				registro_horas.close();
				
				if(!enHoras){
					bufferHoras.horas = 0;
					bufferHoras.valor = 0;
					bufferHoras.tardanza = 0;
				}
				
				// Mostrar datos formateados
				cout << "EMPLEADO #" << contEmpleados << "\n";
				cout << setw(20) << left << "  ID:" << bufferInfo.id << "\n";
				cout << setw(20) << left << "  Nombre:" << bufferInfo.nombre << "\n";
				cout << setw(20) << left << "  Horas:" << bufferHoras.horas << "\n";
				cout << setw(20) << left << "  Valor hora:" << "$" << bufferHoras.valor << "\n";
				cout << setw(20) << left << "  Tardanza:" << bufferHoras.tardanza << " min\n";
				cout << "  ----------------------------------------------------------------\n";
				
				// Verificar si es el máximo
				if(bufferHoras.tardanza > maxTardanza){
					maxTardanza = bufferHoras.tardanza;
					nombreMaxTardanza = bufferInfo.nombre;
					idMaxTardanza = bufferInfo.id;
				}
			}
		}
	}
	
	empleados.close();
	
	if(contEmpleados == 0){
		cout << "No se encontraron empleados en esta dependencia.\n";
	}else{
		if(maxTardanza >= 0){
			cout << "\n--------------------------------------------------------------------------------\n";
			cout << "      EMPLEADO CON MAS MINUTOS DE TARDANZA:\n";
			cout << "--------------------------------------------------------------------------------\n\n";
			cout << setw(20) << left << "Nombre:" << nombreMaxTardanza << "\n";
			cout << setw(20) << left << "ID:" << idMaxTardanza << "\n";
			cout << setw(20) << left << "Minutos de tardanza:" << maxTardanza << "\n";
			cout << "\n--------------------------------------------------------------------------------\n";
		}else{
			cout << "\nNo se encontraron empleados con tardanza en esta dependencia.\n";
		}
	}
	
	cout << "\nPresione cualquier tecla para continuar...";
	getch();
}

void menuReportes(){
	int opt = 0;
	
	do{
		limpiarPantalla();
		cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n";
		cout << "                   MENU DE REPORTES\n";
		cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n\n";
		
		cout << setw(5) << " " << "1. Reporte General\n";
		cout << setw(5) << " " << "2. Reporte de empleados con tardanza\n";
		cout << setw(5) << " " << "3. Reporte de empleados puntuales\n";
		cout << setw(5) << " " << "4. Reporte de descuento por tardanza\n";
		cout << setw(5) << " " << "5. Volver al menu principal\n";
		cout << "\n--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n";
		
		cout << "\nSeleccione una opcion: ";
		cin >> opt;
		
		switch(opt){
			case 1: reporteGeneral(); break;
			case 2: reporteEmpleadosrt(); break;
			case 3: reporteEmpleadopt(); break;
			case 4: reporteDescuento(); break;
			case 5: cout << "\nRegresando al menu principal...\n"; break;
			default: 
				cout << "\nOpcion invalida. Intente nuevamente.\n";
				getch();
		}
	}while(opt != 5);
	
	cout << "\nPresione cualquier tecla para continuar...";
	getch();
}

void reporteGeneral(){
	limpiarPantalla();
	cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n";
	cout << "                  REPORTE GENERAL DE EMPLEADOS\n";
	cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n\n";
	
	ifstream empleados("empleados.txt", ios::binary);
	ifstream horas("registro_horas.txt", ios::binary);
	
	if(empleados.fail() or horas.fail()){
		cout << "Error al abrir los archivos.\n";
		getch();
		return;
	}
	
	EmpleadoInfo info;
	EmpleadoHoras h;
	
	cout << setw(8) << left << "Codigo" 
		 << setw(20) << left << "Nombre" 
		 << setw(12) << left << "Horas trab." 
		 << setw(15) << left << "Oficina" 
		 << setw(12) << left << "Min. Tardanza" 
		 << "\n";
	
	cout << "----------------------------------------------------------------------------\n";
	
	int cont = 0;
	
	while(!empleados.eof()){
		empleados.read(reinterpret_cast<char*>(&info), sizeof(EmpleadoInfo));
		if(empleados.eof()) break;
		
		horas.clear();
		horas.seekg(0);
		
		bool encontrado = false;
		
		while(!horas.eof()){
			horas.read(reinterpret_cast<char*>(&h), sizeof(EmpleadoHoras));
			if(horas.eof()) break;
			
			if(h.id==info.id){
				encontrado = true;
				break;
			}
		}
		
		if(!encontrado){
			h.horas = 0;
			h.valor = 0;
			h.tardanza =0;
		}
		
		char dep[20];
		switch(info.dependencia){
			case 1: strcpy(dep, "Contabilidad"); break;
			case 2: strcpy(dep, "Sistemas"); break;
			case 3: strcpy(dep, "Logistica"); break;
			default: strcpy(dep, "N/A");
		}
		
		cout << setw(8) << left << info.id 
			 << setw(20) << left << info.nombre 
			 << setw(12) << left << h.horas 
			 << setw(15) << left << dep 
			 << setw(12) << left << h.tardanza 
			 << "\n";
		
		cont++;
	}
	
	cout << "----------------------------------------------------------------------------\n";
	cout << "\nTotal de empleados listados: " << cont << "\n";
	
	empleados.close();
	horas.close();
	
	cout << "\nPresione cualquier tecla para continuar...";
	getch();
}

void reporteEmpleadosrt(){
	limpiarPantalla();
	
	int t_tardanza=0, cantidad=0, max_t=-1, min_t=999999;
	bool existe = false;
	
	cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n";
	cout << "            REPORTE DE EMPLEADOS CON TARDANZA\n";
	cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n\n";
	
	ifstream empleados("empleados.txt", ios::binary);
	ifstream horas("registro_horas.txt", ios::binary);
	
	if(empleados.fail() or horas.fail()){
		cout << "Error abriendo archivos\n";
		getch();
		return;
	}
	
	EmpleadoInfo info;
	EmpleadoHoras h;
	EmpleadoInfo emp_max, emp_min;
	
	cout << setw(20) << left << "Nombre" 
		 << setw(20) << left << "Cargo" 
		 << setw(15) << left << "Dependencia" 
		 << setw(12) << left << "Min. Tardanza" 
		 << "\n";
	
	cout << "----------------------------------------------------------------------------\n";
	
	while(!empleados.eof()){
		empleados.read(reinterpret_cast<char*>(&info), sizeof(EmpleadoInfo));
		if(empleados.eof()) break;
		
		horas.clear();
		horas.seekg(0);
		
		bool encontrado = false;
		
		while(!horas.eof()){
			horas.read(reinterpret_cast<char*>(&h), sizeof(EmpleadoHoras));
			if(horas.eof()) break;
			
			if(h.id == info.id){
				encontrado = true;
				break;
			}
		}
		
		if(!encontrado) continue;
		
		if(h.tardanza > 0){
			existe = true;
			cantidad++;
			t_tardanza += h.tardanza;
			
			char dep[20];
			switch(info.dependencia){
				case 1: strcpy(dep, "Contabilidad"); break;
				case 2: strcpy(dep, "Sistemas"); break;
				case 3: strcpy(dep, "Logistica"); break;
				default: strcpy(dep, "N/A");
			}
			
			cout << setw(20) << left << info.nombre 
				 << setw(20) << left << info.cargo 
				 << setw(15) << left << dep 
				 << setw(12) << left << h.tardanza 
				 << "\n";
			
			if(h.tardanza>max_t){
				max_t = h.tardanza;
				emp_max = info;
			}
			
			if(h.tardanza < min_t){
				min_t = h.tardanza;
				emp_min = info;
			}
		}
	}
	
	cout << "----------------------------------------------------------------------------\n\n";
	
	if(!existe){
		cout << "\nNo hay empleados con tardanza registrada.\n";
	}
	else
	{
		double promedio;
		promedio = (double)t_tardanza/cantidad;
		
		cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n";
		cout << "                    ESTADISTICAS\n";
		cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n\n";
		
		cout << setw(30) << left << "Empleado con MAYOR tardanza:" << emp_max.nombre << " (" << max_t << " min)\n";
		cout << setw(30) << left << "Empleado con MENOR tardanza:" << emp_min.nombre << " (" << min_t << " min)\n";
		cout << setw(30) << left << "Promedio general de tardanza:" << fixed << setprecision(2) << promedio << " minutos\n";
		cout << setw(30) << left << "Total de empleados con tardanza:" << cantidad << "\n";
		cout << setw(30) << left << "Total minutos de tardanza:" << t_tardanza << " minutos\n";
	}
	
	empleados.close();
	horas.close();
	
	cout << "\nPresione cualquier tecla para continuar...";
	getch();
}

void reporteEmpleadopt(){
	limpiarPantalla();
	
	bool puntuales = false;
	double sum_c = 0, sum_s = 0, sum_l = 0;
	int cont_c = 0, cont_s = 0, cont_l = 0;
	
	cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n";
	cout << "              REPORTE DE EMPLEADOS PUNTUALES\n";
	cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n\n";
	
	ifstream empleados("empleados.txt", ios::binary);
	ifstream horas("registro_horas.txt", ios::binary);
	
	if(empleados.fail() or horas.fail()){
		cout << "Error abriendo archivos.\n";
		getch();
		return;
	}
	
	EmpleadoInfo info;
	EmpleadoHoras h;
	
	cout << setw(8) << left << "ID" 
		 << setw(20) << left << "Nombre" 
		 << setw(20) << left << "Cargo" 
		 << setw(15) << left << "Dependencia" 
		 << setw(15) << left << "Horas trabajadas" 
		 << "\n";
	
	cout << "----------------------------------------------------------------------------\n";
	
	while(!empleados.eof()){
		empleados.read(reinterpret_cast<char*>(&info), sizeof(EmpleadoInfo));
		if(empleados.eof()) break;
		
		horas.clear();
		horas.seekg(0);
		
		bool encontrado = false;
		
		while(!horas.eof()){
			horas.read(reinterpret_cast<char*>(&h), sizeof(EmpleadoHoras));
			if(horas.eof()) break;
			
			if(h.id == info.id){
				encontrado = true;
				break;
			}
		}
		
		if(!encontrado) continue;
		
		if(h.tardanza == 0){
			puntuales = true;
			
			char dep[20];
			switch(info.dependencia){
				case 1: strcpy(dep, "Contabilidad"); break;
				case 2: strcpy(dep, "Sistemas"); break;
				case 3: strcpy(dep, "Logistica"); break;
				default: strcpy(dep, "N/A");
			}
			
			cout << setw(8) << left << info.id 
				 << setw(20) << left << info.nombre 
				 << setw(20) << left << info.cargo 
				 << setw(15) << left << dep 
				 << setw(15) << left << h.horas 
				 << "\n";
			
			switch(info.dependencia){
				case 1: sum_c += h.horas; cont_c++; break;
				case 2: sum_s += h.horas; cont_s++; break;
				case 3: sum_l += h.horas; cont_l++; break;
			}
		}
	}
	
	cout << "----------------------------------------------------------------------------\n";
	
	if(!puntuales){
		cout << "\nNo hay empleados puntuales registrados.\n";
	}
	else
	{
		double prom_c, prom_s, prom_l;
		prom_c = cont_c > 0 ? (sum_c/cont_c) : 0;
		prom_s = cont_s > 0 ? (sum_s/cont_s) : 0;
		prom_l = cont_l > 0 ? (sum_l/cont_l) : 0;
		
		cout << "\n--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n";
		cout << "           PROMEDIO DE HORAS POR DEPENDENCIA\n";
		cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n\n";
		
		cout << setw(25) << left << "Contabilidad:" << fixed << setprecision(2) << prom_c << " horas\n";
		cout << setw(25) << left << "Sistemas:" << prom_s << " horas\n";
		cout << setw(25) << left << "Logistica:" << prom_l << " horas\n";
		cout << "\n" << setw(25) << left << "Total empleados puntuales:" << (cont_c + cont_s + cont_l) << "\n";
	}
	
	empleados.close();
	horas.close();
	
	cout << "\nPresione cualquier tecla para continuar...";
	getch();
}

void reporteDescuento(){
	limpiarPantalla();
	
	cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n";
	cout << "            REPORTE DE DESCUENTO POR TARDANZA\n";
	cout << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n\n";
	
	ifstream empleados("empleados.txt", ios::binary);
	ifstream horas("registro_horas.txt", ios::binary);
	ofstream txt("prestaciones.txt");
	
	if(empleados.fail() or horas.fail() or txt.fail()){
		cout << "Error abriendo archivos.\n";
		getch();
		return;
	}
	
	EmpleadoInfo info;
	EmpleadoHoras h;
	
	bool existe = false;
	
	txt << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n";
	txt << "        REPORTE DE PRESTACIONES - DESCUENTO POR TARDANZA\n";
	txt << "--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n\n";
	
	cout << setw(8) << left << "ID" 
		 << setw(15) << left << "Nombre" 
		 << setw(15) << left << "Cargo" 
		 << setw(12) << left << "Dependencia" 
		 << setw(10) << left << "Valor/hr" 
		 << setw(8) << left << "Horas" 
		 << setw(8) << left << "Tardanza" 
		 << setw(10) << left << "H_desc" 
		 << setw(10) << left << "H_netas" 
		 << setw(12) << left << "Descuento" 
		 << setw(12) << left << "Salario" 
		 << "\n";
	
	cout << "----------------------------------------------------------------------------------------------------------------\n";
	
 	while(!empleados.eof()){
 		empleados.read(reinterpret_cast<char*>(&info), sizeof(EmpleadoInfo));
 		if(empleados.eof()) break;
 		
		horas.clear();
 		horas.seekg(0);
 		
 		bool encontrado= false;
 		
 		while(!horas.eof()){
 			horas.read(reinterpret_cast<char*>(&h), sizeof(EmpleadoHoras));
 			if(horas.eof()) break;
 			
 			if(h.id == info.id){
 				encontrado = true;
 				break;
			 }
		 }
		 
		 if(!encontrado) continue;
		 
		 if(h.tardanza <= 0) continue;
		 
		 existe = true;
		 
		 char dep[20];
		 switch(info.dependencia){
		 	case 1: strcpy(dep, "Contabilidad"); break;
		 	case 2: strcpy(dep, "Sistemas"); break;
		 	case 3: strcpy(dep, "Logistica"); break;
		 }
		 
		 double H_desc, H_netas, descuento, S_neto;
		 
		 H_desc = h.tardanza/60.0;
		 H_netas = h.horas - H_desc;
		 
		 if(H_netas < 0) H_netas = 0;
		 
		 descuento = H_desc * h.valor;
		 S_neto = H_netas * h.valor;
		 
		cout << setw(8) << left << info.id 
			 << setw(15) << left << info.nombre 
			 << setw(15) << left << info.cargo 
			 << setw(12) << left << dep 
			 << setw(10) << left << fixed << setprecision(2) << h.valor 
			 << setw(8) << left << h.horas 
			 << setw(8) << left << h.tardanza 
			 << setw(10) << left << fixed << setprecision(2) << H_desc 
			 << setw(10) << left << H_netas 
			 << setw(12) << left << descuento 
			 << setw(12) << left << S_neto 
			 << "\n";
			 
		txt << setw(8) << left << info.id 
			<< setw(15) << left << info.nombre 
			<< setw(15) << left << info.cargo 
			<< setw(12) << left << dep 
			<< setw(10) << left << fixed << setprecision(2) << h.valor 
			<< setw(8) << left << h.horas 
			<< setw(8) << left << h.tardanza 
			<< setw(10) << left << fixed << setprecision(2) << H_desc 
			<< setw(10) << left << H_netas 
			<< setw(12) << left << descuento 
			<< setw(12) << left << S_neto 
			<< "\n";
	 }
	 
	 empleados.close();
	 horas.close();
	 txt.close();
	 
	 if(!existe){
	 	cout << "\nNo hay empleados con tardanza registrada.\n";
	 	getch();
	 	return;
	 }
	 
	 int opc = 0;
	 cout << "\n--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/--/\n";
	 cout << "\nArchivo 'prestaciones.txt' generado exitosamente.\n";
	 cout << "¿Desea ver el archivo? [1] SI [2] NO: ";
	 cin >> opc;
	 
	 if(opc == 1){
	 	limpiarPantalla();
	 	
	 	ifstream visual("prestaciones.txt");
	 	
	 	if(!visual.fail())
	 	{
	 		char linea[300];
	 		
	 		while(!visual.eof()){
	 			visual.getline(linea, 300);
	 			cout << linea << endl;
			 }
			 visual.close();
		}
		
		cout << "\nPresione cualquier tecla para continuar...";
		getch();
	 }
}
