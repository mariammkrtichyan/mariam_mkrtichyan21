
// To compile gcc -o exe array.c

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef double element_type;
typedef int size_type;
element_type access(struct array* o, int index);
struct array* create(int s);


struct array
{
    element_type* start;
    size_type size;
};

size_type size(struct array* o)
{
    return o->size;
}
struct array* insertElement(array* o,element_type value, int position)
{
    int size;
    struct array* new_array;  
    size = o->size;
    new_array = create(size+1);
    for(int i=0; i<(size+1); i++)
    {
        if(i<position)
        {
            new_array->start[i] = access(o, i);
        }
        else if(i == position)
        {
            new_array->start[i] = value;
        }
        else
        {
            new_array->start[i] = access(o, (i-1));
        }
    }
    return (new_array);
}
int empty(struct array* o)
{
    return (o->size == 0);
}

size_type max_size(struct array* o)
{
    return INT_MAX;
}

element_type access(struct array* o, int index)
{
    return o->start[index];
}
struct array* create(int s)
{
   struct array* a = (struct array*)malloc(sizeof(struct array));
   a->size = s;
   a->start = (element_type*)malloc(sizeof(element_type) * s);
   return a;
}

int main()
{
    int i = 0;
    struct array* a = create(34); 
    insertElement(a, 42, 19);
    for (i = 0; i < size(a); ++i) {
        printf("a[%d]=%f\n", i, access(a, i));
    }
 
    return 0;
}

