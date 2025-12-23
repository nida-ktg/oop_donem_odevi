#include "UniqueArray.h" //UniqueArray sınıfının tanımını içeren header dosyası
//Bu header içinde DynamicArray.h zaten include edildiği için
//DynamicArray fonksiyonlarına erişimimiz var

#include <iostream>
using namespace std;


UniqueArray::UniqueArray() : DynamicArray() {} //varsayılan constructor 
UniqueArray::UniqueArray(int cap) : DynamicArray(cap) {} //parametreli constructor


bool UniqueArray::contains(int value) const {  //Bu fonksiyon dizide value değerinin bulunup bulunmadığını kontrol eder

    int i = 0;
    while (i < getSize()) { //i'yi arttırıp tek tek tüm elemanları kontrol ediyoruz
        if (get(i) == value) {
            return true;  //Eleman bulundu
        }
        i++;
    }
    return false;  //Eleman bulunamadı
}


void UniqueArray::push(int value) { //override edilen push fonksiyonu
    if (contains(value)) {
        cout << "Uyarı: " << value << " dizide olan değer eklenemez!!" << endl;
        return;
    }

    DynamicArray::push(value); 
    //if kontrolü ile eklenmek istenen value'nun dizide olmadığı anlaşılınca DynamicArray'in push fonksiyonu çağrılır

}