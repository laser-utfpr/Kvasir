
#include <X11/Xlib.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>

#ifndef _MOUSEPOINTER_H_
#define _MOUSEPOINTER_H_

class MousePointer{
private:
    int _inicialEixoX, _inicialEixoY;
    int _atualEixoX, _atualEixoY;

//--coisas do mouse
    Display *_dpy;
	Window _root;
	Window _retRoot;
	Window _retChild;
	int _rootX;
	int _rootY;
	int _winX;
	int _winY;
    int i;
	unsigned int _mask;
	XEvent _click;
	void parar();
	int botao;

public:
     void _calibrar();
    MousePointer();
    ~MousePointer(){};
    int getEixoX();
    int getEixoY();
};
#endif
