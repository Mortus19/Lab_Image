#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<fstream>
#include "Image.h"
#include "Image_TXT.h"
#include "Image_BIN.h"
#include <stdio.h>
using namespace std;
/*
===========================================================
class Imetod {
public:
    virtual unsigned char getValue(int i , int j) = 0;
};

class White :public Imetod {
public:
    unsigned char getValue(int i, int j) {
        return 255;
    }
};

class Chess_color :public Imetod {
public:
    unsigned char getValue(int i, int j) {
        if ((i + j) % 2) return 0;
        return 255;
    }
};

void fill(Image& obj, Imetod* fun) {
    int h = obj.get_h();
    int w = obj.get_w();
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            obj.get(i + 1, j + 1) = fun->getValue(i, j);
        }
    }
}


class While_template {
public:
    unsigned char getValue(int i, int j) {
        return 255;
    }
};

template<class T>
void fill(Image& obj, T* fun) {
    int h = obj.get_h();
    int w = obj.get_w();
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            obj.get(i + 1, j + 1) = fun->getValue(i, j);
        }
    }
}
===========================================================
*/

int main() {
    /*
    ===========================
    Image tmp(5, 5);
    Image tmp2(5, 5);
    Chess_color op;
    White op2;
    fill(tmp, &op);
    fill(tmp2, &op2);
    cout << tmp << '\n';
    cout << tmp2 << '\n';
    fill (Image , Imetod)
    Imetod - метод покраски
    ===========================
    



    ===========================
    Image tmp(5, 5);
    While_template op;
    fill(tmp, &op);
    cout << tmp << '\n';
    ===========================





    ===========================
    Шаблоны работают быстрее + объем кода меньше. Но читаемость кода хуже
    inline - не вызывает функцию , а сразу подставляет код , когда инлайнится , тогда круто
    при полиморфизме ничего не инлайнется , а вызывается таблица виртуальных методов
    ===========================
    */

    /*
    Основной код
    Image_TXT myImage_TXT("input.txt", "output.txt");
    myImage_TXT.Save_File();
    Image_BIN myImage_BIN("input.bin", "output.bin");
    myImage_BIN.Save_File();
    */

    /*
    =============================================================================================
    23.09.2022
    Для множества нам необходимо определить время выполнения операций
    1)Как добавить элемент
    2)Как удалить элемент
    3)Объединить два множества
    4)Пересечь два множества
    1>>20 = 1/(2^20)
    1<<20
    a = 3,a = 00000000011(в двоичном)
    b = a << 2; ,b = 00000001100(в двоичном)
    c = b>>3 , c = 000000001
    b = a&(1<<2 - 1) , эквивалентно b = a%4 , если не степень двойки то будет трудно
    x - хотим установить в число a x-бит значение 1
    a = a|(1<<x);
    a &= ~(1<<n); - убираем элемент
    a|b - объединение множеств
    a&b - объединение множеств
    int s = sizeof(int)*8;
    MemLen = (N+s-1)/s;
    (N+s-1) >> (sizeof(int)+1)


    Операции объединения и пересечения оптимальным образом


    =============================================================================================
    
    
    */


    return 0;
}
