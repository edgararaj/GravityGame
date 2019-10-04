#pragma once

namespace Object {
	struct Point {
		int x, y;
	};

	struct Circle {
		int radius;
		Point position;
	};

	struct Square {
		Point position;
		int side;
	};
}
