#include <iostream>
#include <iomanip>
using namespace std;
int main (){

int n;
cout << "ingrese la cantidad de Nadadores :";
cin >>n;
float arr[n];
string nadadores[n];

for (int i =0;i < n; i++){
    cout <<"nombre del nadador #"<<i+1<<" : ";
    cin >>nadadores[i];
  
    cout<< "tiempo en segundos del nadador #"<<i+1<<" : ";
    cin >> arr[i];
     cout << endl;
}

for (int i=0;i < n-1;i++){

for (int x=0; x < n-i-1;x++)
{
    if (arr[x]>arr[x+1])
    {   float aux=arr[x];
        string aux2=nadadores[x];

        arr[x]=arr[x+1];
        nadadores[x]=nadadores[x+1];
        arr[x+1]=aux;
        nadadores[x+1]=aux2;
    }
}

}

for (int i=0; i < n;i++){
    cout << i+1<<" puesto :"<<arr[i]<<"Sec"<<setw(5)<<nadadores[i]<<endl<<endl;
}
    return 0;
}