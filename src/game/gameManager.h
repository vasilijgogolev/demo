#pragma once
#include "application/system/GameManager.h"

namespace game {
	class gameManager : public Engine::Application::GameManager {
	public:
		gameManager() = default;
		~gameManager() = default;
		void initialize() override;
		void update() override;
		void draw() override;
		void processInput() override;
		void terminate() override;
	};
}