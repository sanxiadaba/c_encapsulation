#include<stdio.h>

typedef struct Animal {
	int age;
	int (*getAge)(struct Animal *);
	void (*setAge)(struct Animal *, int);
} Animal;

int getAge(Animal *animal) {
	return animal->age;
}

#define new

void setAge(Animal *animal, int age) {
	animal->age = age;
}

#define Animal(num) ({		\
	Animal animal;			\
	animal.age = num;		\
	animal.getAge = getAge;	\
	animal.setAge = setAge;	\
	animal;					\
})


int main(int argc, char *argv[]) {
	Animal animal = new Animal(20);
	animal.setAge(&animal, 100);
	printf("animal age is %d\n", animal.getAge(&animal));
	return 0;
}
