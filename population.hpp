#ifndef MUHGENES_POPULATION_H
#define MUHGENES_POPULATION_H

#include <list>

namespace MuhGenes {

class Population {
  private:
    int genome_size;
    int gene_size;
  public:
    int population_size;
    list <Genome> genomes;
    
    Population();
    
    void population_setup(int in, int igenome_n, int igene_n);
    void breed_ongene();
    void evaluate();
    void add_genome();
    void delete_genome(int n);
    
    void print() const;
    void print_avg_fitness() const;
    double get_avg_fitness() const;
};

} // namespace MuhGenes

#endif // MUHGENES_POPULATION_H
