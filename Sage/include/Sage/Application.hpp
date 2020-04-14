#pragma once
#include "Core.hpp"
#include "Events/Event.hpp"
#include "Window.hpp"
namespace Sage {
	class SAGE_API Application
	{
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//to be defined in the client
	Application* CreateApplication();
}
