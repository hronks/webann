#include "ann2.h"
#include <emscripten/bind.h>



EMSCRIPTEN_BINDINGS(my_module) {

  emscripten::class_<Layer>("Layer")
    .constructor<int, int>()
    .function("test1", &Layer::test1)
    .function("test2", &Layer::test2)
    .property("inputs", &Layer::inputs)
    .property("outputs", &Layer::outputs);

  emscripten::class_<DenseDoubleLayer, emscripten::base<Layer>>("DenseDoubleLayer");

}
