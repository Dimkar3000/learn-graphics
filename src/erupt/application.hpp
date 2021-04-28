#pragma once

#include "core.hpp"

namespace Erupt
{
  class ERUPT_API Application
  {
  public:
    Application();
    virtual ~Application();

    void Run();
  };
  Application *CreateApplication();
}