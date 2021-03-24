/*input.txt
9 13
2 3 9 2 5 1 3 7 10
2 1 3 4 3 10 6 6 1 7 10 10 10
*/
#include<iostream>
#include <string.h>
using namespace std;

class Node {
  public:
  int key;
  int times;
  Node *left;
  Node *right;
  int height;
};

int height(Node *N) {
  if(N == NULL)
    return 0;
  return N->height;
}

int max(int a, int b) {
  return a > b ? a : b;
}

Node* newNode(int key, int times){
  Node* node = new Node();
  node->key = key;
  node->times = times;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return node;
}

Node *rightRotate(Node *y) {
  Node *x = y->left;
  Node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

Node *leftRotate(Node *x) {
  Node *y = x->right;
  Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

int getBalance(Node *N) {
  if(N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}

Node* insert(Node* node, int key) {
  if(node == NULL)
    return newNode(key, 1);

  if(key < node->key)
    node->left = insert(node->left, key);
  else if(key > node->key)
    node->right = insert(node->right, key);
  else {
    node->times += 1;
    return node;
  }

  node->height = 1 + max(height(node->left), height(node->right));

  int balance = getBalance(node);

  if(balance > 1 && key < node->left->key)
    return rightRotate(node);

  if(balance < -1 && key > node->right->key)
    return leftRotate(node);

  if(balance > 1 && key > node->left->key) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  if(balance < -1 && key < node->right->key) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

int find(Node *root, int key) {
  if(root != NULL) {
    if(root->key == key) return root->times;
    else if(root->key > key) return find(root->left, key);
    else if(root->key < key) return find(root->right, key);
  }
  return INT32_MAX;
}

void preOrder(Node *root)
{
    if(root != NULL)
    {
        cout << root->key << " " << root->times << " - ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void findPrime(bool* & prime, int len) {
  memset(prime, true, len);
  prime[0] = prime[1] = false;
  for (int i = 2; i < len; ++i)
    if (prime[i])
      if (i * 1ll * i < len)
        for (int j=i*i; j < len; j+=i)
          prime[j] = false;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n = 0;
  int m = 0;
  cin >> n >> m;

  int* A = new int[n];
  int* B = new int[m];

  // AVL Tree
  Node *root = NULL;
  int max = INT32_MIN;

  for(int i = 0; i < n; i++) {
    cin >> A[i];
    max = max > A[i] ? max : A[i];
  }

  bool* prime = new bool[max + 1];

  findPrime(prime, max + 1);

  for(int i = 0; i < m; i++) {
    cin >> B[i];
    root = insert(root, B[i]);
  }

  int k = n;
  for(int i = 0; i < n; i++) {
    int num = find(root, A[i]);
    if(num != INT32_MAX && prime[num]) {
      A[i] = INT32_MIN;
      k--;
    }
  }

  int* C = new int[k];

  int l = 0;
  for(int i = 0; i < n; i++) {
    if(A[i] != INT32_MIN) C[l++] = A[i];
  }

  for(int i = 0; i < k; i++) cout << C[i] << " ";
  cout << "\n";
  return 0;
}
