#include "Common/Graphics.h"
#include "Controls/Label.h"
#include "Controls/Button.h"
#include "Controls/TextBox.h"
#include "Controls/Panel.h"
#include "Controls/NumericBox.h"
#include "Controls/MessageBox.h"
#include "Controls/ComboBox.h"
#include "Controls/CheckList.h"
#include "Controls/RadioBox.h"
#include "Common/EventEngine.h"

void buttonFunction(Button* button)
{
	if (button != NULL)
		button->setValue("Pressed");
}

int main(int argc, char** argv)
{

//	Label l("Hello World");
	//Button l(1,2,"Hello Button");
	//TextBox l(1, 2, "Hello Button", 10);
	/*TextBox* t = new TextBox(1, 2, "Hello Button", 10);
	Panel l(1, 2, 30, 40);
	l.AddControl(t);*/
	//NumericBox l(0, 0, 8, 0, 100);
	//l.setFontColor(Color::Purple);
	//l.setBackgroundColor(Color::Orange);
	SpecialMessageBox* x = new SpecialMessageBox(13, 10, 25, "message");
	Button* b = new Button(1,2,"Hello Button");
	b->setCallbackFunction(buttonFunction);
	TextBox* t = new TextBox(17, 2, "Hello Text", 10);
	TextBox* t2 = new TextBox(17, 22, "Hello Text2", 10);
	NumericBox* n = new NumericBox(12, 7, 8, 0, 100);
	n->setFontColor(Color::Purple);
	n->setBackgroundColor(Color::Orange);
	vector<string> options;
	options.push_back("One");
	options.push_back("Two");
	options.push_back("Three");
	options.push_back("Four");
	ComboBox* cb = new ComboBox(5, 15, 17, options);
	options.clear();
	options.push_back("Five");
	options.push_back("Six");
	options.push_back("Seven");
	options.push_back("Eight");
	CheckList* cl = new CheckList(34, 20, 10, options);

	options.clear();
	options.push_back("Moshe");
	options.push_back("Yossi");
	options.push_back("Shlomo");
	options.push_back("Gil");
	RadioBox* rb = new RadioBox(47, 20, 10, options);

	Panel l(1, 2, 30, 40);
	l.AddControl(x);
	l.AddControl(b);
	l.AddControl(t);
	l.AddControl(t2);
	l.AddControl(n);
	l.AddControl(cb);
	l.AddControl(cl);
	l.AddControl(rb);
	vector<Control*> controls;
	l.getAllControls(&controls);
	for (auto it = controls.begin(); it != controls.end(); it++)
	{
		if ((*it)->canGetFocus())
		{
			Control::setFocus(**it);
			break;
		}
	}
	//	Control& l2 = l;
	EventEngine e;
	e.run(l);
}
