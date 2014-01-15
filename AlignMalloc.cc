#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void *align_malloc(size_t required_bytes, size_t alignment) {
     void *p1;
     void **p2;
     size_t offset = alignment -1 + sizeof(void *);
     if( (p1 = (void *) malloc(required_bytes + offset)) == NULL) 
         return NULL;
     p2 = (void **) (((size_t) (p1) + offset) & ~(alignment-1));
     p2[-1] = p1;
     return p2;
}

void aligned_free(void *p2) {
     void * p1 = ((void**)p2)[-1];
     free(p1);
}

int main( ) {
    cout <<"size of (void *): " <<sizeof(void*)<<endl;
    void * p1 = align_malloc(sizeof(char), 16);
    *((char*)p1) = 'a';
    cout << p1 <<" : " <<*((char*)p1) <<endl;
    cout << "p1[-1] : "<<((void **)p1)[-1]<<endl;
    aligned_free(p1);
    return 0;
}
