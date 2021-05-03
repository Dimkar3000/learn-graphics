
#include <erupt.hpp>
class SandBoxApplication : public Erupt::Application
{
public:
  SandBoxApplication() {}

  ~SandBoxApplication() {}
};

Erupt::Application *Erupt::CreateApplication()
{
  ERUPT_INFO("Client Logger works={0}", 42);
  return new SandBoxApplication();
}