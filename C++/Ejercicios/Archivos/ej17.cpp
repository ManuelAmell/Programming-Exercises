#include <iostream>

using namespace std;    
    
int main(){

int grupo[3]={1,2,3};
int e=2;
int nuevotam=0;

for(int i=0;i<3;i++)
{
    cout<<"["<<grupo[i]<<"]"<<"   ";

}
cout <<endl;

for (int i=0;i<3;i++)//se recorre el arreglo original
{
    if (grupo[i]!=e)//si el elemento es diferente de e
    {
        grupo[nuevotam]=grupo[i];//se guarda en el nuevo arreglo
        nuevotam++;
    }
}
for(int i=0;i<nuevotam;i++)
{
    cout<<"["<<grupo[i]<<"]"<<"   ";
    
}
    return 0;
}