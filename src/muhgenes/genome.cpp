#include "genome.hpp"

#include <iostream>

using namespace std;

namespace MuhGenes {

Genome::Genome(int igenome_size, int igene_size)
  : genome_size(igenome_size)
  , gene_size(igene_size)
  , fitness(-1.0)
  , genes()
{
  genes.reserve(genome_size);
  for (int i = 0; i < genome_size; i++) {
    genes.emplace_back(gene_size);
  }
}

std::ostream& operator<<(std::ostream& out, const Genome& genome)
{
  for (auto&& gene : genome.genes) {
    out << gene;
  }
  if (genome.fitness != -1.0) {
    out << " fitness: " << genome.fitness;
  }
  return out;
}

} // namespace MuhGenes
