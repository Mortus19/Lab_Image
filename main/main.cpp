#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<fstream>
#include "Image.h"
#include "Image_TXT.h"
#include "Image_BIN.h"
#include <stdio.h>
using namespace std;

int main() {
    /*
    commit??
    */
    Image_TXT myImage_TXT("input.txt", "output.txt");
    myImage_TXT.Save_File();
    Image_BIN myImage_BIN("input.bin", "output.bin");
    myImage_BIN.Save_File();
    return 0;
}
