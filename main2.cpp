#include "ann2.h"
#include <emscripten/bind.h>

EMSCRIPTEN_BINDINGS(my_module) {

  emscripten::class_<Layer>("Layer")
    .constructor<std::string, int, int>()
    .property("type", &Layer::type)
    .property("inputs", &Layer::inputs)
    .property("outputs", &Layer::outputs);

  emscripten::class_<DenseDoubleLayer, emscripten::base<Layer>>("DenseDoubleLayer");

  emscripten::class_<AnnWrap>("AnnWrap")
    .constructor()
    .function("push_back_layer", &AnnWrap::push_back_layer)
    .function("pop_back_layer", &AnnWrap::pop_back_layer)
    .function("set_cost_funct", &AnnWrap::set_cost_funct)
    .function("signature", &AnnWrap::signature);
//    .property("signature", &AnnWrap::signature);
}
