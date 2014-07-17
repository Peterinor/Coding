
#include "SimpleWindow.h"

CComModule _Module;

int WINAPI WinMain( __in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in LPSTR lpCmdLine, __in int nShowCmd )
{
	_Module.Init(NULL, hInstance);

	SimpleWindow sWnd;
	MSG msg;

	if(NULL == sWnd.Create(::GetDesktopWindow(), CWindow::rcDefault, _T("Simple WTL Window Test"))){

		return 1;
	}

	sWnd.ShowWindow(nShowCmd);
	sWnd.UpdateWindow();

	while(GetMessage(&msg, NULL, 0, 0) > 0){

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	_Module.Term();

	return 0;
}