#pragma once
#define MAX_MATERIAL 10
#define WIDTH 50
#define HEIGHT 50
#define ALIVE 1
#define DEATH 0

class material
{
protected:
    int estado;
    int nombre;
public:
    material(int state, int name) : estado(state), nombre(name) {
    };
    material() : estado(0), nombre(0) {
    }
    virtual ~material() {}
    int getEstado() { return estado; }
    virtual void reaccionar(material* current[WIDTH][HEIGHT], material* update[WIDTH][HEIGHT], int x, int y) {};
    int num_neighbors(material* content[WIDTH][HEIGHT], int x, int y);
};

class vivo : public material
{
public:
    vivo() : material(1, 1) {};
    ~vivo() {}
    void reaccionar(material* current[WIDTH][HEIGHT], material* update[WIDTH][HEIGHT], int x, int y);
};

class muerto : public material
{
public:
    muerto() : material(0, 0) {};
    ~muerto() {}
    void reaccionar(material* current[WIDTH][HEIGHT], material* update[WIDTH][HEIGHT], int x, int y);
};