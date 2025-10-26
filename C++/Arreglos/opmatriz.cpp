#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;
int main(){
   
    int opc=1;
    int n;
    
 cout << "ingrese el tamaño de la matriz :";
 cin >>n;
  long long sumatoria[n]={0};
    double matriz[n][n]={0};

    for (int i =0;i < n;i++){
        for (int x=0; x < n;x++){
            matriz[i][x]=0;
        }
    }

    do{
            
            cout <<"\n 0) mostrar matriz"
                 <<"\n 1)Rellenar TODA la matriz de números"
                 <<"\n 2)Suma de cada fila de la matriz"
                 <<"\n 3)Suma de cada columna de la matriz"
                 <<"\n 4)Sumar la diagonal principal"
                 <<"\n 5)Sumar la diagonal inversa"
                 <<"\n 6)Sumar la fila x:"
                 <<"\n 7)Sumar la columna x:"
                 <<"\n 8)La media de todos los valores de la matriz"
                 <<"\n 9)Buscar un valor dado en la matriz"
                 <<"\n 10)salir"<<endl;
                 cin >>opc;
                 
                 while (opc <0 or opc >10){
                    system("cls");
            cout <<"\n 0) mostrar matriz"
                 <<"\n 1)Rellenar TODA la matriz de números "
                 <<"\n 2)Suma de cada fila de la matriz"
                 <<"\n 3)Suma de cada columna de la matriz"
                 <<"\n 4)Sumar la diagonal principal"
                 <<"\n 5)Sumar la diagonal inversa"
                 <<"\n 6)Sumar la fila x:"
                 <<"\n 7)La media de todos los valores de la matriz"
                 <<"\n 8)Buscar un valor dado en la matriz"
                 <<"\n 9)salir"
                 <<"\n\ningrese un numero valido :"<<endl;
                 cin >>opc;
                 }
                 if (opc==0){
            
                    for (int i=0;i <n ;i++){
                        for (int x=0;x < n;x++){
                            cout << "[ "<<matriz[i][x]<<" ]";
                        }
                        cout <<endl;
                    }
                    
                 }
            else if (opc==1){system("cls");
            for (int i=0 ;i < n;i++){//filas
                    for (int x=0 ;x < n; x++){//columnas

                        for (int j=0 ;j < n;j++){
                            for (int k=0 ;k < n; k++){
                                    cout <<"["<<matriz[j][k]<<"] ";
                                        }
                                        cout <<endl;
                                            }
                
                 cout <<"ingrese el numero para la posicion fila "<<i+1<<" columna "<<x+1<<endl;
                    cin >>matriz[i][x];
                    system("cls");           
                             }//fin columnas
                            }//fin filas

                        }//opc1

            else if (opc==2){system("cls");
                 sumatoria[n]=0;
                 for (int i=0;i <n ;i++){//filas

                        for (int x=0;x < n;x++){//columnas
                            cout << "[ "<<matriz[i][x]<<" ]";
                            sumatoria[i]+=matriz[i][x];
                        }
                                    cout <<setw(3)<< "Suma fila #";
                            
                                    cout <<i+1<<" = "<<sumatoria[i];
                                    cout <<endl;
                                        }
                            }//opc2

            else if(opc ==3){system("cls");
                sumatoria[n]=0;
                for(int a=0; a < n;a++){//filas
                                for (int b=0;b < n ;b++){//columnas 
                                    cout << "[ "<<matriz [a][b]<<" ] ";
                                }
                                cout << endl;
                            }
                for (int i=0;i < n;i++){//filas S
                    for (int x=0;x < n;x++){//columnas S
                        sumatoria [i]+=matriz[x][i];
                    }
                    cout <<"Sumatoria columna "<<i+1<<" = "<<sumatoria[i]<<endl;
                }

            }//opc3

            else if (opc==4){system("cls");
                    int diagonal=0;
                     for (int i=0;i <n ;i++){
                        for (int x=0;x < n;x++){
                            cout << "[ "<<matriz[i][x]<<" ]  ";
                        }
                        cout <<endl;
                    }
                    for (int i=n-1;i >= 0;i--){
                    diagonal +=matriz[i][i];
                    }
                                        
                            cout << "[ suma DIAGONAL PRINCIPAL]"<<diagonal;
                        cout <<endl;
                    
            }//fin opc4

            else if (opc==5){ system("cls");
                int diagonal=0;
                int x=0;
                for (int i=n-1;i >=0;i--){
                    diagonal+=matriz[i][x];
                    x++;
                }
                            for (int i=0;i <n ;i++){
                        for (int x=0;x < n;x++){
                            cout << "[ "<<matriz[i][x]<<" ]";
                                        }
                        cout <<endl;
                                    }
                                    cout <<"Suma DIAGONAL INVERSA: "<<diagonal<<endl;
            }//fin opc5
            else if (opc==6){system("cls");
                int filas;long sumafilas=0;
                do{
                cout << "INGRESE LA FILA A SUMAR :";
                cin >> filas;
            }while(filas<1 || filas >n);
                
                            for (int i=filas-1;i <filas;i++){
                                 for (int x=0;x < n;x++){
                            sumafilas+=matriz[i][x];
                                        }
                                    }
                                     for (int i=0;i <n ;i++){
                                         for (int x=0;x < n;x++){
                                    cout << "[ "<<matriz[i][x]<<" ]";   
                                    }

                                        if(i==filas-1){
                                        cout <<"La suma de la fila " <<filas<<" = "<<sumafilas;
                                        }  
                                        cout <<endl;
                                    }
                            }//fin opc6

                            else if (opc==7){system("cls");
                                int columna;
                                long sumacolumna=0;
                                do
                                {
                                    cout << "INGRESE EL NUMERO DE COLUMNA A SUMAR : ";
                                    cin >> columna;
                                } while (columna <1|| columna >n);

                                for (int i=0;i < n;i++){
                                        sumacolumna += matriz[i][columna-1];
                                }
                                cout <<"La suma de la columna "<<columna <<" = "<<sumacolumna<<endl;

                                 for (int i=0;i <n ;i++){
                                      for (int x=0;x < n;x++){
                                             cout << "[ "<<matriz[i][x]<<" ]";
                                                    }
                                                 cout <<endl;
                                                    }

                            }

                            else if (opc==8){
                                double acumulado=0;
                                for (int i=0;i < n ; i++){
                                    for (int x=0;x < n;x++){
                                        acumulado +=matriz[i][x];
                                    }
                                }
                                cout << "EL PROMEDIO DE DATOS ES :"<<acumulado / (n*n);
                            }//fin opc8

                            else if (opc == 9) {
                             float buscar;
                               bool encontrado = false;

                            cout << "Ingrese un número a buscar en la matriz: ";
                            cin >> buscar;

                             cout << "MATRIZ\n\n";
                            for (int i = 0; i < n; i++) {
                                for (int x = 0; x < n; x++) {

                                    if (matriz[i][x] == buscar) {
                                    encontrado = true;
                                    // Imprimir resaltado con corchetes verdes y número alineado
                                    cout<< "\033[32m["
                                        << setw(2) << matriz[i][x]
                                        << "]\033[0m ";Sleep(400);
                                     } else {
                                    
                                     cout << "[" << setw(2) << matriz[i][x] << "] ";Sleep(400);
                                        }           
                                     }
                                    cout << endl;
                                    } 

                                     if (encontrado) {
                                     cout << "\nEl número " << buscar << " fue encontrado en las posiciones:\n";
                                        for (int i = 0; i < n; i++) {
                                             for (int x = 0; x < n; x++) {

                                            if (matriz[i][x] == buscar) {
                                                cout << " -> (" << i << ", " << x << ")\n";
                                                     }

                                                }
                                            }

                             } else {
                              cout << "\nEl número " << buscar << " no fue encontrado en la matriz.\n";
                                                 }
                                                 cout <<"para volver a l menu : ";
                                       system("pause"); }
       
        }while(opc!=10);
    return 0;
}