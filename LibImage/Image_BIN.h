#pragma once
#include"Image.h"
#include<fstream>
#include<iostream>
#include<string>
using namespace std;
class Image_BIN {
    Image obj;
    string name_file_in;
    string name_file_out;
public:
    Image_BIN(string _name_file_in = "", string _name_file_out = "");
    void Save_File();
    void Read_File();
    void change_file_in(string _name_file_in = "");
    void change_file_out(string _name_file_out = "");
    unsigned char& get(int i, int j);
    Image_BIN& operator=(const Image_BIN& a);
    void zoom();
    void resize(int _h, int _w);
    int get_h();
    int get_w();
    friend ostream& operator<<(ostream& out,const Image_BIN& a);
};

