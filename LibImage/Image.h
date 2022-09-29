#pragma once
#include <iostream>
using namespace std;
class Image {
protected:
    int h;
    int w;
    unsigned char** arr;
public:
    Image(int _h = 0, int _w = 0);
    Image(const Image& a);
    int get_h();
    int get_w();
    unsigned char& get(int i, int j);
    Image& operator=(const Image& a);
    void zoom();
    void resize(int _h, int _w);
    unsigned char* get_memory_adress();
    friend ostream& operator<<(ostream& out,const Image& a);
    ~Image();
};
