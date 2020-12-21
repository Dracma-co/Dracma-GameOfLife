#include <iostream>
#define MAX_INSTRUCCIONES 10
#define MAX_TABLERO 100

using namespace std;

typedef struct material {
    int estado;
    void (*instruccion[MAX_INSTRUCCIONES]) (struct material[MAX_TABLERO][MAX_TABLERO], int x, int y);
} material_t;

int main(int argc, char* argv[]) {

    return 0;
}
