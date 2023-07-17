#include "Cake.h"


void Cake::start() {
	getBody()->GetFixtureList()->SetSensor(true);
	setTag("Cake");
}