#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "object.h"
#include <assert.h>


void Object_destroy(void *self)
{
    Object *obj = self;

    if(obj) {
        if(obj->description) free(obj->description);
        free(obj);
    }
}

void Object_describe(void *self)
{
    Object *obj = self;
    printf("%s.\n",obj->description);
}

int Object_init(void *self)
{
    //do nothing really
    return 1;
}

void *Object_move(void *self, Direction direction)
{
    printf("You cant go that direction.\n");
    return NULL;
}

int Object_attack(void *self, int damage)
{
    printf("You cant attack that\n");
    return 0;
}

void *Object_new(size_t size, Object proto, char *description)
{
    // setup the default functions in case they arent set
    if(!proto.init) proto.init = Object_init;
    if(!proto.describe) proto.describe = Object_describe;
    if(!proto.attack) proto.attack = Object_attack;
    if(!proto.move) proto.move = Object_move;

    // This seems weird, but we can make a struct of one size,
    // then point a different pointer at it to "cast" it.
   Object *el = calloc(1, size);
   *el = proto;

   // copy the description over.
   el->description = strdup(description);

   // initialize it with whatever init we were given.
    if(!el->init(el)) {
        // looks like it didnt initialize properly.
        el->distroy(el);
        return NULL;

    } else {
        // all done we make an Object of any type.
        return el;


        }
    }



