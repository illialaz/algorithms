#pragma comment(linker, "/STACK:335544320")
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// struct Node {
//   int val;
//   Node* right;
//   Node* left;
//   Node(): left(nullptr), right(nullptr), val(0) {}
//   Node(int num): left(nullptr), right(nullptr), val(num) {}
// };

class Tree {
  private:
    pair<int, pair<int, int> > * tree;

    void addChild(pair<int, pair<int, int> > & parent, int val, char whichChild, int numInArr) {
      if(whichChild == 'L') {
        parent.second.first = numInArr;
      }
      if(whichChild == 'R') {
        parent.second.second = numInArr;
      }
      tmpel.first = val;
      tmpel.second.first = -1;
      tmpel.second.second = -1;
      tree[numInArr] = tmpel;
    }

    void checkChild(pair<int, pair<int, int> > child, int min, int max) {
      if(isSearchTree && child.second.first != -1) checkChild(tree[child.second.first], min, child.first);
      if(!isSearchTree) return;

      if(child.first < min || child.first >= max) {
        isSearchTree = false;
        return;
      }
      
      if(isSearchTree && child.second.second != -1) checkChild(tree[child.second.second], child.first, max);
      if(!isSearchTree) return;
    }

  public:
    bool isSearchTree;
    pair<int, pair<int, int> > tmpel;
    Tree() : tree(nullptr), isSearchTree(true) {}

    void fillTree() {
      std::ios_base::sync_with_stdio(false);
      std::cin.tie(nullptr);
      freopen("bst.in", "r", stdin);
      freopen("bst.out", "w", stdout);
      int n;
      scanf("%d", &n);
      tree = new pair<int, pair<int, int> >[n];
      int p = 1;
      int m;
      double a = INT32_MAX + 1;
      int b = INT32_MAX;
      if(a > b) cout << true; 
      char c = '0';
      int numElems = 0;
      scanf("%d", &m);

      addChild(tree[0], m, c, numElems);
      numElems++;
      
      for(int i = 0; i < n - 1; i++) {
        scanf("%d %d %c", &m, &p, &c);
        addChild(tree[p - 1], m, c, numElems);
        numElems++;
      }
      checkChild(tree[0], INT32_MIN, INT32_MAX);
      if(isSearchTree) cout << "YES";
      else cout << "NO";
    }
};

int main() {
  Tree c;
  c.fillTree();
  return 0;
}
