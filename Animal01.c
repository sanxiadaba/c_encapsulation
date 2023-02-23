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


void animalConstructor(Animal *animal, int age)
{
    animal->age = age;
    animal->getAge = getAge;
    animal->setAge = setAge;
}


int main(int argc, char *argv[])
{
    Animal animal;
    animalConstructor(&animal, 20);
    animal.setAge(&animal, 100);
    printf("animal age is %d\n", animal.getAge(&animal));
    return 0;
}
