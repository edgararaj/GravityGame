#pragma once

#include "Objects.h"

namespace Engine {
	bool circleVsCircle(Object::Circle circle1, Object::Circle circle2);
	bool squareVsSquare(Object::Square square1, Object::Square square2);
	Object::Square getCircleBoundingSquare(Object::Circle circle);
}
