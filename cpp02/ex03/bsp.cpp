#include "Point.hpp"

static Fixed area(Point const p1, Point const p2, Point const p3) {
	Fixed result = (p1.getX() * (p2.getY() - p3.getY()) + 
			p2.getX() * (p3.getY() - p1.getY()) + 
			p3.getX() * (p1.getY() - p2.getY()));
	
	if (result < Fixed(0))
		result = Fixed(0) - result;
	
	return result;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed mainArea = area(a, b, c);
	
	if (mainArea == Fixed(0))
		return false;
	
	Fixed area1 = area(point, b, c);
	Fixed area2 = area(a, point, c);
	Fixed area3 = area(a, b, point);
	
	if (area1 == Fixed(0) || area2 == Fixed(0) || area3 == Fixed(0))
		return false;
	
	return (area1 + area2 + area3) == mainArea;
}