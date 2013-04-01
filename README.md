# How to use it

## Via CMake

```
mkdir build
cd build
cmake ..
make install

gcc -o your_c_prog your_c_prog.c -luser_malloc 
g++ -o your_cpp_prog your_cpp_prog.cpp -luser_mallc

./your_c_prog
./your_cpp_prog
```

## Via GCC

```
g++ -fpic -c user_malloc.cpp
g++ -shared -o libuser_malloc.so user_malloc.o -ldl

gcc -L./ -o your_c_prog your_c_prog.c -luser_malloc
g++ -L./ -o your_cpp_prog your_cpp_prog.cpp -luser_mallc

export LD_LIBRAY_PATH=$PWD
./your_c_prog
./your_cpp_prog
```

