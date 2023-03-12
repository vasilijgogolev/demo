#include <iostream>
#include "application/system/App.h"
#include "game/gameManager.h"

int main(int argc, char** argv) {

	std::unique_ptr<game::gameManager> gManager = std::make_unique<game::gameManager>();
	Engine::Application::App::setGameManager(std::move(gManager));
	Engine::Application::App::setGameResolution(640, 480);
	Engine::Application::App::setGameName("demo");
	if (!Engine::Application::App::initialize()) {
		std::cout << "Bad initialize!\n";
		return -1;
	}
	Engine::Application::App::run();
	return 0;
}