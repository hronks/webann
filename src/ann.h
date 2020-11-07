#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include "maths.h"

struct ActFunctBase {

  std::string type;

  ActFunctBase(std::string t) {
    type = t;
  }

};

template<typename T> struct ActFunct: public ActFunctBase {

  T (*f) (T);

  ActFunct(T (*f_t) (T), std::string t):ActFunctBase(t) {
    f = f_t;
  }

};

template<typename T> T ReLU(T x) {
  if(x > 0) return x;
  return 0;
};

template<typename T> T Sigmoid(T x) {
  if(x > 0) return x;
  return 0;
};


struct Layer {

  std::string type;
  int inputs;
  int outputs;
  std::string cell_type;
  std::vector <ActFunctBase*> act_funct;

  Layer(std::string t, int a, int b) {
    type = t;
    inputs = a;
    outputs = b;
  }

  virtual std::string data() {};

};

struct DenseDoubleLayer: public Layer {

  std::vector<double> input;
  std::vector<double> output;

  std::vector<std::vector<double>>  weight;
  std::vector<double> bias;

  DenseDoubleLayer(int a, int b):Layer("DenseDoubleLayer", a, b) {
    input.resize(a);
    output.resize(b);

    weight.resize(b);
    srand((unsigned) time(NULL));
    for(int i = 0; i < b; ++i) {
      weight[i].resize(a);
      for(int j = 0; j < a; ++j) {
        weight[i][j] = random<double>(-(double)1/a,(double)1/a);
      }
    }

    bias.resize(b);
    for(int i = 0; i < b; ++i)
      bias[i] = random<double>(-1,1);

  }

  std::string data() {
    std::string temp = "";

    temp += "i/o: ";
    temp += std::to_string(input.size());
    temp += " -> ";
    temp += std::to_string(output.size());
    temp += "\n\nweight matrix:\n";

    for(int i = 0; i < weight.size(); ++i) {
      temp += "| ";
      for(int j = 0; j < weight[i].size(); ++j ) {
        temp += std::to_string(weight[i][j]);
        temp += " ";
      }
      temp += " |\n";
    }

    temp += "\nbias vector:\n";
    for(int i = 0; i < bias.size(); ++i) {
      temp += "| ";
      temp += std::to_string(bias[i]);
      temp += " |\n";
    }
    return temp;
  }

};

struct CostFunctBase {

  std::string type;

  CostFunctBase(std::string t) {
    type = t;
  }

};

template<typename T> struct CostFunct: public CostFunctBase {

  T (*f) (std::vector<T>, std::vector<T>);

  CostFunct(T (*f_t) (std::vector<T>, std::vector<T>), std::string t):CostFunctBase(t) {
    f = f_t;
  }

};

template<typename T> T BinaryCrossEntropy(std::vector<T> x, std::vector<T> y) {
  T temp;

  for(int i = 0; i < x.size(); ++i) {
    temp += (y[i] - x[i]) * (y[i] - x[i]);
  }
  return temp;
};

template<typename T> T Quadratic(std::vector<T> x, std::vector<T> y) {
  T temp;

  for(int i = 0; i < x.size(); ++i) {
    temp += (y[i] - x[i]) * (y[i] - x[i]);
  }
  return temp;
};

struct AnnWrap {

  std::vector<Layer*> layer;
  CostFunctBase* cost_funct;
  std::string cost_funct_type;

  void push_back_layer(std::string layer_type_t, std::string layer_value_type_t, std::string layer_cell_type_t, int inputs_t, int outputs_t);
  void pop_back_layer();
  void set_cost_funct(std::string funct_type_t, std::string value_type_t);
  std::string signature();
  std::string layer_data(int l);

};
