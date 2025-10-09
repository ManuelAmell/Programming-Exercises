#include <iostream>//ejercicio 14*/
#define iq "cociente IQ"
#define bz " belleza"
#define cu "cultura general"
using namespace std;
int main(){

    int x=0;
    string nombres[20];
    float p[3][20];
    long  ac[3]={0};


    for (int i=0;i < 20; i++){
        fflush(stdin);
        cout << "Nombre "<<"competidora "<<i+1<<" :";getline(cin,nombres[i+1]);
        
            cout <<"ingrese "<<iq<<"para "<<x+1<<" : "<<endl;
            cin >> p[i][x];
            ac[0]+=p[i][x];

            cout << "ingrese "<<cu<<"para "<<x+1<<": "<<endl;
            cin >>p[i][x+1];
             ac[1]+=p[i][x+1];

            cout <<"ingrese "<<bz<<"para "<<x+1<<" : "<<endl;
            cin >> p[i][x+2];
            ac[2]+=p[i][x+2];
            
        }
        
        
    

    return 0;
}