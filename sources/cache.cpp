// Copyright 2020 Your Name <your_email>

#include "cache.hpp"

#include <random>
const size_t offset = 16;
const size_t experimentsNum = 1000;

Experiment::Experiment() {
  for (size_t i = 1.0 / 2 * cache_size[0]; i < 3.0 / 2 * cache_size[2]; i *= 2)
    sizeContainer.push_back(i);
  sizeContainer.push_back(3.0 / 2 * cache_size[2]);
}

void Experiment::Strait() {
  travel_type = "Strait";
  int plodder;
  if (!travelTime.empty()) {
    travelTime.clear();
  }
  for (const size_t& i : sizeContainer) {
    int* arr = new int[i / 4];
    for (size_t j = 0; j < i / 4; j += offset) {
      plodder = arr[j];
    }
    clock_t start_travel = clock();
    for (size_t n = 0; n < experimentsNum; ++n) {
      for (size_t j = 0; j < i / 4; j += offset) {
        plodder = arr[j];
      }
    }
    clock_t end_travel = clock();
    travelTime.push_back(static_cast<double>(end_travel - start_travel) /
                         CLOCKS_PER_SEC * experimentsNum);
    delete[] arr;
    ++plodder;
  }
}

void Experiment::Reverse() {
  travel_type = "Reverse";
  int plodder;
  if (!travelTime.empty()) {
    travelTime.clear();
  }
  for (const size_t& i : sizeContainer) {
    int* arr = new int[i / 4];
    for (size_t j = i / 4; j > 0; j -= offset) {
      plodder = arr[j - 1];
    }
    clock_t start_travel = clock();
    for (size_t n = 0; n < experimentsNum; ++n) {
      for (size_t j = i / 4; j > 0; j -= offset) {
        plodder = arr[j - 1];
      }
    }
    clock_t end_travel = clock();
    travelTime.push_back(static_cast<double>(end_travel - start_travel) /
                         CLOCKS_PER_SEC * experimentsNum);
    delete[] arr;
    ++plodder;
  }
}

void Experiment::Random() {
  travel_type = "Random";
  int plodder;
  if (!travelTime.empty()) {
    travelTime.clear();
  }
  for (const size_t& i : sizeContainer) {
    std::vector<size_t> randValues;
    int* arr = new int[i / 4];
    for (size_t j = 0; j < i / 4; j += offset) {
      plodder = arr[j];
      randValues.push_back(j);
    }
    std::random_device rd;
    std::mt19937 rnd(rd());
    std::shuffle(randValues.begin(), randValues.end(), rnd);
    clock_t startTravel = clock();
    for (size_t n = 0; n < experimentsNum; ++n) {
      for (const auto& index : randValues) {
        plodder = arr[index];
      }
    }
    clock_t endTravel = clock();
    travelTime.push_back(static_cast<double>(endTravel - startTravel) /
                         CLOCKS_PER_SEC * experimentsNum);
    delete[] arr;
    ++plodder;
  }
}

std::ostream& operator<<(std::ostream& out, const Experiment& experiment) {
  out << "investigation:\n"
      << "\ttravel_order: " << experiment.travel_type << "\n"
      << "\texperiments:\n";
  for (size_t i = 0; i < experiment.sizeContainer.size(); ++i) {
    out << "\t- experiment: \n"
        << "\t\tnumber: " << i + 1 << "\n"
        << "\t\tinput_data:\n"
        << "\t\t\tbuffer_size: " << experiment.sizeContainer[i] / Kilobyte
        << "KB\n"
        << "\t\tresults:\n"
        << "\t\t\tduration: " << experiment.travelTime[i] << "ms\n";
  }
  return out;
}
