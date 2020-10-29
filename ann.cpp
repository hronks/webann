#include "ann.h"

void AnnWrap::print_signature() {

  for(int i = 0; i < layer.size(); ++i) {
    std::cout<<layer[i]->inputs<<",";
    std::cout<<layer[i]->type<<",";
    std::cout<<layer[i]->cell_type<<",";
  }
  std::cout<<layer[layer.size()-1]->outputs<<";";
  std::cout<<cost_function->type;
};
