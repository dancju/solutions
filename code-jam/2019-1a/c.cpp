#include <iostream>
#include <map>

using namespace std;

struct tire {
  struct node {
    map<char, node *> children;
    int size;
    node() : size(0) {}
    template <class I> void insert(I begin, I end) {
      size++;
      if (begin == end)
        return;
      if (children.find(*begin) == children.end())
        children[*begin] = new node();
      children[*begin]->insert(begin + 1, end);
    }
    size_t bazinga(bool is_root) const {
      if (size <= 1)
        return 0;
      size_t res = 0;
      for (map<char, node *>::const_iterator i = children.cbegin();
           i != children.cend(); i++)
        res += i->second->bazinga(false);
      res += (!is_root) * 2 * (size - res >= 2);
      return res;
    }
  } root;
  template <class I> void insert(I begin, I end) { root.insert(begin, end); }
  size_t bazinga() { return root.bazinga(true); }
};

void main0() {
  int n;
  tire t;
  cin >> n;
  while (n--) {
    string w;
    cin >> w;
    t.insert(w.rbegin(), w.rend());
  }
  cout << t.bazinga() << '\n';
}

int main() {
  int n_case;
  cin >> n_case;
  for (int i_case = 1; i_case <= n_case; i_case++) {
    cout << "Case #" << i_case << ": ";
    main0();
  }
  return 0;
}
