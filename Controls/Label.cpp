#include "Label.h"
#include <iostream>

Label::Label(string value) : Control(), value(value) {};

Label::Label(short newLeft, short newTop, string val) : Control(newLeft, newTop), value(val) {};

string Label::getValue()
{
    return this->value;
}

void Label::setValue(string value)
{
    this->value = value;
}

bool Label::pointInside(int x, int y)
{
	return (y == top) && (x >= left) && (x <= left + value.size());
}

void Label::draw(Graphics& g, int x, int y, size_t z)
{
	if (!z)
	{
		g.setForeground(fontColor);
		g.setBackground(backgroundColor);
		g.write(x + left, y + top, value);
	}

}
