struct Node{
    std::string gejala;
    bool isLeaf;
    Node* left;
    Node* right;

    Node(std::string gejala, bool isLeaf){
        this->gejala = gejala;
        this->isLeaf = isLeaf;
        this->left = nullptr;
        this->right = nullptr;
    }
};

using ptr = Node*;
using tree = ptr;

tree createTree(){
    return nullptr;
}

ptr isitree(){
    createTree();
    ptr root = new Node("GJ04", 0);

    ptr temp = root;
    temp->right = new Node("GG02", 1);
    temp->left = new Node("GJ05", 0);

    temp = temp->left;
    temp->right = new Node("GG01", 1);
    temp->left = new Node("GJ20", 0);

    temp = temp->left;
    temp->right = new Node("GG03", 1);
    temp->left = new Node("GJ01", 0);

    temp = temp->left;
    temp->right = new Node("GG03", 1);
    temp->left = new Node("GG01", 1);

    return root;
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