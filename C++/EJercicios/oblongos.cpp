#include <iostream>
using namespace std;
int main (){
int n,c=0;
cout << "ingrese N :";
cin >> n;
int arr[n],arro[n];
for (int i=0;i < n; i++){
    do{
    cout << "ingrese el elemento #"<<i+1<<" :";
    cin >> arr[i];
    }while (arr[i]<0);
    for (int x=0;x < arr[i];x++)
    {

    if ((x * (x+1))==arr[i])
    {
        arro[c]=arr[i];
        c++;
        break;
    }
    
    }
}
cout <<" arreglo original"<<endl;
for (int i=0;i < n;i++)
{
    cout <<arr[i]<<" ";
}
cout <<" arreglo de elementos oblongos"<<endl;

for (int i=0;i < c;i++)
{
    cout <<arro[i]<<" ";
}
    return 0;
}//17,19