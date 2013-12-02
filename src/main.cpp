#include "muhgenes/muhgenes.hpp"
#include <iostream>

using namespace std;
using namespace MuhGenes;

int main(int argc, char **argv)
{
  Population p (1000, 10, 4);

  double fitness = 0;
  
  while (fitness < 1.0 - 0.0001) {
    p.breed_ongene();
    fitness = p.get_avg_fitness();
    cout << fitness << ", " << endl;
  }

  return 0;
}
