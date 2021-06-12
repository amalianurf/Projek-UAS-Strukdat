#include <iostream>
#include <iomanip>
#include <windows.h>
#include "tree.hpp"

void batas();
void error();
void menu();
void ulang();
std::string printLeaf(const tree &root, const int con1, const int con2, const int con3, const int con4);
void test(const tree &root);

int main(){
    menu();
}

void batas(){
    std::cout << std::setw(45) << std::setfill('=') << "\n";
}

void error(){
    batas();
    std::cout << "Error: Input yang Anda masukkan salah!!\n";
    batas();
    system("pause");
    menu();
}

void menu(){
    ptr root = isitree();
    int input;
    system("cls");
    batas();
    std::cout << "\tJUDUL APLIKASI\n";
    batas();
    std::cout << "[1] Mulai Test\n"
                 "[2] Keluar\n"
                 "Pilih (1/2) : ";
    std::cin >> input;
    if(input == 1){
        test(root);
    } else if(input == 2){
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

std::string printLeaf(const tree &root, const int con1, const int con2, const int con3, const int con4){
    if(root->isLeaf){
        if(root->gejala == "GG01"){
            return "Gangguan Perilaku";
        } else if(root->gejala == "GG02"){
            return "Gangguan Komunikasi";
        } else{
            return "Gangguan Interaksi Sosial";
        }
    }

    if(root->gejala == "GJ04"){
        if(con1 == 2){
            return printLeaf(root->left, con1, con2, con3, con4);
        }
        return printLeaf(root->right, con1, con2, con3, con4);
    }

    if(root->gejala == "GJ05"){
        if(con2 == 2){
            return printLeaf(root->left, con1, con2, con3, con4);
        }
        return printLeaf(root->right, con1, con2, con3, con4);
    }

    if(root->gejala == "GJ20"){
        if(con3 == 2){
            return printLeaf(root->left, con1, con2, con3, con4);
        }
        return printLeaf(root->right, con1, con2, con3, con4);
    }

    if(root->gejala == "GJ01"){
        if(con4 == 2){
            return printLeaf(root->left, con1, con2, con3, con4);
        }
        return printLeaf(root->right, con1, con2, con3, con4);
    }

    return "Gangguan/Gejala tidak ditemukan!";
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
    batas();
    std::cout << "Hasil Anda : " << printLeaf(root, con1, con2, con3, con4) << "\n";
    batas();
    system("pause");
    ulang();
}