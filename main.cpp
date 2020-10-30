#include "ann.h"
#include <emscripten.h>

int add_one(int x);
int count_chars(char* x);
void load_layer(int a, int b, char* type, char* cell_type);

ReLU relu;
Layer live_layer;

extern "C" {

  int main() {
    printf("Hello World\n");
    EM_ASM( InitWrappers() );
    printf("Initialization Complete\n");
  }

  void test() {
    printf("button test\n");
  }

  void int_test(int num) {
    int x;
    x = add_one(num);
    printf("int test=%d\n", x);
  }

  void float_test(float num) {
    printf("float test=%f\n", num);
  }

  void string_test(char* str) {
    printf("string test=%s\n", str);

    int x = count_chars(str);
    printf("int test=%d\n", x);
  }

  void load_layer_export (int a, int b, char* type, char* cell_type) {

    live_layer.inputs = a;
    live_layer.outputs = b;

    if(type == "dense") {
      live_layer.type = &relu;
    }

    load_layer(a, b, type, cell_type);

  }

}

void load_layer (int a, int b, char* type, char* cell_type) {

  char *output;
  output = type;

  printf("%d,", live_layer.inputs);
  printf("%d\n", live_layer.outputs);
  printf("%s\n", live_layer.type);
//  printf("%s\n", live_layer.cell_type);
}

int add_one(int x) {
  return ++x;
}

int count_chars(char* x) {

  return strlen(x);

}
