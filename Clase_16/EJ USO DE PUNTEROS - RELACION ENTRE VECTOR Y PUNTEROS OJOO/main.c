#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, *b, *c, x, vec[5], *ptr, i;

    a = 15;
    x = a; //copia
    b = &a;
    c = b;

    printf("a: %d\nb: %d\nc: %d\nx: %d\n", a, *b, *c, x);

    *b = 13;

    printf("a: %d\nb: %d\nc: %d\nx: %d\n", a, *b, *c, x);

    ptr = vec; // ptr = &vec[0];

    for(i=0; i<5; i++){
        *(ptr+i) = (i+5);
    }

    for(i=0; i<5; i++){
        printf("%d\n", *(ptr+i));
    }

    printf("\n\n");

    for(i=0; i<5; i++){
        *(vec+i) = (i+5);
    }

    for(i=0; i<5; i++){
        printf("%d\n", *(vec+i));
    }

    printf("\n\n");

    for(i=0; i<5; i++){
        vec[i] = (i+5);
    }

    for(i=0; i<5; i++){
        printf("%d\n", vec[i]);
    }

    printf("\n\n");

    for(i=0; i<5; i++){
        ptr[i] = (i+5);
    }

    for(i=0; i<5; i++){
        printf("%d\n", ptr[i]);
    }

    return 0;
}
