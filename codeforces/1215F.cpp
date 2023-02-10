#include <cstdint>
#include <cstdio>
#include <stack>
#include <vector>

class digraph_t {
    std::vector<std::vector<uint32_t>> g;

public:
    digraph_t(size_t n_nodes)
        : g { n_nodes }
    {
    }
    const size_t n_nodes() const { return g.size(); }
    const std::vector<uint32_t>& operator[](size_t u) const { return g[u]; }
    void add_edge(size_t u, size_t v) { g[u].push_back(v); }
};

class scc_t {
    size_t count;
    std::vector<uint32_t> id;
    void tarjan(
        const digraph_t& g, size_t& stamp, std::vector<uint32_t>& dfn, std::vector<uint32_t>& low, std::stack<uint32_t>& s,
        std::vector<bool>& in_stack, size_t u)
    {
        dfn[u] = low[u] = ++stamp;
        s.push(u);
        in_stack[u] = 1;
        for (size_t v : g[u]) {
            if (!dfn[v]) { // 樹枝邊
                tarjan(g, stamp, dfn, low, s, in_stack, v);
                low[u] = std::min(low[u], low[v]);
            } else if (in_stack[v]) // 返祖邊
                low[u] = std::min(low[u], dfn[v]);
        }
        if (low[u] == dfn[u]) {
            for (size_t v = s.top(); v != u; in_stack[v] = 0, s.pop(), v = s.top())
                id[v] = count;
            in_stack[u] = 0;
            s.pop();
            id[u] = count;
            count++;
        }
    }

public:
    scc_t(const digraph_t& g)
        : count(0)
    {
        size_t n_nodes = g.n_nodes();
        size_t stamp = 0;
        std::vector<uint32_t> dfn(n_nodes), low(n_nodes);
        std::stack<uint32_t> s;
        std::vector<bool> in_stack(n_nodes, false);
        id.resize(n_nodes);
        for (size_t i = 0; i < n_nodes; i++)
            if (!dfn[i])
                tarjan(g, stamp, dfn, low, s, in_stack, i);
    }
    size_t n_components() const { return count; }
    size_t operator[](size_t x) const { return id[x]; }
};

class two_sat {
    size_t n_vars;
    digraph_t g;

public:
    two_sat(size_t n_vars)
        : n_vars(n_vars)
        , g(n_vars * 2)
    {
    }
    void add_implication(size_t u, bool bu, size_t v, bool bv)
    {
        g.add_edge(u * 2 ^ bu, v * 2 ^ bv);
        g.add_edge(v * 2 ^ bv ^ 1, u * 2 ^ bu ^ 1);
    }
    void add_or(size_t u, size_t v)
    {
        add_implication(u, false, v, true);
    }
    void add_xor(size_t u, size_t v)
    {
        add_implication(u, true, v, false);
    }
    std::vector<int32_t> solve(int32_t n_station) const
    {
        scc_t scc(g);
        std::vector<int32_t> res;
        for (int i = 0; i < n_vars * 2; i += 2)
            if (scc[i] == scc[i + 1])
                return {};
            else if (scc[i + 1] < scc[i])
                res.push_back(i >> 1);
        return res;
    }
};

int main()
{
    int32_t n_complain, n_station, n_freq, n_mutex;
    scanf("%d %d %d %d", &n_complain, &n_station, &n_freq, &n_mutex);
    two_sat s(n_station + n_freq);
    for (int i = 0; i < n_freq - 1; i++)
        s.add_implication(n_station + i, true, n_station + i + 1, true);
    for (int i = 0; i < n_complain; i++) {
        int32_t u, v;
        scanf("%d %d", &u, &v);
        s.add_or(u - 1, v - 1);
    }
    for (int i = 0; i < n_station; i++) {
        int32_t l, r;
        scanf("%d %d", &l, &r);
        l--;
        r--;
        if (l)
            s.add_implication(i, true, n_station + l - 1, false);
        s.add_implication(i, true, n_station + r, true);
    }
    for (int i = 0; i < n_mutex; i++) {
        int32_t u, v;
        scanf("%d %d", &u, &v);
        s.add_xor(u - 1, v - 1);
    }
    std::vector<int32_t> res = s.solve(n_station);
    if (res.empty()) {
        puts("-1");
        return 0;
    }
    std::vector<int32_t>::iterator it = lower_bound(res.begin(), res.end(), n_station);
    printf("%lu %d\n", it - res.begin(), *it - n_station + 1);
    for (std::vector<int32_t>::iterator i = res.begin(); i < it; i++)
        printf("%d ", *i + 1);
    puts("");
    return 0;
}
