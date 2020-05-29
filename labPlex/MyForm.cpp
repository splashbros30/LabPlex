#include "MyForm.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
using namespace System::Drawing::Design;

[STAThreadAttribute]
int main(array<System::String ^> ^args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	labPlex::MyForm name;
	Application::Run(%name);

	return 0;
}

