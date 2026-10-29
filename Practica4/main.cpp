#include <GLFW/glfw3.h>
#include <vector>
#include <numbers>
#include <cmath>
#include <iostream>

#include "Vertex2D.h"

// Declaracion de la funcion
void triangle();



// Añadir una función que detecte un botón para rotar
void key_pad(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    
    if (action == GLFW_PRESS)
    {
        switch (key)
        {
            // Closing the window
            case GLFW_KEY_ESCAPE:
                glfwSetWindowShouldClose(window, GLFW_TRUE);
                break;

            // ROTATION en Z
            case GLFW_KEY_Q:
                glRotatef(10, 0, 0, 1);
                break;
            case GLFW_KEY_E:
                glRotatef(-10, 0, 0, 1);
                break;

            // Rotacion en Y
            case GLFW_KEY_U:
                glRotatef(10, 0, 1, 0);
                break;
            case GLFW_KEY_O:
                glRotatef(-10, 0, 1, 0);
                break;

            // Traslacion en X
            case GLFW_KEY_D:
                glTranslatef(0.1, 0, 0);
                break;
            case GLFW_KEY_A:
                glTranslatef(-0.1, 0, 0);
                break;

            // Traslacion en Y
            case GLFW_KEY_W:
                glTranslatef(0, 0.1, 0);
                break;

            case GLFW_KEY_S:
                glTranslatef(0, -0.1, 0);
                break;


        }
    }


}

int main(void)
{

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Practica 4 - Rotando triangulos", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwSetKeyCallback(window, key_pad);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    // Aplicar la transformacion para el viewport
    glViewport(0, 0, 640, 480);
    
    glfwSetKeyCallback(window, key_pad);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
    
        triangle();
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

// Definicion de funcion
void triangle()
{
    glBegin(GL_TRIANGLES);
    // Configurar el color del primer vértice
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, 0.5f);

    // Configurar el color del segundo vértice
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.5f, 0.5f);

    // Configurar el color del tercer vértice
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.0f, -0.5f);

    glEnd();
}