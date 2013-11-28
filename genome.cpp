#include "genome.hpp"

namespace MuhGenes {

void Genome::print()
{
  for (int i = 0; i < genome_size; i++) {
    genes[i].print();
  }
  if (fitness != -1.0) {
    printf(" fitness: %f", fitness);
  }
  printf("\n");
}


Genome::Genome()
{
  fitness = -1.0;
}

void Genome::genome_setup(int igenome_size, int igene_size)
{
  genome_size = igenome_size;
  gene_size = igene_size;

  Gene temp;

  for (int i = 0; i < genome_size; i++) {
    genes.push_back(temp);
    genes[i].gene_setup(gene_size);
  }
}


} // namespace MuhGenes
