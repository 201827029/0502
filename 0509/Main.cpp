#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);//���Ͽ� ���ڿ��� ���� �Լ�.
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
int main(void)
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

        //glClearColor(0, 0, 1, 1);
        //glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);//���� Frame�� �׷��� Buffer�� ���� Frame�� �׷��� Buffer�� Swap
        glfwPollEvents();//���� Frame�� �Է� �� ��� �̺�Ʈ�� ��� ó��
    }

    glfwDestroyWindow(window);
    glfwTerminate();//���� �޸𸮸� �����ϴ� �Լ��̴�.
                    //���α׷��� ����Ǳ� ������ �ݵ�� ȣ���ؾ� �Ѵ�.
    exit(EXIT_SUCCESS);
}