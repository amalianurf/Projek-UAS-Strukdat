struct Node{
    std::string gejala;
    Node* left;
    Node* right;
};

using ptr = Node*;
using tree = ptr;
tree root;

tree createTree(){
    return nullptr;
}

ptr createElement(std::string gejala){
    ptr newNode = new Node;
    newNode->gejala = gejala;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void insert(tree &root, ptr newElement, bool condition) {
    if(root == nullptr){
        root = newElement;
    } else if(!condition){
        insert(root->left, newElement, condition);
    } else{
        insert(root->right, newElement, condition);
  }
}

ptr search(tree &root, std::string gejala, bool condition) {
  if(root == nullptr || root->gejala == gejala){
    return root;
  } if(!condition){
    return search(root->right, gejala, condition);
  }
  return search(root->left, gejala, condition);
}