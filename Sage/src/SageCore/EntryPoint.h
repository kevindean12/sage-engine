#pragma once

#include "Application.h"

#ifdef SAGE_PLATFORM_WINDOWS

extern Sage::Application* Sage::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Sage::CreateApplication();
	app->Run();
	delete app;
}
#endif