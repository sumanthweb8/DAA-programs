#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 100
#define INF INT_MAX

// Structure to represent a road between cities
struct Road {
    int from, to, distance;
};

// Function to find the shortest paths using Bellman-Ford algorithm
void bellmanFord(int source, int numCities, int numRoads, struct Road roads[], int distances[]) {
    for (int i = 1; i <= numCities; i++) {
        distances[i] = INF;
    }
    distances[source] = 0;

    for (int i = 1; i <= numCities - 1; i++) {
        for (int j = 0; j < numRoads; j++) {
            int u = roads[j].from;
            int v = roads[j].to;
            int weight = roads[j].distance;
            if (distances[u] != INF && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
            }
        }
    }
}

int main() {
    int numCities, numRoads, source;
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);

    printf("Enter the number of roads: ");
    scanf("%d", &numRoads);

    struct Road roads[MAX_CITIES];
    printf("Enter the details of each road:\n");
    for (int i = 0; i < numRoads; i++) {
        scanf("%d %d %d", &roads[i].from, &roads[i].to, &roads[i].distance);
    }

    printf("Enter the source city: ");
    scanf("%d", &source);

    int distances[MAX_CITIES];
    bellmanFord(source, numCities, numRoads, roads, distances);

    printf("Shortest distances from city %d to all other cities:\n", source);
    for (int i = 1; i <= numCities; i++) {
        printf("City %d: ", i);
        if (distances[i] == INF) {
            printf("Not reachable\n");
        } else {
            printf("%d\n", distances[i]);
        }
    }

    return 0;
}
