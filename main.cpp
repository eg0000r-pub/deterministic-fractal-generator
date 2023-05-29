#include <iostream>
#include <sstream>

#include <FractalCommon/FractalCommon.h>

using Eigen::Vector3f;
using namespace std;

static constexpr int n_iter = 6;

static const float a = 1.0f/sqrtf(3.0f);
static const Vector3f dirs[] = {
        {a, a, a},
        {-a, a, a},
        {a, -a, a},
        {-a, -a, a},
        {a, a, -a},
        {-a, a, -a},
        {a, -a, -a},
        {-a, -a, -a}
};

int main() {
    Aggregate aggregate;
    aggregate.emplace_back(0.0f, 0.0f, 0.0f);

    float distance = 2.0f;
    for (int i = 0; i < n_iter; i ++) {
        Aggregate newAggregate = aggregate;
        for (auto const & dir : dirs) {
            for (auto const & pp : aggregate) {
                newAggregate.emplace_back(pp+dir*distance);
            }
        }
        aggregate = newAggregate;
        distance *= 3.0f;

        stringstream filename;
        filename << "agg_" << i << ".vtk";
        dumpVtk(aggregate, filename.str().c_str());
    }

    return 0;
}
