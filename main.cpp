#include <iostream>
#define MAX_INSTRUCCIONES 10
#define MAX_TABLERO 100
#define WIDTH 50
#define HEIGHT 50

typedef struct material {
    int estado;
    void (*instruccion[MAX_INSTRUCCIONES]) (struct material[MAX_TABLERO][MAX_TABLERO], int x, int y);
} material_t;

void paint(material content[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (content[i][j].estado == 0)
                printf("  ");
            else
                printf("||");
        }
        printf("\n");
    }
}

void take_input(int content[HEIGHT][WIDTH]) {
    content[25][10] = 1;
    content[26][10] = 1;
    content[27][10] = 1;
    content[28][10] = 1;
    content[29][10] = 1;
    content[27][8] = 1;
    content[27][9] = 1;
    content[27][11] = 1;
    content[27][12] = 1;
}

void inicializar(material content[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            content[i][j].estado = 0;
    take_input(content);
    paint(content);
}

bool play() {
    return false;
}

int main(int argc, char* argv[]) {
    material content[WIDTH][HEIGHT];
    inicializar(content);
    return 0;
}
