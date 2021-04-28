#pragma once
#include "erupt.hpp"
#ifdef ERUPT_PLATFORM_WINDOWS

/// Client Definition
extern Erupt::Application *Erupt::CreateApplication();

int main(int arc, char **argv)
{
  auto app = Erupt::CreateApplication();
  app->Run();
  delete app;
}

#endif