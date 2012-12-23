
#include <vector>
#include <iostream>
#include "perceptron.hpp"
#include "trainer.hpp"
#include "graphic.hpp"

# define NBTRAINER	100

# define WIDTH	800
# define HEIGHT	600

float	f(float x)
{
  return x + 1;
}

void	setup(Trainer **training)
{
  int			i;
  float			x;
  float			y;
  int			answer;

  for (i = 0; i < NBTRAINER; i++)
    {
      x = rand() % WIDTH;
      y = rand() % HEIGHT;
      answer = 1;
      if (y < f(x))
	answer = -1;
      training[i] = new Trainer(x, y, answer);
    }
}

int main()
{
  Graphic		gui(WIDTH, HEIGHT);
  Perceptron		p(3);
  Trainer		**training = new Trainer*[NBTRAINER];
  int			i;
  int			guess;

  float			guessingrate = 0;
  int			nb_guess = 0;
  int			sucessfullguess = 0;

  while (1)
    {
      setup(training);
      nb_guess = 0;
      sucessfullguess = 0;
      for (i = 0;i < NBTRAINER; i++)
	{
	  guess = p.feedForward(training[i]->getInputs());
	  if (guess == training[i]->getAnswer())
	      sucessfullguess++;
	  p.train(training[i]->getInputs(), training[i]->getAnswer());
	  if (guess > 0)
	    gui.PutPixel(training[i]->getInputs()[0], training[i]->getInputs()[1], 0x00FF00);
	  else
	    gui.PutPixel(training[i]->getInputs()[0], training[i]->getInputs()[1], 0xFF0000);
	  nb_guess++;
	}
      std::cout << "guessing score : " << (float)sucessfullguess / (float)nb_guess * 100.f << "%" << std::endl;
      gui.update();
    }
  return 0;
}
