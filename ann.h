#include <iostream>
#include <vector>
#include <string>


struct ActFunct {

  std::string type;

  ActFunct(std::string t = "") {
    type = t;
  }

};

template <typename T>
struct ReLU: public ActFunct {

  ReLU():ActFunct("relu") { }


};

template <typename T>
struct Sigmoid: public ActFunct {

  Sigmoid():ActFunct("sigmoid") { }


};

struct Layer {

  int inputs, outputs;
  std::string type;
  std::string cell_type;

  Layer(std::string t = "", std::string s = "", int a = 0, int b = 0) {
    type = t;
    cell_type = s;
    inputs = a;
    outputs = b;
  }

};

template <typename T>
struct DenseLayer: public Layer {

  std::vector<T> input;
  std::vector<T> output;
  std::vector<ActFunct*> act_funct;

  DenseLayer(int a = 0, int b = 0, ActFunct *f = NULL):Layer("dense", f->type, a, b) { }

};

struct CostFunction {

  std::string type;

  CostFunction(std::string t = "") {
    type = t;
  }
};

template <typename T>
struct CrossEntropy: public CostFunction {

  CrossEntropy():CostFunction("cross_entropy") { }


};

struct AnnWrap {

  std::vector<Layer*> layer;
  CostFunction *cost_function;

  void print_signature();

};
