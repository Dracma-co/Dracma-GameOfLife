#include <iostream>
#define MAX_INSTRUCTIONS 10
#define MAX_DISPLAY 100
#define WIDTH 50
#define HEIGHT 50
#define MAX_MATERIAL 10
#define ALIVE 1
#define DEATH 0


void paint() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (content[i][j] == 0)
                printf("_|");
            else
                printf("0|");
        }
        printf("\n");
    }
}

void TakeInput() {
    content[25][10] = 1;
    content[26][10] = 1;
    content[27][10] = 1;
    content[28][10] = 1;
    content[29][10] = 1;
}

bool play() {
    return false;
}


typedef struct material {
    int estado;
    void (*instruccion[MAX_INSTRUCCIONES]) (struct material[MAX_TABLERO][MAX_TABLERO], int x, int y);
} material_t;

int main(int argc, char* argv[]) {
    TakeInput();
    paint();
    return 0;
}
