#include <iostream>
#include <vector>

int main() {
    int vertexCount, edgeCount;
    std::cin >> vertexCount >> edgeCount;

    std::vector<std::vector<int>> graph(vertexCount);

    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        std::cin >> a >> b;
        --a;
        --b;

        // Если ориентированный
        graph[a].push_back(b);

        // Если неориентированный
        /*
            graph[a].push_back(b);
            graph[b].push_back(a);
        */

    }

    return 0;
}