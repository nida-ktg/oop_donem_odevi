#include "SortedArray.h" //SortedArray sınıfının tanımını içeren header dosyası

#include <iostream>
using namespace std;


SortedArray::SortedArray() : DynamicArray() {} //Bu constructor çağrıldığında, DynamicArray'nin varsayılan constructor'ı çalışır

SortedArray::SortedArray(int cap) : DynamicArray(cap) {}


void SortedArray::push(int value) { //OVERRIDE EDİLEN PUSH FONKSİYONU

    if (getSize() == 0) {
        //Hiç eleman yoksa direkt ekleyebiliriz
        DynamicArray::push(value);
        return;
    }


    if (getSize() == getCapacity()) { //Eğer capacity doluysa, önce kapasiteyi büyütmemiz gerekir

        DynamicArray::push(value);
        //value şimdilik-geçici olarak sona eklendi

    } else {
        //yer açmak amacıyla sahte bir push yapıyoruz
        DynamicArray::push(value);
    }


    int i = getSize() - 2;


    //Büyük elemanları sağa kaydırmak için:
    while (i >= 0 && (*this)[i] > value) {
        (*this)[i + 1] = (*this)[i]; //Büyük elemanı bir sağa kaydırıyoruz
        i--;
    }

    //value'yu doğru yere yerleştiriyoruz
    (*this)[i + 1] = value;
}



int SortedArray::binarySearch(int value) const {

    int left = 0; //sol sınır

    int right = getSize() - 1; //sağ sınır

    while (left <= right) {
        int mid = left + (right - left) / 2;
        //Ortadaki index hesaplanır (Bu yöntem overflow riskini azaltır)

        int midValue = get(mid);

        if (midValue == value) {
            return mid;
        }
        else if (midValue < value) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1; //eleman bulunamadıysa
}
