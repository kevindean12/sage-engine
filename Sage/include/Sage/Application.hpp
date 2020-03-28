#pragma once
#include "Core.hpp"
#include "Events/Event.hpp"
namespace Sage {
	class SAGE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//to be defined in the client
	Application* CreateApplication();
}
