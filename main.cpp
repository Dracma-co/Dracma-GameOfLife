#include <stdio.h>
#include <iostream>
#include <windows.h>
#include "materiales.h"
#include <GLFW/glfw3.h>

void initialization(material* content[WIDTH][HEIGHT]) {
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            content[i][j] = new death();
}
void paint(material* content[WIDTH][HEIGHT]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++)
            (content[i][j]->get_name() == DEATH) ? printf("  ") : printf("[]");
        printf("|\n");
    }
    printf("\n");
}

void take_input(material* content[WIDTH][HEIGHT]) {
    content[11][10] = new alive();
    content[12][11] = new alive();
    content[10][12] = new alive();
    content[11][12] = new alive();
    content[12][12] = new alive();
    content[12][13] = new alive();
    content[12][14] = new alive();
    content[12][15] = new alive();
}

void copy_content(material* old_content[WIDTH][HEIGHT], material* new_content[WIDTH][HEIGHT]) {
    for (int i = 0; i < WIDTH; i++)
        for (int j = 0; j < HEIGHT; j++)
            old_content[i][j] = new_content[i][j];
}
//
//int main(int argc, char* argv[]) {
//
//    material* content_now[WIDTH][HEIGHT];
//    material* content_update[WIDTH][HEIGHT];
//
//    bool game_state = true;
//
//    initialization(content_now);
//    take_input(content_now);
//
//    paint(content_now);
//    while (game_state) {
//        Sleep(1);
//        for (int i = 0; i < WIDTH; i++) {
//            for (int j = 0; j < HEIGHT; j++) {
//                content_now[i][j]->reaccionar(content_now, content_update, i, j);
//            }
//        }
//        copy_content(content_now, content_update);
//        system("cls");
//        paint(content_now);
//    }
//
//    return 0;
//}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);


        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.5f, -0.5f);
        glEnd();
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
