#include "sse.h"

typedef struct f32_array_t {
  uint_64 length;
  float_32 * ptr;
} f32_array;

f32_array* f32_alloc(uint_64 length)
{
  f32_array* ptr = (f32_array_t*)memalign(16, 16 + length*sizeof(float_32));
  ptr->length = length;
  ptr->ptr = (float_32*)((char*)ptr + 16);
}

void f32_free(f32_array* ptr)
{
  ptr->length = 0;
  ptr->ptr = NULL;
  free(ptr);
}

f32_array* f32_init(uint_64 length, float_32 *f(uint_64))
{
  f32_array* arr = f32_alloc(length);
  float_32* ptr = arr->ptr;
  for (uint_64 i=0; i<length; i++) {
    ptr[i] = f(i);
  }
  return arr;
}

f32_array* f32_map(f32_array* src, float_32 *f(float_32))
{
  uint_64 length = src->length;
  float_32* sptr = src->ptr;
  f32_array* dst = f32_alloc(length);
  float_32* dptr = dst->ptr;
  for (uint_64 i=0; i<length; i++) {
    dptr[i] = f(sptr[i]);
  }
  return arr;
}


