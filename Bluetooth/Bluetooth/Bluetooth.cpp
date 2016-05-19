// Bluetooth.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Bluetooth.h"
#include <Windows.h>
#include <string.h>
#include <string>
#include <iostream>
using std::cout;
using std::endl;

#define MAX_LOADSTRING 100
/* this is a macro that will siick a 'L' in front of string literal
we need the 'L' for unicode ezxtension*/
#define _TEXT(t) L##t
#define ID_Button 1
#define ID_SUBMITBUTTON 2
#define ID_EDIT 3

// Global Variables:
BOOL DEBUG = true;								// used for debugging messages
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
HWND userhWnd;									// user input hWnd
volatile HANDLE ble_handle;						// Used to connect to the BLE Device
int comPort = 0;									// this the port BLED112 is set to
int count = 0;

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_BLUETOOTH, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_BLUETOOTH));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

	/* FROM amin.cpp under bluegiga's example */
	char str[80];

	if (comPort == 0)
	{
		
	}
	else {

		snprintf(str, sizeof(str) - 1, "\\\\.\\%d", comPort);
		ble_handle = CreateFileA(str,
			GENERIC_READ | GENERIC_WRITE,
			FILE_SHARE_READ | FILE_SHARE_WRITE,
			NULL,
			OPEN_EXISTING,
			0,
			NULL);


		if (ble_handle == INVALID_HANDLE_VALUE)
		{
			printf("Error opening serialport %d. %d\n", comPort, (int)GetLastError());
			return -1;
		}

		bglib_output = Output;


		//stop previous operation
		ble_cmd_gap_end_procedure();
		//get connection status,current command will be handled in response
		ble_cmd_connection_get_status(0);

		//Message loop
		while (1)
		{
			if (readMessage())
			{
				printf("Error reading message\n");
				break;
			}
		}
	}

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_BLUETOOTH));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_BLUETOOTH);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//	
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable
   
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
// This is where we put buttons and handle actions!
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	wchar_t myString[] = _TEXT("This is a test");

    switch (message)
    {
	case WM_CREATE:
		/* The 'L" is a wchar_t literal for extended character set. Need it when using Windows.h */
		/* 1 Way of creating a static text box */
		//CreateWindowW(L"STATIC",L"This is a test",WS_VISIBLE | WS_CHILD | WS_BORDER, 20, 20, 300, 25, hWnd,NULL, NULL, NULL);

		/* Second way  here we use the  macro we defined in the beginning
			wchar_t myString = "This is a test";   will complain
			wchar_t myString = _TEXT("This is a test");  gets rewritten as wchar_t myString[] = L"This is a text"; for the compiler 
		*/
		CreateWindowW(L"STATIC", myString, WS_VISIBLE | WS_CHILD | WS_BORDER, 20, 20, 300, 25, hWnd, NULL, NULL, NULL);

		CreateWindowW(L"Button", L"Button 1", WS_VISIBLE| WS_CHILD, 60, 60, 80, 25, hWnd, (HMENU) ID_Button, NULL, NULL);
		/* Create a user text box */
		userhWnd = CreateWindowW(L"EDIT", L"Enter COM Port Number", WS_BORDER | WS_CHILD | WS_VISIBLE, 300, 300, 200, 25, hWnd, (HMENU)ID_EDIT, NULL, NULL);
		/* Creeate submit button, when pressed it should grab the text from userhWnd*/
		CreateWindowW(L"BUTTON", L"SUBMIT", WS_BORDER | WS_CHILD | WS_VISIBLE, 300, 325, 75, 25, hWnd, (HMENU)ID_SUBMITBUTTON, NULL, NULL);
		
		break;
    case WM_COMMAND:
		/* TODO: User can only input 256 byte messages 
			I need to add error control for this */
		//
		
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
			case ID_Button:
				MessageBox(hWnd,L"This worked",L"Notification",MB_OK);
				break;
			case ID_SUBMITBUTTON:
				/* TODO: Need to check if user inputed anything */
				if (userhWnd != NULL) {
					wchar_t userInput[3];
					GetWindowText(userhWnd, userInput, 3);

					if(DEBUG) OutputDebugString(userInput);
					comPort = _wtoi(userInput);
				}
				break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
			TCHAR greeting[] = _T("Hello World!");
			TextOut(hdc, 5, 5, greeting, _tcslen(greeting));

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

/* These functions are used for BLED112*/
void Output(uint8 len1, uint8* data1, uint16 len2, uint8* data2)
{
	DWORD written;

	if (!WriteFile(ble_handle,
		data1,
		len1,
		&written,
		NULL
	))
	{
		printf("ERROR: Writing data. %d\n", (int)GetLastError());
		exit(-1);
	}

	if (!WriteFile(ble_handle,
		data2,
		len2,
		&written,
		NULL
	))
	{
		printf("ERROR: Writing data. %d\n", (int)GetLastError());
		exit(-1);
	}
}
int readMessage()
{
	DWORD rread;
	const struct ble_msg *apimsg;
	struct ble_header apihdr;
	unsigned char data[256];//enough for BLE
							//read header

	if (!ReadFile(ble_handle,
		(unsigned char*)&apihdr,
		4,
		&rread,
		NULL))
	{
		return GetLastError();
	}
	if (!rread)return 0;
	//read rest if needed
	if (apihdr.lolen)
	{
		if (!ReadFile(ble_handle,
			data,
			apihdr.lolen,
			&rread,
			NULL))
		{
			return GetLastError();
		}
	}
	apimsg = ble_get_msg_hdr(apihdr);
	if (!apimsg)
	{
		printf("ERROR: Message not found:%d:%d\n", (int)apihdr.cls, (int)apihdr.command);
		return -1;
	}
	apimsg->handler(data);

	return 0;
}

void printHelp()
{
	printf("Demo application to scan devices\n");
	printf("\tscan_example\tCOM-port\n");
}