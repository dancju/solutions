#include<algorithm>
#include<iostream>
#include<set>
using namespace std;

int decimal(int *l, int *r) {
    int ans = 0;
    for (int *i = l; i < r; i++) {
        ans *= 10;
        ans += *i;
    }
    return ans;
}

int main() {
    int l[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    set<int> s;
    do {
        for (int *i = l+1; i<l+9; i++)
            for (int *j = i+1; j < l+9; j++) {
                int a = decimal(l, i), b = decimal(i, j), c = decimal(j, l+9);
                if (a*b == c)
                    s.insert(c);
            }
    } while (next_permutation(l, l+9));
    int ans = 0;
    for (set<int>::iterator i = s.begin(); i != s.end(); i++)
        ans += *i;
    cout << ans << endl;
    return 0;
}
