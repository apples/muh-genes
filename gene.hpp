#ifndef MUHGENES_GENE_H
#define MUHGENES_GENE_H

#include <vector>

namespace MuhGenes {

class Gene {
  private:
    int gene_size;
    
  public:
    std::vector <bool> bases;
    
    void gene_setup(int igene_size);
    void randomize();
    bool set_base(int i, bool val);
    
    int get_size() const;
    
    void print() const;
};

} // namespace MuhGenes

#endif // MUHGENES_GENE_H
