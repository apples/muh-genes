#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "genetic.h"
using namespace std;

int main(int argc, char **argv)
{
  Population p;

  p.population_setup(1000, 10, 4);

  double fitness = 0;
  
  while (fitness < 1.0 - 0.0001) {
    p.breed_ongene();
    fitness = p.get_avg_fitness();
    printf("%f, \n", fitness);
  }

  return 0;
}
