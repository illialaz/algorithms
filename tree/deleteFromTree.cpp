#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Node {
  int val;
  Node* right;
  Node* left;
  Node* parent;
  Node(): left(nullptr), right(nullptr), parent(nullptr), val(0) {}
  Node(int num, Node* pr): left(nullptr), right(nullptr), parent(pr), val(num) {}
};

class Tree {
  private:
    Node* root;
    int elemDel;
    vector<Node*> elems;

    void putNode(int val, Node* & cur, Node* parent) {
      if(cur == nullptr) {
        cur = new Node(val, parent);
      }
      else if(cur->val > val) putNode(val, cur->left, cur);
      else if(cur->val < val) putNode(val, cur->right, cur);
    }

    void leftTraversal(Node* cur) {
      if(cur == nullptr) return;
      elems.push_back(cur);
      leftTraversal(cur->left);
      leftTraversal(cur->right);
    }

  public:
    Tree() {
      root = nullptr;
      elemDel = 0;
    }

    void fillTree() {
      ifstream fin("input2.txt");
      fin >> elemDel;
      int val;
      while(fin >> val) {
        putNode(val, root, nullptr);
      }
    }

    int getKey() { return elemDel; }

    void deleteElem(int key) {
      Node* del = find(key);
      if(del == nullptr) return;

      if(del->right != nullptr && del->left != nullptr) {
        Node* tmp = del->right;
        while(tmp->left != nullptr) tmp = tmp->left;
        int value = tmp->val;
        deleteElem(tmp->val);
        del->val = value;
      }
      else if(del->right == nullptr && del->left == nullptr) {
        if(del == root) root = nullptr;
        else del->parent->left == del ? del->parent->left = nullptr : del->parent->right = nullptr;
      }
      else if(del->right == nullptr && del->left != nullptr) {
        if(del == root) {
          del->left->parent = nullptr;
          this->root = del->left;
        }
        else {
          del->left->parent = del->parent;
          del->val > del->parent->val ? del->parent->right = del->left : del->parent->left = del->left;
        }
      }
      else if(del->right != nullptr && del->left == nullptr) {
        if(del == root) {
          del->right->parent = nullptr;
          this->root = del->right;
        }
        else {
          del->right->parent = del->parent;
          del->val > del->parent->val ? del->parent->right = del->right : del->parent->left = del->right;
        }
      }
    }

    Node* find(int key) {
      elems.clear();
      leftTraversal(this->root);

      for(Node* elem : elems) {
        if(elem->val == key) {
          elems.clear();
          return elem;
        }
      }
      elems.clear();
      return nullptr;
    }

    void leftPrintTree() {
      leftTraversal(this->root);
      std::ofstream fout("output.txt");

      for(Node* elem : elems) fout << elem->val << endl;
      elems.clear();
    }
};

int main() {
  Tree c;
  c.fillTree();
  c.deleteElem(c.getKey());
  c.leftPrintTree();
}
