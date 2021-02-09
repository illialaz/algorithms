#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <string>
#include<fstream>
#include <vector>

using namespace std;

struct Node {
  int val;
  Node* right;
  Node* left;
  Node(): left(nullptr), right(nullptr), val(0) {}
  Node(int num): left(nullptr), right(nullptr), val(num) {}
};

class Tree {
  private:

    void putNode(int val, Node* & cur) {
      if(cur == nullptr) {
        cur = new Node(val);
      }
      else if(cur->val > val) putNode(val, cur->left);
      else if(cur->val < val) putNode(val, cur->right);
    }

    void leftTraversal(Node* cur) {
      if(cur == nullptr) return;
      res.push_back(cur->val);
      leftTraversal(cur->left);
      leftTraversal(cur->right);
    }

    vector<int> res;

  public:
    Node* root;

    Tree() {
      root = nullptr;
    }

    void fillTree(string fileName) {
      ifstream fin("input.txt");
      int val;
      while(fin >> val) {
        putNode(val, root);
      }
    }

    void leftPrintTree() {
      leftTraversal(this->root);
      std::ofstream fout("output.txt");

      for(vector<int>::iterator itr = res.begin(); itr != res.end(); itr++) fout << *itr << endl;
    }
};

int main() {
  Tree c;
  c.fillTree("input.txt");
  c.leftPrintTree();
}
