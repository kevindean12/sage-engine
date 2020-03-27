#pragma once

#include "Application.hpp"

#ifdef SAGE_PLATFORM_WINDOWS

extern Sage::Application* Sage::CreateApplication();

int main(int argc, char** argv)
{
	Sage::Log::Init();
	SAGE_CORE_WARN("Initialized Log");
	int a = 9;
	SAGE_INFO("Hello! var={0}", a);

	auto app = Sage::CreateApplication();
	app->Run();
	delete app;
}
#endif