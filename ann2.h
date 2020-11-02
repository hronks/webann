#include <iostream>
#include <vector>
#include <string>

struct ActFunctBase {

  std::string type;

  ActFunctBase(std::string t) {
    type = t;
  }

};

template<typename T> struct ActFunct: public ActFunctBase {

  ActFunct(int a, int b):ActFunctBase("DenseDoubleLayer") {
    
  }

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

  DenseDoubleLayer(int a, int b):Layer("DenseDoubleLayer", a, b) {

  }

};

struct AnnWrap {

  std::vector<Layer*> layer;

  void push_back_layer(
    std::string layer_type_t,
    std::string layer_value_type_t,
    std::string layer_cell_type_t,
    int inputs_t, int outputs_t) {

    if(layer_type_t == "dense") {
      if(layer_value_type_t == "double") {
        DenseDoubleLayer *ptr = new DenseDoubleLayer(inputs_t, outputs_t);
        layer.push_back(ptr);
      }
    }
  }

  void pop_back_layer() {

    delete layer[layer.size() - 1];
    layer.pop_back();

  }

  std::string signature() {

    std::string temp;
    temp = "";

    for(int i = 0; i < layer.size(); ++i) {
      temp += "[";
      temp += layer[i]->type;
      temp += ", ";
      temp += std::to_string(layer[i]->inputs);
      temp += ", ";
      temp += std::to_string(layer[i]->outputs);
      temp += "]";
      if(i < layer.size()-1) temp += " -> ";
    }

    return temp;
  }

};
