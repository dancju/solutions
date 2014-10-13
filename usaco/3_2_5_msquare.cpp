/*
ID: danny_c1
PROG: msquare
LANG: C++
*/
#include <array>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

typedef array<uint8_t, 8> state;
size_t state_hash(const state &a) {
  const static uint16_t FAC[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
  size_t res = 0;
  for (int i = 0; i < 8; ++i) {
    int t = 0;
    for (int j = i + 1; j < 8; ++j)
      if (a[i] > a[j])
        ++t;
    res += t * FAC[8 - 1 - i];
  }
  return res + 1;
}
const state INIT_STATE{1, 2, 3, 4, 5, 6, 7, 8};
const uint16_t INIT_HASH = state_hash(INIT_STATE);
state transform(int oid, const state &s) {
  const static state OPERATIONS[] = {
      {7, 6, 5, 4, 3, 2, 1, 0},
      {3, 0, 1, 2, 5, 6, 7, 4},
      {0, 6, 1, 3, 4, 2, 5, 7}
  };
  state t;
  for (int i = 0; i < 8; i++)
    t[i] = s[OPERATIONS[oid][i]];
  return t;
}

int main() {
  freopen("msquare.in", "r", stdin);
  freopen("msquare.out", "w", stdout);
  /* input */
  state target_state;
  for (int i = 0; i < 8; i++) {
    cin >> target_state[i];
    target_state[i] -= '0';
  }
  /* search */
  array<uint8_t, 40321> oper, rank;
  array<uint16_t, 40321> prev;
  queue<state> q;
  memset(rank.data(), -1, rank.size() * sizeof(uint8_t));
  rank[state_hash(INIT_STATE)] = 0;
  q.push(INIT_STATE);
  while (!q.empty()) {
    state u_state = q.front();
    q.pop();
    uint16_t u_hash = state_hash(u_state);
    for (int i = 0; i < 3; i++) {
      state v_state = transform(i, u_state);
      uint16_t v_hash = state_hash(v_state);
      if (rank[v_hash] > rank[u_hash] + 1) {
        rank[v_hash] = rank[u_hash] + 1;
        oper[v_hash] = i;
        prev[v_hash] = u_hash;
        q.push(v_state);
      }
    }
  }
  /* output */
  vector<uint8_t> res;
  uint16_t target_hash = state_hash(target_state);
  cout << (int)rank[target_hash] << '\n';
  for (uint16_t i = target_hash; i != INIT_HASH; i = prev[i])
    res.push_back(oper[i]);
  for (auto i = res.rbegin(); i != res.rend(); i++)
    cout << char('A' + *i);
  cout << '\n';
  return 0;
}