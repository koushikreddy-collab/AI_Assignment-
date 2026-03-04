#include <stdio.h>

int visited[5][5];

void DFS(int x, int y) {
    if (x < 0 || y < 0 || x > 4 || y > 3 || visited[x][y])
        return;

    printf("(%d,%d)\n", x, y);
    visited[x][y] = 1;

    if (x == 2 || y == 2) {
        printf("Goal Reached!\n");
        return;
    }

    // Recursive calls
    DFS(4, y); // Fill A
    DFS(x, 3); // Fill B
    DFS(0, y); // Empty A
    DFS(x, 0); // Empty B

    int transfer;

    transfer = (x < (3 - y)) ? x : (3 - y);
    DFS(x - transfer, y + transfer);

    transfer = (y < (4 - x)) ? y : (4 - x);
    DFS(x + transfer, y - transfer);
}

int main() {
    DFS(0,0);
    return 0;
}
