#include <iostream>
#include <iomanip>
#include <cstring>
#include <conio.h>
#include <cstdlib>
#include "wp.h"
using namespace std;

// NOTAS
/* linea 375 -> calcular los puntos nuevos de a y b, ni idea de como hacerlo. 

*/

struct publicacion {
    int id_publicacion, anio;
    char abstract[200], titulo_publicacion[50], premio[200], tipo_publicacion[50];
    float puntos_b, puntos_a;
};

struct autores {
    int id_autor;
    char nombre[50], correo[50], programa[100];
    publicacion pb[50];
    int np;
};

// + - + - + - + - + - + - + - + funciones + - + - + - + - + - + - + - + - +

void puntos_y_tipo(int op, publicacion &p) {
    switch (op) {
        case 1: strcpy(p.tipo_publicacion, "Publicacion en revista internacional indexada"); p.puntos_b = 100; break;
        case 2: strcpy(p.tipo_publicacion, "Publicacion en revista nacional"); p.puntos_b = 80; break;
        case 3: strcpy(p.tipo_publicacion, "Ponencia en congreso internacional"); p.puntos_b = 70; break;
        case 4: strcpy(p.tipo_publicacion, "Ponencia en congreso nacional"); p.puntos_b = 60; break;
        case 5: strcpy(p.tipo_publicacion, "Articulo en boletin o revista estudiantil"); p.puntos_b = 40; break;
        default: strcpy(p.tipo_publicacion, "Desconocido"); p.puntos_b = 0;
    }
}

bool existe_p(autores autor[], publicacion p, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < autor[i].np; j++)
            if (p.id_publicacion == autor[i].pb[j].id_publicacion)
                return true;
    return false;
}

bool existe_a(autores autor[], autores nuevo, int n) {
    for (int i = 0; i < n; i++)
        if (nuevo.id_autor == autor[i].id_autor)
            return true;
    return false;
}

int buscar_autor(int id, autores autor[], int n) {
    for (int i = 0; i < n; i++)
        if (id == autor[i].id_autor)
            return i;
    return -1;
}

void registro_autor(autores autor[], int &n) {
    system("cls");
    autores nuevo;
    if (n >= 10) {
        cout << "Cantidad maxima registrada.\n";
        system("pause");
        return;
    }

    cout << "\n=== Registro de Autor " << n + 1 << " ===\n";
    cout << "ID: ";
    cin >> nuevo.id_autor;

    if (existe_a(autor, nuevo, n)) {
        cout << "Autor ya registrado.\n";
        system("pause");
        return;
    }

    cin.ignore();
    cout << "Nombre: "; cin.getline(nuevo.nombre, 50);
    cout << "Correo: "; cin.getline(nuevo.correo, 50);
    cout << "Programa: "; cin.getline(nuevo.programa, 100);

    nuevo.np = 0;
    autor[n] = nuevo;
    n++;
    cout << "Autor registrado correctamente.\n";
    system("pause");
}

void mostrarMenuColores() {
    cout << "\nSeleccione color:\n";
    cout << "[1] Rojo\n";
    cout << "[2] Verde\n";
    cout << "[3] Azul\n";
    cout << "[4] Amarillo\n";
    cout << "[5] Resetear color\n";
}

void registrar_publicacion(autores autor[], int n) {
    system("cls");
    if (n == 0) {
        cout << "No hay autores registrados.\n";
        system("pause");
        return;
    }

    int aux;
    cout << "ID del autor dueño de la publicacion: ";
    cin >> aux;

    int i = buscar_autor(aux, autor, n);
    if (i == -1) {
        cout << "Este autor no existe.\n";
        system("pause");
        return;
    }

    if (autor[i].np >= 50) {
        cout << "Numero maximo de publicaciones registradas.\n";
        system("pause");
        return;
    }

    publicacion p;
    cout << "\n=== Registro de Publicacion para: " << autor[i].nombre << " ===\n";
    cout << "ID de la publicacion: ";
    cin >> p.id_publicacion;

    if (existe_p(autor, p, n)) {
        cout << "Ya existe esta publicacion.\n";
        system("pause");
        return;
    }

    cin.ignore();
    cout << "Titulo: "; cin.getline(p.titulo_publicacion, 50);

    int op;
    do {
        cout << "\nTipo de publicacion:\n";
        cout << "[1] Revista internacional indexada\n";
        cout << "[2] Revista nacional\n";
        cout << "[3] Congreso internacional\n";
        cout << "[4] Congreso nacional\n";
        cout << "[5] Boletin o revista estudiantil\n";
        cout << "Seleccione: ";
        cin >> op;
        if (op < 1 || op > 5) cout << "Opcion invalida.\n";
    } while (op < 1 || op > 5);

    puntos_y_tipo(op, p);

    cout << "Año: "; cin >> p.anio;
    cin.ignore();
    cout << "Premio (si no aplica escriba 'ninguno'): ";
    cin.getline(p.premio, 200);

    if (strcmp(p.premio, "ninguno") != 0 && strlen(p.premio) > 0)
        p.puntos_a = 20;
    else
        p.puntos_a = 0;

    cout << "Resumen: ";
    cin.getline(p.abstract, 200);

    char resp;
    cout << "\n¿Desea analizar o editar el texto? (s/n): ";
    cin >> resp;
    cin.ignore();

    if (tolower(resp) == 's') {
        int opcion1;
        do {
            system("cls");
            cout << "--- My WP ---\n";
            cout << "[1] Analizar texto\n";
            cout << "[2] Editar texto\n";
            cout << "[3] Salir\n";
            cout << "Seleccione una opción: ";
            cin >> opcion1;
            cin.ignore();

            switch (opcion1) {
                case 1: {
                    int sub;
                    do {
                        system("cls");
                        cout << "--- Análisis de Texto ---\n";
                        cout << "[1] Total de caracteres\n";
                        cout << "[2] Contar vocales\n";
                        cout << "[3] Contar numéricos\n";
                        cout << "[4] Contar espacios\n";
                        cout << "[5] Contar especiales\n";
                        cout << "[6] Contar palabras\n";
                        cout << "[7] Salir\n";
                        cout << "Seleccione: ";
                        cin >> sub;

                        switch (sub) {
                            case 1: cout << "Total de caracteres: " << totalCaracteres(p.abstract) << endl; break;
                            case 2: cout << "Vocales: " << contarVocales(p.abstract) << endl; break;
                            case 3: cout << "Numéricos: " << contarNumericos(p.abstract) << endl; break;
                            case 4: cout << "Espacios: " << contarEspacios(p.abstract) << endl; break;
                            case 5: cout << "Especiales: " << contarEspeciales(p.abstract) << endl; break;
                            case 6: cout << "Palabras: " << contarPalabras(p.abstract) << endl; break;
                        }
                        system("pause");
                    } while (sub != 7);
                    break;
                }

                case 2: {
                    int sub;
                    do {
                        system("cls");
                        cout << "--- Edición de Texto ---\n";
                        cout << "[1] Convertir todo a mayúsculas\n";
                        cout << "[2] Convertir todo a minúsculas\n";
                        cout << "[3] Detectar tipo de oración\n";
                        cout << "[4] Capitalizar palabras\n";
                        cout << "[5] Asignar color\n";
                        cout << "[6] Salir\n";
                        cout << "Seleccione: ";
                        cin >> sub;
                        cin.ignore();

                        switch (sub) {
                            case 1: aMayusculas(p.abstract); cout << p.abstract << endl; break;
                            case 2: aMinusculas(p.abstract); cout << p.abstract << endl; break;
                            case 3: cout << "Tipo de oración: " << tipoOracion(p.abstract) << endl; break;
                            case 4: capitalizarPalabras(p.abstract); cout << p.abstract << endl; break;
                            case 5: {
                                int colorOp;
                                mostrarMenuColores();
                                cin >> colorOp;
                                asignarColor(colorOp);
                                cout << p.abstract << endl;
                                asignarColor(5);
                                break;
                            }
                        }
                        system("pause");
                    } while (sub != 6);
                    break;
                }
            }
        } while (opcion1 != 3);
    }

    autor[i].pb[autor[i].np] = p;
    autor[i].np++;

    cout << "\nPublicación registrada correctamente.\n";
    cout << "Puntos base: " << p.puntos_b << "\n";
    cout << "Puntos adicionales: " << p.puntos_a << "\n";
    cout << "Total: " << p.puntos_b + p.puntos_a << "\n";
    system("pause");
}

void mostrarDatosAutor(autores autor[], int i){
	cout << "Datos del autor: \n";
	cout << "ID del autor: " << autor[i].id_autor << endl;
	cout << "Nombre del autor: " << autor[i].nombre << endl;
	cout << "Correo del autor: " << autor[i].correo << endl;
	cout << "Programa del autor: " << autor[i].programa << endl;
}

void actualizarAutor(autores autor[], int n){
	system("cls");
	
	int autID, autDeseado, opc = 0;
	
	cout << "Ingresar la ID del autor que desea actualizar: ";
	cin >> autID;
	
	autDeseado = buscar_autor(autID, autor, n);
	
	if(autDeseado >= 0){
		cout << "Se ha encontrado al autor!\n";
		
		mostrarDatosAutor(autor, autDeseado);
		
		do{
			cout << "Que dato desea modificar?: \n";
			cout << "[1] Nombre. \n";
			cout << "[2] Correo. \n";
			cout << "[3] Programa. \n";
			cin >> opc;
		}while(opc < 1 || opc > 3);
		
		switch(opc){
			case 1:{
				cout << "Ingresar el nombre modificado: ";
				fflush(stdin); 
				gets(autor[autDeseado].nombre);
				break;
			}
			case 2:{
				cout << "Ingresar el correo modificado: ";
				fflush(stdin);
				gets(autor[autDeseado].correo);
				break;
			}
			case 3:{
				cout << "Ingresar el programa modificado: ";
				fflush(stdin);
				gets(autor[autDeseado].programa);
				break;
			}
		}
		
	}else{
		cout << "No se ha encontrado al autor ingresado. \n";
	}
}

void actualizarPub(autores autor[], int n){
	int pubID, opc;
	bool found = false;
	
	int f, c;
	
	cout << "Ingresar ID de la publicación: ";
	cin >> pubID;
	
	for(f = 0; f < n; f++){
		for(c = 0; c < autor[f].np; c++){
			if(pubID == autor[f].pb[c].id_publicacion){
				found = true;
				break;
			}
		}
		if(found) break;
	}
	
	if(found == true){
		system("cls");
		cout << "Datos de la publicacion: ";
		cout << "ID: " << autor[f].pb[c].id_publicacion << endl;
		cout << "Año: " << autor[f].pb[c].anio << endl;
		cout << "Abstract: \n" << autor[f].pb[c].abstract << endl;
		cout << "Titulo: " << autor[f].pb[c].titulo_publicacion << endl;
		cout << "Premio: \n" << autor[f].pb[c].premio << endl;
		cout << "Tipo de publicación: " << autor[f].pb[c].tipo_publicacion << endl;
		cout << "Puntos a: " << autor[f].pb[c].puntos_a << endl;
		cout << "Puntos b: " << autor[f].pb[c].puntos_b << endl;
		
		do{
			cout << "Que dato desea modificar?: \n";
			cout << "[1] Año. \n";
			cout << "[2] Abstract. \n";
			cout << "[3] Titulo. \n";
			cout << "[4] Premio. \n";
			cout << "[5] Tipo de publicación (1-5). \n";
			cin >> opc;
		}while(opc < 1 || opc > 5);
		
		cin.ignore();
		
		switch(opc){
			case 1:{
				cout << "Ingresar nuevo año: ";
				cin >> autor[f].pb[c].anio;
				break;
			}
			case 2:{
				cout << "Ingresar nuevo abstract: \n";
				gets(autor[f].pb[c].abstract);
				break;
			}
			case 3:{
				cout << "Ingresar nuevo titulo: \n";
				gets(autor[f].pb[c].titulo_publicacion);
				break;
			}
			case 4:{
				cout << "Ingresar nuevo premio: \n";
				gets(autor[f].pb[c].premio);
				
				if(strcmp(autor[f].pb[c].premio, "ninguno") != 0){
					autor[f].pb[c].puntos_a = 20;
				}else{
					autor[f].pb[c].puntos_a = 0;
				}
				
				break;
			}
			case 5:{
				int nuev;
				
				do{
					cout << "Ingresar nuevo tipo de publicación (1-5): ";
					cin >> nuev;
				}while(nuev < 1 || nuev > 5);
				
				puntos_y_tipo(nuev, autor[f].pb[c]);
				break;
			}
		}
		
	}else{
		cout << "No se encontró una publicación con esa ID. \n";
	}
}

void asignarActualizar(autores autor[], int n){
	system("cls");
	char opc;
	bool loop = true;
	
	while(loop){
		cout << "ASIGNACIÓN Y ACTUALIZACIÓN DE DATOS \n";
		cout << "[a] Autor. \n";
		cout << "[b] Publicación. \n";
		cout << "[c] Salir. \n";
		cout << "Opción deseada: ";
		cin >> opc; 
		opc = tolower(opc);
		
		switch(opc){
			case 'a': actualizarAutor(autor, n); break;
			case 'b': actualizarPub(autor, n); break;
			case 'c': loop = false; break;
		}
	}
}

void consultarAutor(autores autor[], int n){
	int autID, AD;
	
	cout << "Ingresar la ID del autor: ";
	cin >> autID;
	
	AD = buscar_autor(autID, autor, n);
	
	if(autor[AD].np == 0){
		cout << "El autor no tiene publicaciones. \n";
		return;
	}
	
	if(AD >= 0){
		cout << "PUBLICACIONES DEL AUTOR: \n";
		
		for(int i = 0; i < autor[AD].np; i++){
			cout << "PUBLICACION #"  << i+1 << endl;
			cout << "Título: " << autor[AD].pb[i].titulo_publicacion << endl;
			cout << "Tipo de publicacion: " << autor[AD].pb[i].tipo_publicacion << endl;
			cout << "Premio: " << autor[AD].pb[i].premio << endl;
			cout << "Puntaje base: " << autor[AD].pb[i].puntos_b << endl;
			cout << "Puntos adicionales: " << autor[AD].pb[i].puntos_a << endl;
			cout << "Total de puntos: " << autor[AD].pb[i].puntos_b + autor[AD].pb[i].puntos_a << endl << endl;
		}
	}else{
		cout << "No se encontró la ID del autor. \n";
	}
	
	system("pause");
}

void consultarPub(autores autor[], int n){
	int ID, f, c;
	bool found = false;
	
	cout << "Ingresar la ID de la publicación: ";
	cin >> ID;
	
	for(f = 0; f < n; f++){
		for(c = 0; c < autor[f].np; c++){
			if(ID == autor[f].pb[c].id_publicacion){
				found = true;
				break;
			}
		}
		if (found) break;
	}
	
	if(found){
		cout << "Autor de la publicación: " << autor[f].nombre << endl;
		cout << "Programa al que pertenece: " << autor[f].programa << endl;
		cout << "Cantidad de puntos obtenidos: " << autor[f].pb[c].puntos_b + autor[f].pb[c].puntos_a << endl << endl;
	}else{
		cout << "No se encontró la ID de la publicación... \n";
	}
	
	system("pause");
}

void listadoGeneral(autores autor[], int n){
	
	for(int i = 0; i < n; i++){
		cout << "Publicaciones de: " << autor[i].nombre << ": \n \n";
		double acum = 0;
		for(int j = 0; j < autor[i].np; j++){
			cout << "#" << j+1 << ": \n";
			cout << "Titulo: " << autor[i].pb[j].titulo_publicacion << endl;
			cout << "Puntaje total: " << autor[i].pb[j].puntos_b + autor[i].pb[j].puntos_a << endl;
			acum += autor[i].pb[j].puntos_b + autor[i].pb[j].puntos_a;
		}
		cout << "\n Puntaje acumulado del autor: " << acum << "\n \n";
	}
	
	system("pause");
}

void reportesConsultas(autores autor[], int n){
	system("cls");
	char opc;
	bool loop = true;
	
	while(loop){
		cout << "REPORTES Y CONSULTAS \n";
		cout << "[a] Consultar un autor. \n";
		cout << "[b] Consultar una publicación. \n";
		cout << "[c] Listado de todos los autores y sus publicaciones. \n";
		cout << "[d] Salir. \n";
		cout << "Opción deseada: ";
		cin >> opc; 
		opc = tolower(opc);
		
		switch(opc){
			case 'a':{
				consultarAutor(autor, n);
				break;
			}
			case 'b':{
				consultarPub(autor, n);
				break;
			}
			case 'c':{
				listadoGeneral(autor, n);
				break;
			}
			case 'd':{
				loop = false;
				break;
			}
		}
	}
}

void estadisticas(autores autor[],int n){
	
	system("cls");
	cout << "====Estadisticas Generales====\n";
	
	if(n == 0){
		cout << "No hay autores registrados.\n";
		system("pause");
		return;
	}
	
	cout << "\nA) Numero de publicaciones por autor:\n";
	for(int i = 0; i < n; i++){
		cout << autor[i].nombre << ": " << autor[i].np << " publicaciones\n";
	}
	
	int conPremio = 0, totalAutoresConPub = 0;
	for(int i = 0; i < n; i++){
		bool tienePremio = false;
		if(autor[i].np > 0) totalAutoresConPub++;
		for(int j = 0; j < autor[i].np; j++){
			if (strcmp(autor[i].pb[j].premio, "ninguno") != 0 && strlen(autor[i].pb[j].premio) > 0)
			{
                tienePremio = true;
                break;
            }
		}
		if(tienePremio) conPremio++;
	}
	
	float porcentajePremio = (totalAutoresConPub == 0) ? 0 : (float)conPremio / totalAutoresConPub * 100;
	cout << "\nB) Porcentaje de autores con algun premio: " << fixed << setprecision(2) << porcentajePremio << "%\n";
	
	float maxP = -1, minP = 999999;
	int iMax = -1, iMin = -1;
	for(int i = 0; i < n; i++){
		float total = 0;
		for(int j = 0; j < autor[i].np; j++){
			total += autor[i].pb[j].puntos_b + autor[i].pb[j].puntos_a;
		}
		
		if(autor[i].np > 0)
		{
			if(total > maxP){
				maxP = total; iMax = i;
			}
			else if(total < minP){
				minP = total; iMin = i;
			}
		}
	}
	
	cout << "\nC) Autor con mayor puntaje: ";
    if (iMax != -1) cout << autor[iMax].nombre << " (" << maxP << " puntos)\n";
    else cout << "No disponible.\n";
	
	cout << "   Autor con menor puntaje: ";
    if (iMin != -1) cout << autor[iMin].nombre << " (" << minP << " puntos)\n";
    else cout << "No disponible.\n";
    
    const int tipos = 5;
    int conteo[tipos] = {0};
    float sumaPuntos[tipos] = {0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < autor[i].np; j++) {
            int t = 0;
            if (strcmp(autor[i].pb[j].tipo_publicacion, "Publicacion en revista internacional indexada") == 0) t = 0;
            else if (strcmp(autor[i].pb[j].tipo_publicacion, "Publicacion en revista nacional") == 0) t = 1;
            else if (strcmp(autor[i].pb[j].tipo_publicacion, "Ponencia en congreso internacional") == 0) t = 2;
            else if (strcmp(autor[i].pb[j].tipo_publicacion, "Ponencia en congreso nacional") == 0) t = 3;
            else t = 4;

            conteo[t]++;
            sumaPuntos[t] += autor[i].pb[j].puntos_b + autor[i].pb[j].puntos_a;
        }
    }
    
     int totalPub = 0, maxTipo = 0;
    for (int i = 0; i < tipos; i++) totalPub += conteo[i];
    for (int i = 1; i < tipos; i++) if (conteo[i] > conteo[maxTipo]) maxTipo = i;

    const char* nombresTipos[tipos] = {
        "Revista internacional indexada",
        "Revista nacional",
        "Congreso internacional",
        "Congreso nacional",
        "Boletin o revista estudiantil"
    };

    cout << "\nD) Tipo con más registros: " << nombresTipos[maxTipo] << endl;
    if (totalPub > 0) {
        cout << "   Representa el " << fixed << setprecision(2) << (float)conteo[maxTipo] / totalPub * 100 << "% de las publicaciones.\n";
        cout << "   Promedio de puntos: " << sumaPuntos[maxTipo] / conteo[maxTipo] << endl;
    }

    system("pause");
}

// + - + - + - + - + - + - + int main + - + - + - + - + - + - + - +

int main() {
	setlocale(LC_ALL, "spanish");
    int op, n = 0;
    autores autor[10];

    do {
        system("cls");
        cout << setw(30) << "PUBLISOFT\n";
        cout << "----------------------------------------\n";
        cout << "[1] Registro de autores\n";
        cout << "[2] Registro de publicaciones\n";
        cout << "[3] Asignación y actualización de puntos\n";
        cout << "[4] Reportes y consultas\n";
        cout << "[5] Estadisticas\n";
        cout << "[6] Salir\n";
        cout << "Seleccione una opción: ";
        cin >> op;

        switch (op) {
            case 1: registro_autor(autor, n); break;
            case 2: registrar_publicacion(autor, n); break;
            case 3: asignarActualizar(autor, n); break;
            case 4: reportesConsultas(autor, n); break;
            case 5: estadisticas(autor, n); break;
            case 6: cout << "Gracias por usar PUBLISOFT. saliendo..."; break;
        }
    } while (op != 6);
}

