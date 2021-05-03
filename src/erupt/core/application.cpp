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
  };
  Application::~Application(){

  };

  void Application::Run()
  {
    while (m_Running)
    {
     
      m_Window->OnUpdate();
    }
  }

}