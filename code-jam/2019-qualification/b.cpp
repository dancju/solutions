#include<iostream>

using namespace std;

string path;

int main() {
  int n_case;
  cin >> n_case;
  for (int i_case = 1; i_case <= n_case; i_case++) {
    cout << "Case #" << i_case << ": ";
    int n;
    cin >> n >> path;
    for (auto i : path)
      cout << (char)('S' + 'E' -i);
    cout << '\n';
  }
  return 0;
}
