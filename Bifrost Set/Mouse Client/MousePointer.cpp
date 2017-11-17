#include "MousePointer.h"
MousePointer::MousePointer(){
    _dpy = XOpenDisplay(NULL);
	_root = XDefaultRootWindow(_dpy);
    _calibrar();
}


int MousePointer::getEixoX(){ //--Captura coordenada X do mouse
    if(XQueryPointer(_dpy, _root, &_retRoot, &_retChild, &_rootX, &_rootY, &_winX, &_winY, &_mask)){
    //--Faz o Offset!
        _atualEixoX = (-1)*(_inicialEixoX-_rootX);
    }
    return _atualEixoX;
}//--GET EIXO X

int MousePointer::getEixoY(){ //--Captura coordenada Y do mouse
    if(XQueryPointer(_dpy, _root, &_retRoot, &_retChild, &_rootX, &_rootY, &_winX, &_winY, &_mask)){
    //--Faz o Offset!
        _atualEixoY =_inicialEixoY-_rootY;
    }
    return _atualEixoY;
}//--GET EIXO Y

void  MousePointer::_calibrar(){//--Obtem o tamanho da tela e com isso calibra automaticamente o mouse

 Display* pdsp = NULL;
 Screen* pscr = NULL;
 int w,h;
 pdsp = XOpenDisplay( NULL );

 if ( !pdsp ) {
  fprintf(stderr, "Failed to open default display.\n");
 }

    pscr = DefaultScreenOfDisplay( pdsp );
 if ( !pscr ) {
  fprintf(stderr, "Failed to obtain the default screen of given display.\n");
 }


 w = pscr->width;
 h = pscr->height;
 _inicialEixoX = w/2;
 _inicialEixoY = h/2;

 XCloseDisplay( pdsp );
}//--Fim da calibração
void MousePointer::parar()
{

  /*      XNextEvent(_dpy,&_click);
        switch(_click.type)
        {
            case ButtonRelease:
                switch(_click.xbutton.button)
                {
                    case Button1:
                    _atualEixoX=0;
                    _atualEixoY=0;
                    break;
                }
        }*/
}
//verificar melhor cm fazer

