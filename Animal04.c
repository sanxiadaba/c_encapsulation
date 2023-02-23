#include<stdio.h>

#define new

typedef struct Animal {
	int age;
	int (*getAge)(void);
	void (*setAge)(int);
} Animal;


int n = 0;

#define Animal(num) __Animal(num,n)

#define __Animal(num,n) ({             		\
		Animal animal_##n;        			\
		animal_##n.age = num;           	\
		int getAge_##n() {					\
			return animal_##n.age;			\
		}									\
		void setAge_##n(int age) {			\
			animal_##n.age = age;			\
		}									\
		animal_##n.getAge = getAge_##n;     \
		animal_##n.setAge = setAge_##n;    	\
		n++;								\
		animal_##n;                     	\
})



int main(int argc, char *argv[]) {
	Animal animal_01 = new Animal(1);
	Animal animal_02 = new Animal(2);
	animal_01.setAge(100);
	animal_02.setAge(200);
	printf("animal_01 age is %d\n", animal_01.getAge());
	printf("animal_02 age is %d\n", animal_02.getAge());
	return 0;
}
