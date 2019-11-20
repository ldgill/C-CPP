#include <assert.h>
#include <stdlib.h>

void swap3(int *a, int *b, int *c) {
     assert (a !=NULL);
     assert (b !=NULL);
     assert (c !=NULL);

     int temp = *a;
     *a = *c;
     *c = *b;
     *b = temp;
}
int main (){
    int a=1, b=2, c=3;
    swap3(&a, &b, &c);
    assert (a==3);
    assert (b==1);
    assert (c==2);
    return 0;
}
