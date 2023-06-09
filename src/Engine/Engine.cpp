#include "Engine.h"


using namespace gloutobate;

void gloutobate::Engine::addGameObject(gloutobate::GameObject* gameObjectPtr, bool isDynamic) {
	graphicEngine.addGameObject(gameObjectPtr);
	if (isDynamic) {
		physicEngine.createDynamicBody(gameObjectPtr, 0.2f);
	}
	else {
		physicEngine.createStaticBody(gameObjectPtr);
	}
}

void gloutobate::Engine::drawOnFrame(sf::Drawable* drawable) {
	graphicEngine.addDrawableForOneFrame(drawable);
}

void Engine::start() {
	do {
		const auto frameStart = std::chrono::steady_clock::now();
		physicEngine.update();

		std::this_thread::sleep_until(frameStart + millisecondsPerFrame);
	} while (graphicEngine.drawFrame(update));
}
