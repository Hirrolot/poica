/*
 * MIT License
 *
 *
 * Copyright (c) 2020 Hirrolot
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
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <poica.h>

#include <stdio.h>

interface(Animal, void (*noise)(void *self););

record(Dog, field(counter, int));
record(Cat, field(counter, int));

void dogNoise(void *self) {
    Dog *dog = (Dog *)self;
    dog->counter++;
    printf("Woof! Counter: %d\n", dog->counter);
}

void catNoise(void *self) {
    Cat *cat = (Cat *)self;
    cat->counter++;
    printf("Meow! Counter: %d\n", cat->counter);
}

const VTable(Animal) VTable(Animal, Dog) = {dogNoise};
const VTable(Animal) VTable(Animal, Cat) = {catNoise};

/*
 * Output:
 * Woof! Counter: 1
 * Woof! Counter: 2
 * Woof! Counter: 3
 * Meow! Counter: 1
 * Meow! Counter: 2
 */
int main(void) {
    Dog dog = {.counter = 0};
    Cat cat = {.counter = 0};

    Animal animal;

    animal.self.mut = &dog;
    animal.vtable = &VTable(Animal, Dog);

    animal.vtable->noise(animal.self.mut);
    animal.vtable->noise(animal.self.mut);
    animal.vtable->noise(animal.self.mut);

    animal.self.mut = &cat;
    animal.vtable = &VTable(Animal, Cat);

    animal.vtable->noise(animal.self.mut);
    animal.vtable->noise(animal.self.mut);
}
