#include "../Controls/Label.h"

class Button;
typedef void(*callbackFunction)(Button*);

class Button : public Label
{
public:
	Button(short newLeft, short newTop, string val);
	~Button();

	virtual void mousePressed(int x, int y, bool isLeft);
	void setCallbackFunction(callbackFunction func) { f = func; }

private:
	callbackFunction f;
};
