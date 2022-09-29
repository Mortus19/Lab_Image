#pragma once
#include"Image.h"
#include<fstream>
#include<iostream>
#include<string>
using namespace std;
class Image_TXT: public Image {
    string name_file_in;
    string name_file_out;
public:
    Image_TXT(string _name_file_in = "", string _name_file_out = "");
    void Read_File();
    void Save_File();
    void change_file_in(string _name_file_in = "");
    void change_file_out(string _name_file_out = "");
    Image_TXT& operator= (const Image& obj);
    //friend ostream& operator<<(ostream& out, Image_TXT& obj);
};
