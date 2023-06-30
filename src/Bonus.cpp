#include "Bonus.h"

void Item::start() {
	getBody()->GetFixtureList()->SetSensor(true);
	setTag("Bonus");
}
