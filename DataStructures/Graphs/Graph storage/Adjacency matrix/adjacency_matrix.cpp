#include <iostream>
#include <vector>

int main() {

    int vertexCount, edgeCount;
    std::cin >> vertexCount >> edgeCount;
    
    std::vector<std::vector<int>> graph(vertexCount, std::vector<int>(vertexCount));

    for (int i = 0; i < edgeCount; i++) {
        int a, b;
        std::cin >> a >> b;

        // Если с 1
        --a;
        --b;

        // Если ориентированный
        graph[a][b] = 1;

        /* Если неориентированный
            graph[a][b] = 1;
            graph[b][a] = 1;
        */
    }

    return 0;
}