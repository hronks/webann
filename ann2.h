#include <iostream>
#include <vector>
#include <string>

struct Layer {

  int inputs;
  int outputs;

  Layer(int a, int b) {
    inputs = a;
    outputs = b;
  }

  void test1() {
    inputs = 3;
  }

  int test2() {
    return inputs * outputs;
  }
};

struct DenseDoubleLayer: public Layer {

  std::vector<double> input;
  std::vector<double> output;

  DenseDoubleLayer(int a, int b):Layer(a, b) {

  }

};
