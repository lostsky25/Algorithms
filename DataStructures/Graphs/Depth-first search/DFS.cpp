#include <iostream>
#include <vector>

void dfs(int v, std::vector<std::vector<int>>& g, std::vector<int>& used) {
    used[v] = 1;
    
    for (auto x : g[v]) {
        if (used[x] == 0) {
            dfs(x, g, used);
        }
        else if (used[x] == 1) {
            std::cout << "Yes\n";
            exit(0);
        }
    }
}

int main() {

    int n, m; // n - кол-во вершин, m - кол-во ребер
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n + 1);
    std::vector<int> used(n + 1);

    for (int i = 0; i < m; ++i) {
        int v, u;
        std::cin >> v >> u;

        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        if (used[i] == 0) {
            dfs(i, graph, used);
        }
    }

    return 0;
}