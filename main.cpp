#include <iostream>
#include <unistd.h>

#define MAX_INSTRUCTIONS 10
#define MAX_MATERIAL 10
#define WIDTH 50
#define HEIGHT 50

#define ALIVE 1
#define DEATH 0

typedef struct material {
    int state;
    void (*instruction[MAX_INSTRUCTIONS]) (struct material current[WIDTH][HEIGHT], struct material update[WIDTH][HEIGHT], struct material list[MAX_MATERIAL], int x, int y);
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
    content[11][10] = list_material[ALIVE];
    content[12][11] = list_material[ALIVE];
    content[10][12] = list_material[ALIVE];
    content[11][12] = list_material[ALIVE];
    content[12][12] = list_material[ALIVE];
}

int num_neighbors (material_t content[WIDTH][HEIGHT], int x, int y) {
    int num = 0, pos_x, pos_y;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {

            pos_x = (x + i < 0) ? WIDTH - 1 : (x + i)%WIDTH;
            pos_y = (y + j < 0) ? HEIGHT - 1 : (y + j)%HEIGHT;

            if (pos_x != x || pos_y != y)
                if (content[pos_x][pos_y].state == ALIVE) num++;
        }
    }
    return num;
}

void instruction_alive (material_t content_now[WIDTH][HEIGHT], material_t content_update[WIDTH][HEIGHT], material_t list_material[MAX_MATERIAL], int x, int y) {
    int neighbors_alive = num_neighbors(content_now, x, y);

    content_update[x][y] = (neighbors_alive < 2 || neighbors_alive > 3) ? list_material[DEATH] : content_now[x][y];
}

void instruction_death (material_t content_now[WIDTH][HEIGHT], material_t content_update[WIDTH][HEIGHT], material_t list_material[MAX_MATERIAL], int x, int y) {
    int neighbors_alive = num_neighbors(content_now, x, y);

    content_update[x][y] = (neighbors_alive == 3) ? list_material[ALIVE] : content_now[x][y];
}

void copy_content (material_t old_content[WIDTH][HEIGHT], material_t new_content[WIDTH][HEIGHT]) {
    for (int i = 0; i < WIDTH; i++)
        for (int j = 0; j < HEIGHT; j++)
            old_content[i][j] = new_content[i][j];
}

void make_material_list(material_t list_material[]) {

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
}

int main(int argc, char* argv[]) {

    material_t content_now[WIDTH][HEIGHT];
    material_t content_update[WIDTH][HEIGHT];
    material_t list_material[MAX_MATERIAL];

    bool game_state = true;

    make_material_list(list_material);
    initialization(content_now, list_material);
    take_input(content_now, list_material);

    paint(content_now);
    while (game_state) {
        sleep(1);
        for (int i = 0; i < WIDTH; i++) {
            for (int j = 0; j < HEIGHT; j++) {
                for (int k = 0; k < content_now[i][j].num_instructions; k++) {
                    content_now[i][j].instruction[k](content_now, content_update, list_material, i, j);
                }
            }
        }
        copy_content(content_now, content_update);
        system("clear");
        paint(content_now);
    }

    return 0;
}
