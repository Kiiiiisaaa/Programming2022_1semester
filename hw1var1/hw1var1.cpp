#include <stdio.h>
#include <math.h>

int main() {
	float x1 = 0, y1 = 3, x2 = 4, y2 = 0, x3 = 0, y3 = 0, p, s, a, b, c;
	a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	b = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
	c = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
	p = (a + b + c) / 2;
	s = sqrt(p * (p - a) * (p - b) * (p - c));
	printf("P = %f\nS = %f", p * 2, s);
}