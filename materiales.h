#pragma once
#include "material.h"
class vivo : public material
{
public:
	vivo() : material(1, 1) {};
	~vivo() {}
	void reaccionar(material* current[WIDTH][HEIGHT], material* update[WIDTH][HEIGHT], int x, int y) {
		int neighbors_alive = num_neighbors(current, x, y);
		update[x][y] = ((neighbors_alive < 2 || neighbors_alive > 3)) ? new muerto() : current[x][y];
	}
};

class muerto : public material
{
public:
	muerto() : material(0, 0) {};
	~muerto() {}
	void reaccionar(material* current[WIDTH][HEIGHT], material* update[WIDTH][HEIGHT], int x, int y) {
		int neighbors_alive = num_neighbors(current, x, y);
		update[x][y] = ((neighbors_alive < 2 || neighbors_alive > 3)) ? new vivo() : current[x][y];
	}
};
