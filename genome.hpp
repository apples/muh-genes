#ifndef MUHGENES_GENOME_H
#define MUHGENES_GENOME_H

#include <vector>

namespace MuhGenes {

class Genome {
  private:
    int genome_size;
    int gene_size;
    
  public:
    double fitness;
    std::vector <Gene> genes;
    
    Genome();
    
    void genome_setup(int igenome_size, int igene_size);
    
    void print() const;
};

} // namespace MuhGenes

#endif // MUHGENES_GENOME_H
