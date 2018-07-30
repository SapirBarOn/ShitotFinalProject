#include "Button.h"

Button::Button(short newLeft, short newTop, string val) : Label(newLeft, newTop, val), f(NULL) {};

Button::~Button()
{
}

void Button::mousePressed(int x, int y, bool isLeft)
{
	if (f != NULL)
		f(this);
}
