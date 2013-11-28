#include "gene.hpp"

namespace MuhGenes {

void Gene::gene_setup(int igene_size)
{
  gene_size = igene_size;
  for (int i = 0; i < gene_size; i++) {
    bases.push_back(0);
  }
  randomize();
}

void Gene::randomize()
{
  for (int i = 0; i < gene_size; i++) {
    if (drand48() > 0.5) {
      bases[i] = 1;
    } else {
      bases[i] = 0;
    }
  }
}

bool Gene::set_base(int i, bool val)
{
  if (i < gene_size && i >= 0) {
    bases[i] = val;
    return true;
  } else {
    return false;
  }
}

int Gene::get_size() const
{
  return gene_size;
}


void Gene::print() const
{
  for (int i = 0; i < gene_size; i++) {
    printf("%d", static_cast <bool> (bases[i]));
  }
  printf(" ");
}

} // namespace MuhGenes
