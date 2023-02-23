#include<stdio.h>

typedef struct Animal
{
    int age;
    int (*getAge)(struct Animal *);
    void (*setAge)(struct Animal *, int);
}Animal;

int getAge(Animal *animal)
{
    return animal->age;
}

void setAge(Animal *animal, int age)
{
    animal->age = age;
}


Animal animalConstructor(int age)
{
    Animal animal;
    animal.age = age;
    animal.getAge = getAge;
    animal.setAge = setAge;
    return animal;
}


int main(int argc, char *argv[])
{
    Animal animal = animalConstructor(20);
    animal.setAge(&animal, 100);
    printf("animal age is %d\n", animal.getAge(&animal));
    return 0;
}
