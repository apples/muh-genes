#ifndef MUHGENES_GENOME_HPP
#define MUHGENES_GENOME_HPP

#include "gene.hpp"

#include <vector>

namespace MuhGenes {

class Genome {
    int genome_size;
    int gene_size;
    
  public:
    double fitness;
    std::vector <Gene> genes;
    
    Genome(int igenome_size, int igene_size);
    
    void print() const;
};

} // namespace MuhGenes

#endif // MUHGENES_GENOME_HPP
