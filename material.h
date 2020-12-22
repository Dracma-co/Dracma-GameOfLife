#pragma once
#define MAX_MATERIAL 10
#define WIDTH 50
#define HEIGHT 50
#define ALIVE 1
#define DEATH 0

class material
{
protected:
    static material list[MAX_MATERIAL];
    static material current[WIDTH][HEIGHT];
    static material update[WIDTH][HEIGHT];
    int estado;
    int nombre;
public:
    material(int state, int name) : estado(state), nombre(name) {};
    ~material() {}
    virtual void reaccionar(int x, int y);
    int num_neighbors(material content[WIDTH][HEIGHT], int x, int y) {
        int num = 0, pos_x, pos_y;

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {

                pos_x = (x + i < 0) ? WIDTH - 1 : (x + i) % WIDTH;
                pos_y = (y + j < 0) ? HEIGHT - 1 : (y + j) % HEIGHT;

                if (pos_x != x || pos_y != y)
                    if (content[pos_x][pos_y].estado == ALIVE) num++;
            }
        }
        return num;
    }

};

