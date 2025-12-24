#include <iostream>

using namespace std;

#include "DynamicArray.h" //DynamicArray sınıfını kullanabilmek için

#include "SortedArray.h" //SortedArray sınıfını kullanabilmek için

#include "UniqueArray.h" //UniqueArray sınıfını kullanabilmek için


int main() {


    cout << "*** DynamicArray Testi ***" << endl;

    DynamicArray arr1; //Varsayılan constructor çağrılır
  

    arr1.push(10); //şu anda dizi: [10]

    arr1.push(20);
    //şu anda dizi: [10, 20]

    arr1.push(30); //burada capacity dolduğu için capacity otomatik büyüdü. şu anda dizi: [10, 20, 30]

    arr1.print(); //çıktı: [10, 20, 30]



    cout << "\n*** operator[] Testi ***" << endl;

    arr1[1] = 50; //operator[] referans döndürdüğü için arr1[1] değerini değiştirebiliyoruz

    cout << "arr1[1] = " << arr1[1] << endl; //çıktı: 50



    cout << "\n*** operator+ Testi ***" << endl;

    DynamicArray arr2;

    arr2.push(60);
    arr2.push(70);
    //arr2 = [60, 70]

    DynamicArray arr3 = arr1 + arr2; //operator + çağrıldı, arr1 ve arr2 birleştirildi

    arr3.print(); //çıktı: [10, 50, 30, 60, 70]



    cout << "\n*** SortedArray Testi ***" << endl;

    SortedArray sorted; //SortedArray nesnesi oluşturulur - DynamicArray constructor'ı da otomatik çalışır
    //elemanlar küçükten büyüğe sıralı ekler

    sorted.push(55);
    sorted.push(15);
    sorted.push(35);
    sorted.push(25);
    sorted.push(45);

    sorted.print(); //çıktı: [15, 25, 35, 45, 55]



    cout << "\n*** Binary Search Testi ***" << endl;

    int index = sorted.binarySearch(15);

    cout << "15 bulundu, indeks: " << index << endl; //çıktı: 10 bulundu, indeks: 0



    cout << "\n*** UniqueArray Testi ***" << endl;

    UniqueArray unique;  //UniqueArray nesnesi oluşturulur

    unique.push(100);
    unique.push(200);
    unique.push(100); //önemli!!! -> 100 zaten var olduğu için EKLENMEZ
    unique.push(300);

    unique.print(); //çıktı: [100, 200, 300]


    cout << "\n*** Contains Fonksiyonu Testi ***" << endl;


    cout << "200 var mı? "
         << (unique.contains(200) ? "Evet" : "Hayir")
         << endl;

    cout << "500 var mı? "
         << (unique.contains(500) ? "Evet" : "Hayir")
         << endl;
    

    return 0;
}
