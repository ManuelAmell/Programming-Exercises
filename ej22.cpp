#include <iostream>

using namespace std;

int main (){

int m1[3][3];
int m2[3][3];

for (int x=0;x <3;x++)
{
    for (int i=0;i <3;i++)
    {
        cout <<"ingrese el valor para "<<"["<<x+1<<"]-"<<"["<<i+1<<"]";
        cin >>m1[x][i];

    }

}

for (int o=0;o < 3;o++)
{
    for(int p=0;p < 3 ;p++)
    {
        m2[p][o]=m1[o][p];
    }
   

 
}

cout <<"matriz  original"<<endl;

for (int r=0;r < 3;r++)
 {
    for (int e=0;e <3 ;e++)
    {
        cout <<"["<<m1[r][e]<<"]\t";

    }
    cout<<"\n";
 }

 cout <<"matriz transpuesta :"<<endl;

 for (int q=0;q < 3;q++)
 {
   for(int w=0; w <3 ;w++)
   {
       cout <<"["<<m2[q][w]<<"]\t";
   }
   cout <<"\n";
 }
 
return 0;
}