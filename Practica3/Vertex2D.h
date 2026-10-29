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
