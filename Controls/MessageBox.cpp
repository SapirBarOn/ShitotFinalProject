#include "MessageBox.h"
#include "Label.h"
#include "Button.h"

void MessageBoxClickOK(Button* button)
{
	if (button != NULL)
	{
		Control* buttonParent = button->getParent();
		if ((buttonParent != NULL) && (dynamic_cast<SpecialMessageBox*>(buttonParent) != NULL))
			((SpecialMessageBox*)(buttonParent))->setClickedButton("OK");
	}
}

void MessageBoxClickCancel(Button* button)
{
	if (button != NULL)
	{
		Control* buttonParent = button->getParent();
		if ((buttonParent != NULL) && (dynamic_cast<SpecialMessageBox*>(buttonParent) != NULL))
			((SpecialMessageBox*)(buttonParent))->setClickedButton("Cancel");
	}
}

SpecialMessageBox::SpecialMessageBox(short newLeft, short newTop, short newWidth, string message) : Panel(newLeft, newTop, newWidth, 3)
{
	text = new Label(newLeft + newWidth / 4, newTop, message);
	okButton = new Button(newLeft + newWidth / 8, newTop + 2, "OK");
	okButton->setCallbackFunction(MessageBoxClickOK);
	cancelButton = new Button(newLeft + 4 * newWidth / 6, newTop + 2, "Cancel");
	cancelButton->setCallbackFunction(MessageBoxClickCancel);
	AddControl(text);
	AddControl(okButton);
	AddControl(cancelButton);
}

string SpecialMessageBox::getClickedButton()
{
	return clickedButton;
}
void SpecialMessageBox::setClickedButton(string buttunName)
{
	clickedButton = buttunName;
}
