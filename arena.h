#pragma once
#include "material.h"
class arena : private material
{
private:
	bool vivo;
public:
	arena(bool alive) : vivo(alive), material(1, 1) {};
	~arena() {}
	void reaccionar(material current[WIDTH][HEIGHT], material update[WIDTH][HEIGHT], int x, int y) {
		if (vivo) {
			int neighbors_alive = num_neighbors(current, x, y);
			if ((neighbors_alive < 2 || neighbors_alive > 3))
				update[x][y] = material(0, 0);
			update[x][y] = current[x][y];
		}
		else
		{

		}
	}
};

