#define _CRT_SECURE_NO_WARNINGS

#include "NumericBox.h"
#include "TextBox.h"
#include "Button.h"

void NumericBoxUp(Button* button)
{
	if (button != NULL)
	{
		Control* buttonParent = button->getParent();
		if ((buttonParent != NULL) && (dynamic_cast<NumericBox*>(buttonParent) != NULL))
			((NumericBox*)(buttonParent))->upOne();
	}
}

void NumericBoxDown(Button* button)
{
	if (button != NULL)
	{
		Control* buttonParent = button->getParent();
		if ((buttonParent != NULL) && (dynamic_cast<NumericBox*>(buttonParent) != NULL))
			((NumericBox*)(buttonParent))->downOne();
	}
}

NumericBox::NumericBox(short newLeft, short newTop, short newWidth, int min, int max) :
Panel(newLeft, newTop, newWidth, 1), minValue(min), maxValue(max), currentValue(min)
{
	char buf[50];
	sprintf(buf, "%d", currentValue);
	text = new TextBox(newLeft + 3, newTop, buf, newWidth - 5);
	up = new Button(newLeft, newTop, "+");
	up->setCallbackFunction(NumericBoxUp);
	down = new Button(newLeft + newWidth - 2, newTop, "-");
	down->setCallbackFunction(NumericBoxDown);
	AddControl(text);
	AddControl(up);
	AddControl(down);
}

bool NumericBox::SetValue(int newValue)
{
	if ((newValue >= minValue) && (newValue <= maxValue))
	{
		currentValue = newValue;
		char buf[50];
		sprintf(buf, "%d", currentValue);
		text->setValue(buf);
		return true;
	}
	return false;
}

void NumericBox::upOne()
{
	SetValue(GetValue() + 1);
}

void NumericBox::downOne()
{
	SetValue(GetValue() - 1);
}

