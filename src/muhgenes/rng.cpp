#include "rng.hpp"

using namespace std;

namespace MuhGenes {

mt19937& get_rng()
{
    static mt19937 rng (random_device{}());
    return rng;
}

double droll()
{
    static uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(get_rng());
}

int iroll(int n)
{
    uniform_int_distribution<int> dist(0, n);
    return dist(get_rng());
}

} // namespace MuhGenes
