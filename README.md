# 🎮 C++ Hazineden Kaçış Oyunu

Bu proje, Nesne Yönelimli Programlama (OOP) prensipleri kullanılarak geliştirilmiş konsol tabanlı bir macera oyunudur. Oyuncu, sınırlı canı ile düşmanlardan kaçarak harita üzerindeki gizli hazineyi bulmaya çalışır.

---

## ✨ Özellikler

* **OOP Mimarisi:** Kalıtım (Inheritance), Polimorfizm (Polymorphism) ve Kapsülleme (Encapsulation) prensipleri uygulanmıştır.
* **Dinamik Harita:** 5x5 boyutunda bir ızgara üzerinde anlık konum takibi yapılır.
* **Rastgele Nesneler:** Hazine, bonus iksirler ve düşmanlar her oyunda farklı konumlara yerleştirilir.
* **Hayatta Kalma Mekaniği:** Her adımda can azalır; iksirler can artırırken düşmanlar can düşürür.

---

## 🛠 Teknik Detaylar

Proje aşağıdaki sınıfsal hiyerarşiyi kullanır:



* **GameObject (Soyut Sınıf):** Tüm oyun nesnelerinin (x, y) konumlarını ve temel aksiyonlarını tanımlar.
* **Player:** Hareket kontrolü ve sağlık yönetimini sağlar.
* **Bonus / Enemy / Treasure:** `GameObject` sınıfından türetilen ve farklı etkileşimler sunan sınıflardır.

---

## 📋 Nasıl Oynanır?

### Kontroller
* `W`: Yukarı
* `A`: Sol
* `S`: Aşağı
* `D`: Sağ

### Kurallar
1.  **Hazineyi Bul:** Oyunu kazanmak için gizli hazine hücresine ulaşın.
2.  **Canını Koru:** Canınız 0'a düşerse oyun biter. Unutmayın, her hareket 5 can götürür!
3.  **İksirleri Topla:** Mavi iksirler size +20 can sağlar.
4.  **Düşmanlardan Kaç:** Kırmızı düşman hücreleri canınızı -20 azaltır.

---

## 🚀 Derleme ve Çalıştırma

1.  Herhangi bir C++ derleyicisi (G++, Clang, Visual Studio) ile dosyayı derleyin:
    ```bash
    g++ oyun.cpp -o hazine_avi
    ```
2.  Uygulamayı çalıştırın:
    ```bash
    ./hazine_avi
    ```
