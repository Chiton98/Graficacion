#include <GLFW/glfw3.h>
#include <vector>
#include <numbers>
#include <cmath>
#include <iostream>

#include "Vertex2D.h"
#include "Circulo.h"
#include "CurvaRara.h"

// Call backs for the events
void close_window(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void maximize_window(GLFWwindow* window, int key, int scancode, int action, int mods)
{

}


int main(void)
{

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Practica 3 - El circulo", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwSetKeyCallback(window, close_window);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    // Aplicar la transformacion para el viewport
    glViewport(0, 0, 640, 480);

    // Crear el objeto Circulo
    Circulo miCirculo = Circulo{ 0.5f, 100 };
    CurvaRara miCurvaRara = CurvaRara(6.0f, 1.0f, 100);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        miCirculo.Dibujar();
    
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}