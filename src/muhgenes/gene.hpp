#ifndef MUHGENES_GENE_HPP
#define MUHGENES_GENE_HPP

#include <functional>
#include <vector>

namespace MuhGenes {

class Gene {
    int gene_size;
    
  public:
    std::vector <bool> bases;
    
    Gene(int igene_size);
    void randomize();
    bool set_base(int i, bool val);
    
    int get_size() const;
    
    void print() const;
};

} // namespace MuhGenes

#endif // MUHGENES_GENE_HPP
