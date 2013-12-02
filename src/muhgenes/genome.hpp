#ifndef MUHGENES_GENOME_HPP
#define MUHGENES_GENOME_HPP

#include "gene.hpp"

#include <iostream>
#include <vector>

namespace MuhGenes {

class Genome {
    int genome_size;
    int gene_size;
    
  public:
    double fitness;
    std::vector <Gene> genes;
    
    Genome(int igenome_size, int igene_size);
};

std::ostream& operator<<(std::ostream& out, const Genome& genome);

} // namespace MuhGenes

#endif // MUHGENES_GENOME_HPP
