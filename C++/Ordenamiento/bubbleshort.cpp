//algoritmo por bubble short
#include <iostream>
#include <iomanip>
using namespace std;
int main(){

    int n;
    cout << "ingrese el volumen del arreglo :";
    cin >> n;
    int arr[n];//sizeof(arr) / sizeof(arr[0])// aqui no funciona sizeof por que es arreglo dinamico

    for (int i=0;i < n;i ++){
        cout << "ingrese el elemento # "<<i+1<<" : "<<endl; 
        cin >>arr[i];
    }   

    
    cout << "arreglo original :"<<endl;

    if (n==1){

        cout << "arreglo de un elemento  :"<<arr[0]<<endl;
    }
    
    else{

    
    for (int i=0;i < n;i++){
        cout << arr[i] <<" ";
        ;
    }
    
    cout << endl;
    
    for ( int i=0;i < n-1 ;i++ )
    {
        bool orden=false;
        
        for ( int x=0;x < n-i-1;x++ )
        {
            if (arr[x] < arr[x+1]) // el signo determina el orden si es mayor o menor
            {   //swap(arr[x],arr[x+1]);//no valido en clase y mas facil
                int aux= arr[x];
                arr[x]= arr[x+1];
                arr[x+1]= aux;
                orden=true;
            }
        }
         if (!orden){
                break;
            }
    }

    cout << "arreglo ordenado de mayor a menor : "<<endl;
    for (int i=0; i < n ;i++)
    {
        cout << arr[i]<<" ";
       
    }
}

    return 0;
}