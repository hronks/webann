#include "ann.h"
#include <emscripten.h>

int add_one(int x);
int count_chars(char* x);
void print_network();

ReLU <double> relu;
Sigmoid <double> sigmoid;

std::vector<DenseLayer<double>> dense_layer;

AnnWrap network;

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

    if(strcmp(type,"dense") == 0) {
      if(strcmp(cell_type,"relu") == 0)
        DenseLayer<double> temp(a, b, &relu);
      if(strcmp(cell_type,"sigmoid") == 0)
        DenseLayer<double> temp(a, b, &sigmoid);
      dense_layer.push_back(temp);
      network.layer.push_back(& dense_layer[dense_layer.size()-1]);
    }

    print_network();
  }
}

void print_network () {

  for(int i = 0; i < network.layer.size(); ++i) {

    printf("hello%lu\n", network.layer.size());
  }

//  printf("%d,", live_layer.inputs);
//  printf("%d\n", live_layer.outputs);
//  printf("%s\n", live_layer.type);
//  printf("%s\n", live_layer.cell_type);
}

int add_one(int x) {
  return ++x;
}

int count_chars(char* x) {

  return strlen(x);

}
