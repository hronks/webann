#include "ann.h"
#include <emscripten.h>

int add_one(int x);
int count_chars(char* x);

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

  void load_layer(char* str) {
    printf("working\n");
  }

}

int add_one(int x) {
  return ++x;
}

int count_chars(char* x) {

  return strlen(x);

}
