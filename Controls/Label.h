#pragma once

#include "../Common/Control.h"
#include <string>


using namespace std;

class Label: public Control
{   
	protected:
        string value;
    public:
        Label(string);
		Label(short newLeft, short newTop, string val);
		string getValue();
        void setValue(string);
        void draw(Graphics& g, int x, int y, size_t z);
		virtual bool pointInside(int x, int y);
};
