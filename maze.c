#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define WIDTH 10
#define HEIGHT 10
#define INF INT_MAX

typedef struct {
    int x, y;
} Point;


int maze[HEIGHT][WIDTH] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 1, 0, 0, 0, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

Point start = {1, 1};
Point goal = {8, 8};


Point directions[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};


int is_valid(Point p) {
    return p.x >= 0 && p.x < WIDTH && p.y >= 0 && p.y < HEIGHT && maze[p.y][p.x] == 0;
}


void print_maze() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == start.y && j == start.x) {
                printf("S ");
            } else if (i == goal.y && j == goal.x) {
                printf("G ");
            } else if (maze[i][j] == 0) {
                printf("0 ");
            } else if (maze[i][j] == 1) {
                printf("1 ");
            } else if (maze[i][j] == 4) {
                printf(". ");
            }
        }
        printf("\n");
    }
}

// Depth-First Search (DFS)
int dfs(Point pos) {
    if (pos.x == goal.x && pos.y == goal.y) {
        maze[pos.y][pos.x] = 4;
        return 1;
    }
    maze[pos.y][pos.x] = 4;

    for (int i = 0; i < 4; i++) {
        Point next = {pos.x + directions[i].x, pos.y + directions[i].y};
        if (is_valid(next)) {
            if (dfs(next)) return 1;
        }
    }
    maze[pos.y][pos.x] = 0; 
    return 0;
}

// Breadth-First Search (BFS)
typedef struct {
    Point points[WIDTH * HEIGHT];
    int front, rear;
} Queue;

Queue create_queue() {
    Queue q = { .front = 0, .rear = 0 };
    return q;
}

void enqueue(Queue *q, Point p) {
    q->points[q->rear++] = p;
}

Point dequeue(Queue *q) {
    return q->points[q->front++];
}

int is_empty(Queue *q) {
    return q->front == q->rear;
}

int bfs() {
    Queue queue = create_queue();
    enqueue(&queue, start);
    maze[start.y][start.x] = 4;

    while (!is_empty(&queue)) {
        Point pos = dequeue(&queue);
        if (pos.x == goal.x && pos.y == goal.y) return 1;

        for (int i = 0; i < 4; i++) {
            Point next = {pos.x + directions[i].x, pos.y + directions[i].y};
            if (is_valid(next)) {
                maze[next.y][next.x] = 4;
                enqueue(&queue, next);
            }
        }
    }
    return 0;
}

// Dijkstra's Algorithm
typedef struct {
    Point point;
    int dist;
} Node;

Point parent[HEIGHT][WIDTH];

int dijkstra() {
    int dist[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            dist[i][j] = INF;
            parent[i][j] = (Point){-1, -1};
        }
    }
    dist[start.y][start.x] = 0;

    Node pq[WIDTH * HEIGHT];
    int pq_size = 0;

    pq[pq_size++] = (Node){start, 0};

    while (pq_size > 0) {
        int min_index = 0;
        for (int i = 1; i < pq_size; i++) {
            if (pq[i].dist < pq[min_index].dist) {
                min_index = i;
            }
        }

        Node current = pq[min_index];
        Point pos = current.point;

        for (int i = min_index; i < pq_size - 1; i++) {
            pq[i] = pq[i + 1];
        }
        pq_size--;

        if (pos.x == goal.x && pos.y == goal.y) {
            Point p = goal;
            while (p.x != -1 && p.y != -1) {
                maze[p.y][p.x] = 4;
                p = parent[p.y][p.x];
            }
            return 1;
        }

        for (int i = 0; i < 4; i++) {
            Point next = {pos.x + directions[i].x, pos.y + directions[i].y};
            if (is_valid(next)) {
                int new_dist = dist[pos.y][pos.x] + 1;
                if (new_dist < dist[next.y][next.x]) {
                    dist[next.y][next.x] = new_dist;
                    parent[next.y][next.x] = pos;
                    pq[pq_size++] = (Node){next, new_dist};
                }
            }
        }
    }
    return 0;
}

// A* Algorithm
int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int a_star() {
    int dist[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            dist[i][j] = INF;
            parent[i][j] = (Point){-1, -1};
        }
    }
    dist[start.y][start.x] = 0;

    Node pq[WIDTH * HEIGHT];
    int pq_size = 0;

    pq[pq_size++] = (Node){start, 0};

    while (pq_size > 0) {
        int min_index = 0;
        for (int i = 1; i < pq_size; i++) {
            if (pq[i].dist < pq[min_index].dist) {
                min_index = i;
            }
        }

        Node current = pq[min_index];
        Point pos = current.point;

        for (int i = min_index; i < pq_size - 1; i++) {
            pq[i] = pq[i + 1];
        }
        pq_size--;

        if (pos.x == goal.x && pos.y == goal.y) {
            Point p = goal;
            while (p.x != -1 && p.y != -1) {
                maze[p.y][p.x] = 4;
                p = parent[p.y][p.x];
            }
            return 1;
        }

        for (int i = 0; i < 4; i++) {
            Point next = {pos.x + directions[i].x, pos.y + directions[i].y};
            if (is_valid(next)) {
                int new_dist = dist[pos.y][pos.x] + 1 + heuristic(next, goal);
                if (new_dist < dist[next.y][next.x]) {
                    dist[next.y][next.x] = new_dist;
                    parent[next.y][next.x] = pos;
                    pq[pq_size++] = (Node){next, new_dist};
                }
            }
        }
    }
    return 0;
}

int main() {
    printf("Maze:\n");
    print_maze();

    printf("\nChoose algorithm:\n");
    printf("1. Depth-First Search (DFS)\n");
    printf("2. Breadth-First Search (BFS)\n");
    printf("3. Dijkstra's Algorithm\n");
    printf("4. A* Algorithm\n");
    int choice;
    scanf("%d", &choice);

    int found = 0;
    switch (choice) {
        case 1: found = dfs(start); break;
        case 2: found = bfs(); break;
        case 3: found = dijkstra(); break;
        case 4: found = a_star(); break;
        default: printf("Invalid choice!\n"); return 1;
    }

    if (found) {
        printf("\nPath found:\n");
    } else {
        printf("\nNo path found.\n");
    }
    print_maze();
    return 0;
}
