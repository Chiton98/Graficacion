#pragma once

class CurvaRara
{
private:
    float m_a;
    float m_b;
    int m_divisiones;
    std::vector<Vertex2D> m_elementos;
public:
    std::vector<Vertex2D> GetElementos();
    CurvaRara(float a, float b, int divisiones);
    void Dibujar();
};

std::vector<Vertex2D> CurvaRara::GetElementos()
{
    return m_elementos;
}

CurvaRara::CurvaRara(float a, float b, int divisiones)
{
    m_a = a;
    m_b = b;

    // 1. Definir el número de divisiones (puntos) del circulo
    m_divisiones = divisiones;

    // 2. Definir el tamaño de paso (deltaT)

    float deltaT = 2 * std::numbers::pi_v<float> / divisiones;


    float ti = 0.0f;

    float k = a / b;
    //4. Evaluar los valores (x,y) para cada instante de tiempo
    for (int i = 0; i < divisiones; i++)
    {
        ti = i * deltaT;
        float x = (m_a - m_b) * cosf(ti) + m_b * cosf(ti * ((m_a / m_b) - 1));
        float y = (m_a - m_b) * sinf(ti) - m_b * sinf(ti * ((m_a / m_b) - 1));



        // Almacenar los valores de (x,y) en un vertex2D
        Vertex2D v = Vertex2D{ x,y };

        m_elementos.push_back(v);
    }


}

void CurvaRara::Dibujar()
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