#include "Engine.h"


using namespace gloutrobate;

void gloutrobate::Engine::addGameObject(gloutrobate::GameObject* gameObjectPtr, bool isDynamic) {
	gameObjects.push_back(gameObjectPtr);
	if (isDynamic) {
		physicEngine.createDynamicBody(gameObjectPtr, 1.0f);
	}
	else {
		physicEngine.createStaticBody(gameObjectPtr);
	}
}

void gloutrobate::Engine::drawOnFrame(sf::Drawable* drawable) {
	graphicEngine.addDrawableForOneFrame(drawable);
}

void Engine::start(std::function<void(sf::Event)> const& eventHandler) {
	do {
		update();
		const auto frameStart = std::chrono::steady_clock::now();
		physicEngine.update(gameObjects);

		std::this_thread::sleep_until(frameStart + millisecondsPerFrame);
	} while (graphicEngine.drawFrame(gameObjects, eventHandler));
}
