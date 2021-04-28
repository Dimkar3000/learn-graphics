// #include <iostream>

// #include <glad/glad.h>
// #include <GLFW/glfw3.h>

// void proccessInputs(GLFWwindow *window)
// {
//   if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//   {
//     glfwSetWindowShouldClose(window, true);
//   }
// }

// int main()
// {
//   // Init
//   glfwInit();
//   glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
//   glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
//   glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

//   // Create Window
//   auto *window = glfwCreateWindow(800, 600, "Learn Opengl 2", NULL, NULL);
//   if (window == NULL)
//   {
//     std::cout << "Failed to create GLFW window" << std::endl;
//     glfwTerminate();
//     return -1;
//   }
//   glfwMakeContextCurrent(window);

//   // Init Glad
//   if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//   {
//     std::cout << "Failed to initialize GLAD" << std::endl;
//     return -1;
//   }

//   // Set Viewport
//   glViewport(0, 0, 800, 600);
//   glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//   glfwSetFramebufferSizeCallback(window,
//                                  [](GLFWwindow *window, int width, int height) {
//                                    glViewport(0, 0, width, height);
//                                  });

//   // Vertex Shader
//   const char *vertexShaderSource = "#version 330 core\n"
//                                    "layout (location = 0) in vec3 aPos;\n"
//                                    "void main()\n"
//                                    "{\n"
//                                    " gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//                                    "}\0";
//   unsigned int vertexShader;
//   vertexShader = glCreateShader(GL_VERTEX_SHADER);
//   glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//   glCompileShader(vertexShader);
//   int success;
//   char infoLog[512];
//   glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//   if (!success)
//   {
//     glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//     std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
//               << infoLog << std::endl;
//     return -1;
//   }

//   // Fragment Shader
//   const char *fragmentShaderSource = R"(#version 330 core
// out vec4 FragColor;
// void main()
// {
// FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
// }
// )";
//   unsigned int fragmentShader;
//   fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//   glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//   glCompileShader(fragmentShader);
//   memset(infoLog, 0, 512);
//   glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//   if (!success)
//   {
//     glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//     std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
//               << infoLog << std::endl;
//     return -1;
//   }

//   unsigned int shaderProgram;
//   shaderProgram = glCreateProgram();
//   glAttachShader(shaderProgram, vertexShader);
//   glAttachShader(shaderProgram, fragmentShader);
//   glLinkProgram(shaderProgram);
//   glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//   if (!success)
//   {
//     glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//     std::cout << "ERROR::SHADER::PROGRAM::LINK_FAILED\n"
//               << infoLog << std::endl;
//     return -1;
//   }
//   glDeleteShader(vertexShader);
//   glDeleteShader(fragmentShader);

//   // Test
//   float vertices[] = {
//       -0.5f, -0.5f, 0.0f,
//       0.5f, -0.5f, 0.0f,
//       0.0f, 0.5f, 0.0f};
//   unsigned int VBO;
//   glGenBuffers(1, &VBO);
//   glBindBuffer(GL_ARRAY_BUFFER, VBO);
//   glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//   // VAO
//   unsigned int VAO;
//   glGenVertexArrays(1, &VAO);
//   glBindVertexArray(VAO);
//   // 2. copy our vertices array in a buffer for OpenGL to use
//   glBindBuffer(GL_ARRAY_BUFFER, VBO);
//   glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//   // 3. then set our vertex attributes pointers
//   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),
//                         (void *)0);
//   glEnableVertexAttribArray(0);

//   // Game Loop
//   while (!glfwWindowShouldClose(window))
//   {
//     // input
//     proccessInputs(window);
//     glClear(GL_COLOR_BUFFER_BIT);

//     // rendering commands
//     glUseProgram(shaderProgram);
//     glBindVertexArray(VAO);
//     glDrawArrays(GL_TRIANGLES, 0, 3);

//     // check and call events and swap
//     glfwPollEvents();
//     glfwSwapBuffers(window);
//   }

//   // Shoutdown
//   glfwTerminate();
// }
#include <erupt.hpp>

class SandBoxApplication : public Erupt::Application
{
public:
  SandBoxApplication() {}

  ~SandBoxApplication() {}
};

Erupt::Application *Erupt::CreateApplication()
{
  return new SandBoxApplication();
}