#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>

using namespace std;

const int N = 1000;

struct triple {
    short first, second;
    string third;
    triple(short f, short s, string t) {
        first = f;
        second = s;
        third = t;
    }
};

int n0, n1, m0, m1, k0, k1;
short dfa0[N][26], dfa1[N][26];
bool a0[N], a1[N], s[N+1][N+1];

inline string bazinga() {
    queue<triple> q;
    s[1][1] = 1;
    q.push(triple(0, 0, ""));
    if(a0[0]^a1[0])
        return "";
    while(q.size()) {
        triple u = q.front();
        q.pop();
        for(int c = 0; c<26; c++) {
            int _0 = -1, _1 = -1;
            if(u.first!=-1)
                _0 = dfa0[u.first][c];
            if(u.second!=-1)
                _1 = dfa1[u.second][c];
            if(_0==-1 && _1==-1)
                continue;
            if(s[_0+1][_1+1]==0) {
                triple v = triple(_0, _1, u.third+(char)(c+'a'));
                if((_0!=-1&&a0[_0])^(_1!=-1&&a1[_1]))
                    return string(v.third);
                s[_0+1][_1+1] = 1;
                q.push(v);
            }
        }
    }
    return "0";
}

int main() {
    int n_case;
    scanf("%d", &n_case);
    for(int i_case = 1; i_case<=n_case; i_case++) {

        memset(a0, 0, sizeof a0);
        memset(dfa0, -1, sizeof dfa0);
        memset(a1, 0, sizeof a1);
        memset(dfa1, -1, sizeof dfa1);
        memset(s, 0, sizeof s);

        scanf("%d%d%d", &n0, &m0, &k0);
        for(int i = 0; i<k0; i++) {
            int _;
            scanf("%d", &_);
            a0[_] = 1;
        }
        for(int i = 0; i<m0; i++) {
            int _0, _1;
            char _;
            scanf("%d%d %c", &_0, &_1, &_);
            dfa0[_0][_-'a'] = _1;
        }

        scanf("%d%d%d", &n1, &m1, &k1);
        for(int i = 0; i<k1; i++) {
            int _;
            scanf("%d", &_);
            a1[_] = 1;
        }
        for(int i = 0; i<m1; i++) {
            int _0, _1;
            char _;
            scanf("%d%d %c", &_0, &_1, &_);
            dfa1[_0][_-'a'] = _1;
        }

        printf("Case #%d: %s\n", i_case, bazinga().c_str());

    }
    return 0;
}
