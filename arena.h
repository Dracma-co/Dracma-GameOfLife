#pragma once
#pragma once
#include "material.h"
class arena : private material
{
private:
	bool vivo;
public:
	arena(bool alive) : vivo(alive) {};
	~arena() {}
	void reaccionar(int x, int y) {
		if (vivo) {
			int neighbors_alive = num_neighbors(current, x, y);
			if ((neighbors_alive < 2 || neighbors_alive > 3))
				update
				update[x][y] = ? : current[x][y];
		}
	}
};

