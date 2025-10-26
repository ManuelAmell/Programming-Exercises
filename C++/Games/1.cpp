#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>

using namespace std;

struct Product {
    int id;
    string name;
    int stock;
    int minStock;
    float cost;
    float price;
    int totalSold;
    string category;
    string barcode;
    time_t dateAdded;
    time_t lastModified;
    bool active;
};

struct Transaction {
    int productId;
    string productName;
    int quantity;
    float amount;
    string type;
    time_t timestamp;
    string notes;
};

// --- Utilidades ---
string toFixed(float v, int decimals = 2) {
    ostringstream ss;
    ss << fixed << setprecision(decimals) << v;
    return ss.str();
}

bool isNumber(const string &s) {
    if (s.empty()) return false;
    char *endptr = nullptr;
    strtod(s.c_str(), &endptr);
    return *endptr == '\0';
}

string getCurrentDateTime() {
    time_t now = time(0);
    char buf[80];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now));
    return string(buf);
}

string toLowerCase(const string &str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// --- Funciones de guardado/carga ---
void saveData(const vector<Product> &products, const vector<Transaction> &transactions, 
              float totalRevenue, float totalCostSold) {
    ofstream file("inventory_data.txt");
    if (!file.is_open()) {
        cerr << "Error al guardar datos" << endl;
        return;
    }
    
    file << totalRevenue << " " << totalCostSold << "\n";
    file << products.size() << "\n";
    
    for (const auto &p : products) {
        file << p.id << "|" << p.name << "|" << p.stock << "|" << p.minStock << "|"
             << p.cost << "|" << p.price << "|" << p.totalSold << "|"
             << p.category << "|" << p.barcode << "|" << p.dateAdded << "|"
             << p.lastModified << "|" << p.active << "\n";
    }
    
    file << transactions.size() << "\n";
    for (const auto &t : transactions) {
        file << t.productId << "|" << t.productName << "|" << t.quantity << "|"
             << t.amount << "|" << t.type << "|" << t.timestamp << "|" << t.notes << "\n";
    }
    
    file.close();
    cout << "Datos guardados exitosamente" << endl;
}

void loadData(vector<Product> &products, vector<Transaction> &transactions, 
              float &totalRevenue, float &totalCostSold, int &nextId) {
    ifstream file("inventory_data.txt");
    if (!file.is_open()) {
        cout << "No se encontró archivo de datos previo" << endl;
        return;
    }
    
    file >> totalRevenue >> totalCostSold;
    file.ignore();
    
    int numProducts;
    file >> numProducts;
    file.ignore();
    
    products.clear();
    nextId = 1;
    
    for (int i = 0; i < numProducts; ++i) {
        string line;
        getline(file, line);
        istringstream iss(line);
        
        Product p;
        string token;
        
        getline(iss, token, '|'); p.id = stoi(token);
        getline(iss, p.name, '|');
        getline(iss, token, '|'); p.stock = stoi(token);
        getline(iss, token, '|'); p.minStock = stoi(token);
        getline(iss, token, '|'); p.cost = stof(token);
        getline(iss, token, '|'); p.price = stof(token);
        getline(iss, token, '|'); p.totalSold = stoi(token);
        getline(iss, p.category, '|');
        getline(iss, p.barcode, '|');
        getline(iss, token, '|'); p.dateAdded = stoll(token);
        getline(iss, token, '|'); p.lastModified = stoll(token);
        getline(iss, token, '|'); p.active = stoi(token);
        
        products.push_back(p);
        if (p.id >= nextId) nextId = p.id + 1;
    }
    
    int numTransactions;
    file >> numTransactions;
    file.ignore();
    
    transactions.clear();
    for (int i = 0; i < numTransactions; ++i) {
        string line;
        getline(file, line);
        istringstream iss(line);
        
        Transaction t;
        string token;
        
        getline(iss, token, '|'); t.productId = stoi(token);
        getline(iss, t.productName, '|');
        getline(iss, token, '|'); t.quantity = stoi(token);
        getline(iss, token, '|'); t.amount = stof(token);
        getline(iss, t.type, '|');
        getline(iss, token, '|'); t.timestamp = stoll(token);
        getline(iss, t.notes, '|');
        
        transactions.push_back(t);
    }
    
    file.close();
    cout << "Datos cargados exitosamente" << endl;
}

void exportReport(const vector<Product> &products, const vector<Transaction> &transactions,
                  float totalRevenue, float totalCostSold) {
    ofstream file("reporte_" + to_string(time(0)) + ".txt");
    if (!file.is_open()) return;
    
    file << "╔════════════════════════════════════════════════╗\n";
    file << "║     REPORTE DEL SISTEMA DE INVENTARIO         ║\n";
    file << "╚════════════════════════════════════════════════╝\n\n";
    file << "Fecha: " << getCurrentDateTime() << "\n\n";
    
    file << "┌─ RESUMEN FINANCIERO ─────────────────────────┐\n";
    file << "│ Ingresos totales:  $" << toFixed(totalRevenue) << "\n";
    file << "│ Costo total:       $" << toFixed(totalCostSold) << "\n";
    file << "│ Ganancia neta:     $" << toFixed(totalRevenue - totalCostSold) << "\n";
    float margin = totalRevenue > 0 ? ((totalRevenue - totalCostSold) / totalRevenue) * 100 : 0;
    file << "│ Margen:            " << toFixed(margin, 1) << "%\n";
    file << "└──────────────────────────────────────────────┘\n\n";
    
    file << "┌─ INVENTARIO ACTUAL ──────────────────────────┐\n";
    int lowStock = 0;
    for (const auto &p : products) {
        if (p.active) {
            file << "│ ID:" << p.id << " | " << p.name << " | Cat:" << p.category << "\n";
            file << "│   Stock: " << p.stock << " | Vendidos: " << p.totalSold
                 << " | Precio: $" << toFixed(p.price) << " | Costo: $" << toFixed(p.cost) << "\n";
            if (p.stock <= p.minStock) {
                file << "│   ⚠ ALERTA: Stock bajo (mínimo: " << p.minStock << ")\n";
                lowStock++;
            }
            file << "│\n";
        }
    }
    file << "└──────────────────────────────────────────────┘\n\n";
    
    file << "Productos con stock bajo: " << lowStock << "\n\n";
    
    file << "┌─ PRODUCTOS MÁS VENDIDOS ─────────────────────┐\n";
    vector<Product> sorted = products;
    sort(sorted.begin(), sorted.end(), [](const Product &a, const Product &b){
        return a.totalSold > b.totalSold;
    });
    for (int i = 0; i < min(10, (int)sorted.size()); ++i) {
        file << "│ " << (i+1) << ". " << sorted[i].name 
             << " - " << sorted[i].totalSold << " unidades\n";
    }
    file << "└──────────────────────────────────────────────┘\n\n";
    
    file << "┌─ HISTORIAL DE TRANSACCIONES (últimas 50) ───┐\n";
    int start = max(0, (int)transactions.size() - 50);
    for (int i = start; i < (int)transactions.size(); ++i) {
        const auto &t = transactions[i];
        char buf[80];
        strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M", localtime(&t.timestamp));
        file << "│ " << buf << " | " << t.type << " | " << t.productName 
             << " | Cant: " << t.quantity << " | $" << toFixed(t.amount) << "\n";
        if (!t.notes.empty()) {
            file << "│   Nota: " << t.notes << "\n";
        }
    }
    file << "└──────────────────────────────────────────────┘\n";
    
    file.close();
    cout << "Reporte exportado" << endl;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(1400, 800), "Sistema de Gestión de Inventario Pro", sf::Style::Default);
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/dejavu-sans-fonts/DejaVuSans.ttf")) {
        cerr << "Error: No se pudo cargar la fuente" << endl;
        return -1;
    }

    vector<Product> products;
    vector<Transaction> transactions;
    int nextId = 1;
    float totalRevenue = 0.0f;
    float totalCostSold = 0.0f;

    loadData(products, transactions, totalRevenue, totalCostSold, nextId);

    enum Mode { NONE, ADD, SELL, RETURN, VIEW, HISTORY, SEARCH, EDIT, ALERTS, STATS } mode = NONE;

    string in_name = "", in_stock = "", in_cost = "", in_price = "", in_quantity = "";
    string in_category = "", in_search = "", in_barcode = "", in_minStock = "", message = "";
    int activeField = 0;
    int selectedProductIdx = -1;
    int hoveredProductIdx = -1;
    float listScroll = 0.0f;
    float historyScroll = 0.0f;
    bool showInactive = false;
    
    float messageTimer = 0.0f;
    sf::Clock animClock;

    sf::Text title("SISTEMA DE GESTION DE INVENTARIO PRO", font, 30);
    title.setFillColor(sf::Color::White);
    title.setStyle(sf::Text::Bold);

    struct Button { sf::FloatRect rect; string label; sf::Color color; string icon; };
    vector<Button> buttons = {
        {{0,0,0,0}, "Agregar", sf::Color(70,130,180), "+"},
        {{0,0,0,0}, "Vender", sf::Color(60,180,75), "$"},
        {{0,0,0,0}, "Devolver", sf::Color(255,140,0), "←"},
        {{0,0,0,0}, "Editar", sf::Color(100,149,237), "✎"},
        {{0,0,0,0}, "Totales", sf::Color(138,43,226), "Σ"},
        {{0,0,0,0}, "Historial", sf::Color(220,20,60), "⌚"},
        {{0,0,0,0}, "Buscar", sf::Color(0,139,139), "🔍"},
        {{0,0,0,0}, "Alertas", sf::Color(255,69,0), "⚠"},
        {{0,0,0,0}, "Estadísticas", sf::Color(72,61,139), "📊"},
        {{0,0,0,0}, "Guardar", sf::Color(34,139,34), "💾"},
        {{0,0,0,0}, "Reporte", sf::Color(184,134,11), "📄"}
    };

    auto drawButton = [&](sf::RenderWindow &w, const Button &b, bool active=false){
        sf::RectangleShape r(sf::Vector2f(b.rect.width, b.rect.height));
        r.setPosition(b.rect.left, b.rect.top);
        
        sf::Color btnColor = active ? sf::Color(b.color.r+40, b.color.g+40, b.color.b+40) : b.color;
        r.setFillColor(btnColor);
        r.setOutlineThickness(2);
        r.setOutlineColor(active ? sf::Color::Yellow : sf::Color(50,50,50));
        
        if (active) {
            sf::RectangleShape glow(sf::Vector2f(b.rect.width+6, b.rect.height+6));
            glow.setPosition(b.rect.left-3, b.rect.top-3);
            glow.setFillColor(sf::Color::Transparent);
            glow.setOutlineThickness(3);
            glow.setOutlineColor(sf::Color(255,255,0,100));
            w.draw(glow);
        }
        
        w.draw(r);
        
        sf::Text icon(b.icon, font, 20);
        icon.setPosition(b.rect.left + 8, b.rect.top + 8);
        icon.setFillColor(sf::Color::White);
        w.draw(icon);
        
        sf::Text t(b.label, font, 12);
        t.setPosition(b.rect.left + 35, b.rect.top + b.rect.height/2 - 8);
        t.setFillColor(sf::Color::White);
        t.setStyle(sf::Text::Bold);
        w.draw(t);
    };

    auto drawLabel = [&](const string &txt, float x, float y, int size=16, sf::Color color=sf::Color::White, bool bold=false){
        sf::Text t(txt, font, size);
        t.setPosition(x, y);
        t.setFillColor(color);
        if (bold) t.setStyle(sf::Text::Bold);
        window.draw(t);
    };

    auto drawInputField = [&](float x, float y, float w, float h, const string &content, 
                              const string &placeholder, bool active){
        sf::RectangleShape field(sf::Vector2f(w, h));
        field.setPosition(x, y);
        field.setFillColor(sf::Color(50,50,60));
        field.setOutlineThickness(2);
        field.setOutlineColor(active ? sf::Color::Yellow : sf::Color(80,80,90));
        
        if (active) {
            float time = animClock.getElapsedTime().asSeconds();
            if (fmod(time, 1.0f) < 0.5f) {
                sf::RectangleShape cursor(sf::Vector2f(2, h-8));
                float textWidth = content.length() * 8.0f;
                cursor.setPosition(x + 5 + textWidth, y + 4);
                cursor.setFillColor(sf::Color::Yellow);
                window.draw(cursor);
            }
        }
        
        window.draw(field);
        
        sf::Text t(content.empty() ? placeholder : content, font, 14);
        t.setPosition(x+5, y+h/2-10);
        t.setFillColor(content.empty() ? sf::Color(120,120,120) : 
                       (active ? sf::Color::Yellow : sf::Color::White));
        window.draw(t);
    };

    auto drawProductCard = [&](const Product &p, float x, float y, float w, bool selected, bool hovered){
        sf::RectangleShape card(sf::Vector2f(w, 90));
        card.setPosition(x, y);
        
        sf::Color bgColor;
        if (selected) bgColor = sf::Color(80,100,140);
        else if (hovered) bgColor = sf::Color(60,60,80);
        else bgColor = sf::Color(45,45,55);
        
        if (p.stock <= p.minStock && p.minStock > 0) {
            bgColor.r = min(bgColor.r + 40, 255);
            bgColor.g = max(bgColor.g - 20, 0);
        }
        
        card.setFillColor(bgColor);
        card.setOutlineThickness(selected ? 3 : 1);
        card.setOutlineColor(selected ? sf::Color::Yellow : sf::Color(30,30,30));
        window.draw(card);
        
        if (p.stock <= p.minStock && p.minStock > 0) {
            sf::CircleShape alert(8);
            alert.setPosition(x + 8, y + 8);
            alert.setFillColor(p.stock == 0 ? sf::Color(255,0,0) : sf::Color(255,200,0));
            window.draw(alert);
            drawLabel("!", x + 11, y + 6, 14, sf::Color::White, true);
        }
        
        drawLabel("ID:" + to_string(p.id) + " - " + p.name, x+30, y+8, 16, sf::Color::White, true);
        
        sf::RectangleShape catTag(sf::Vector2f(80, 18));
        catTag.setPosition(x + 30, y + 30);
        catTag.setFillColor(sf::Color(70,70,90));
        window.draw(catTag);
        drawLabel(p.category, x + 35, y + 32, 11, sf::Color(200,200,255));
        
        string stockText = "Stock: " + to_string(p.stock);
        sf::Color stockColor = p.stock == 0 ? sf::Color(255,50,50) :
                               p.stock <= p.minStock ? sf::Color(255,200,100) : 
                               p.stock > p.minStock * 3 ? sf::Color(100,255,100) : sf::Color::White;
        drawLabel(stockText, x + 120, y + 32, 12, stockColor);
        
        drawLabel("Vendidos: " + to_string(p.totalSold), x + 220, y + 32, 12, sf::Color(180,180,200));
        
        drawLabel("$" + toFixed(p.price), x + 30, y + 55, 18, sf::Color(100,255,100), true);
        drawLabel("Costo: $" + toFixed(p.cost), x + 120, y + 58, 11, sf::Color(255,200,150));
        
        float unitProfit = p.price - p.cost;
        drawLabel("Ganancia: $" + toFixed(unitProfit), x + 220, y + 58, 11, 
                 unitProfit >= 0 ? sf::Color(150,255,150) : sf::Color(255,150,150));
        
        float maxBarWidth = w - 70;
        float stockPercent = p.minStock > 0 ? (float)p.stock / (p.minStock * 5) : 0.5f;
        stockPercent = min(stockPercent, 1.0f);
        
        sf::RectangleShape stockBg(sf::Vector2f(maxBarWidth, 6));
        stockBg.setPosition(x + 30, y + 80);
        stockBg.setFillColor(sf::Color(30,30,40));
        window.draw(stockBg);
        
        sf::RectangleShape stockBar(sf::Vector2f(maxBarWidth * stockPercent, 6));
        stockBar.setPosition(x + 30, y + 80);
        sf::Color barColor = stockPercent < 0.2f ? sf::Color(255,50,50) :
                             stockPercent < 0.5f ? sf::Color(255,200,0) : sf::Color(50,255,50);
        stockBar.setFillColor(barColor);
        window.draw(stockBar);
    };

    while (window.isOpen()) {
        sf::Event event;
        hoveredProductIdx = -1;
        
        if (messageTimer > 0) {
            messageTimer -= 0.016f;
            if (messageTimer <= 0) message = "";
        }
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                saveData(products, transactions, totalRevenue, totalCostSold);
                window.close();
            }

            if (event.type == sf::Event::Resized) {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }

            if (event.type == sf::Event::MouseWheelScrolled) {
                if (mode == HISTORY) {
                    historyScroll += -event.mouseWheelScroll.delta * 20.0f;
                    if (historyScroll < 0) historyScroll = 0;
                } else {
                    listScroll += -event.mouseWheelScroll.delta * 20.0f;
                    if (listScroll < 0) listScroll = 0;
                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mp = sf::Mouse::getPosition(window);
                float mx = (float)mp.x, my = (float)mp.y;
                sf::Vector2u winSize = window.getSize();
                float leftPanelWidth = 220;

                for (size_t i=0; i<buttons.size(); ++i){
                    sf::FloatRect bRect(10, 70 + i*60, leftPanelWidth-20, 50);
                    buttons[i].rect = bRect;
                    if (bRect.contains(mx,my)){
                        message = "";
                        messageTimer = 0;
                        activeField = 0;
                        listScroll = 0;
                        historyScroll = 0;
                        in_name = in_stock = in_cost = in_price = in_quantity = in_category = in_search = in_barcode = in_minStock = "";
                        
                        if (i==0) { mode = ADD; selectedProductIdx = -1; }
                        else if (i==1) { mode = SELL; selectedProductIdx = -1; }
                        else if (i==2) { mode = RETURN; selectedProductIdx = -1; }
                        else if (i==3) { mode = EDIT; selectedProductIdx = -1; }
                        else if (i==4) mode = VIEW;
                        else if (i==5) mode = HISTORY;
                        else if (i==6) mode = SEARCH;
                        else if (i==7) mode = ALERTS;
                        else if (i==8) mode = STATS;
                        else if (i==9) {
                            saveData(products, transactions, totalRevenue, totalCostSold);
                            message = "✓ Datos guardados correctamente";
                            messageTimer = 3.0f;
                        }
                        else if (i==10) {
                            exportReport(products, transactions, totalRevenue, totalCostSold);
                            message = "✓ Reporte exportado correctamente";
                            messageTimer = 3.0f;
                        }
                    }
                }

                float mainX = leftPanelWidth + 20;
                if (mode == SELL || mode == RETURN || mode == SEARCH || mode == EDIT) {
                    int y0 = 350 - (int)listScroll;
                    int visibleCount = 0;
                    for (size_t i=0; i<products.size(); ++i){
                        if (!showInactive && !products[i].active) continue;
                        
                        float y = (float)y0 + visibleCount*100;
                        sf::FloatRect itemRect(mainX, y, winSize.x - mainX - 30, 90);
                        
                        if (itemRect.contains(mx,my)){
                            selectedProductIdx = (int)i;
                            message = "✓ Producto seleccionado: " + products[i].name;
                            messageTimer = 2.0f;
                            
                            if (mode == EDIT) {
                                in_name = products[i].name;
                                in_stock = to_string(products[i].stock);
                                in_cost = toFixed(products[i].cost);
                                in_price = toFixed(products[i].price);
                                in_category = products[i].category;
                                in_barcode = products[i].barcode;
                                in_minStock = to_string(products[i].minStock);
                            }
                        }
                        visibleCount++;
                    }
                }

                float formX = mainX;
                
                if (mode == ADD || mode == EDIT){
                    if (sf::FloatRect(formX+130, 90, 400, 30).contains(mx,my)) activeField = 1;
                    else if (sf::FloatRect(formX+130, 130, 150, 30).contains(mx,my)) activeField = 2;
                    else if (sf::FloatRect(formX+130, 170, 150, 30).contains(mx,my)) activeField = 3;
                    else if (sf::FloatRect(formX+130, 210, 150, 30).contains(mx,my)) activeField = 4;
                    else if (sf::FloatRect(formX+450, 90, 250, 30).contains(mx,my)) activeField = 5;
                    else if (sf::FloatRect(formX+450, 130, 200, 30).contains(mx,my)) activeField = 6;
                    else if (sf::FloatRect(formX+450, 170, 100, 30).contains(mx,my)) activeField = 7;
                    
                    else if (sf::FloatRect(formX, 260, 200, 50).contains(mx,my)){
                        if (mode == ADD) {
                            if (in_name.empty() || !isNumber(in_stock) || !isNumber(in_cost) || !isNumber(in_price)){
                                message = "✗ Error: Completa los campos obligatorios";
                                messageTimer = 3.0f;
                            } else {
                                int minStock = isNumber(in_minStock) ? stoi(in_minStock) : 5;
                                Product p{nextId++, in_name, stoi(in_stock), minStock, stof(in_cost), 
                                         stof(in_price), 0, in_category.empty() ? "General" : in_category,
                                         in_barcode, time(0), time(0), true};
                                products.push_back(p);
                                message = "✓ Producto agregado: " + p.name;
                                messageTimer = 3.0f;
                                in_name = in_stock = in_cost = in_price = in_category = in_barcode = in_minStock = "";
                                activeField = 0;
                                saveData(products, transactions, totalRevenue, totalCostSold);
                            }
                        } else if (mode == EDIT && selectedProductIdx >= 0) {
                            Product &p = products[selectedProductIdx];
                            if (!in_name.empty()) p.name = in_name;
                            if (isNumber(in_stock)) p.stock = stoi(in_stock);
                            if (isNumber(in_cost)) p.cost = stof(in_cost);
                            if (isNumber(in_price)) p.price = stof(in_price);
                            if (!in_category.empty()) p.category = in_category;
                            p.barcode = in_barcode;
                            if (isNumber(in_minStock)) p.minStock = stoi(in_minStock);
                            p.lastModified = time(0);
                            
                            message = "✓ Producto actualizado: " + p.name;
                            messageTimer = 3.0f;
                            saveData(products, transactions, totalRevenue, totalCostSold);
                            in_name = in_stock = in_cost = in_price = in_category = in_barcode = in_minStock = "";
                            selectedProductIdx = -1;
                            activeField = 0;
                        }
                    }
                    
                    if (mode == EDIT && selectedProductIdx >= 0) {
                        if (sf::FloatRect(formX + 220, 260, 200, 50).contains(mx,my)) {
                            products[selectedProductIdx].active = !products[selectedProductIdx].active;
                            message = products[selectedProductIdx].active ? "✓ Producto activado" : "✓ Producto desactivado";
                            messageTimer = 3.0f;
                            saveData(products, transactions, totalRevenue, totalCostSold);
                        }
                    }
                }

                if (mode == SELL || mode == RETURN){
                    if (sf::FloatRect(formX+130, 90, 150, 30).contains(mx,my)) activeField = 8;
                    else if (sf::FloatRect(formX, 140, 200, 50).contains(mx,my)){
                        if (selectedProductIdx<0) {
                            message="✗ Selecciona un producto primero";
                            messageTimer = 3.0f;
                        }
                        else if (!isNumber(in_quantity)) {
                            message="✗ Cantidad inválida";
                            messageTimer = 3.0f;
                        }
                        else {
                            int q = stoi(in_quantity);
                            Product &p = products[selectedProductIdx];
                            
                            if (mode == SELL) {
                                if (q<=0) {
                                    message="✗ Cantidad debe ser mayor que 0";
                                    messageTimer = 3.0f;
                                }
                                else if (q>p.stock) {
                                    message="✗ Stock insuficiente. Disponible: " + to_string(p.stock);
                                    messageTimer = 3.0f;
                                }
                                else {
                                    p.stock-=q; 
                                    p.totalSold+=q;
                                    float amount = p.price*q;
                                    totalRevenue+=amount;
                                    totalCostSold+=p.cost*q;
                                    
                                    Transaction t{p.id, p.name, q, amount, "VENTA", time(0), ""};
                                    transactions.push_back(t);
                                    
                                    message="✓ Venta exitosa: " + to_string(q) + "x " + p.name + 
                                           " | Total: $" + toFixed(amount);
                                    messageTimer = 5.0f;
                                    in_quantity=""; 
                                    activeField=0;
                                    selectedProductIdx=-1;
                                    saveData(products, transactions, totalRevenue, totalCostSold);
                                }
                            } else {
                                if (q<=0) {
                                    message="✗ Cantidad debe ser mayor que 0";
                                    messageTimer = 3.0f;
                                }
                                else if (q>p.totalSold) {
                                    message="✗ No puedes devolver más de lo vendido (" + to_string(p.totalSold) + ")";
                                    messageTimer = 3.0f;
                                }
                                else {
                                    p.stock+=q; 
                                    p.totalSold-=q;
                                    float amount = p.price*q;
                                    totalRevenue-=amount;
                                    totalCostSold-=p.cost*q;
                                    
                                    Transaction t{p.id, p.name, q, amount, "DEVOLUCION", time(0), ""};
                                    transactions.push_back(t);
                                    
                                    message="✓ Devolución registrada: " + to_string(q) + "x " + p.name;
                                    messageTimer = 5.0f;
                                    in_quantity=""; 
                                    activeField=0;
                                    selectedProductIdx=-1;
                                    saveData(products, transactions, totalRevenue, totalCostSold);
                                }
                            }
                        }
                    }
                }

                if (mode == SEARCH){
                    if (sf::FloatRect(formX+100, 90, 400, 30).contains(mx,my)) activeField = 9;
                }
            }

            if (event.type==sf::Event::TextEntered){
                uint32_t c = event.text.unicode;
                if (c>=32 && c!=127){
                    if (activeField==1) in_name.push_back((char)c);
                    else if (activeField==2) in_stock.push_back((char)c);
                    else if (activeField==3) in_cost.push_back((char)c);
                    else if (activeField==4) in_price.push_back((char)c);
                    else if (activeField==5) in_category.push_back((char)c);
                    else if (activeField==6) in_barcode.push_back((char)c);
                    else if (activeField==7) in_minStock.push_back((char)c);
                    else if (activeField==8) in_quantity.push_back((char)c);
                    else if (activeField==9) in_search.push_back((char)c);
                }
                if (c==8){
                    if (activeField==1 && !in_name.empty()) in_name.pop_back();
                    else if (activeField==2 && !in_stock.empty()) in_stock.pop_back();
                    else if (activeField==3 && !in_cost.empty()) in_cost.pop_back();
                    else if (activeField==4 && !in_price.empty()) in_price.pop_back();
                    else if (activeField==5 && !in_category.empty()) in_category.pop_back();
                    else if (activeField==6 && !in_barcode.empty()) in_barcode.pop_back();
                    else if (activeField==7 && !in_minStock.empty()) in_minStock.pop_back();
                    else if (activeField==8 && !in_quantity.empty()) in_quantity.pop_back();
                    else if (activeField==9 && !in_search.empty()) in_search.pop_back();
                }
            }
            
            if (event.type==sf::Event::KeyPressed){
                if (event.key.code==sf::Keyboard::Escape){
                    activeField = 0;
                    if (mode == EDIT || mode == SELL || mode == RETURN) {
                        selectedProductIdx = -1;
                        in_name = in_stock = in_cost = in_price = in_quantity = in_category = in_barcode = in_minStock = "";
                    }
                    message = "";
                }
                if (event.key.code==sf::Keyboard::Tab){
                    activeField = (activeField+1)%10;
                }
            }
        }

        sf::Vector2i mp = sf::Mouse::getPosition(window);
        float mx = (float)mp.x, my = (float)mp.y;
        float leftPanelWidth = 220;
        float mainX = leftPanelWidth + 20;
        
        if (mode == SELL || mode == RETURN || mode == SEARCH || mode == EDIT) {
            int y0 = 350 - (int)listScroll;
            int visibleCount = 0;
            for (size_t i=0; i<products.size(); ++i){
                if (!showInactive && !products[i].active) continue;
                float y = (float)y0 + visibleCount*100;
                sf::FloatRect itemRect(mainX, y, window.getSize().x - mainX - 30, 90);
                if (itemRect.contains(mx,my)){
                    hoveredProductIdx = (int)i;
                }
                visibleCount++;
            }
        }

        // RENDERIZADO
        window.clear(sf::Color(20,20,25));
        sf::Vector2u winSize = window.getSize();

        sf::RectangleShape sidePanel(sf::Vector2f(leftPanelWidth, winSize.y));
        sidePanel.setFillColor(sf::Color(30,30,35));
        window.draw(sidePanel);
        
        sf::RectangleShape sideBorder(sf::Vector2f(2, winSize.y));
        sideBorder.setPosition(leftPanelWidth, 0);
        sideBorder.setFillColor(sf::Color(60,60,70));
        window.draw(sideBorder);

        sf::RectangleShape headerBg(sf::Vector2f(winSize.x - leftPanelWidth, 60));
        headerBg.setPosition(leftPanelWidth, 0);
        headerBg.setFillColor(sf::Color(35,35,45));
        window.draw(headerBg);
        
        title.setPosition(leftPanelWidth + 20, 15);
        window.draw(title);

        for (size_t i=0; i<buttons.size(); ++i){
            buttons[i].rect = sf::FloatRect(10, 70+i*60, leftPanelWidth-20, 50);
            bool active = (i==0 && mode==ADD) || (i==1 && mode==SELL) || 
                         (i==2 && mode==RETURN) || (i==3 && mode==EDIT) ||
                         (i==4 && mode==VIEW) || (i==5 && mode==HISTORY) ||
                         (i==6 && mode==SEARCH) || (i==7 && mode==ALERTS) ||
                         (i==8 && mode==STATS);
            drawButton(window, buttons[i], active);
        }

        mainX = leftPanelWidth + 20;
        float mainY = 70;

        if (!message.empty() && messageTimer > 0) {
            float msgWidth = 600;
            float msgHeight = 50;
            float msgX = (winSize.x - msgWidth) / 2;
            float msgY = winSize.y - 100;
            
            sf::RectangleShape msgBg(sf::Vector2f(msgWidth, msgHeight));
            msgBg.setPosition(msgX, msgY);
            
            if (message[0] == '✓') msgBg.setFillColor(sf::Color(40,100,40,230));
            else if (message[0] == '✗') msgBg.setFillColor(sf::Color(140,40,40,230));
            else msgBg.setFillColor(sf::Color(60,60,80,230));
            
            msgBg.setOutlineThickness(2);
            msgBg.setOutlineColor(sf::Color::White);
            window.draw(msgBg);
            
            drawLabel(message, msgX + 20, msgY + 15, 16, sf::Color::White, true);
        }

        if (mode == ADD || mode == EDIT){
            drawLabel(mode==ADD ? "➕ AGREGAR NUEVO PRODUCTO" : "✎ EDITAR PRODUCTO", 
                     mainX, mainY, 22, sf::Color(100,200,255), true);
            
            drawLabel("Nombre *", mainX, mainY+50, 14);
            drawInputField(mainX+130, mainY+50, 400, 30, in_name, "Nombre del producto", activeField==1);
            
            drawLabel("Stock *", mainX, mainY+90, 14);
            drawInputField(mainX+130, mainY+90, 150, 30, in_stock, "0", activeField==2);
            
            drawLabel("Costo *", mainX, mainY+130, 14);
            drawInputField(mainX+130, mainY+130, 150, 30, in_cost, "0.00", activeField==3);
            
            drawLabel("Precio Venta *", mainX, mainY+170, 14);
            drawInputField(mainX+130, mainY+170, 150, 30, in_price, "0.00", activeField==4);
            
            drawLabel("Categoría", mainX+320, mainY+50, 14);
            drawInputField(mainX+450, mainY+50, 250, 30, in_category, "Ej: Electrónica", activeField==5);
            
            drawLabel("Código Barras", mainX+320, mainY+90, 14);
            drawInputField(mainX+450, mainY+90, 200, 30, in_barcode, "Opcional", activeField==6);
            
            drawLabel("Stock Mínimo", mainX+320, mainY+130, 14);
            drawInputField(mainX+450, mainY+130, 100, 30, in_minStock, "5", activeField==7);
            
            sf::RectangleShape saveBtn(sf::Vector2f(200, 50));
            saveBtn.setPosition(mainX, mainY+220);
            saveBtn.setFillColor(sf::Color(70,130,180));
            saveBtn.setOutlineThickness(3);
            saveBtn.setOutlineColor(sf::Color::White);
            window.draw(saveBtn);
            drawLabel(mode==ADD ? "💾 AGREGAR" : "💾 ACTUALIZAR", mainX+40, mainY+233, 16, sf::Color::White, true);
            
            if (mode == EDIT && selectedProductIdx >= 0 && selectedProductIdx < (int)products.size()) {
                sf::RectangleShape toggleBtn(sf::Vector2f(200, 50));
                toggleBtn.setPosition(mainX + 220, mainY+220);
                toggleBtn.setFillColor(products[selectedProductIdx].active ? sf::Color(200,50,50) : sf::Color(50,200,50));
                toggleBtn.setOutlineThickness(3);
                toggleBtn.setOutlineColor(sf::Color::White);
                window.draw(toggleBtn);
                drawLabel(products[selectedProductIdx].active ? "❌ DESACTIVAR" : "✓ ACTIVAR", 
                         mainX + 250, mainY+233, 16, sf::Color::White, true);
            }
            
            drawLabel("* Campos obligatorios | ESC para cancelar", mainX, mainY+290, 12, sf::Color(150,150,150));
        }
        
        else if (mode == SELL || mode == RETURN){
            drawLabel(mode==SELL ? "💰 VENDER PRODUCTO" : "↩ DEVOLVER PRODUCTO", 
                     mainX, mainY, 22, sf::Color(100,200,255), true);
            
            drawLabel("Paso 1: Selecciona un producto de la lista inferior", mainX, mainY+35, 14, sf::Color(200,200,200));
            drawLabel("Paso 2: Ingresa la cantidad y confirma", mainX, mainY+55, 14, sf::Color(200,200,200));
            
            drawLabel("Cantidad:", mainX, mainY+90, 14);
            drawInputField(mainX+130, mainY+90, 150, 30, in_quantity, "0", activeField==8);
            
            sf::RectangleShape actionBtn(sf::Vector2f(200, 50));
            actionBtn.setPosition(mainX, mainY+140);
            actionBtn.setFillColor(mode==SELL ? sf::Color(60,180,75) : sf::Color(255,140,0));
            actionBtn.setOutlineThickness(3);
            actionBtn.setOutlineColor(sf::Color::White);
            window.draw(actionBtn);
            drawLabel(mode==SELL ? "💵 VENDER" : "↩ DEVOLVER", mainX+50, mainY+153, 16, sf::Color::White, true);
            
            if (selectedProductIdx >= 0 && selectedProductIdx < (int)products.size()) {
                const Product &p = products[selectedProductIdx];
                sf::RectangleShape infoBg(sf::Vector2f(winSize.x - mainX - 30, 100));
                infoBg.setPosition(mainX, mainY+210);
                infoBg.setFillColor(sf::Color(40,60,90));
                infoBg.setOutlineThickness(2);
                infoBg.setOutlineColor(sf::Color(100,150,200));
                window.draw(infoBg);
                
                drawLabel("📦 PRODUCTO SELECCIONADO", mainX+10, mainY+220, 14, sf::Color::Yellow, true);
                drawLabel(p.name, mainX+10, mainY+245, 18, sf::Color::White, true);
                drawLabel("Stock disponible: " + to_string(p.stock), mainX+10, mainY+275, 14, sf::Color(150,255,150));
                drawLabel("Precio: $" + toFixed(p.price), mainX+250, mainY+275, 14, sf::Color(100,255,100));
                if (mode == RETURN) {
                    drawLabel("Vendidos: " + to_string(p.totalSold), mainX+400, mainY+275, 14, sf::Color(200,200,255));
                }
            }
            
            drawLabel("📋 LISTA DE PRODUCTOS", mainX, mainY+330, 16, sf::Color(150,200,255), true);
            int y0 = mainY+360 - (int)listScroll;
            int visibleCount = 0;
            
            for (size_t i=0; i<products.size(); ++i){
                if (!showInactive && !products[i].active) continue;
                
                float y = (float)y0 + visibleCount*100;
                if (y > mainY+340 && y < winSize.y - 50) {
                    drawProductCard(products[i], mainX, y, winSize.x - mainX - 30, 
                                   (int)i == selectedProductIdx, (int)i == hoveredProductIdx);
                }
                visibleCount++;
            }
        }
        
        else if (mode == VIEW){
            drawLabel("📊 RESUMEN FINANCIERO", mainX, mainY, 22, sf::Color(100,200,255), true);
            
            float margin = totalRevenue - totalCostSold;
            float marginPercent = totalRevenue > 0 ? (margin / totalRevenue) * 100 : 0;
            
            auto drawStatCard = [&](float x, float y, string title, string value, sf::Color color){
                sf::RectangleShape card(sf::Vector2f(280, 100));
                card.setPosition(x, y);
                card.setFillColor(sf::Color(40,40,50));
                card.setOutlineThickness(3);
                card.setOutlineColor(color);
                window.draw(card);
                
                drawLabel(title, x+15, y+15, 14, sf::Color(180,180,180));
                drawLabel(value, x+15, y+45, 24, color, true);
            };
            
            drawStatCard(mainX, mainY+40, "💰 Ingresos Totales", "$" + toFixed(totalRevenue), sf::Color(100,255,100));
            drawStatCard(mainX+300, mainY+40, "💸 Costos Totales", "$" + toFixed(totalCostSold), sf::Color(255,150,100));
            drawStatCard(mainX+600, mainY+40, "📈 Ganancia Neta", "$" + toFixed(margin), 
                        margin >= 0 ? sf::Color(100,255,100) : sf::Color(255,100,100));
            
            drawLabel("Margen de ganancia: " + toFixed(marginPercent, 1) + "%", mainX, mainY+160, 18, sf::Color::Yellow);
            
            int totalStock = 0, totalProducts = products.size(), activeProducts = 0;
            for (const auto &p : products) {
                totalStock += p.stock;
                if (p.active) activeProducts++;
            }
            
            drawLabel("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━", mainX, mainY+200, 14, sf::Color(60,60,80));
            drawLabel("📦 Total productos: " + to_string(totalProducts) + " (" + to_string(activeProducts) + " activos)", 
                     mainX, mainY+230, 16);
            drawLabel("📊 Unidades en stock: " + to_string(totalStock), mainX, mainY+265, 16);
            drawLabel("🔄 Total transacciones: " + to_string(transactions.size()), mainX, mainY+300, 16);
            
            drawLabel("🏆 TOP 5 PRODUCTOS MÁS VENDIDOS", mainX, mainY+350, 18, sf::Color(255,215,0), true);
            
            vector<Product> sorted = products;
            sort(sorted.begin(), sorted.end(), [](const Product &a, const Product &b){
                return a.totalSold > b.totalSold;
            });
            
            int yTop = mainY + 390;
            for (int i = 0; i < min(5, (int)sorted.size()); ++i) {
                sf::RectangleShape topCard(sf::Vector2f(winSize.x - mainX - 30, 45));
                topCard.setPosition(mainX, yTop + i*55);
                topCard.setFillColor(sf::Color(50,50,70));
                topCard.setOutlineThickness(1);
                topCard.setOutlineColor(sf::Color(80,80,100));
                window.draw(topCard);
                
                drawLabel(to_string(i+1) + ".", mainX+10, yTop + i*55 + 12, 18, sf::Color::Yellow, true);
                drawLabel(sorted[i].name, mainX+40, yTop + i*55 + 12, 16, sf::Color::White);
                drawLabel(to_string(sorted[i].totalSold) + " unidades", mainX+350, yTop + i*55 + 12, 14, sf::Color(150,255,150));
                float profit = (sorted[i].price - sorted[i].cost) * sorted[i].totalSold;
                drawLabel("Ganancia: $" + toFixed(profit), mainX+500, yTop + i*55 + 12, 14, sf::Color(100,255,100));
            }
        }
        
        else if (mode == HISTORY){
            drawLabel("⌚ HISTORIAL DE TRANSACCIONES", mainX, mainY, 22, sf::Color(100,200,255), true);
            
            int y0 = mainY+50 - (int)historyScroll;
            
            if (transactions.empty()){
                drawLabel("No hay transacciones registradas", mainX, mainY+50, 16, sf::Color(150,150,150));
            } else {
                for (int i = transactions.size()-1; i >= 0; --i){
                    const auto &t = transactions[i];
                    float y = (float)y0 + (transactions.size()-1-i)*80;
                    
                    if (y > mainY+30 && y < winSize.y - 50) {
                        sf::RectangleShape item(sf::Vector2f(winSize.x-mainX-30, 75));
                        item.setPosition(mainX, y);
                        
                        sf::Color bgColor;
                        if (t.type=="VENTA") bgColor = sf::Color(40,70,40);
                        else if (t.type=="DEVOLUCION") bgColor = sf::Color(70,50,40);
                        else bgColor = sf::Color(50,50,70);
                        
                        item.setFillColor(bgColor);
                        item.setOutlineThickness(1);
                        item.setOutlineColor(sf::Color(30,30,30));
                        window.draw(item);
                        
                        char buf[80];
                        strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M", localtime(&t.timestamp));
                        
                        drawLabel(string(buf), mainX+10, y+8, 12, sf::Color(180,180,180));
                        
                        sf::Color typeColor;
                        if (t.type=="VENTA") typeColor = sf::Color(150,255,150);
                        else if (t.type=="DEVOLUCION") typeColor = sf::Color(255,200,150);
                        else typeColor = sf::Color(200,200,255);
                        
                        drawLabel(t.type, mainX+10, y+28, 16, typeColor, true);
                        drawLabel(t.productName, mainX+10, y+50, 14, sf::Color::White);
                        
                        drawLabel("Cantidad: " + to_string(t.quantity), mainX+350, y+28, 14);
                        drawLabel("Total: $" + toFixed(t.amount), mainX+350, y+50, 16, sf::Color::Yellow, true);
                        
                        if (!t.notes.empty()) {
                            drawLabel("📝 " + t.notes, mainX+550, y+28, 12, sf::Color(150,150,200));
                        }
                    }
                }
            }
        }
        
        else if (mode == SEARCH){
            drawLabel("🔍 BUSCAR PRODUCTO", mainX, mainY, 22, sf::Color(100,200,255), true);
            
            drawLabel("Buscar:", mainX, mainY+50, 14);
            drawInputField(mainX+100, mainY+50, 400, 30, in_search, "Nombre, categoría o código de barras", activeField==9);
            
            drawLabel("RESULTADOS DE BÚSQUEDA", mainX, mainY+100, 16, sf::Color(150,200,255), true);
            
            int y0 = mainY+140 - (int)listScroll;
            int found = 0;
            
            string searchLower = toLowerCase(in_search);
            
            for (size_t i=0; i<products.size(); ++i){
                if (!showInactive && !products[i].active) continue;
                
                bool matches = in_search.empty() || 
                    toLowerCase(products[i].name).find(searchLower) != string::npos ||
                    toLowerCase(products[i].category).find(searchLower) != string::npos ||
                    toLowerCase(products[i].barcode).find(searchLower) != string::npos;
                
                if (matches){
                    float y = (float)y0 + found*100;
                    
                    if (y > mainY+120 && y < winSize.y - 50) {
                        drawProductCard(products[i], mainX, y, winSize.x - mainX - 30, 
                                       (int)i == selectedProductIdx, (int)i == hoveredProductIdx);
                    }
                    found++;
                }
            }
            
            if (found == 0 && !in_search.empty()){
                drawLabel("❌ No se encontraron productos", mainX, mainY+140, 16, sf::Color(200,100,100));
            } else if (in_search.empty()) {
                drawLabel("💡 Ingresa un término de búsqueda", mainX, mainY+140, 14, sf::Color(150,150,150));
            } else {
                drawLabel("✓ " + to_string(found) + " producto(s) encontrado(s)", mainX+520, mainY+50, 12, sf::Color(100,255,100));
            }
        }
        
        else if (mode == ALERTS){
            drawLabel("⚠ ALERTAS DEL SISTEMA", mainX, mainY, 22, sf::Color(255,100,100), true);
            
            vector<int> lowStockProducts;
            vector<int> outOfStockProducts;
            
            for (size_t i=0; i<products.size(); ++i){
                if (!products[i].active) continue;
                if (products[i].stock == 0) outOfStockProducts.push_back(i);
                else if (products[i].stock <= products[i].minStock && products[i].minStock > 0) lowStockProducts.push_back(i);
            }
            
            int yPos = mainY + 50;
            
            if (!outOfStockProducts.empty()) {
                drawLabel("🔴 PRODUCTOS SIN STOCK (" + to_string(outOfStockProducts.size()) + ")", 
                         mainX, yPos, 18, sf::Color(255,50,50), true);
                yPos += 40;
                
                for (int idx : outOfStockProducts) {
                    sf::RectangleShape alert(sf::Vector2f(winSize.x - mainX - 30, 60));
                    alert.setPosition(mainX, yPos);
                    alert.setFillColor(sf::Color(80,30,30));
                    alert.setOutlineThickness(2);
                    alert.setOutlineColor(sf::Color(255,0,0));
                    window.draw(alert);
                    
                    drawLabel(products[idx].name, mainX+10, yPos+10, 16, sf::Color::White, true);
                    drawLabel("Categoría: " + products[idx].category + " | Vendidos: " + to_string(products[idx].totalSold),
                             mainX+10, yPos+35, 12, sf::Color(200,200,200));
                    
                    yPos += 70;
                }
            }
            
            if (!lowStockProducts.empty()) {
                drawLabel("🟡 STOCK BAJO (" + to_string(lowStockProducts.size()) + ")", 
                         mainX, yPos, 18, sf::Color(255,200,0), true);
                yPos += 40;
                
                for (int idx : lowStockProducts) {
                    sf::RectangleShape alert(sf::Vector2f(winSize.x - mainX - 30, 60));
                    alert.setPosition(mainX, yPos);
                    alert.setFillColor(sf::Color(70,60,30));
                    alert.setOutlineThickness(2);
                    alert.setOutlineColor(sf::Color(255,200,0));
                    window.draw(alert);
                    
                    drawLabel(products[idx].name, mainX+10, yPos+10, 16, sf::Color::White, true);
                    drawLabel("Stock actual: " + to_string(products[idx].stock) + 
                             " | Mínimo: " + to_string(products[idx].minStock) + 
                             " | Categoría: " + products[idx].category,
                             mainX+10, yPos+35, 12, sf::Color(200,200,200));
                    
                    yPos += 70;
                }
            }
            
            if (lowStockProducts.empty() && outOfStockProducts.empty()) {
                drawLabel("✓ No hay alertas. Todos los productos tienen stock suficiente.", 
                         mainX, mainY+50, 16, sf::Color(100,255,100));
            }
        }
        
        else if (mode == STATS){
            drawLabel("📊 ESTADÍSTICAS AVANZADAS", mainX, mainY, 22, sf::Color(100,200,255), true);
            
            int totalProducts = products.size();
            int activeProducts = 0;
            int totalStock = 0;
            float totalInventoryValue = 0;
            float totalInventoryCost = 0;
            
            map<string, int> categoryCount;
            map<string, float> categoryRevenue;
            
            for (const auto &p : products) {
                if (p.active) {
                    activeProducts++;
                    totalStock += p.stock;
                    totalInventoryValue += p.price * p.stock;
                    totalInventoryCost += p.cost * p.stock;
                    categoryCount[p.category]++;
                    categoryRevenue[p.category] += p.price * p.totalSold;
                }
            }
            
            float inventoryMargin = totalInventoryValue - totalInventoryCost;
            float inventoryMarginPercent = totalInventoryValue > 0 ? (inventoryMargin / totalInventoryValue) * 100 : 0;
            float avgPrice = totalStock > 0 ? totalInventoryValue / totalStock : 0;
            float avgCost = totalStock > 0 ? totalInventoryCost / totalStock : 0;
            float avgMargin = avgPrice - avgCost;
            float avgMarginPercent = avgPrice > 0 ? (avgMargin / avgPrice) * 100 : 0;
            
            int yPos = mainY + 40;
            auto drawStat = [&](string label, string value){
                drawLabel(label + ": " + value, mainX, yPos, 16);
                yPos += 30;
            };
            
            drawStat("📦 Total productos", to_string(totalProducts) + " (" + to_string(activeProducts) + " activos)");
            drawStat("📊 Unidades en stock", to_string(totalStock));
            drawStat("💰 Valor total del inventario", "$" + toFixed(totalInventoryValue));
            drawStat("💸 Costo total del inventario", "$" + toFixed(totalInventoryCost));
            drawStat("📈 Margen de inventario", "$" + toFixed(inventoryMargin));
            drawStat("📊 % Margen de inventario", toFixed(inventoryMarginPercent, 1) + "%");
            drawStat("💵 Precio promedio", "$" + toFixed(avgPrice));
            drawStat("💵 Costo promedio", "$" + toFixed(avgCost));
            drawStat("📈 Margen promedio", "$" + toFixed(avgMargin));
            drawStat("📊 % Margen promedio", toFixed(avgMarginPercent, 1) + "%");
            
            yPos += 20;
            drawLabel("🏷 DISTRIBUCIÓN POR CATEGORÍAS", mainX, yPos, 18, sf::Color(150,200,255), true);
            yPos += 35;
            
            if (categoryCount.empty()) {
                drawLabel("No hay categorías definidas.", mainX, yPos, 14, sf::Color(150,150,150));
            } else {
                for (const auto &[cat, count] : categoryCount) {
                    float revenue = categoryRevenue[cat];
                    drawLabel("• " + cat + ": " + to_string(count) + " productos | Ingresos: $" + toFixed(revenue), 
                             mainX, yPos, 14);
                    yPos += 30;
                }
            }
        }
        
        window.display();
    }
    
    saveData(products, transactions, totalRevenue, totalCostSold);
    return 0;
}