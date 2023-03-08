#include "gtest/gtest.h"
#ifdef WIN32
#include <Windows.h>
#endif

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	
	//::testing::GTEST_FLAG(filter) = "file_tests.check_initial_files"; //TO RUN ONLY SPECIFIC TEST
	
	RUN_ALL_TESTS();
	return 0;
}

#ifdef WIN32
int APIENTRY WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	return main(__argc, __argv);
}
#endif
