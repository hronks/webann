#include "ann.h"
#include <emscripten/bind.h>

EMSCRIPTEN_BINDINGS(my_module) {

  emscripten::class_<AnnWrap>("AnnWrap")
    .constructor()
    .function("push_back_layer", &AnnWrap::push_back_layer)
    .function("pop_back_layer", &AnnWrap::pop_back_layer)
    .function("set_cost_funct", &AnnWrap::set_cost_funct)
    .function("signature", &AnnWrap::signature)
    .function("layer_data", &AnnWrap::layer_data);

  emscripten::class_<AnnData>("AnnData")
    .constructor<std::string, std::string>()
    .function("get_data_string", &AnnData::get_data_string);

  emscripten::class_<State>("State")
    .constructor()
    .property("data", &State::data);

}
