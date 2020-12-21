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

}



int main(int argc, char* argv[]) {
    TakeInput();
    paint();
    return 0;
}
