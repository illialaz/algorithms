#pragma comment(linker, "/STACK:167772160")
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <map>
#include <iterator>

using namespace std;

struct Node {
  int val;
  Node* right;
  Node* left;
  Node* parent;
  int depth;
  Node(): left(nullptr), right(nullptr), parent(nullptr), val(0), depth(0) {}
  Node(int num, Node* pr, int dep): left(nullptr), right(nullptr), parent(pr), val(num), depth(dep) {}
};

class Tree {
  private:
    Node* root;
    vector<Node*> elems;
    vector<Node*> leaves;

    Node* putNode(int val, Node* & cur, Node* parent) {
      if(root == nullptr) cur = new Node(val, parent, 0);
      if(cur == nullptr) {
        return cur = new Node(val, parent, parent->depth + 1);
      }
      else if(cur->val > val) return putNode(val, cur->left, cur);
      else if(cur->val < val) return putNode(val, cur->right, cur);
    }

    void leftTraversal(Node* cur) {
      if(cur == nullptr) return;
      elems.push_back(cur);
      if(cur != root && cur->left == nullptr && cur->right == nullptr) leaves.push_back(cur);
      leftTraversal(cur->left);
      leftTraversal(cur->right);
    }

  public:
    Tree() {
      root = nullptr;
    }

    void fillTree() {
      std::ios_base::sync_with_stdio(false);
      std::cin.tie(nullptr);
      freopen("tst.in", "r", stdin);
      int val;
      while(scanf(" %d", &val) == 1) {
        putNode(val, root, nullptr);
      }
    }

    void deleteElem(int key) {
      Node* del = find(root, key);
      if(del == nullptr) return;

      if(del->right != nullptr && del->left != nullptr) {
        Node* tmp = del->left;
        while(tmp->right != nullptr) tmp = tmp->right;
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

    void deleteMedian() {
      leftTraversal(root);
      elems.clear();
      int minDepth = INT32_MAX;
      for(Node* elem : leaves) {
        if(elem->depth + 1 < minDepth) minDepth = elem->depth + 1;
      }

      map<int, int> deleted;

      if(minDepth % 2 != 0) {
        for(Node* elem : leaves) {
          if(elem->depth + 1 == minDepth) {
            int delElem = findMedianVal(elem);
            if(deleted.find(delElem) == deleted.end()) deleted[delElem] = delElem;
          }
        }
      }
      for(pair<int, int> elem : deleted) deleteElem(elem.second);
    }

    int findMedianVal(Node* leaf) {
      int n = leaf->depth + 1;
      int* arr = new int[n];
      Node* tmp = root;
      int left = 0;
      int right = n - 1;
      for(int i = 0; i < n; i++) {
        if(tmp->val > leaf->val) {
          arr[right--] = tmp->val;
          tmp = tmp->left;
        }
        else {
          arr[left++] = tmp->val;
          tmp = tmp -> right;
        }
        if(left == (n + 1) / 2 || right == (n - 3) / 2) break;
      }
      return arr[(n - 1) / 2];
    }

    Node* find(Node* cur, int key) {
      if(cur == nullptr) return nullptr;
      if(cur->val == key) return cur;
      if(cur->val > key) return find(cur->left, key);
      if(cur->val < key) return find(cur->right, key);
    }

    void leftPrintTree() {
      leftTraversal(this->root);
      std::ofstream fout("tst.out");

      for(Node* elem : elems) fout << elem->val << endl;
      elems.clear();
    }
};

int main() {
  Tree c;
  c.fillTree();
  c.deleteMedian();
  c.leftPrintTree();
}
