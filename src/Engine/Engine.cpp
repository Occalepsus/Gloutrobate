#include "Engine.h"


using namespace gloutobate;

void gloutobate::Engine::addGameObject(gloutobate::GameObject* gameObject, bool isDynamic) {
	graphicEngine.addGameObject(gameObject);
	if (isDynamic) {
		physicEngine.createDynamicBody(gameObject, 0.2f);
	}
	else {
		physicEngine.createStaticBody(gameObject);
	}
}

void gloutobate::Engine::drawOnFrame(sf::Drawable* drawable) {
	graphicEngine.addDrawableForOneFrame(drawable);
}

void Engine::start() {
	//gameThread = std::jthread{ [this]() {
		do {
			const auto frameStart = std::chrono::steady_clock::now();
			physicEngine.update();

			std::this_thread::sleep_until(frameStart + millisecondsPerFrame);
		} while (graphicEngine.drawFrame(update));
	//} };
}
