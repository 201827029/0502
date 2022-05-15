#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#pragma comment(lib, "opengl32") //library 파일의 경로를 명시적으로 나타낼 때 쓰인다.

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);//파일에 문자열을 쓰는 함수.
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
int main(void)//기말
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);

    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);//윈도우를 만든다.

    if (!window)
    {
        glfwTerminate();//사용된 메모리를 삭제하는 함수이다.
                        //프로그램이 종료되기 직전에 반드시 호출해야 한다.
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);//Window를 등록하는 함수이며,
                                   //등록되면 Thread로 설정되어 사용된다.
    glfwSetKeyCallback(window, key_callback);

    while (!glfwWindowShouldClose(window))//현재 Window가 종료되었는지 확인하는 함수
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);//프레임버퍼의 크기를 가지고 온다
        ratio = width / (float)height;

        glClearColor(0.96f, 1, 0.98f, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        //glBegin(GL_POINTS);//점을 그린다.
        //glColor3f(1.0f, 0.0f, 0.0f);
        //glVertex2f(0.0f, 0.0f); //f = float
        //glEnd();

        //glBegin(GL_TRIANGLES);//점을 그린다.
        //glColor3f(1.0f, 0.0f, 0.0f);
        //glVertex2f(0.0f, 0.0f); //f = float
        //glVertex2f(1.0f, 1.0f);
        //glColor3f(0.0f, 0.0f, 0.0f);
        //glVertex2f(1.0f, -1.0f);
        //glEnd();

        //glBegin(GL_QUADS);
        //glColor3f(0.1f, 0.1f, 0.4f);
        //glVertex2f(-0.1f, -0.1f); //사각형을 그리기 위해 4개의 정점을 설정한다.
        //glVertex2f(0.1f, -0.1f);
        //glVertex2f(0.1f, 0.1f);
        //glVertex2f(-0.1f, 0.1f);
        //glEnd();

        if (GetAsyncKeyState(VK_SPACE) & 0x8000)
        {
            glBegin(GL_TRIANGLES);
            glColor3f(0.0f, 0.0f, 1.0f);
            glVertex2f(-0.5f, 0.3f);
            glVertex2f(-0.5f, 0.1f);
            glVertex2f(-0.7f, 0.1f);
            glVertex2f(-0.5f, 0.3f);
            glVertex2f(-0.7f, 0.3f);
            glVertex2f(-0.7f, 0.1f);
            glEnd();
        }
        else {
            glBegin(GL_TRIANGLES);
            glColor3f(0.0f, 0.0f, 1.0f);
            glVertex2f(-0.5f, 0.0f);
            glVertex2f(-0.5f, -0.2f);
            glVertex2f(-0.7f, -0.2f);
            glVertex2f(-0.5f, 0.0f);
            glVertex2f(-0.7f, 0.0f);
            glVertex2f(-0.7f, -0.2f);
            glEnd();
        }
        
        

        glfwSwapBuffers(window);//이전 Frame에 그려진 Buffer와 현재 Frame에 그려진 Buffer를 Swap
        glfwPollEvents();//현재 Frame의 입력 및 출력 이벤트를 모두 처리
    }

    glfwDestroyWindow(window);
    glfwTerminate();//사용된 메모리를 삭제하는 함수이다.
                    //프로그램이 종료되기 직전에 반드시 호출해야 한다.
    exit(EXIT_SUCCESS);
}