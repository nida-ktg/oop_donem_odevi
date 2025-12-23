#ifndef UNIQUEARRAY_H
#define UNIQUEARRAY_H

#include "DynamicArray.h"
//UniqueArray sınıfı, DynamicArray'den türeyeceği için önce o sınıfı include etmeliyiz


class UniqueArray : public DynamicArray {
    //Aynı değerden birden fazla kez bulunamaz. Yani dizi her zaman benzersiz (unique) elemanlar içerir

public:

    UniqueArray(); //varsayılan constructor
    UniqueArray(int cap); //parametreli constructor


    void push(int value) override;
    //DynamicArray'deki push(int) fonksiyonu override edilir
    //Amacımız, aynı elemanın ikinci kez eklenmesini ENGELLEMEK


    bool contains(int value) const; //ek fonksiyon
    //Dizide belirtilen value var mı diye kontrol eder, varsa true yoksa false
    //const çünkü dizinin içeriğini değiştirmez

};

#endif
