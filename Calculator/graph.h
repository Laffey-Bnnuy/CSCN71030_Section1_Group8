#pragma once
typedef struct p2d {
	double x, y;
}*PP2D,P2D;

typedef struct p3d {
	double x, y,z;
}*PP3D, P3D;

double distance_2D(PP2D,PP2D);
double distance_3D(PP3D,PP3D);

void point_area_perimeter();
void distance_3D_main();
void distance_2D_main();