#include <iostream>
#include <cstdlib> // Rastgele say� �retimi i�in
#include <ctime>

using namespace std;

class GameObject {
protected:
    int x, y; // Konum bilgisi (enkaps�lasyon: protected eri�im seviyesi ile kaps�llendi)
public:
    GameObject() : x(0), y(0) {}
    virtual void action() = 0; // Polimorfizm i�in saf sanal fonksiyon
    int getX() { return x; }
    int getY() { return y; }
    void setPosition(int newX, int newY) {
        x = newX;
        y = newY;
    }
};

class Player : public GameObject {
private:
    string name; // Oyuncunun ad� (enkaps�lasyon: private eri�im seviyesi ile korunuyor)
    int health;  // Oyuncunun can durumu
public:
    Player(string playerName) {
        name = playerName;
        health = 100; // Ba�lang�� can� 100
        x = 0;
        y = 0;
    }

    // Oyuncunun haritada hareket etmesini sa�lar
    void move(char direction) {
        if (direction == 'W' || direction == 'w') {
            if (y > 0) y--;
            else cout << "Sinirdasiniz!\n";
        } else if (direction == 'S' || direction == 's') {
            if (y < 4) y++;
            else cout << "Sinirdasiniz!\n";
        } else if (direction == 'A' || direction == 'a') {
            if (x > 0) x--;
            else cout << "Sinirdasiniz!\n";
        } else if (direction == 'D' || direction == 'd') {
            if (x < 4) x++;
            else cout << "Sinirdasiniz!\n";
        } else {
            cout << "Gecersiz hareket!\n";
        }
    }

    // Oyuncunun can�n� g�nceller
    void updateHealth(int amount) {
        health += amount;
        if (health > 100) health = 100; // Maksimum can 100
        if (health < 0) health = 0;     // Minimum can 0
    }

    int getHealth() { return health; }

    // Oyuncunun durumunu ekrana yazd�r�r
    void displayStatus() {
        cout << name << ", Can: " << health << ", Konum: (" << x << ", " << y << ")\n";
    }

    void action() override {} // Polimorfizm gere�i action metodu tan�mland�

};

class Bonus : public GameObject {
public:
    Bonus() {}
    void action() override {
        cout << "Bir iksir buldunuz. Caniniz +20 artti! ??\n";
    }
};
class Treasure : public GameObject {
public:
    Treasure() {}
    void action() override {
        cout << "Tebrikler! Hazineyi buldunuz ve oyunu kazandiniz! ??\n";
    }
};

// Enemy s�n�f�: Oyuncunun can�n� azaltan d��man nesnesi
// GameObject s�n�f�ndan t�retilmi�tir (kal�t�m).
class Enemy : public GameObject {
public:
    Enemy() {}
    void action() override {
        cout << "Bir dusmanla karsilastiniz! Caniniz -20 azaldi! ??\n";
    }
};


void drawMap(int playerX, int playerY) {
    cout << "\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == playerY && j == playerX)
                cout << " P "; // Oyuncu
            else
                cout << " . "; // Bo� alan
        }
        cout << endl;
    }
    cout << "\n";
}
int main(){

    return 0;
}
