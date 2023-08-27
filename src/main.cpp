#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

int main() {

  GLFWwindow *window;

  /* Initialize the library */
  if (!glfwInit())
    return -1;

  /* Create a windowed mode window and its OpenGL context */
  window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }

  /* Make the window's context current */
  glfwMakeContextCurrent(window);

  // vertex points for triangle
  float vertexPositions[6] = {-0.5f, -0.5f, 0.0f, 0.5f, 0.5f, -0.5f};

  // create a buffer
  unsigned int buffer;
  glGenBuffers(1, &buffer);

  // bind the buffer GL_ARRAY_BUFFER
  glBindBuffer(GL_ARRAY_BUFFER, buffer);

  // add data to buffer
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), &vertexPositions,
               GL_STATIC_DRAW);

  /* Loop until the user closes the window */
  while (!glfwWindowShouldClose(window)) {
    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);

    /* Swap front and back buffers */
    glfwSwapBuffers(window);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    /* Poll for and process events */
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
