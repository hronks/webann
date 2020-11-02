#include "ann2.h"

void AnnWrap::push_back_layer(
  std::string layer_type_t,
  std::string layer_value_type_t,
  std::string layer_cell_type_t,
  int inputs_t, int outputs_t) {

  if(layer_value_type_t == "double") {
    if(layer_type_t == "dense") {
      DenseDoubleLayer *ptr = new DenseDoubleLayer(inputs_t, outputs_t);
      layer.push_back(ptr);
    }

    if(layer_cell_type_t == "relu") {
      layer[layer.size()-1]->cell_type = "ReLU";
      ActFunct<double> *ptr = new ActFunct<double>(&ReLU, "ReLU");
      for(int i = 0; i < layer[layer.size()-1]->outputs; ++i)
        layer[layer.size()-1]->act_funct.push_back(ptr);
    }

    if(layer_cell_type_t == "sigmoid") {
      layer[layer.size()-1]->cell_type = "Sigmoid";
      ActFunct<double> *ptr = new ActFunct<double>(&Sigmoid, "Sigmoid");
      for(int i = 0; i < layer[layer.size()-1]->outputs; ++i)
        layer[layer.size()-1]->act_funct.push_back(ptr);
    }
  }
}

void AnnWrap::pop_back_layer() {

  for(int i = 0; i < layer[layer.size() - 1]->act_funct.size(); ++i)
    delete layer[layer.size() - 1]->act_funct[i];
  delete layer[layer.size() - 1];
  layer.pop_back();

}

void AnnWrap::set_cost_funct(std::string funct_type_t, std::string value_type_t) {

  cost_funct_type = value_type_t;

  if(value_type_t == "double") {
    if(funct_type_t == "binary_cross_entropy") {
      CostFunct<double> *ptr = new CostFunct<double>(&BinaryCrossEntropy, "BinaryCrossEntropy");
      cost_funct = ptr;
    }
  }
}

std::string AnnWrap::signature() {

  std::string temp;
  temp = "";

  for(int i = 0; i < layer.size(); ++i) {
    temp += "[";
    temp += layer[i]->type;
    temp += ", ";
    temp += layer[i]->cell_type;
    temp += ", ";
    temp += std::to_string(layer[i]->inputs);
    temp += ", ";
    temp += std::to_string(layer[i]->outputs);
    temp += "]";
    temp += " -> ";
  }

  temp += cost_funct->type;
  temp += " (";
  temp += cost_funct_type;
  temp += ")";
  return temp;
}
