#pragma once

#ifdef ERUPT_PLATFORM_WINDOWS

/// Client Definition
extern Erupt::Application *Erupt::CreateApplication();

int main(int arc, char **argv)
{
  Erupt::Log::Init();
  ERUPT_CORE_WARN("Engine Begin");
  auto app = Erupt::CreateApplication();
  app->Run();
  delete app;
}

#endif