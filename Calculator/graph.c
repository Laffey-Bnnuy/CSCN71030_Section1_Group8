#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#define N 9
double distance_2D(PP2D a, PP2D b) {
	return sqrt((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y));
}
double distance_3D(PP3D a, PP3D b) {
	return sqrt((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y) + (a->z - b->z) * (a->z - b->z));
}
void distance_2D_main() {
    printf("Enter point A(x,y): ");
    PP2D A= (PP2D)malloc(sizeof(P2D));
    PP2D B = (PP2D)malloc(sizeof(P2D));
    scanf_s("%lf%lf", &A->x, &A->y);
    printf("Enter point B(x,y): ");
    scanf_s("%lf%lf", &B->x, &B->y);

    while (getchar() != '\n');
    printf("2D: Distance between A and B is: %lf\n", distance_2D(A, B));
    
}
void distance_3D_main() {
    printf("Enter point A(x,y,z): ");
    PP3D A = (PP3D)malloc(sizeof(P3D));
    PP3D B = (PP3D)malloc(sizeof(P3D));
    scanf_s("%lf%lf%lf", &A->x, &A->y,&A->z);
    printf("Enter point B(x,y,z): ");
    scanf_s("%lf%lf%lf", &B->x, &B->y,&B->z);
    while (getchar() != '\n');

    printf("3D: Distance between A and B is: %lf", distance_3D(A, B));

}
void ArraySwap(int i, int j, PP2D array) {
    float tempx = array[i].x;
    float tempy = array[i].y;
    array[i].x = array[j].x;
    array[i].y = array[j].y;
    array[j].x = tempx;
    array[j].y = tempy;
   
}
void sorting_points_2D(PP2D array, int n) {
    
    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j <= n-1; j++) {
            if (array[i].x > array[j].x)
                ArraySwap(i, j, array);
            else if (array[i].x == array[j].x) {
                if (array[i].y > array[j].y)
                    ArraySwap(i, j, array);
            }
        }
    }
}

void distance_between_points(double** distances,PP2D array,int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            distances[i][j] = distance_2D(&array[i], &array[j]);
        }
    }
   
   /* for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", distances[i][j]);
        }
        printf("\n");
    }*/

}


void nearestNeighborTSP(double** distances, int* route, double* totalDistance,double n) {
    bool visited[N] = { false };
    int count = 1;
    route[1] = 0; // Starting from city 0
    visited[0] = true;
    *totalDistance = 0;

    for (int step = 1; step < n; step++) {
        int last = route[count];
        int nearest = -1;
        double minDist = LONG_MAX;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && distances[last][i] < minDist) {
                minDist = distances[last][i];
                nearest = i;
            }
        }
        route[++count] = nearest;
        visited[nearest] = true;
        *totalDistance += minDist;
    }

    *totalDistance += distances[route[count]][0]; // Return to start
    route[++count] = 0; 
    route[0] = count - 1; // Store the count of vertices visited
}

//int main() {
//    int distances[N][N] = {
//        {0, 2, 2, 5, 9, 3},
//        {2, 0, 4, 6, 7, 8},
//        {2, 4, 0, 8, 6, 3},
//        {5, 6, 8, 0, 4, 9},
//        {9, 7, 6, 4, 0, 10},
//        {3, 8, 3, 9, 10, 0}
//    };
//    int route[N + 2]; // +1 for total count, +1 for total distance
//    int totalDistance;
//
//    nearestNeighborTSP(distances, route, &totalDistance);
//    printf("Route: ");
//    for (int i = 1; i <= route[0]; i++) {
//        printf("%d ", route[i]);
//    }
//    printf("0");
//    printf("\nTotal Distance: %d\n", totalDistance);
//
//    return 0;
//}

double polygonArea(PP2D a, int n,int* route)
{
    // Initialize area
    double area = 0.0;
   /* for (int i = 0; i < n; i++) {
        printf("%lf %lf\n", a[i].x, a[i].y);
    }*/
     
   /* int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        area += (a[j].x + a[i].x) * (a[j].y - a[i].y);
        j = i;
    }*/

    int j = route[n];
    for (int i = 0; i < n; i++)
    {
        int temp = route[i + 1];
        area += (a[j].x + a[temp].x) * (a[j].y - a[temp].y);
        j = route[i+1];
    }
     //Return absolute value
    return abs(area / 2.0);
}

void point_area_perimeter() {
    int n;
    printf("Enter number of points: ");
    scanf_s("%d", &n);
    PP2D array_points_2D = (PP2D)malloc(sizeof(P2D) * n);
    for (int i = 0; i < n; i++) {
        scanf_s("%lf%lf", &array_points_2D[i].x, &array_points_2D[i].y);
    }
    sorting_points_2D(array_points_2D, n);
    while (getchar() != '\n');
    double** distance;
    distance = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        distance[i] = (double*)malloc(n * sizeof(distance[0]));
    }
    int* route = (int*)malloc((n + 2) * sizeof(int));
    distance_between_points(distance, array_points_2D, n);
    double perimeter = 0;
    nearestNeighborTSP(distance, route, &perimeter, n);
    free(distance);
    /*for (int i = 0; i < n ; i++) {
        printf("%lf %lf\n", array_points_2D[route[i+1]].x, array_points_2D[route[i + 1]].y);
    }*/
    printf("polygon perimeter: %lf\n", perimeter);
    printf("polygon area: %lf\n",polygonArea(array_points_2D, n,route));

}

