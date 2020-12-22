#include <stdio.h>
#include <iostream>
#include <iostream>
#include <unistd.h>

#include "materiales.h"

void initialization(material* content[WIDTH][HEIGHT]) {
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            content[i][j] = new death();
}
void paint(material* content[WIDTH][HEIGHT]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++)
            (content[i][j]->get_name() == DEATH) ? printf("  ") : printf("[]");
        printf("\n");
    }
    printf("\n");
}

void take_input(material* content[WIDTH][HEIGHT]) {
    content[11][10] = new alive();
    content[12][11] = new alive();
    content[10][12] = new alive();
    content[11][12] = new alive();
    content[12][12] = new alive();
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
    copy_content(content_update, content_now);

    paint(content_now);
    while (game_state) {
        sleep(1);
        for (int i = 0; i < WIDTH; i++) {
            for (int j = 0; j < HEIGHT; j++) {
                content_now[i][j]->reaccionar(content_now, content_update, i, j);
            }
        }
        copy_content(content_now, content_update);
        system("clear");
        paint(content_now);
    }

    return 0;
}
