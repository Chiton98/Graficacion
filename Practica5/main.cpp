#include <GLFW/glfw3.h>

#include <vector>
#include <numbers>
#include <iostream>

typedef struct
{
    std::vector<float> t;
    std::vector<float> q;
}Trayectoria;

Trayectoria generar_trayectoria(float t0, float tf, float q0, float qf, float deltaT);
void dibujar_trayectoria(Trayectoria tray);
void triangulo();

int main(void)
{


    GLFWwindow* window;

    // PARTE 1: GENERAR TRAYECTORIA EN COORDENADAS NORMALIZADAS
    // Trayectoria tray = generar_trayectoria(-1.0f, 1.0f, -1.0f, 1.0f, 0.01f);

    float deltaT = 0.01;
    // PARTE 2: GENERAR TRAYECTORIA PARA ROTAR EL TRIÁNGULO
    Trayectoria tray = generar_trayectoria(0.0f, 5.0f, 0.0f, 180.0f, deltaT);

    // PARTE 3 (OPCIONAL):  LEER UN ARCHIVO PARA CARGAR LOS PARÁMETROS


    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Practica 5", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    double lastTime = glfwGetTime();
    double current = 0.0f;
    double elapsed = 0.0f;
    double totalTime = 0.0f;

    int i = -1;
    float theta = 0.0f;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {


        current = glfwGetTime();
        elapsed = current - lastTime;
        totalTime += elapsed;

        // process input

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();


        // update (lógica)
        while (totalTime >= deltaT)
        {
            i++;
            if (i >= tray.q.size())
            {
                i = 0;
            }
            // Rotar
            theta = tray.q[i];
            totalTime -= deltaT;
        }
        glClear(GL_COLOR_BUFFER_BIT);

        glPushMatrix();
            // render
            glRotatef(theta, 0.0f, 0.0f, 1.0f);
            triangulo();
        glPopMatrix();

        lastTime = current;
    }

    glfwTerminate();
    return 0;
}

Trayectoria generar_trayectoria(float t0, float tf, float q0, float qf, float deltaT)
{
    float D = t0 * t0 * t0 - 3.0f * t0 * t0 * tf + 3 * t0 * tf * tf - tf * tf * tf;

    // Calcular los coeficieintes
    float a0 = (q0 * tf * tf * (3.0f * t0 - tf) + qf * t0 * t0 * (t0 - 3 * tf)) / (D);
    float a1 = (6.0f * t0 * tf * (qf - q0)) / D;
    float a2 = (3 * (q0 - qf) * (tf + t0)) / D;
    float a3 = (2 * (qf - q0)) / D;

    int n = (tf - t0) / deltaT;

    std::vector<float> time = {};
    std::vector<float> Q = {};

    float t = 0.0f;
    float q = 0.0f;
    for (int i = 0; i < n; i++)
    {
        t = t0 + deltaT * i;
        time.push_back(t);

        q = a0 + a1 * t + a2 * t * t + a3 * t * t * t;
        Q.push_back(q);
    }
    Trayectoria miTrayectoria = { time, Q };
    return miTrayectoria;
}

void dibujar_trayectoria(Trayectoria tray)
{
    int n = tray.q.size();
    glColor3f(0.0f, 1.0f, 0.0f);

    glBegin(GL_LINE_STRIP);
    // Por cada par (t, q) dibujar algo
    for (int i = 0; i < n; i++)
    {
        glVertex2f(tray.t[i], tray.q[i]);
    }
    glEnd();
}

void triangulo()
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

