#include "Objects.h"
#include <cmath>

namespace Engine {
	bool circleVsCircle(Object::Circle circle1, Object::Circle circle2) {

		if (circle1.position.x == circle2.position.x && circle1.position.y == circle2.position.y) {
			return true;
		}
		else if (circle1.position.x == circle2.position.x) {
			int sumCircleRadius = circle1.radius + circle2.radius;
			int distanceCircles = abs(circle1.position.y - circle2.position.y);

			return distanceCircles <= sumCircleRadius;
		}
		else if (circle1.position.y == circle2.position.y) {
			int sumCircleRadius = circle1.radius + circle2.radius;
			int distanceCircles = abs(circle1.position.x - circle2.position.x);

			return distanceCircles <= sumCircleRadius;
		}
		else {
			int sumCircleRadius_m = (circle1.radius + circle2.radius) * (circle1.radius + circle2.radius);
			int distanceCirclesX_m = (circle1.position.x - circle2.position.x) * (circle1.position.x - circle2.position.x);
			int distanceCirclesY_m = (circle1.position.y - circle2.position.y) * (circle1.position.y - circle2.position.y);
			int distanceCircles_m = distanceCirclesX_m + distanceCirclesY_m;

			return distanceCircles_m <= sumCircleRadius_m;
		}

	}

	bool squareVsSquare(Object::Square square1, Object::Square square2) {
		if ((square1.position.x + square1.side) < square2.position.x || square1.position.x > (square2.position.x + square2.side))
			return false;
		else if ((square1.position.y + square1.side) < square2.position.y || square1.position.y > (square2.position.y + square2.side))
			return false;
		else
			return true;
	}

	Object::Square getCircleBoundingSquare(Object::Circle circle) {
		return { {circle.position.x - circle.radius, circle.position.y - circle.radius}, circle.radius * 2 };
	}
}