#include <iostream>
#include <stack>

using namespace std;

bool isCorrect(char a, char b) {
  if(a == '{' && b == '}') return true;
  if(a == '(' && b == ')') return true;
  if(a == '[' && b == ']') return true;
  return false;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  stack<char> a;
  string str;
  cin >> str;
  char check;
  for(int i = 0; i < str.length(); i++) {
    if(str[i] == '{' || str[i] == '[' || str[i] == '(') a.push(str[i]);
    else {
      if(a.size() ==  0) {
        cout << "NO\n";
        cout << i;
        return 0;
      }
      check = a.top();
      if(isCorrect(check, str[i])) {
        a.pop();
      }
      else {
        cout << "NO\n";
        cout << i;
        return 0;
      }
    }
  }
  if(!a.empty()) {
    cout << "NO\n";
    cout << str.length();
    return 0;
  }
  cout << "YES";
}
