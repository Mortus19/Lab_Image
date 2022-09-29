#include "Image_BIN.h"

Image_BIN::Image_BIN(string _name_file_in, string _name_file_out ) {
    name_file_in = _name_file_in;
    name_file_out = _name_file_out;
    Read_File();
}
void Image_BIN::Save_File() {
    ofstream fout(name_file_out, ios::binary);
    int _h = obj.get_h(); int _w = obj.get_w();
    fout.write((char*)&_h, sizeof(int));
    fout.write((char*)&_w, sizeof(int));
    fout.write((char*)(obj.get_memory_adress()), sizeof(unsigned char) * _h * _w);
    fout.close();
}
void Image_BIN::Read_File() {
    int _h, _w;
    ifstream fin(name_file_in, ios::binary);
    fin.read((char*)&_h, sizeof(int));
    fin.read((char*)&_w, sizeof(int));
    obj.resize(_h, _w);
    //obj = Image(_h, _w);
    fin.read((char*)(obj.get_memory_adress()), sizeof(unsigned char) * _h * _w);
    fin.close();
}
unsigned char& Image_BIN::get(int i, int j) {
    return obj.get(i, j);
}
Image_BIN& Image_BIN::operator=(const Image_BIN& a) {
    name_file_in = a.name_file_in;
    name_file_out = a.name_file_out;
    obj = a.obj;
    return *this;
}
int Image_BIN::get_h() {
    return obj.get_h();
}
int Image_BIN::get_w() {
    return obj.get_w();
}
void Image_BIN::zoom() {
    obj.zoom();
}
void Image_BIN::change_file_in(string _name_file_in) {
    name_file_in = _name_file_in;
}
void Image_BIN::change_file_out(string _name_file_out) {
    name_file_out = _name_file_out;
}
ostream& operator<<(ostream& out, const Image_BIN& a) {
    out << a.obj;
    return out;
}
void Image_BIN::resize(int _h, int _w) {
    obj.resize(_h, _w);
}