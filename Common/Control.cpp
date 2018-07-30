#include "Control.h"

Control* Control::focus = NULL;

Control::Control() : left(0), top(0), parent(NULL), fontColor(Color::White), backgroundColor(Color::Black)
{
}

Control::Control(short newLeft, short newTop) : left(newLeft), top(newTop), parent(NULL), fontColor(Color::White), backgroundColor(Color::Black)
{
}

Control::~Control()
{
}

void Control::setFocus(Control& control)
{
	if (focus != nullptr)
		focus->removeFocus();
	focus = &control;
}
