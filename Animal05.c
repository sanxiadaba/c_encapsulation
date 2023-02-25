#include<stdio.h>

#define new

typedef struct Animal {
	int age;
	int (*getAge)(void);
	void (*setAge)(int);
} Animal;





#define Animal(num) ({             			\
		Animal animal;        				\
		animal.age = num;           		\
		int getAge() {						\
			return animal.age;				\
		}									\
		void setAge(int age) {				\
			animal.age = age;				\
		}									\
		animal.getAge = getAge;     		\
		animal.setAge = setAge;    			\
		animal;                     		\
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