#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct State {
    int x, y;
};

struct State queue[MAX];
int front = 0, rear = 0;

int visited[5][5];

void enqueue(struct State s) {
    queue[rear++] = s;
}

struct State dequeue() {
    return queue[front++];
}

int isGoal(struct State s) {
    return (s.x == 2 || s.y == 2);
}

void BFS() {
    struct State start = {0,0};
    enqueue(start);
    visited[0][0] = 1;

    while(front < rear) {
        struct State current = dequeue();
        printf("(%d,%d)\n", current.x, current.y);

        if(isGoal(current)) {
            printf("Goal Reached!\n");
            return;
        }

        struct State next;

        // Fill A
        next.x = 4; next.y = current.y;
        if(!visited[next.x][next.y]) {
            enqueue(next);
            visited[next.x][next.y] = 1;
        }

        // Fill B
        next.x = current.x; next.y = 3;
        if(!visited[next.x][next.y]) {
            enqueue(next);
            visited[next.x][next.y] = 1;
        }

        // Empty A
        next.x = 0; next.y = current.y;
        if(!visited[next.x][next.y]) {
            enqueue(next);
            visited[next.x][next.y] = 1;
        }

        // Empty B
        next.x = current.x; next.y = 0;
        if(!visited[next.x][next.y]) {
            enqueue(next);
            visited[next.x][next.y] = 1;
        }

        // Pour A to B
        int transfer = (current.x < (3 - current.y)) ? current.x : (3 - current.y);
        next.x = current.x - transfer;
        next.y = current.y + transfer;
        if(!visited[next.x][next.y]) {
            enqueue(next);
            visited[next.x][next.y] = 1;
        }

        // Pour B to A
        transfer = (current.y < (4 - current.x)) ? current.y : (4 - current.x);
        next.x = current.x + transfer;
        next.y = current.y - transfer;
        if(!visited[next.x][next.y]) {
            enqueue(next);
            visited[next.x][next.y] = 1;
        }
    }
}

int main() {
    BFS();
    return 0;
}
