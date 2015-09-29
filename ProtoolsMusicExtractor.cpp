//---------------------------------------------------------------------------

#include "Generic.h"
#pragma hdrstop

//---------------------------------------------------------------------------

USEFORM("Controller.cpp", ControllerForm);
USEFORM("SettingsUnit.cpp", SettingsForm);

//---------------------------------------------------------------------------

WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// Run single instance only.

	HANDLE MutexHandle = CreateMutex
	(
		0,
		true,
		"{FCE79210-3BA2-43D7-84C0-4F0FE44F079D}"
	);

	if(GetLastError() == ERROR_ALREADY_EXISTS)
	{
		// Program is already running.

		if(MutexHandle)
		{
			CloseHandle(MutexHandle);
		}

		return 0;
	}

	try
	{
		Application->Initialize();
		Application->Title = "Protools Music Extractor";
		Application->CreateForm(__classid(TControllerForm), &ControllerForm);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}

	// Kill mutex.

	ReleaseMutex(MutexHandle);
	CloseHandle(MutexHandle);

	return 0;
}

//---------------------------------------------------------------------------
