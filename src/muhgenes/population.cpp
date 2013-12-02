#include "population.hpp"

#include "rng.hpp"

#include <ctime>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

namespace MuhGenes {

Population::Population(int ipopulation_size, int igenome_size, int igene_size)
  : genome_size(igenome_size)
  , gene_size(igenome_size)
  , population_size(ipopulation_size)
  , genomes()
{
  for (int i = 0; i < population_size; ++i) {
    genomes.emplace_back(genome_size, gene_size);
  }
}

void Population::evaluate()
{
  int sum;
  
  for (auto&& genome : genomes) {
    if (genome.fitness == -1.0) {
      sum = 0;
      for (auto&& gene : genome.genes) {
        for (auto&& b : gene.bases) {
          sum += b;
        }
      }
      if (sum != 5) {
        genome.fitness = 1.0 / abs(5 - sum);
      } else {
        genome.fitness = 1.0;
      }
    }
  }
}

void Population::print_avg_fitness()
{
  cout << "Avg fitness: " << get_avg_fitness() << endl;
}

double Population::get_avg_fitness()
{
  evaluate();
  
  double sum = 0;
  
  for (auto&& genome : genomes) {
    if (genome.fitness > 0.0 && genome.fitness <= 1.0) {
      sum += genome.fitness;
    }
  }
  return sum / population_size;
}

void Population::breed_ongene()
{
  double time_st, time_end;

  time_st = clock();
  evaluate();
  time_end = clock();

  time_st = clock();

  vector <Genome*> lits;
  vector <bool> breed_chart (population_size);
  vector <int> breed_genomes (population_size / 2);
  int selected = 0;

  for (int i = 0; i < population_size; i++) {
    breed_chart[i] = false;
  }

  int i = 0;

  while (selected < population_size / 2) {
    i = 0;
    for (auto&& genome : genomes) {
      if (breed_chart[i] == false) {
        if (selected >= population_size / 2) break;

        if (genome.fitness > droll()) {
          breed_chart[i] = true;
          breed_genomes[selected] = i;
          lits.push_back(&genome);
          selected++;
        }
      }
      ++i;
    }
  }

  time_end = clock();


  int bred = 0;
  int breed_one;
  int breed_two;
  int fuse_gene;
  int original_size = population_size;

  time_st = clock();

  while (bred < original_size / 2) {
    breed_one = iroll(original_size/2 - 1);
    breed_two = iroll(original_size/2 - 1);

    fuse_gene = iroll(genome_size - 1);

    add_genome();

    for (int i = 0; i < genome_size; ++i) {
      if (i < fuse_gene) {
        genomes.back().genes[i] = lits[breed_one]->genes[i];
      } else {
        genomes.back().genes[i] = lits[breed_two]->genes[i];
      }
    }
    ++bred;
  }
  time_end = clock();


  time_st = clock();

  for (int i = bred; i > 0; i--) {
    delete_genome(0);
  }

  time_end = clock();
}

void Population::add_genome()
{
  genomes.emplace_back(genome_size, gene_size);
}

void Population::delete_genome(int n)
{
  genomes.pop_front();
}

std::ostream& operator<<(std::ostream& out, const Population& pop)
{
  for (auto&& genome : pop.genomes) {
    out << genome << endl;
  }
  return out;
}

} // namespace MuhGenes
