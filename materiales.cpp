#include "materiales.h"

int material::num_neighbors(material* content[WIDTH][HEIGHT], int x, int y) {
    int num = 0, pos_x, pos_y;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            pos_x = (x + i < 0) ? WIDTH - 1 : (x + i) % WIDTH;
            pos_y = (y + j < 0) ? HEIGHT - 1 : (y + j) % HEIGHT;

            material* material_alive = dynamic_cast<alive*> (content[pos_x][pos_y]);

            if (pos_x != x || pos_y != y)
                if (material_alive) num++;
        }
    }
    return num;
}

void alive::reaccionar(material* current[WIDTH][HEIGHT], material* update[WIDTH][HEIGHT], int x, int y) {
    int neighbors_alive = num_neighbors(current, x, y);

    update[x][y] = ((neighbors_alive < 2) || (neighbors_alive > 3)) ? new death() : current[x][y];
}

void death::reaccionar(material* current[WIDTH][HEIGHT], material* update[WIDTH][HEIGHT], int x, int y) {
    int neighbors_alive = num_neighbors(current, x, y);

    update[x][y] = (neighbors_alive == 3) ? new alive() : current[x][y];
}
