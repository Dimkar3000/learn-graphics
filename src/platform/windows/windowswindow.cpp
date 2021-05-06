#include "erupt_pch.hpp"

#include "windowswindow.hpp"

#include "erupt/events/mouseEvent.hpp"
#include "erupt/events/keyEvent.hpp"
#include "erupt/events/applicationEvent.hpp"
#include "glad/glad.h"
namespace Erupt
{
  static void GLFWFailCallback(int error, const char *description)
  {
    ERUPT_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
  }
  static bool s_GLFWInitialized = false;

  Window *Window::Create(const WindowProps &props)
  {
    return new WindowsWindow(props);
  }

  WindowsWindow::WindowsWindow(const WindowProps &props)
  {
    Init(props);
  }

  WindowsWindow::~WindowsWindow()
  {
    Shutdown();
  }

  void WindowsWindow::Init(const WindowProps &props)
  {
    m_Data.Title = props.Title;
    m_Data.Width = props.Width;
    m_Data.Height = props.Height;

    ERUPT_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

    if (!s_GLFWInitialized)
    {
      // TODO: glfwTerminate on system shutdown
      int success = glfwInit();
      ERUPT_CORE_ASSERT(success, "Could not intialize GLFW!");
      glfwSetErrorCallback(GLFWFailCallback);
      s_GLFWInitialized = true;
    }

    m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(m_Window);
    int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    ERUPT_CORE_ASSERT(status, "Could not intialize GLAD!");

    glfwSetWindowUserPointer(m_Window, &m_Data);
    SetVSync(true);

    // Set GLFW callbacks
    glfwSetWindowSizeCallback(m_Window, [](GLFWwindow *window, int width, int height) {
      WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
      data.Width = width;
      data.Height = height;

      WindowResizeEvent event(width, height);
      data.EventCallback(event);
    });

    glfwSetWindowCloseCallback(m_Window, [](GLFWwindow *window) {
      WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
      WindowCloseEvent event;
      data.EventCallback(event);
    });

    glfwSetKeyCallback(m_Window, [](GLFWwindow *window, int key, int scancode, int action, int mods) {
      WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
      switch (action)
      {
      case GLFW_PRESS:
      {
        KeyPressedEvent event(key, 0);
        data.EventCallback(event);
        break;
      }
      case GLFW_RELEASE:
      {

        KeyReleasedEvent event(key);
        data.EventCallback(event);
        break;
      }
      case GLFW_REPEAT:
      {

        KeyPressedEvent event(key, 1);
        data.EventCallback(event);
        break;
      }
      }
    });

    glfwSetMouseButtonCallback(m_Window, [](GLFWwindow *window, int button, int action, int mods) {
      WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
      switch (action)
      {
      case GLFW_PRESS:
      {
        MouseButtonPressedEvent event(button);
        data.EventCallback(event);
        break;
      }
      case GLFW_RELEASE:
      {
        MouseButtonReleasedEvent event(button);
        data.EventCallback(event);
        break;
      }
      }
    });

    glfwSetScrollCallback(m_Window, [](GLFWwindow *window, double xOffeset, double yOffeset) {
      WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
      MouseScrolledEvent event((float)xOffeset, (float)yOffeset);
      data.EventCallback(event);
    });

    glfwSetCursorPosCallback(m_Window, [](GLFWwindow *window, double xPos, double yPos) {
      WindowData &data = *(WindowData *)glfwGetWindowUserPointer(window);
      MouseMovedEvent event((float)xPos, (float)yPos);
      data.EventCallback(event);
    });
  }

  void WindowsWindow::Shutdown()
  {
    glfwDestroyWindow(m_Window);
  }

  void WindowsWindow::OnUpdate()
  {
    glfwPollEvents();
    glfwSwapBuffers(m_Window);
  }

  void WindowsWindow::SetVSync(bool enabled)
  {
    if (enabled)
      glfwSwapInterval(1);
    else
      glfwSwapInterval(0);

    m_Data.VSync = enabled;
  }

  bool WindowsWindow::IsVSync() const
  {
    return m_Data.VSync;
  }

}