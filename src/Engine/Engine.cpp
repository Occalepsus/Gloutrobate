#include "Engine.h"


using namespace gloutobate;

void gloutobate::Engine::addGameObject(gloutobate::GameObject* gameObjectPtr, bool isDynamic) {
	graphicEngine.addGameObject(gameObjectPtr);
	if (isDynamic) {
		physicEngine.createDynamicBody(gameObjectPtr, 1.0f);
	}
	else {
		physicEngine.createStaticBody(gameObjectPtr);
	}
}

void gloutobate::Engine::drawOnFrame(sf::Drawable* drawable) {
	graphicEngine.addDrawableForOneFrame(drawable);
}

void Engine::start(std::function<void(sf::Event)> const& eventHandler) {
	do {
		update();
		const auto frameStart = std::chrono::steady_clock::now();
		physicEngine.update();

		std::this_thread::sleep_until(frameStart + millisecondsPerFrame);
	} while (graphicEngine.drawFrame(eventHandler));
}
