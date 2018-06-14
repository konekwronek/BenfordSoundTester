// Benford Sound Tester.cpp : main project file.

#include "stdafx.h"
#include "KlasaKonwerter.h"
#include "Form1.h"

using namespace BenfordSoundTester;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form1());
	return 0;
}
