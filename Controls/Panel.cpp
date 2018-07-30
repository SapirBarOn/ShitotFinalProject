#include "Panel.h"

Panel::Panel(short newLeft, short newTop, short newWidth, short newHeight) :
Control(newLeft, newTop), width(newWidth), height(newHeight)
{
}

Panel::~Panel()
{
	for (std::vector<Control*>::iterator it = controls.begin(); it != controls.end(); ++it)
		delete *it;
}

void Panel::AddControl(Control* control)
{
	controls.push_back(control);
	control->setParent(this);
}

void Panel::setFontColor(Color newColor)
{
	Control::setFontColor(newColor);
	for (std::vector<Control*>::iterator it = controls.begin(); it != controls.end(); ++it)
		(*it)->setFontColor(newColor);
}

void Panel::setBackgroundColor(Color newColor)
{
	Control::setBackgroundColor(newColor);
	for (std::vector<Control*>::iterator it = controls.begin(); it != controls.end(); ++it)
		(*it)->setBackgroundColor(newColor);
}

void Panel::draw(Graphics& g, int x, int y, size_t z)
{
	for (std::vector<Control*>::iterator it = controls.begin(); it != controls.end(); ++it)
		(*it)->draw(g, x, y, z);
}

bool Panel::pointInside(int x, int y)
{
	for (std::vector<Control*>::iterator it = controls.begin(); it != controls.end(); ++it)
	{
		if ((*it)->pointInside(x, y))
			return true;
	}
	return false;
}

void Panel::mousePressed(int x, int y, bool isLeft)
{
	for (std::vector<Control*>::iterator it = controls.begin(); it != controls.end(); ++it)
	{
		if ((*it)->pointInside(x, y))
		{
			(*it)->mousePressed(x, y, isLeft);
			break;
		}
	}
}

void Panel::getAllControls(vector<Control*>* allControls)
{
	for (std::vector<Control*>::iterator it = controls.begin(); it != controls.end(); ++it)
	{
		if (dynamic_cast<Panel*>(*it) == NULL)
		{
			allControls->push_back(*it);
		}
		else
		{
			(*it)->getAllControls(allControls);
		}
	}
}
