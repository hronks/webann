#include "ann.h"

int main() {

  ReLU <double> relu;
  Sigmoid <double> sigmoid;
  CrossEntropy <double> cross_entropy;

  DenseLayer<double> l1(10, 32, &relu);
  DenseLayer<double> l2(32, 32, &relu);
  DenseLayer<double> l3(32, 1, &sigmoid);

  AnnWrap network;

  network.layer.push_back(&l1);
  network.layer.push_back(&l2);
  network.layer.push_back(&l3);
  network.cost_function = &cross_entropy;

  network.print_signature();
}
