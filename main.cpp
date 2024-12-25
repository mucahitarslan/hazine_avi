#include <iostream>
#include <cstdlib> // Rastgele sayý üretimi için
#include <ctime>

using namespace std;

class GameObject {
protected:
    int x, y; // Konum bilgisi (enkapsülasyon: protected eriþim seviyesi ile kapsüllendi)
public:
    GameObject() : x(0), y(0) {}
    virtual void action() = 0; // Polimorfizm için saf sanal fonksiyon
    int getX() { return x; }
    int getY() { return y; }
    void setPosition(int newX, int newY) {
        x = newX;
        y = newY;
    }
};

class Player : public GameObject {
private:
    string name; // Oyuncunun adý (enkapsülasyon: private eriþim seviyesi ile korunuyor)
    int health;  // Oyuncunun can durumu
public:
    Player(string playerName) {
        name = playerName;
        health = 100; // Baþlangýç caný 100
        x = 0;
        y = 0;
    }

    // Oyuncunun haritada hareket etmesini saðlar
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

    // Oyuncunun canýný günceller
    void updateHealth(int amount) {
        health += amount;
        if (health > 100) health = 100; // Maksimum can 100
        if (health < 0) health = 0;     // Minimum can 0
    }

    int getHealth() { return health; }

    // Oyuncunun durumunu ekrana yazdýrýr
    void displayStatus() {
        cout << name << ", Can: " << health << ", Konum: (" << x << ", " << y << ")\n";
    }

    void action() override {} // Polimorfizm gereði action metodu tanýmlandý

};

class Treasure : public GameObject {
public:

};

// Enemy sýnýfý: Oyuncunun canýný azaltan düþman nesnesi
// GameObject sýnýfýndan türetilmiþtir (kalýtým).
class Enemy : public GameObject {
public:

};


void drawMap(int playerX, int playerY) {

}

int main(){

    return 0;
}
