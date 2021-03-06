/*
 * Coroutine internals
 *
 * Copyright (c) 2011 Kevin Wolf <kwolf@redhat.com>
 * Copyright (c) 2016 Cyberhaven <vitaly@cyberhaven.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef COROUTINE_INT_H
#define COROUTINE_INT_H

#include "coroutine.h"

typedef enum {
    COROUTINE_YIELD = 1,
    COROUTINE_TERMINATE = 2,
} CoroutineAction;

struct Coroutine {
    CoroutineEntry *entry;
    void *entry_arg;
    Coroutine *caller;
};

Coroutine *coroutine_new(uint64_t stack_size);
void coroutine_delete(Coroutine *co);
CoroutineAction coroutine_switch(Coroutine *from, Coroutine *to, CoroutineAction action);

#endif
