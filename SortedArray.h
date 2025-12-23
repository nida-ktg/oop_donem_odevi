#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H


#include "DynamicArray.h"
//SortedArray, DynamicArray'den türediği için header'ını include ediyoruz
 


// Bu sınıf, DynamicArray sınıfından türetilmiştir  İçindeki elemanlar HER ZAMAN küçükten büyüğe sıralıdır
class SortedArray : public DynamicArray {
// ↑ public inheritance kullanıyoruz 
public:
   
    SortedArray();        //Varsayılan constructor
    
    SortedArray(int cap);  //Parametreli constructor


    void push(int value) override;

    // Bu fonksiyon DynamicArray'deki push()'ı OVERRIDE eder
    // Çünkü: Normal DynamicArray sona ekler ama biz sıralı eklemek istiyoruz
   
    

    int binarySearch(int value) const;

    // Dizide binary search algoritması ile arama yapar
    // elemanı bulursa→ index döndürür
    // Bulunamazsa: -1 döndür
    
};
#endif