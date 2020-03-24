#include <Sage.h>

class Sandbox : public Sage::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Sage::Application* Sage::CreateApplication()
{
	return new Sandbox();
}