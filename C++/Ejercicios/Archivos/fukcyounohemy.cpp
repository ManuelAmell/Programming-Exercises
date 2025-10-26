#include<iostream>
using namespace std;
int main()
{
    int n;

    cout<<"Ingresar n numero de candidatos: "; cin>>n;

    int matriz[n][5];
    string nombre[n];

    for(int x = 0; x < n; x++){
        cin.ignore();
        cout<<"Ingresar nombre del candidato #"<<x + 1; getline(cin, nombre[n]);

        for(int y = 0; y < 5; y++){
            cout<<"Ingresar votos que consigui en la zona #"<<y + 1; cin>>matriz[x][y];
        }
    }

    cout<<"Output: "<<endl;

    for(int x = 0; x < n; x++){
        cout<<nombre[x]<<": ";
        for(int y = 0; y < 5; y++){
            cout<<matriz[x][y]<<"   ";
        }
        cout<<endl;
    }
}