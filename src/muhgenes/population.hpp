#ifndef MUHGENES_POPULATION_HPP
#define MUHGENES_POPULATION_HPP

#include "genome.hpp"

#include <list>
#include <random>

namespace MuhGenes {

class Population {
    int genome_size;
    int gene_size;
    
  public:
    int population_size;
    std::list <Genome> genomes;
    
    Population(int in, int igenome_n, int igene_n);
    
    void breed_ongene();
    void evaluate();
    void add_genome();
    void delete_genome(int n);
    
    void print_avg_fitness();
    double get_avg_fitness();
    
    void print() const;
};

} // namespace MuhGenes

#endif // MUHGENES_POPULATION_HPP
