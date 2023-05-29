//
// Created by egor on 5/29/23.
//

//
// Created by egor on 5/29/23.
//

#include "variations.h"

using Eigen::Vector3f;
using namespace std;

static const float a = 1.0f;
static const Vector3f lattice[] = {
        {a, 0.0f, -a/sqrtf(2)},
        {-a, 0.0f, -a/sqrtf(2)},
        {0.0f, a, a/sqrtf(2)},
        {0.0f, -a, a/sqrtf(2)}
};

Aggregate getAggregateTypeD(int n_iter) {
    Aggregate aggregate;
    aggregate.assign(lattice, lattice + sizeof(lattice)/sizeof(lattice[0]));

    float distance = 2.0f;
    for (int i = 0; i < n_iter; i ++) {
        Aggregate newAggregate;
        for (auto const & pos : lattice) {
            for (auto const & pp : aggregate) {
                newAggregate.emplace_back(pp+pos*distance);
            }
        }
        aggregate = newAggregate;
        distance *= 2.0f;
    }

    return aggregate;
}
