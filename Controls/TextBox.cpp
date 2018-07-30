#include "TextBox.h"
#include <algorithm>

TextBox::TextBox(short newLeft, short newTop, string val, int newWidth) : Label(newLeft, newTop, val), width(newWidth), cursorPosition(newLeft)
{
}

void TextBox::keyDown(int keyCode, char charecter)
{
	if ((keyCode == VK_UP) || (keyCode == VK_DOWN))
	{
		return;
	}
	if (keyCode == VK_LEFT) // left
	{
		if (cursorPosition > left)
			cursorPosition--;
	}
	else if (keyCode == VK_RIGHT) // right
	{
		if (cursorPosition < left + getValue().size())
			cursorPosition++;
	}
	else if (keyCode == VK_DELETE) // delete
	{
		int index = cursorPosition - left;
		if (index < value.size())
			value.erase(value.begin() + index, value.begin() + index + 1);
	}
	else if (keyCode == VK_BACK) // backspace
	{
		int index = cursorPosition - left - 1;
		if (index < value.size())
		{
			value.erase(value.begin() + index, value.begin() + index + 1);
			cursorPosition--;
		}
	}
	else
	{
		// write text
		int index = cursorPosition - left;
		if ((index >= 0) && (index < value.size()))
		{
			std::replace(value.begin() + index, value.begin() + index + 1, *(value.begin() + index), (char)keyCode);
			cursorPosition++;
		}
		else
		{
			if (index <= width - 2)
				value.push_back((char)keyCode);
		}
	}
}

void TextBox::draw(Graphics& g, int x, int y, size_t z)
{
	Label::draw(g, x, y, z);
	if (Control::getFocus() == this)
	{
		g.moveTo(cursorPosition, y + top);
		g.setCursorVisibility(true);
	}
}

void TextBox::mousePressed(int x, int y, bool isLeft)
{
	cursorPosition = x;
}
