#include <GLFW/glfw3.h>
#include <vector>
#include <numbers>
#include <cmath>
#include <iostream>

#pragma once
class Vertex2D
{
    // Privado
    private:
        float m_x;
        float m_y;


    //Público
    public:
        Vertex2D();
        Vertex2D(float x, float y);
        float GetX();
        float GetY();
};

Vertex2D::Vertex2D()
{
    m_x = 0.0f;
    m_y = 0.0f;
}

Vertex2D::Vertex2D(float x, float y)
{
    m_x = x;
    m_y = y;
}

float Vertex2D::GetX()
{
    return m_x;
}

float Vertex2D::GetY()
{
    return m_y;
}



int main(void)
{
    std::vector<Vertex2D> triangle = { { Vertex2D{-0.5f,0.5f},
                                        Vertex2D{0.5, 0.5f},
                                        Vertex2D{0,-0.5f}} };
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* window;
    window = glfwCreateWindow(640, 480, "Practica 2 - El triangulo", NULL, NULL);
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

        // Dibujar el triángulo
        glBegin(GL_TRIANGLES);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex2f(triangle[0].GetX(), triangle[0].GetY());
            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex2f(triangle[1].GetX(), triangle[1].GetY());
            glColor3f(0.0f, 0.0f, 1.0f);
            glVertex2f(triangle[2].GetX(), triangle[2].GetY());
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}