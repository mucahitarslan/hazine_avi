#include <iostream>
#include <cstdlib> // Rastgele sayı üretimi için
#include <ctime>
using namespace std;

// GameObject sınıfı: Kalıtım için temel sınıf
// Soyut bir sınıf olarak tanımlanmıştır. Ortak özellikler ve davranışlar türetilmiş sınıflara aktarılır.
class GameObject {
protected:
    int x, y; // Konum bilgisi (enkapsülasyon: protected erişim seviyesi ile kapsüllendi)
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

// Player sınıfı: Oyuncu karakteri için bir sınıf
// GameObject sınıfından türetilmiştir (kalıtım).
class Player : public GameObject {
private:
    string name; // Oyuncunun adı (enkapsülasyon: private erişim seviyesi ile korunuyor)
    int health;  // Oyuncunun can durumu
public:
    Player(string playerName) {
        name = playerName;
        health = 100; // Başlangıç canı 100
        x = 0;
        y = 0;
    }

    // Oyuncunun haritada hareket etmesini sağlar
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

    // Oyuncunun canını günceller
    void updateHealth(int amount) {
        health += amount;
        if (health > 100) health = 100; // Maksimum can 100
        if (health < 0) health = 0;     // Minimum can 0
    }

    int getHealth() { return health; }

    // Oyuncunun durumunu ekrana yazdırır
    void displayStatus() {
        cout << name << ", Can: " << health << ", Konum: (" << x << ", " << y << ")\n";
    }

    void action() override {} // Polimorfizm gereği action metodu tanımlandı
};

// Bonus sınıfı: Oyuncunun canını artıran bonus nesnesi
// GameObject sınıfından türetilmiştir (kalıtım).
class Bonus : public GameObject {
public:
    Bonus() {}
    void action() override {
        cout << "Bir iksir buldunuz. Caniniz +20 artti! ??\n";
    }
};

// Treasure sınıfı: Oyunun kazanılmasını sağlayan hazine nesnesi
// GameObject sınıfından türetilmiştir (kalıtım).
class Treasure : public GameObject {
public:
    Treasure() {}
    void action() override {
        cout << "Tebrikler! Hazineyi buldunuz ve oyunu kazandiniz! ??\n";
    }
};

// Enemy sınıfı: Oyuncunun canını azaltan düşman nesnesi
// GameObject sınıfından türetilmiştir (kalıtım).
class Enemy : public GameObject {
public:
    Enemy() {}
    void action() override {
        cout << "Bir dusmanla karsilastiniz! Caniniz -20 azaldi! ??\n";
    }
};

// Harita çizim fonksiyonu
// Oyuncunun ve diğer nesnelerin pozisyonlarını harita üzerinde gösterir
void drawMap(int playerX, int playerY) {
    cout << "\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == playerY && j == playerX)
                cout << " P "; // Oyuncu
            else
                cout << " . "; // Boş alan
        }
        cout << endl;
    }
    cout << "\n";
}

int main() {
    srand(time(0)); // Rastgele sayı üretimi için başlangıç
    string playerName;
    cout << "Oyuncu adinizi girin: ";
    cin >> playerName;

    Player player(playerName); // Oyuncu nesnesi oluşturulur

    // Bonus, hazine ve düşman nesnelerini oluşturma
    Bonus bonus;
    Treasure treasure;
    Enemy enemy;

    // Nesnelerin konumlarını rastgele belirleme
    treasure.setPosition(rand() % 5, rand() % 5);

    do {
        bonus.setPosition(rand() % 5, rand() % 5);
    } while (bonus.getX() == treasure.getX() && bonus.getY() == treasure.getY());

    do {
        enemy.setPosition(rand() % 5, rand() % 5);
    } while ((enemy.getX() == treasure.getX() && enemy.getY() == treasure.getY()) ||
             (enemy.getX() == bonus.getX() && enemy.getY() == bonus.getY()));

    cout << "\nHazineyi bulmak icin W/A/S/D tuslarini kullanarak hareket edin!\n";

    while (true) {
        drawMap(player.getX(), player.getY()); // Harita çizimi
        player.displayStatus();

        // Oyuncunun hareketi
        char moveDirection;
        cout << "Hareketinizi girin (W/A/S/D): ";
        cin >> moveDirection;

        player.move(moveDirection);
        player.updateHealth(-5); // Her adımda can 5 azalır

        // Oyuncu bonusu bulursa
        if (player.getX() == bonus.getX() && player.getY() == bonus.getY()) {
            bonus.action();
            player.updateHealth(20);
            bonus.setPosition(-1, -1); // Bonus artık yok edilir
        }

        // Oyuncu hazinenin yerini bulursa oyun biter
        if (player.getX() == treasure.getX() && player.getY() == treasure.getY()) {
            treasure.action();
            break;
        }

        // Oyuncu düşmanla karşılaşırsa
        if (player.getX() == enemy.getX() && player.getY() == enemy.getY()) {
            enemy.action();
            player.updateHealth(-20);
        }

        // Oyuncunun canı biterse oyun kaybedilir
        if (player.getHealth() <= 0) {
            cout << "\nUzgunum, caniniz tukendi. Oyunu kaybettiniz. ??\n";
            break;
        }
    }

    cout << "Oyun bitti. Tekrar gorusmek uzere!\n";
    return 0;
}
