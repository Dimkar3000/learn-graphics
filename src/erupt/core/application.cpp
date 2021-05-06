#include "erupt_pch.hpp"

#include "application.hpp"
#include "erupt/events/applicationEvent.hpp"
#include "erupt/log.hpp"

#include <glad/glad.h>

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
    glClearColor(1, 0, 1, 1);
    while (m_Running)
    {
      glClear(GL_COLOR_BUFFER_BIT);
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