#include <math.h> //математическая бибилотека

///Вычисление выражения, x и y значения для выражения https://ivtipm.github.io/Programming/Glava01/index01.htm#z2
float calc_z2(float x, float y) 
{
	return ((abs(x) - abs(y)) / (1 + abs(x*y))); //вычисляем выражение

}
