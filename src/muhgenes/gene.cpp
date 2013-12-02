#include "gene.hpp"

#include "rng.hpp"

using namespace std;

namespace MuhGenes {

Gene::Gene(int igene_size)
  : gene_size(igene_size)
  , bases(gene_size, false)
{
  randomize();
}

void Gene::randomize()
{
  for (auto&& b : bases) {
    b = (droll() > 0.5);
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

std::ostream& operator<<(std::ostream& out, const Gene& gene)
{
  for (auto&& b : gene.bases) {
    out << b;
  }
  out << ' ';
  return out;
}

} // namespace MuhGenes
