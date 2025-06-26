#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <sstream>

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

std::string generarCodigo(int id) {
    std::ostringstream oss;
    oss << "PKT-" << id << "-" << rand() % 9000 + 1000;
    return oss.str();
}

bool iaDetectarPatron(int id, double defectRate) {
    if (id % 7 == 0 && defectRate > 0.2) return true;
    return false;
}

int main() {
    using namespace std;

    ofstream db("registro_paquetes.txt");//archivo de texto
    if (!db) {
        cerr << "Error al crear archivo de base de datos.\n";
        return 1;
    }

    int totalBags;
    double defectRate;
    cout << "Cantidad de paquetes a simular: ";
    cin  >> totalBags;
    cout << "Probabilidad de equipaje defectuoso (0.0-1.0): ";
    cin  >> defectRate;

    const int WIDTH = 100;
    const int HEIGHT = 20;
    const int FRAME_MS = 200;

    int zones[5] = {5, 30, 55, 80, 95};
    const char* zoneNames[5] = {
        "REGISTRO",
        "CLASIFICACION",
        "SEGURIDAD",
        "TRANSPORTE",
        "EMBARQUE"
    };

    const int reX = 50, reY = 15;

    struct Bag {
        int id, x, y, dx;
        string codigo;
    };
    vector<Bag> bags;

    int spawned = 0, processed = 0, a_devolver = 0, reinspected = 0;
    int spawnTimer = 0;

    srand((unsigned)time(NULL));

    auto drawBox = [&](int left, int top, const string& label, vector<string>& scr) {
        for (int y = 0; y < 3; ++y) {
            for (int x = 0; x < 24; ++x) {
                int sx = left + x;
                int sy = top + y;
                if (sx >= 0 && sx < WIDTH && sy >= 0 && sy < HEIGHT) {
                    if ((y == 0 || y == 2) && (x > 0 && x < 23)) scr[sy][sx] = '-';
                    else if ((x == 0 || x == 23) && (y > 0 && y < 2)) scr[sy][sx] = '|';
                    else if ((x == 0 && y == 0) || (x == 23 && y == 0) || (x == 0 && y == 2) || (x == 23 && y == 2)) scr[sy][sx] = '+';
                }
            }
        }
        for (size_t i = 0; i < label.size() && left + 2 + i < WIDTH - 1; ++i)
            scr[top + 1][left + 2 + i] = label[i];
    };

    while (processed + a_devolver < totalBags) {
        if (spawned < totalBags) {
            spawnTimer += FRAME_MS;
            if (spawnTimer >= FRAME_MS) {
                string cod = generarCodigo(spawned + 1);
                bags.push_back({spawned + 1, 0, 10, 1, cod});
                db << "[REGISTRO] Paquete #" << spawned + 1 << " (" << cod << ") registrado en sistema.\n";
                ++spawned;
                spawnTimer = 0;
            }
        }

        for (int i = 0; i < (int)bags.size(); ++i) {
            Bag &b = bags[i];
            b.x += b.dx;

            for (int z = 0; z < 5; ++z) {
                if (b.x == zones[z]) {
                    if (z == 2) {
                        double r = rand() / double(RAND_MAX);
                        bool ia_detecta = iaDetectarPatron(b.id, defectRate);
                        if (r < defectRate || ia_detecta) {
                            ++a_devolver;
                            setColor(12);
                            cout << "[A DEVOLVER] Paquete #" << b.id << " (" << b.codigo << ") en mal estado\n";
                            setColor(7);
                            db << "[A DEVOLVER] Paquete #" << b.id << " (" << b.codigo << ") en mal estado.\n";
                            bags.erase(bags.begin() + i);
                            --i; goto continue_loop;
                        }
                        if (r < defectRate + 0.10) {
                            b.x = reX; b.y = reY;
                            ++reinspected;
                            db << "[REINSPECCION] Paquete #" << b.id << " (" << b.codigo << ") enviado a reinspeccion.\n";
                            break;
                        }
                    }
                    if (z == 4) {
                        ++processed;
                        setColor(10);
                        cout << "[PROCESADO] Paquete #" << b.id << " (" << b.codigo << ") embarcado\n";
                        setColor(7);
                        db << "[EMBARQUE] Paquete #" << b.id << " (" << b.codigo << ") procesado correctamente.\n";
                        bags.erase(bags.begin() + i);
                        --i;
                    }
                    break;
                }
            }
            continue_loop: ;
        }

        system("cls");
        vector<string> screen(HEIGHT, string(WIDTH, ' '));

        for (int z = 0; z < 5; ++z) drawBox(zones[z] - 4, 5, zoneNames[z], screen);
        drawBox(reX - 4, reY - 1, "REINSPECCION", screen);

        for (auto &b : bags)
            if (b.x >= 0 && b.x < WIDTH && b.y >= 0 && b.y < HEIGHT)
                screen[b.y][b.x] = 'O';

        for (auto &ln : screen) cout << ln << '\n';
        setColor(11);
        cout << "Creados: " << spawned
             << " | Procesados: " << processed
             << " | A devolver: " << a_devolver
             << " | En transito: " << bags.size()
             << " | Reinspeccionados: " << reinspected << "\n";
        setColor(7);

        Sleep(FRAME_MS);
    }

    int notifications = processed + a_devolver;

    setColor(14);
    cout << "\nSimulacion completada. Total a devolver: " << a_devolver << "\n";
    setColor(11);
    cout << "\nNotificando a la empresa de envios sobre el estado de la simulacion...\n";
    cout << "Total de paquetes procesados: " << processed << "\n";
    cout << "Total de paquetes a devolver: " << a_devolver << "\n";
    cout << "Total de paquetes reinspeccionados: " << reinspected << "\n";
    cout << "Notificaciones enviadas a la empresa: " << notifications << "\n";
    cout << "Reporte enviado exitosamente.\n";
    setColor(7);

    db << "\n--- REPORTE FINAL ---\n";
    db << "Procesados: " << processed << "\n";
    db << "A devolver: " << a_devolver << "\n";
    db << "Reinspeccionados: " << reinspected << "\n";
    db << "Notificaciones: " << notifications << "\n";
    db.close();
//Manuel Amell
    return 0;
}