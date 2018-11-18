#include "LEDMatrix.h"
#include "windows.h"
#include <opencv2/opencv.hpp>

[System::STAThread]
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow ){
System::Windows::Forms::Application::Run(%LEDgui::LEDMatrix());
}