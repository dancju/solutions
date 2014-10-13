#include<iostream>
#include<queue>

using namespace std;

void main1() {
  string n;
  cin >> n;
  queue<char> q0, q1;
  for (char i : n) {
    if (i == '0') {
      q0.push('0');
      q1.push('0');
    } else if (i == '5') {
      q0.push('2');
      q1.push('3');
    } else {
      q0.push(i-1);
      q1.push('1');
    }
  }
  while (q0.front() == '0')
    q0.pop();
  for (; !q0.empty(); q0.pop())
    cout << q0.front();
  cout << ' ';
  for (; !q1.empty(); q1.pop())
    cout << q1.front();
}

int main() {
  int n_case;
  cin >> n_case;
  for (int i_case = 1; i_case <= n_case; i_case++) {
    cout << "Case #" << i_case << ": ";
    main1();
    cout << '\n';
  }
  return 0;
}
