#include <iostream>
#include <iomanip>
#include <windows.h>
#include "tree.hpp"

void batas(int batas);
void error();
void menu();
void ulang();
void pohon();
std::string printLeaf(const tree &root, const int con1, const int con2, const int con3, const int con4);
void test(const tree &root);

int main(){
    menu();
}

void batas(int batas){
    std::cout << std::setw(batas) << std::setfill('=') << "\n";
}

void error(){
    batas(45);
    std::cout << "Error: Input yang Anda masukkan salah!!\n";
    batas(45);
    system("pause");
    menu();
}

void menu(){
    ptr root = isitree();
    int input;
    system("cls");
    batas(45);
    std::cout << "\tJUDUL APLIKASI\n";
    batas(45);
    std::cout << "[1] Mulai Test\n"
                 "[2] Pohon Keputusan\n"
                 "[3] Keluar\n"
                 "Pilih (1/2) : ";
    std::cin >> input;
    if(input == 1){
        test(root);
    } else if(input == 2){
        pohon();
    } else if(input == 3){
        exit(0);
    } else{
        error();
    }
}

void ulang(){
    system("cls");
    ptr root = isitree();
    int input;
    std::cout << "Apakah Anda ingin mengulangi test?\n";
    std::cout << "[1] Ya\n"
                 "[2] Tidak\n"
                 "Pilih (1/2) : ";
    std::cin >> input;
    if(input == 1){
        test(root);
    } else if(input == 2){
        menu();
    } else{
        error();
    }
}

void pohon(){
    system("cls");
    batas(60);
    std::cout << "                      POHON KEPUTUSAN\n";
    batas(60);
    std::cout << "\n                                                              Tidak dapat merespon\n"
                 "                                                              jika dipanggil orang\n"
                 "                                                       _________________|_________________\n"
                 "                                                      |                                   |\n"
                 "                                                    Tidak                                Ya\n"
                 "                                                      |                                   |\n"
                 "                                      Suka melakukan kegiatan/gerakan                     |\n"
                 "                                            secara berulang-ulang                Gangguan Komunikasi\n"
                 "                                     _________________|_______________\n"
                 "                                    |                                 |\n"
                 "                                  Tidak                              Ya\n"
                 "                                    |                                 |\n"
                 "                      Tidak tertarik dengan orang lain        Gangguan Perilaku\n"
                 "                       _____________|________________\n"
                 "                      |                              |\n"
                 "                    Tidak                           Ya\n"
                 "                      |                              |\n"
                 "         Tidak memiliki kontak mata        Gangguan Interaksi Sosial  \n"
                 "         _____________|_____________\n"
                 "        |                           |\n"
                 "      Tidak                        Ya\n"
                 "        |                           |\n"
                 "Gangguan Perilaku     Gangguan Interaksi Sosial\n\n";
    system("pause");
    menu();
}

void test(const tree &root){
    system("cls");
    int con1, con2, con3, con4;
    std::cout << "[1] Tidak dapat merespon jika dipanggil orang?\n" //GJ04
                 "    1. Ya\n"
                 "    2. Tidak\n"
                 "    Pilih (1/2) : ";
    std::cin >> con1;
    if(con1 != 1 && con1 != 2){
        error();
    }
    std::cout << "\n[2] Suka melakukan kegiatan/gerakan secara berulang-ulang?\n" //GJ05
                 "    1. Ya\n"
                 "    2. Tidak\n"
                 "    Pilih (1/2) : ";
    std::cin >> con2;
    if(con2 != 1 && con2 != 2){
        error();
    }
    std::cout << "\n[3] Tidak tertarik dengan orang lain?\n" //GJ20
                 "    1. Ya\n"
                 "    2. Tidak\n"
                 "    Pilih (1/2) : ";
    std::cin >> con3;
    if(con3 != 1 && con3 != 2){
        error();
    }
    std::cout << "\n[4] Tidak memiliki kontak mata?\n" //GJ01
                 "    1. Ya\n"
                 "    2. Tidak\n"
                 "    Pilih (1/2) : ";
    std::cin >> con4;
    if(con4 != 1 && con4 != 2){
        error();
    }

    std::cout << "\n";
    batas(45);
    std::cout << "Hasil Anda : " << printLeaf(root, con1, con2, con3, con4) << "\n";
    batas(45);
    system("pause");
    ulang();
}