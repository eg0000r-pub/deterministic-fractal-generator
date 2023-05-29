//
// Created by egor on 5/29/23.
//

#include "variations.h"

using Eigen::Vector3f;
using namespace std;

static const float a = 2.0f;
static const Vector3f lattice[] = {
        {a, a, a},
        {a, a, -a},
        {a, -a, a},
        {a, -a, -a},
        {-a, a, a},
        {-a, a, -a},
        {-a, -a, a},
        {-a, -a, -a},
        {a, a, 0.0f},
        {a, -a, 0.0f},
        {-a, a, 0.0f},
        {-a, -a, 0.0f},
        {a, 0.0f, a},
        {a, 0.0f, -a},
        {-a, 0.0f, a},
        {-a, 0.0f, -a},
        {0.0f, a, a},
        {0.0f, a, -a},
        {0.0f, -a, a},
        {0.0f, -a, -a}
};

Aggregate getAggregateTypeC(int n_iter) {
    Aggregate aggregate;
    aggregate.assign(lattice, lattice + sizeof(lattice)/sizeof(lattice[0]));

    float distance = 3.0f;
    for (int i = 0; i < n_iter; i ++) {
        Aggregate newAggregate;
        for (auto const & pos : lattice) {
            for (auto const & pp : aggregate) {
                newAggregate.emplace_back(pp+pos*distance);
            }
        }
        aggregate = newAggregate;
        distance *= 3.0f;
    }

    return aggregate;
}