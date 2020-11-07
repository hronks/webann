em++ main.cpp ^
ann.cpp ^
-o build/index.html ^
--emrun ^
--shell-file shell.html ^
-s NO_EXIT_RUNTIME=1 -s ^
EXPORTED_FUNCTIONS="['_test', '_string_test', '_int_test', '_float_test', '_main', '_load_layer_export']" ^
-s EXTRA_EXPORTED_RUNTIME_METHODS="['cwrap', 'ccall']"^
&& ^
emrun build/index.html
