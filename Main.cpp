#include "Pch.h"
#include "Application.h"

using namespace CPPSnake;

Int32 WINAPI _WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPCSTR lpCmdLine, Int32 nCmdShow) {

	Application* app = new Application();
	if (!app->initialize()) {

		MessageBox(NULL, TEXT("Failed to initialize application. Programm wil exit emmidiately"), 
			TEXT("Error!"), MB_OK | MB_ICONERROR);
		delete app;
		return 0;
	}

	app->run();
	delete app;
	return 0;
}