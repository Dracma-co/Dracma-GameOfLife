#include <stdio.h>
#include <stdlib.h>
#include <windows.h>  // notice this! you need it!

#define MAX_INSTRUCCIONES 10
#define WIDTH 50
#define HEIGHT 50

typedef struct material {
    int estado;
    void (*instruccion[MAX_INSTRUCCIONES]) (int display[HEIGHT][WIDTH], int newy[HEIGHT][WIDTH], int x, int y);
} material_t;

void paint(int content[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (content[i][j] == 0)
                printf("  ");
            else
                printf("||");
        }
        printf("\n");
    }
}

void instruccion1(int display[HEIGHT][WIDTH], int newy[HEIGHT][WIDTH], int i, int j) {
    int nghb = display[((i % HEIGHT) + HEIGHT) % HEIGHT][(((j + 1) % WIDTH) + WIDTH) % WIDTH] + display[((i % HEIGHT) + HEIGHT) % HEIGHT][(((j - 1) % WIDTH) + WIDTH) % WIDTH];
    nghb += display[(((i + 1) % HEIGHT) + HEIGHT) % HEIGHT][(((j + 1) % WIDTH) + WIDTH) % WIDTH] + display[(((i + 1) % HEIGHT) + HEIGHT) % HEIGHT][(((j - 1) % WIDTH) + WIDTH) % WIDTH];
    nghb += display[(((i - 1) % HEIGHT) + HEIGHT) % HEIGHT][(((j + 1) % WIDTH) + WIDTH) % WIDTH] + display[(((i - 1) % HEIGHT) + HEIGHT) % HEIGHT][(((j - 1) % WIDTH) + WIDTH) % WIDTH];
    nghb += display[(((i - 1) % HEIGHT) + HEIGHT) % HEIGHT][(((j) % WIDTH) + WIDTH) % WIDTH] + display[(((i + 1) % HEIGHT) + HEIGHT) % HEIGHT][(((j) % WIDTH) + WIDTH) % WIDTH];
    if (display[i][j] == 0 && nghb == 3)
        newy[i][j] = 1; //it is alive
    if (display[i][j] == 1 && (nghb > 3 || nghb < 2))
        newy[i][j] = 0; //it is dead
}

void take_input(int content[HEIGHT][WIDTH]) {
    content[25][10] = 1;
    content[26][10] = 1;
    content[27][10] = 1;
    content[35][11] = 1;
    content[34][11] = 1;
    content[23][34] = 1;
    content[34][12] = 1;

    content[11][12] = 1;
    content[12][14] = 1;
    content[13][12] = 1;
}

void inicializar(int display[HEIGHT][WIDTH], material content[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
        {
            content[i][j].estado = 0;
            content[i][j].instruccion[0] = instruccion1;

            display[i][j] = 0;
        }
    take_input(display);
    paint(display);
}

//bool play() {
//    return false;
//}

int main() {
    material actual[HEIGHT][WIDTH];
    int display[HEIGHT][WIDTH];
    inicializar(display, actual);
    while (true) {
        Sleep(150);
        int newState[HEIGHT][WIDTH];
        for (int i = 0; i < HEIGHT; i++)
            for (int j = 0; j < WIDTH; j++)
            {
                newState[i][j] = display[i][j];
                actual[i][j].instruccion[0](display, newState, i, j);
            }
        for (int i = 0; i < HEIGHT; i++)
            for (int j = 0; j < WIDTH; j++)
            {
                display[i][j] = newState[i][j];
            }
        system("cls");
        paint(display);
    }
    return 0;
}
