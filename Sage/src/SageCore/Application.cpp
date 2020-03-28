#include "Application.hpp"
#include "Events/ApplicationEvent.hpp"
#include "Log.hpp"
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
		WindowResizeEvent e{1280, 720};
		if(e.IsInCategory(EventCategoryApplication))
		{
			SAGE_TRACE(e);
		}
		
		while (true);
	}
}