#include "Graphics.h"

using namespace gloutobate;

bool Graphics::drawFrame(std::function<void(sf::Event)> const& eventHandler) {
	renderWindow.clear();

	for (auto const& drawable : drawables) {
		renderWindow.draw(*drawable);
	}
	sf::Event rwEvent;
	while (renderWindow.pollEvent(rwEvent))
	{
		if (rwEvent.type == sf::Event::Closed) {
			renderWindow.close();
			return false;
		}
		else {
			eventHandler(rwEvent);
		}
	}
	renderWindow.display();

	drawables.clear();
	return renderWindow.isOpen();
}

void Graphics::addDrawable(sf::Drawable* drawable) {
	drawables.push_back(drawable);
}
