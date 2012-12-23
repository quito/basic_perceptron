
#ifndef GRAPHIC_HPP_
# define GRAPHIC_HPP_

# include <SDL/SDL.h>

class Graphic
{
private:
  unsigned	_x;
  unsigned	_y;
  SDL_Surface	*_screen;

public:

  Graphic(unsigned x, unsigned y):
    _x(x),
    _y(y),
    _screen(NULL)
  {
    SDL_Init(SDL_INIT_VIDEO);
    _screen = SDL_SetVideoMode(_x, _y, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("neural network", NULL);
    SDL_FillRect(_screen, NULL, SDL_MapRGB(_screen->format, 0, 0, 0));
  }
  
  ~Graphic()
  {
    SDL_Quit();
  }

  void update(void)
  {
    SDL_Flip(_screen);
  }

  void PutPixel(int x, int y, unsigned long pixel)
  {
    if (!_screen)
      return ;
    int bpp = _screen->format->BytesPerPixel;
    unsigned char *p = (unsigned char *)_screen->pixels + y * _screen->pitch + x * bpp;
    if (bpp==4)
      *(unsigned long*)p = pixel;
  }
};

#endif
