#include "DynamicArray.h" //yazdığımız header dosyasını dahil ettik

#include <iostream>
using namespace std; //cout kullanacağımız için gerekli



DynamicArray::DynamicArray() : capacity(2), size(0) { //varsayılan constructor

    //capacity(2) çünkü küçük başlatılır, ihtiyaç olunca büyütülür (verimli bellek kullanımı)
    
    //size(0) çünkü şu an dizide eleman yok

    data = new int[capacity]; 
    //Bellekte capacity kadar int yer ayırıyoruz, data artık dizinin başlangıç adresini tutuyor

}



DynamicArray::DynamicArray(int cap) : capacity(cap), size(0) { //parametreli constructor
    //Kullanıcı başlangıç kapasitesini kendi belirler 
    //size(0) çünkü başlangıçta yine elemanımız yok

    if(cap <= 0) {
        cout << "!Uyarı! Geçersiz kapasite girdiniz, varsayılan 2 olarak ayarlandı." << endl;
        cap = 2;
    }
    data = new int[capacity];
}




DynamicArray::DynamicArray(const DynamicArray& other) : size(other.size), capacity(other.capacity) { //copy constructor
    //Bir nesneden yeni bir nesne oluşturulurken çalışır
    //Derin kopyalama (deep copy) yapılmalıdır

    data = new int[capacity]; //Yeni bir bellek alanı açıyoruz (deep copy)

    for (int i = 0; i < size; i++) {   //Elemanları tek tek kopyalıyoruz
        data[i] = other.data[i];
    }
}




DynamicArray::~DynamicArray() { //destructor 
    //Nesne yok olurken otomatik çalışır

    delete[] data; //Dinamik diziyi serbest bırakır, eğer bunu yazmazsak memory leak olur
    
}



// TEMEL FONKSİYONLAR

void DynamicArray::push(int value) { //push - dizinin sonuna eleman ekler

    if (size == capacity) { //Eğer dizi doluysa kapasiteyi artırmamız gerekir

        capacity *= 2; //Kapasiteyi iki katına çıkarıyoruz

        int* newData = new int[capacity]; //Yeni ve daha büyük bir dizi oluşturuyoruz

        for (int i = 0; i < size; i++) { //Eski elemanları yeni diziye kopyalıyoruz
            newData[i] = data[i];
        }
        delete[] data; //Eski dizinin belleğini serbest bırakıyoruz
        data = newData; //data artık yeni diziyi gösteriyor    
    }

    data[size] = value; //Yeni elemanı dizinin sonuna ekliyoruz
    size++;
}




void DynamicArray::pop() { //pop - dizinin son elemanını siler

    if (size == 0) { 
        cout << "Uyarı! Dizi boş, silme işlemi yapilamaz." << endl;
        return;
    }

    size--;
    //Son elemanı silmek için sadece size’ı azaltmak yeterli çünkü silme işlemi pahalı ve gereksizdir
}




int DynamicArray::get(int index) const { //get - belirtilen index’teki elemanı döndürür
    //const olan fonksiyonlarda nesnenin içeriği değiştirilemez

    if (index < 0 || index >= size) {
        cout << "Hata: Geçersiz indeks!!" << endl;
        return -1;
    }

    return data[index]; //istenen elemanı döndürür
}



void DynamicArray::set(int index, int value) { //set - önce indexi kontrol eder, varsa değeri değiştirir

    if (index < 0 || index >= size) {
        cout << "Hata: Gecersiz indeks!!" << endl;
        return;
    }

    data[index] = value; //Yeni değeri atıyoruz
}



int DynamicArray::getSize() const { //get size - Dizide kaç eleman var bilgisini verir
    return size;
}


int DynamicArray::getCapacity() const { //get capacity - Dizinin kapasitesini döndürür
    return capacity;
}


bool DynamicArray::isEmpty() const { //is empty - Dizi boş mu diye kontrol eder
    return size == 0; //size 0 ise true döner, değilse false
}


void DynamicArray::clear() { //clear - Tüm elemanları siler
    size = 0; //size'ı 0 yapınca fiziksel olarak silinmez ama program artık okuyamaz
}


void DynamicArray::print() const { //print - Diziyi ekrana yazdırır

    cout << "[";
    int i = 0;
    while (i < size) {
        cout << data[i];
        if (i < size - 1) {
            cout << ", ";
        }
        i++;
    }
    cout << "]" << endl;

}


//OPERATOR OVERLOADING


int& DynamicArray::operator[](int index) { // [] operatörü (yazma)
    //arr[index] = value; gibi kullanımlar için
    if (index < 0 || index >= size) {
        cout << "Hata! Geçersiz indeks!" << endl;
        exit(1); //Hatalı indeks varsa programı sonlandırıyoruz, çünkü referans döndürmek zorundayız
    }

    return data[index]; //Referans döndürülür
}



const int& DynamicArray::operator[](int index) const { // [] operatörü (okuma)
    //Sadece okuma yapılacak durumlar için (const nesneler gibi)
    if (index < 0 || index >= size) {
        cout << "Hata: Gecersiz indeks." << endl;
        exit(1);
    }

    return data[index]; //const bir referans döndürülür
}



DynamicArray DynamicArray::operator+(const DynamicArray& other) const { // + operatorü
    //İki diziyi birleştirir
    //const var yani dizileri sadece okur değişiklik yapmaz 

    DynamicArray result(size + other.size); //burada, sonuç dizisinin kapasitesini en baştan ayarladık

    for (int i = 0; i < size; i++) {
        result.push(data[i]);
    }

    for (int i = 0; i < other.size; i++) {
        result.push(other.data[i]);
    }

    return result; //Yeni oluşturulan diziyi döndürdük
}



DynamicArray& DynamicArray::operator=(const DynamicArray& other) { //atama operatörü =
    //a = b ise çalışır

    if (this == &other) { //void yerine atama operatörünün sol taraftaki nesneyi (kendini) referans olarak döndürmesi için (ilk dizi) other dizisinin verilerini biz this dizisine kopyaladık
        return *this;
    }

    delete[] data; //Mevcut belleği temizliyoruz

    size = other.size;
    capacity = other.capacity;

    data = new int[capacity]; //Yeni bellek 

    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }

    return *this;
}



bool DynamicArray::operator==(const DynamicArray& other) const { //eşitlik kontrolü operatörü ==
    
    if (size != other.size) { //başlangıçta, dizi uzunluğunu karşılaştır farklı ise hemen false döner
        return false;
    }

    for (int i = 0; i < size; i++) { //elemanları tek tek karşılaştırır farklı çıktığı an false döner
        if (data[i] != other.data[i]) {
            return false;
        }
    }

    return true; //bir sorun yoksa yani hepsi aynı ise true döner
}



bool DynamicArray::operator!=(const DynamicArray& other) const { //eşitsizlik kontrolü operatörü !=
    // burada üsteki eşit operatörünün tersini kullandık
    return !(*this == other);
}



ostream& operator<<(ostream& os, const DynamicArray& other) { //çıktı operatörü
    os << "[";

    for (int i = 0; i < other.size; i++) {
        os << other.data[i];

        if (i != other.size - 1) {
            os << ", ";
        }
    }

    os << "]";
    return os;
}