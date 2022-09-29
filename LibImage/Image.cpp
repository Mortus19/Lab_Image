#include "Image.h"


Image::Image(int _h, int _w) {
    if (_h < 0 || _w < 0 || (_h * _w ==0 && _h+_w !=0))
        throw "Not correct data";
    h = _h;
    w = _w;
    if (_h == 0) {
        arr = nullptr;
        return;
    }
    arr = new unsigned char* [h];
    arr[0] = new unsigned char[h * w];
    for (int i = 1; i < h; i++) {
        arr[i] = arr[i - 1] + w;
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            arr[i][j] = 0;
        }
    }
}
int Image::get_h() {
    return this->h;
}
int Image::get_w() {
    return this->w;
}

Image::Image(const Image& a) {
    h = a.h;
    w = a.w;
    arr = new unsigned char* [h];
    arr[0] = new unsigned char[h * w];
    for (int i = 1; i < h; i++) {
        arr[i] = arr[i - 1] + w;
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            arr[i][j] = a.arr[i][j];
        }
    }
}

unsigned char&  Image::get(int i, int j) {
    //Get и set одновременно
    i--; j--;
    if (i >= h || i < 0 || j >= w || j < 0)
        throw "Out of the range Image";
    return arr[i][j];
}

Image& Image:: operator=(const Image& a) {
    if (this == &a)
        return *this;
    if (arr != nullptr) {
        delete arr[0];
        delete[] arr;
    }
    h = a.h;
    w = a.w;
    arr = new unsigned char* [h];
    arr[0] = new unsigned char[h * w];
    for (int i = 1; i < h; i++) {
        arr[i] = arr[i - 1] + w;
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            arr[i][j] = a.arr[i][j];
        }
    }
    return *this;
}

void Image::resize(int _h, int _w) {
    if (arr != nullptr) {
        delete arr[0];
        delete[] arr;
    }
    h = _h;
    w = _w;
    arr = new unsigned char* [h];
    arr[0] = new unsigned char[h * w];
    for (int i = 1; i < h; i++) {
        arr[i] = arr[i - 1] + w;
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            arr[i][j] =0;
        }
    }
}

void Image::zoom() {
    if (arr == nullptr) {
        return;
    }
    int _h = h * 2;
    int _w = w * 2;
    unsigned char** _arr = new unsigned char* [_h];
    _arr[0] = new unsigned char[_h * _w];
    for (int i = 1; i < _h; i++) {
        _arr[i] = _arr[i - 1] + _w;
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            _arr[2 * i][2 * j] = arr[i][j];
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 1; j < _w - 1; j += 2) {
            _arr[2 * i][j] = (_arr[2 * i][j - 1] + _arr[2 * i][j + 1]) / 2;
        }
    }
    for (int i = 1; i < _h - 1; i += 2) {
        for (int j = 0; j < _w - 1; j++) {
            _arr[i][j] = (_arr[i - 1][j] + _arr[i + 1][j]) / 2;
        }
    }
    for (int i = 0; i < _h - 1; i++) {
        _arr[i][_w - 1] = _arr[i][_w - 2];
    }
    for (int i = 0; i < _w; i++) {
        _arr[_h - 1][i] = _arr[_h - 2][i];
    }
    delete[]arr[0];
    delete[]arr;
    h = _h;
    w = _w;
    arr = _arr;
}

unsigned char* Image::get_memory_adress() {
    return arr[0];
}

ostream& operator<<(ostream& out, const Image& a) {
    for (int i = 0; i < a.h; i++) {
        for (int j = 0; j < a.w; j++) {
            out << (int)a.arr[i][j] << " | ";
        }
        out << '\n';
    }
    return out;
}

Image::~Image() {
    delete[] arr[0];
    delete[] arr;
}