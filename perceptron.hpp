
#ifndef PERCEPTRON_HPP
# define PERCEPTRON_HPP

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>

class	Perceptron
{
private:
  std::vector<float>	_weight;
  static const float	_learning_constant = 0.00000005;

public:
  Perceptron(int n) :
    _weight(n)
  {
    int i = 0;
    float t[2] = {1, 1};

    srand(time(NULL));
    while (i++ < n)
      _weight[i] = t[rand() % 2];
  }

  int	activate(float s)
  {
    if (s > 0)
      return 1;
    return -1;
  }


  //inputs = {x, y, biais}
  int	feedForward(const std::vector<float> &inputs)
  {
    float	sum = 0;
    int		i = 0;
    int		size = inputs.size();
    float	bweight = 0;

    while (i++ < size)
      sum += inputs[i] * _weight[i];
    return activate(sum);
  }

  //input = {x, y, biais}
  void	train(const std::vector<float> &inputs, int desired)
  {
    int		guess = feedForward(inputs);
    float	error = (float)desired - (float)guess;
    int		i;

    for (i = 0; i < _weight.size(); i++)
      _weight[i] += _learning_constant * error * inputs[i];
  }
}
;

#endif
