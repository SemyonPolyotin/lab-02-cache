// Copyright 2020 Your Name <your_email>

#ifndef INCLUDE_CACHE_HPP_
#define INCLUDE_CACHE_HPP_

#include <ctime>
#include <iostream>
#include <string>
#include <vector>

const size_t Kilobyte = 1024;

class Experiment {
 public:
  Experiment();
  void Strait();
  void Reverse();
  void Random();
  friend std::ostream& operator<<(std::ostream& out,
                                  const Experiment& experiment);

 private:
  std::string travel_type;
  const std::vector<size_t> cache_size = {256 * Kilobyte, 1024 * Kilobyte,
                                          6144 * Kilobyte};
  std::vector<size_t> sizeContainer;
  std::vector<double> travelTime;
};

#endif  // INCLUDE_CACHE_HPP_
