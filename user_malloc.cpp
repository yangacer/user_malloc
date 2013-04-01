#include <iostream>
#include "dlfcn.h"

extern "C"
void* malloc(size_t size)
{
  typedef void*(*native_fn)(size_t);
  native_fn nf;
  if(0 == (nf = (native_fn)dlsym(RTLD_NEXT, "malloc")))
    return 0;
  void *byte = (*nf)(size); 
  if(!byte)
    return 0;
  else
    std::cout << "alloc\t" << byte << "\t" << size << " bytes\n";
  return byte;
}

extern "C"
void* realloc(void* ptr, size_t size)
{
  typedef void*(*native_fn)(void*, size_t);
  native_fn nf;
  if(0 == (nf = (native_fn)dlsym(RTLD_NEXT, "realloc")))
    return 0;
  void *byte = (*nf)(ptr, size); 
  if(!byte)
    return 0;
  else
    std::cout << "alloc\t" << byte << "\t" << size << " bytes\n";
  return byte;
}

extern "C"
void free(void* ptr)
{
  typedef void(*native_fn)(void*);
  native_fn nf;
  if(0 == (nf = (native_fn)dlsym(RTLD_NEXT, "free")))
    return;
  
  std::cout << "free\t" << ptr << "\n";

  return (*nf)(ptr);
}
