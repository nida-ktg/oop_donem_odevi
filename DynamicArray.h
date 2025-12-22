#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
//bu yapı, bu header dosyasının birden fazla kez include edilmesini engeller. Eğer engellenmezse aynı sınıf birden fazla kez tanımlanabilir ve derleme hatası oluşabilir.

#include <iostream> //cout, ostream gibi giriş-çıkış işlemleri için gerekli

using namespace std; //std::cout yerine direkt cout yazabilmek için


class DynamicArray {

private: //Private seçilme sebebi, dışarıdan doğrudan erişilmemesi için

    int* data;  //Dinamik olarak oluşturulacak olan asıl dizi, new int[capacity] ile bellekte yer ayıracağız, tüm elemanlar bu pointer üzerinden tutulacak

    int size;   //Dizide şu anda kaç eleman var? (push ile artar, pop ile azalır)

    int capacity;   //Dizinin toplam kapasitesi, yani bellekte kaç elemanlık yer ayrılmış

protected:
    void resize();      //Kapasiteyi iki katına çıkarır

public:
    //CONSTRUCTOR ve DESTRUCTOR 

    DynamicArray(); //Varsayılan constructor - Nesne oluşturulduğu anda otomatik çalışır

    DynamicArray(int capacity); //Parametreli constructor - Kullanıcı başlangıç kapasitesini kendisi belirleyebilir

    DynamicArray(const DynamicArray& other); //Copy constructor - Bir nesneden yeni bir nesne oluşturulurken çalışır (deep copy yapılmalıdır)

    ~DynamicArray(); //Destructor - Nesne yok olurken otomatik çalışır (Memory leak olmaması için yapılması zorunlu)


    //TEMEL FONKSİYONLAR

    virtual void push(int value); //Dizinin sonuna eleman ekler

    void pop(); //Dizinin son elemanını siler

    int get(int index) const; //Verilen indexteki elemanı döndürür (const çünkü dizinin içeriğini değiştirmez!)

    void set(int index, int value); //Verilen index'eki elemanı yeni bir değerle değiştirir

    int getSize() const; //Dizide şu anda kaç eleman olduğunu döndürür (const çünkü sadece okuma yapar)

    int getCapacity() const; //Dizinin mevcut kapasitesini döndürür

    bool isEmpty() const; //Dizi boş mu diye kontrol eder (size == 0 ise true döner)

    void clear(); //Dizideki tüm elemanları siler

    virtual void print() const; //Diziyi ekrana yazdırır

    //OPERATOR OVERLOADING 

    int& operator[](int index); //Köşeli parantez operatörü

    DynamicArray operator+(const DynamicArray& other) const; //İki DynamicArray nesnesini birleştirir - Yeni bir DynamicArray döndürür

    DynamicArray& operator=(const DynamicArray& other); //Atama operatörü

    bool operator==(const DynamicArray& other) const; //İki dizinin eşit olup olmadığını kontrol eder

    bool operator!=(const DynamicArray& other) const; //Eşit değil mi kontrolü


    //OUTPUT OPERATOR
    
    friend ostream& operator<<(ostream& os, const DynamicArray& other); //cout << arr; yazabilmek için (friend çünkü; data, size gibi private üyelere erişmesi gerekiyor)

};

#endif //Include guard bitişi
