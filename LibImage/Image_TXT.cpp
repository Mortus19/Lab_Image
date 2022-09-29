#include"Image_TXT.h"

Image_TXT::Image_TXT(string _name_file_in, string _name_file_out) {
    name_file_in = _name_file_in;
    name_file_out = _name_file_out;
    Read_File();
}

void Image_TXT::Read_File() {
    ifstream fin(name_file_in);
    fin >> h >> w;
    this->resize(h, w);
    int temp;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            fin >> temp;
            this->arr[i][j] = temp;
        }
    }
    fin.close();
}
void Image_TXT::Save_File() {
    ofstream fout(name_file_out);
    fout << h << " " << w << '\n';
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            fout << (int)this->get(i + 1, j + 1) << " ";
        }
        fout << '\n';
    }
    fout.close();
}
void Image_TXT::change_file_in(string _name_file_in) {
    name_file_in = _name_file_in;
}
void Image_TXT::change_file_out(string _name_file_out) {
    name_file_out = _name_file_out;
}
Image_TXT& Image_TXT::operator= (const Image& obj) {
    this->Image::operator=(obj);
    return *this;
}
