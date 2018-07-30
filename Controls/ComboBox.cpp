#include "ComboBox.h"
#include "TextBox.h"
#include "Button.h"

void openComboBox(Button* button)
{
	if (button != nullptr)
	{
		Control* buttonParent = button->getParent();
		if ((buttonParent != nullptr) && (dynamic_cast<ComboBox*>(buttonParent) != nullptr))
		{
			((ComboBox*)(buttonParent))->toggleListIsOpen();
			Control::setFocus(*buttonParent);
		}
	}
}

ComboBox::ComboBox(short newLeft, short newTop, short newWidth, vector<string> _options) :
Panel(newLeft, newTop, newWidth, 1), options(_options), listIsOpen(false), selectedIndex(0), tempIndex(-1)
{
	openListButton = new Button(newLeft + newWidth - 1, newTop, "V");
	AddControl(openListButton);
	openListButton->setCallbackFunction(openComboBox);
}

size_t ComboBox::GetSelectedIndex()
{
	return selectedIndex;
}

void ComboBox::SetSelectedIndex(size_t index)
{
	selectedIndex = index;
}

void ComboBox::draw(Graphics& g, int x, int y, size_t z)
{
	Panel::draw(g, x, y, z);
	if (listIsOpen)
	{
		int i = 0;
		for (std::vector<string>::iterator it = options.begin(); it != options.end(); ++it)
		{
			if (i != tempIndex)
			{
				g.setBackground(backgroundColor);
				g.setForeground(fontColor);
			}
			else
			{
				g.setBackground(fontColor);
				g.setForeground(backgroundColor);
			}
			g.write(left + x + 1, top + y + i, (*it));
			i++;
		}
	}
	else
	{
		if (selectedIndex < options.size())
			g.write(left + x + 1, top + y, *(options.begin() + selectedIndex));
		else
			g.write(left + x + 1, top + y, "");
	}
	g.setBackground(backgroundColor);
	g.setForeground(fontColor);
}

bool ComboBox::pointInside(int x, int y)
{
	if (!listIsOpen)
		return Panel::pointInside(x, y);
	return (x >= left) && (x <= left + width) && (y >= top) && (y <= top + options.size());
}

void ComboBox::mousePressed(int x, int y, bool isLeft)
{
	if (openListButton->pointInside(x, y))
	{
		openListButton->mousePressed(x, y, isLeft);
		return;
	}
	if (listIsOpen)
	{
		selectedIndex = y - top;
		listIsOpen = false;
	}
}

void ComboBox::toggleListIsOpen()
{
	listIsOpen = !listIsOpen;
	tempIndex = 0;
}

void ComboBox::getAllControls(vector<Control*>* controls)
{
	controls->push_back(this);
}

void ComboBox::keyDown(int keyCode, char charecter)
{
	if (keyCode == VK_UP) // up
	{
		if (tempIndex > 0)
			tempIndex--;
	}
	else if (keyCode == VK_DOWN) // down
	{
		if (tempIndex < options.size() - 1)
			tempIndex++;
	}
	else if ((keyCode == VK_SPACE) || (keyCode == VK_RETURN)) // space or enter
	{
		selectedIndex = tempIndex;
		listIsOpen = false;
	}
}


