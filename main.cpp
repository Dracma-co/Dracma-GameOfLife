#include <stdio.h>
#include <iostream>
#include<windows.h>
#include "materiales.h"

using namespace std;

void initialization(material* content[WIDTH][HEIGHT]) {
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            content[i][j] = new muerto();
}
void paint(material* content[WIDTH][HEIGHT]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++)
            (content[i][j]->getEstado() == 0) ? printf("  ") : printf("||");
        printf("\n");
    }
    printf("\n");
}

void take_input(material* content[WIDTH][HEIGHT]) {
    content[11][10] = new vivo();
    content[12][11] = new vivo();
    content[10][12] = new vivo();
    content[11][12] = new vivo();
    content[12][12] = new vivo();
}

void copy_content(material* old_content[WIDTH][HEIGHT], material* new_content[WIDTH][HEIGHT]) {
    for (int i = 0; i < WIDTH; i++)
        for (int j = 0; j < HEIGHT; j++)
            old_content[i][j] = new_content[i][j];
}

int main(int argc, char* argv[]) {

    material* content_now[WIDTH][HEIGHT];
    material* content_update[WIDTH][HEIGHT];

    bool game_state = true;

    initialization(content_now);
    take_input(content_now);

    paint(content_now);
    while (game_state) {
        Sleep(100);
        for (int i = 0; i < WIDTH; i++) {
            for (int j = 0; j < HEIGHT; j++) {
                content_now[i][j]->reaccionar(content_now, content_update, i, j);
            }
        }
        copy_content(content_now, content_update);
        system("cls");
        paint(content_now);
    }

    return 0;
}
