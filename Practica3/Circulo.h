#pragma once
#include <GLFW/glfw3.h>
#include <vector>
#include <numbers>

#include "Vertex2D.h"


class Circulo
{
private:
    float m_radio;
    int m_divisiones;
    std::vector<Vertex2D> m_elementos;
public:
    Circulo(float radio, int divisiones);
    void Dibujar();
};

Circulo::Circulo(float radio, int divisiones)
{

    // 1. Definir el número de divisiones (puntos) del circulo
    m_divisiones = divisiones;

    // 2. Definir el tamaño de paso (deltaT)

    float deltaT = 2 * std::numbers::pi_v<float> / divisiones;

    // 3. Definir el radio del circulo
    m_radio = radio;

    float ti = 0.0f;

    //4. Evaluar los valores (x,y) para cada instante de tiempo
    for (int i = 0; i < divisiones; i++)
    {
        ti = i * deltaT;
        float x = radio * cosf(ti);
        float y = radio * sinf(ti);

        // Almacenar los valores de (x,y) en un vertex2D
        Vertex2D v = Vertex2D{ x,y };

        m_elementos.push_back(v);
    }

}


void Circulo::Dibujar()
{
    glBegin(GL_LINE_LOOP);
        // Por cada elemento del circulo, dibujar lineas
        for (int i = 0; i < m_divisiones - 1; i++)
        {
            glVertex2f(m_elementos[i].GetX(), m_elementos[i].GetY());
            glVertex2f(m_elementos[i + 1].GetX(), m_elementos[i + 1].GetY());

        }
    glEnd();
}

