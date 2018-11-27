#pragma once
struct Color {
	int red;
	int green;
	int blue;
	int transparency;
	Color(){}
	Color(int r, int g, int b, int a = 255) {
		red = r; green = g; blue = b; transparency = a;
	}
};
