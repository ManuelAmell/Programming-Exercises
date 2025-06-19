//algoritmo por inserccion
#include <iostream>
#include <chrono>
using namespace std;

int main (){

    int arr[8]={8,6,5,4,3,2,1,0};

int n=sizeof(arr)/sizeof(arr[0]);
cout <<"tamaño del arreglo "<< n<<endl;

for (int i = 1;i < n;i++){

int actual=arr[i];
int j= i-1;

while (j >= 0 && arr[j] > actual ){

arr[ j + 1 ]=arr[j];
j--;

}

arr[j+1]=actual;

}

for (int i =0;i < n; i++){
    cout <<arr[i]<< " ";
}
    return 0;
}