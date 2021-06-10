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
//tree root;

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