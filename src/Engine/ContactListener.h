#pragma once

#include "box2d/box2d.h"

namespace gloutrobate {
	class ContactListener : public b2ContactListener {
		using b2ContactListener::b2ContactListener;

		void BeginContact(b2Contact* contact) override;
		void EndContact(b2Contact* contact) override;
	};
}