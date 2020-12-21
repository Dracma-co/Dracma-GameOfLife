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



int main(int argc, char* argv[]) {
    TakeInput();
    paint();
    return 0;
}
