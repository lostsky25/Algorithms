#include <iostream>
#include <vector>

struct Node
{
    int v, to, w;
};

int main() {

    int vertexCount, edgeCount;
    std::cin >> vertexCount >> edgeCount;

    std::vector<std::pair<int, int>> edges(edgeCount);

    for (auto &[a, b] : edges) {
        std::cin >> a >> b;
        // Если нумерация с 1
        --a;
        --b;
    }

    return 0;
}