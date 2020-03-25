#include "Application.hpp"
#include <stdio.h>

namespace Sage {

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		printf("Sage is running");
		while (true);
	}
}