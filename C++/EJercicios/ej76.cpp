#include <iostream> 
using namespace std;
int main (){
int n;
cout <<"ingrese la cantidad de candidatos :";cin >>n;
string nombres [n];
int votoszona [n][6];
for (int i=0;i < n;i++){
    cout << " nombre del candidato :";
    getline (cin,nombres[n]);
    votoszona[i][5]=0;
    for (int x=0;x <5;x++){
        cout << "zona "<<x+1<<"cantidad de votos :";
        cin >> votoszona[i][x];votoszona[i][5]+=votoszona[i][x];
    }
}
for (int i =0; i < n;i++){
    cout << "nombres :"<<nombres[i];
    for (int x=0; x < n;x++){
        
    }
}

}