#include <iostream>
#include "tree.hpp"

std::string print(const tree &root, const int con1, const int con2, const int con3, const int con4){
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
            return print(root->left, con1, con2, con3, con4);
        }
        return print(root->right, con1, con2, con3, con4);
    }

    if(root->gejala == "GJ05"){
        if(con2 == 2){
            return print(root->left, con1, con2, con3, con4);
        }
        return print(root->right, con1, con2, con3, con4);
    }

    if(root->gejala == "GJ20"){
        if(con3 == 2){
            return print(root->left, con1, con2, con3, con4);
        }
        return print(root->right, con1, con2, con3, con4);
    }

    if(root->gejala == "GJ01"){
        if(con4 == 2){
            return print(root->left, con1, con2, con3, con4);
        }
        return print(root->right, con1, con2, con3, con4);
    }

    return "Gangguan/Gejala tidak ditemukan!";
}

void menu(const tree &root){
    int con1, con2, con3, con4;
    std::cout << "Tidak dapat merespon jika dipanggil orang?\n" //GJ04
                 "1. Ya\n"
                 "2. Tidak\n"
                 "Pilih (1/2) : ";
    std::cin >> con1;
    std::cout << "\nSuka melakukan kegiatan/gerakan secara berulang-ulang?\n" //GJ05
                 "1. Ya\n"
                 "2. Tidak\n"
                 "Pilih (1/2) : ";
    std::cin >> con2;
    std::cout << "\nTidak tertarik dengan orang lain?\n" //GJ20
                 "1. Ya\n"
                 "2. Tidak\n"
                 "Pilih (1/2) : ";
    std::cin >> con3;
    std::cout << "\nTidak memiliki kontak mata?\n" //GJ01
                 "1. Ya\n"
                 "2. Tidak\n"
                 "Pilih (1/2) : ";
    std::cin >> con4;

    std::cout << "\nHasil Anda : " << print(root, con1, con2, con3, con4);
}

main(){
    ptr root = isitree();
    menu(root);
}