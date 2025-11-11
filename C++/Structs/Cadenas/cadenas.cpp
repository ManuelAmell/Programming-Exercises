#include <cctype>
#include <cstring>
#include <iostream>
using namespace std;
int cv(char tal[], int i)
{
    if (tal[i] == '\0') {
        return 0;
    } else {
        if (tal[i] == 'a' || tal[i] == 'e' || tal[i] == 'i' || tal[i] == 'o' || tal[i] == 'u') {
            return 1;
        } else {
            return 0;
        }
    }
    cv(tal, i++);
}
int main()
{
    int c = 0;
    char tal[200];
    cout << "ingrese una cadena: ";
    cin.getline(tal, 200);
    for (int i = 0; i < strlen(tal); i++) {
        c += cv(tal, i);
    }
    cout << "cantidad de vocales: " << c << endl;
}