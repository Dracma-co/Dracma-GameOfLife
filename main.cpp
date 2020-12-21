#include <iostream>
#define MAX_INSTRUCTIONS 10
#define MAX_DISPLAY 100
#define WIDTH 50
#define HEIGHT 50
#define MAX_MATERIAL 10
#define ALIVE 1
#define DEATH 0

typedef struct material {
    int state;
    void (*instruction[MAX_INSTRUCTIONS]) (struct material content[WIDTH][HEIGHT], struct material list[MAX_MATERIAL], int x, int y);
    int num_instructions;
} material_t;

void initialization (material_t content[WIDTH][HEIGHT], material_t list_material[MAX_MATERIAL]) {
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            content[i][j] = list_material[DEATH];
}

void paint(material_t content[WIDTH][HEIGHT]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++)
            (content[i][j].state == 0) ? printf("_|") : printf("0|");
        printf("\n");
    }
    printf("\n");
}

void take_input(material_t content[WIDTH][HEIGHT], material_t list_material[MAX_MATERIAL]) {
    content[25][10] = list_material[ALIVE];
    content[26][10] = list_material[ALIVE];
    content[27][10] = list_material[ALIVE];
    content[28][10] = list_material[ALIVE];
    content[29][10] = list_material[ALIVE];
}

int num_neighbors (material_t content[WIDTH][HEIGHT], int x, int y) {
    int num = 0;
    int pos_x, pos_y;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {

            pos_x = (x + i)%WIDTH;
            pos_y = (y + j)%HEIGHT;

            if (content[pos_x][pos_y].state == ALIVE)
                num++;
        }
    }
    return num;
}

void instruction_alive (material_t content[WIDTH][HEIGHT], material_t list_material[MAX_MATERIAL], int x, int y) {
    int neighbors_alive = num_neighbors(content, x, y);

    if (neighbors_alive < 2 || neighbors_alive > 3)
        content[x][y] = list_material[DEATH];
}

void instruction_death (material_t content[WIDTH][HEIGHT], material_t list_material[MAX_MATERIAL], int x, int y) {
    int neighbors_alive = num_neighbors(content, x, y);

    if (neighbors_alive == 3)
        content[x][y] = list_material[ALIVE];
}

int main(int argc, char* argv[]) {

    material_t content[WIDTH][HEIGHT];
    bool game_state = true;
    material_t list_material[MAX_MATERIAL];

    material_t death;
    death.state = DEATH;
    death.instruction[0] = instruction_death;
    death.num_instructions = 1;

    material_t alive;
    alive.state = ALIVE;
    alive.instruction[0] = instruction_alive;
    alive.num_instructions = 1;

    list_material[DEATH] = death;
    list_material[ALIVE] = alive;

    initialization(content, list_material);
    take_input(content, list_material);

    paint(content);
    while (game_state) {

        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                for (int k = 0; k < content[i][j].num_instructions; k++) {
                    content[i][j].instruction[k](content, list_material, i, j);
                }
            }
        }

        paint(content);
        game_state = false;
    }

    return 0;
}
