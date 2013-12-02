#ifndef MUHGENES_RNG_HPP
#define MUHGENES_RNG_HPP

#include <random>

namespace MuhGenes {

std::mt19937& get_rng();

double droll();
int iroll(int n);

} // namespace MuhGenes

#endif // MUHGENES_RNG_HPP
