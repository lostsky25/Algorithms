#include <iostream>
#include <vector>

int count = 0;
std::vector<std::vector<int>> con;

void dfs(int v, std::vector<std::vector<int>> graph, std::vector<int> used) {
    used[v] = 1;
    con[count].push_back(v);

    for (auto vertex : graph[v]) {
        if (used[vertex] == 0) {
            dfs(vertex, graph, used);
        }
    }
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n + 1);
    std::vector<int> used(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int v, u;
        std::cin >> v >> u;

        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
    {
        if (used[i] == 0) {
            con.push_back(std::vector<int>{});
            dfs(i, graph, used);
            count++;
        }
    }

    std::cout << count << std::endl;
    for (int i = 0; i < con.size(); i++)
    {
        std::cout << con[i].size() << std::endl;
        for (int j = 0; j < con[i].size(); j++)
            std::cout << con[i][j] << ' ';
        std::cout << std::endl;
    }

    return 0;
}