#include <iostream>
using namespace std;

int main()
{
    char comandos[100001];
    cout << "ingrese comandos : ";
    cin >> comandos;

    int x = 0, y = 0;
    int origen = 0;

    for (int i = 0; i < 10000; i++) {

        switch (comandos[i]) {
        case 'N':
            y++;
            break;
        case 'n':
            y++;
            break;
        case 'S':
            y--;
            break;
        case 's':
            y--;
            break;
        case 'E':
            x++;
            break;
        case 'e':
            x++;
            break;
        case 'O':
            x--;
            break;
        case 'o':
            x--;
            break;
        case 'G':
            break;
        case 'g':
            break;
        default:
            continue;
        }
        if (x == 0 && y == 0) {
            origen++;
        }
    }

    cout << "(" << x << "," << y << "," << origen << ")";
    return 0;
}
