#pragma once

#include "erupt/core/base.hpp"
#include "erupt/events/event.hpp"
#include "erupt/core/window.hpp"


namespace Erupt
{
  class ERUPT_API Application
  {
  public:
    Application();
    virtual ~Application();

    void Run();

  private:
    std::unique_ptr<Window> m_Window;
    bool m_Running = true;
  };
  // Defined by the client
  Application *CreateApplication();
}