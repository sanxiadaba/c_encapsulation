#include<stdio.h>

struct Animal {
	int age;
	int (*getAge)(struct Animal *);
	void (*setAge)(struct Animal *, int);
};

int getAge(struct Animal *animal) {
	return animal->age;
}

void setAge(struct Animal *animal, int age) {
	animal->age = age;
}


void animalConstructor(\
                       struct Animal *animal, int age, \
                       int (*getAge)(struct Animal *), \
                       void (*setAge)(struct Animal *, int)) {
	animal->age = age;
	animal->getAge = getAge;
	animal->setAge = setAge;
}


int main(int argc, char *argv[]) {
	struct Animal animal;
	animalConstructor(&animal, 20, getAge, setAge);
	animal.setAge(&animal, 100);
	printf("animal age is %d\n", animal.getAge(&animal));
	return 0;
}
