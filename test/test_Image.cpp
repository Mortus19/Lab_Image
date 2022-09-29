#include "Image.h"
#include "Image_TXT.h"
#include "Image_BIN.h"
#include <gtest.h>

//TEST(<Тестирующая библиотека> , <название теста>)

const string test_file_in_txt = "input_test.txt";
const string test_file_out_txt = "output_test.txt";
const string test_file_in_bin = "input_test.bin";
const string test_file_out_bin = "output_test.bin";

TEST(LibImage, eq_test)
{
    int h = 3;
    int w = 2;
    Image tmp(h, w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            tmp.get(i + 1, j + 1) = 1;
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            EXPECT_EQ(1, tmp.get(i + 1, j + 1));
        }
    }

}

TEST(LibImage, not_eq_test)
{
    int h = 3;
    int w = 2;
    Image tmp(h, w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            tmp.get(i + 1, j + 1) = 1;
        }
    }
    tmp.get(1, 1) = 2;
    ASSERT_NE(1, tmp.get(0 + 1, 0 + 1));
}

TEST(LibImage, negative_size_test)
{
    ASSERT_ANY_THROW(Image tmp(-1, -1));
}

TEST(LibImage, zoom_test)
{
    Image tmp(3, 3);
    int h = tmp.get_h();
    int w = tmp.get_w();
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            tmp.get(i + 1, j + 1) = abs(rand()) % 100;
        }
    }
    tmp.zoom();
    h = tmp.get_h();
    w = tmp.get_w();
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i % 2 == 0 || j % 2 == 0)continue;
            if (i == h - 1 || j == w - 1)continue;
            if(i>0 && i<h-1)
                EXPECT_EQ((tmp.get(i, j + 1) + tmp.get(i + 2, j + 1))/2, tmp.get(i + 1, j + 1));
            if (j > 0 && j < w - 1)
                EXPECT_EQ((tmp.get(i+1, j) + tmp.get(i + 1, j + 2)) / 2, tmp.get(i + 1, j + 1));
        }
    }
}

TEST(LibImage, file_input_txt) {
    //Проверка на считывание из файла txt

    Image tmp(3, 3);
    int h = tmp.get_h();
    int w = tmp.get_w();
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            tmp.get(i + 1, j + 1) = abs(rand()) % 100;
        }
    }
    ofstream out(test_file_in_txt);
    //Записываем объект tmp  в файл test_file_in
    out << h << ' ' << w << '\n';
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            out<<(int)tmp.get(i + 1, j + 1)<<' ';
        }
        out << '\n';
    }
    out.close();
    Image_TXT tmp_file(test_file_in_txt);
    EXPECT_EQ(h, tmp_file.get_h());
    EXPECT_EQ(w, tmp_file.get_w());
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            EXPECT_EQ(tmp.get(i + 1, j + 1), tmp_file.get(i + 1, j + 1));
        }
    }
}

TEST(LibImage, file_output_txt) {
    //Проверка на запись в файл txt
    Image tmp(3, 3);
    int h = tmp.get_h();
    int w = tmp.get_w();
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            tmp.get(i + 1, j + 1) = abs(rand()) % 100;
        }
    }
    ofstream out(test_file_in_txt);
    //Записываем объект tmp  в файл test_file_in
    out << h << ' ' << w << '\n';
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            out << (int)tmp.get(i + 1, j + 1) << ' ';
        }
        out << '\n';
    }
    out.close();
    //Сохраняем объект Image tmp в файл test_file_out
    Image_TXT tmp_file(test_file_in_txt,test_file_out_txt);
    tmp_file.Save_File();
    //Теперь проверяем значения из файла test_file_out и объекта Image tmp
    Image_TXT tmp_file2(test_file_out_txt,"");
    EXPECT_EQ(tmp_file.get_h(), tmp_file2.get_h());
    EXPECT_EQ(tmp_file.get_w(), tmp_file2.get_w());
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            EXPECT_EQ(tmp_file.get(i + 1, j + 1), tmp_file2.get(i + 1, j + 1));
        }
    }
}

TEST(LibImage, file_input_bin) {
    //Проверка на считывание из файла bin
    Image tmp(3, 3);
    int h = tmp.get_h();
    int w = tmp.get_w();
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            tmp.get(i + 1, j + 1) = abs(rand()) % 100;
        }
    }
    ofstream out(test_file_in_bin,ios::binary);
    //Записываем объект tmp  в файл test_file_in_bin
    out.write((char*)&h, sizeof(int));
    out.write((char*)&w, sizeof(int));
    out.write((char*)(tmp.get_memory_adress()), sizeof(unsigned char) * h * w);
    out.close();
    //Сохраняем объект Image tmp в файл test_file_out_bin
    Image_BIN tmp_file(test_file_in_bin, test_file_out_bin);
    //Создаем новый объект на основе файла test_file_out_txt
    EXPECT_EQ(h, tmp_file.get_h());
    EXPECT_EQ(w, tmp_file.get_w());
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            EXPECT_EQ(tmp.get(i + 1, j + 1), tmp_file.get(i + 1, j + 1));
        }
    }
}

TEST(LibImage, file_output_bin) {
    //Проверка на запись в файл bin
    Image tmp(3, 3);
    int h = tmp.get_h();
    int w = tmp.get_w();
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            tmp.get(i + 1, j + 1) = abs(rand()) % 100;
        }
    }
    ofstream out(test_file_in_bin, ios::binary);
    //Записываем объект tmp  в файл test_file_in_bin
    out.write((char*)&h, sizeof(int));
    out.write((char*)&w, sizeof(int));
    out.write((char*)(tmp.get_memory_adress()), sizeof(unsigned char) * h * w);
    out.close();
    //Сохраняем объект Image tmp в файл test_file_out_bin и записали Image в test_file_out_bin
    Image_BIN tmp_file(test_file_in_bin, test_file_out_bin);
    tmp_file.Save_File();
    //Создаем новый объект на основе файла test_file_out_bin
    Image_BIN tmp_file2(test_file_out_bin,"");
    EXPECT_EQ(tmp_file.get_h(), tmp_file2.get_h());
    EXPECT_EQ(tmp_file.get_w(), tmp_file2.get_w());
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            EXPECT_EQ(tmp_file.get(i + 1, j + 1), tmp_file2.get(i + 1, j + 1));
        }
    }

    
}