#include "erupt_pch.hpp"

#include "application.hpp"
#include "erupt/events/applicationEvent.hpp"
#include "erupt/log.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Erupt
{
  Application::Application()
  {
    m_Window = std::unique_ptr<Window>(Window::Create());
    m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
  }
  Application::~Application(){

  };

  void Application::Run()
  {
    while (m_Running)
    {
      m_Window->OnUpdate();
    }
  }
  void Application::OnEvent(Event &e)
  {
    ERUPT_CORE_INFO("{0}", e);
    if (e.GetEventType() == EventType::WindowClose)
    {
      m_Running = false;
    }
  }

}