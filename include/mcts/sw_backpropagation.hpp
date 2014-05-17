/*
 * File:   swb_backpropagation.hpp
 * Author: batman
 *
 * Created on August 2, 2013, 3:38 PM
 */

#ifndef SW_BACKPROPAGATION_H
#define SW_BACKPROPAGATION_H

#include "backpropagation_strategy.hpp"
#include "running_stats.hpp"

namespace mcts {

// TODO rename this to Average- or MeanBackpropagationStrategy
/**
 * class SampleWeightedBackpropagationStrategy
 * Backpropagates the mean of every node.
 **/
class SampleWeightedBackpropagationStrategy : public BackpropagationStrategy {
public:
  RunningStats stats;

  SampleWeightedBackpropagationStrategy() : stats() {}

  virtual void on_backpropagate(double value) { stats.push(value); }

  virtual double ev() { return stats.mean(); }

  virtual double std_deviation() { return stats.standard_deviation(); }

  virtual double variance() { return stats.variance(); }

  virtual int nb_samples() { return stats.num_data_values(); }

  virtual BackpropagationStrategy *create() {
    return new SampleWeightedBackpropagationStrategy();
  }
};
}

#endif /* SWB_BACKPROPAGATION_H */
