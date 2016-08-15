/*
 * test_struct.h
 *
 * Copyright © 2016 Franco Masotti <franco.masotti@student.unife.it>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE file for more details.
 */

#if !defined TEST_STRUCT_H
#define TEST_STRUCT_H

#if defined SIMPLE_TEST
typedef int elementObject;

#elif defined EXTENDED_TEST
struct VertexObject
{
    unsigned int id;
    char *color;
    int d;
    int f;
};

typedef struct VertexObject elementObject;

#endif

#endif
