#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#pragma comment(lib, "opengl32") //library ������ ��θ� ��������� ��Ÿ�� �� ���δ�.

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);//���Ͽ� ���ڿ��� ���� �Լ�.
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
int main(void)//�⸻
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);

    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);//�����츦 �����.

    if (!window)
    {
        glfwTerminate();//���� �޸𸮸� �����ϴ� �Լ��̴�.
                        //���α׷��� ����Ǳ� ������ �ݵ�� ȣ���ؾ� �Ѵ�.
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);//Window�� ����ϴ� �Լ��̸�,
                                   //��ϵǸ� Thread�� �����Ǿ� ���ȴ�.
    glfwSetKeyCallback(window, key_callback);

    while (!glfwWindowShouldClose(window))//���� Window�� ����Ǿ����� Ȯ���ϴ� �Լ�
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);//�����ӹ����� ũ�⸦ ������ �´�
        ratio = width / (float)height;

        glClearColor(0.96f, 1, 0.98f, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        //glBegin(GL_POINTS);//���� �׸���.
        //glColor3f(1.0f, 0.0f, 0.0f);
        //glVertex2f(0.0f, 0.0f); //f = float
        //glEnd();

        //glBegin(GL_TRIANGLES);//���� �׸���.
        //glColor3f(1.0f, 0.0f, 0.0f);
        //glVertex2f(0.0f, 0.0f); //f = float
        //glVertex2f(1.0f, 1.0f);
        //glColor3f(0.0f, 0.0f, 0.0f);
        //glVertex2f(1.0f, -1.0f);
        //glEnd();

        //glBegin(GL_QUADS);
        //glColor3f(0.1f, 0.1f, 0.4f);
        //glVertex2f(-0.1f, -0.1f); //�簢���� �׸��� ���� 4���� ������ �����Ѵ�.
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
        
        

        glfwSwapBuffers(window);//���� Frame�� �׷��� Buffer�� ���� Frame�� �׷��� Buffer�� Swap
        glfwPollEvents();//���� Frame�� �Է� �� ��� �̺�Ʈ�� ��� ó��
    }

    glfwDestroyWindow(window);
    glfwTerminate();//���� �޸𸮸� �����ϴ� �Լ��̴�.
                    //���α׷��� ����Ǳ� ������ �ݵ�� ȣ���ؾ� �Ѵ�.
    exit(EXIT_SUCCESS);
}