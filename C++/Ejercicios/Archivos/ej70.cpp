#include <iostream>//programa organiza numeros de un arreglo primero los pares luego los impares /no incluye orden
using namespace std;
int main (){
int n;
    cout << "ingrese un tamaño para el arreglo :";
    cin >>n;
    int arr[n];
for (int i=0;i < n ;i++){
cout << " ingrese el numero para #"<<i+1<<" :";
cin >>arr[i];
}
int pos=0;

for(int i=0;i<n ;i++)
{   
    if (arr[i] %2 ==0){
    int aux=arr[i];
    for (int x=i;x > pos ;x--){
        arr[x]=arr[x-1];
    }
    arr[pos]=aux;
    pos++;
    }
}
for (int i=0;i <n ;i++){
    cout << arr [i]<< " ";
}
    return 0;
}