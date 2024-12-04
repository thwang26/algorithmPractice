#include <stdio.h>

int main() {
	typedef struct tagPoint
	{
		int x;
		int y;
	} Point;

	Point MyPoint = {30, 40};
	Point* ptr = &MyPoint;

	printf("x: %d, y: %d\n", ptr->x, ptr->y);
	
	return 0;
}

