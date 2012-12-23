
#ifndef TRAINER_HPP_
# define TRAINER_HPP_

#include <vector>
#include "perceptron.hpp"

class Trainer
{
private:
  std::vector<float>	_inputs;
  int			_answers;

public:
  Trainer(float x, float y, int a):
    _inputs(3)
  {
    _inputs[0] = x;
    _inputs[1] = y;
    _inputs[2] = a;
    _answers = a;
  }

  const std::vector<float>	&getInputs(void) const {return _inputs;}
  int				getAnswer(void) const {return _answers;}
};

#endif
