#include <iostream>
#include "application/system/App.h"

int main(int argc, char** argv) {
	auto myApp = new Application::App();
	if (!myApp->initialize()) {
		std::cout << "Bad initialize!\n";
		return -1;
	}
	myApp->run();
	return 0;
}