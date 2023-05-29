//
// Created by egor on 5/29/23.
//

#include "variations.h"

using Eigen::Vector3f;
using namespace std;

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

Aggregate getAggregateTypeA(int n_iter) {
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
    }

    return aggregate;
}