#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <iostream>

#pragma comment(lib, "OpenGL32")




static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
int main(void)
{

    float x = 0.4f, x2 = 0.6f, y = -0.2f, y2 = 0.0f;
    float ex = 0.5f, ex2 = 0.7f, ey = 0.2f, ey2 = 0.4f;

    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;


        glClearColor(0.3f, 0.3f, 0.3f, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE);

        glBegin(GL_QUADS);
        glColor4f(0.1f, 0.1f, 0.7f, 0.6f);
        glVertex2f(x, y); //사각형을 그리기 위해 4개의 점을 설정한다.  도형은 왼쪽 아래 꼭지점부터 반시계로 만들어짐
        glVertex2f(x2, y);
        glVertex2f(x2, y2);
        glVertex2f(x, y2);
        glEnd();

        glBegin(GL_QUADS);
        glColor4f(0.0f, 0.0f, 0.5f, 0.6f);  //도형은 왼쪽 아래 꼭지점부터 반시계로 만들어짐
        glVertex2f(ex, ey);
        glVertex2f(ex2, ey);
        glVertex2f(ex2, ey2);
        glVertex2f(ex, ey2);
        glEnd();

        if (GetAsyncKeyState(VK_LEFT) & 0x8000)
        {
            x -= 0.01f; 
            x2 -= 0.01f;
        }

        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) 
        {
            x += 0.01f; 
            x2 += 0.01f;
        }

        if (GetAsyncKeyState(VK_UP) & 0x8000) 
        {
            y += 0.01f; 
            y2 += 0.01f;
        }

        if (GetAsyncKeyState(VK_DOWN) & 0x8000) 
        {
            y -= 0.01f;
            y2 -= 0.01f;
        }

        if (x2 >= ex && y2 >= ey && x <= ex2 && y <= ey2) {
            std::cout << "충돌";
        };



        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}