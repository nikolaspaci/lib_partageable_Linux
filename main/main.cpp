
#include <iostream>
#include <dlfcn.h>

int main(int argc, char *argv[])
{
	char *error;
	void *libComposant1;
	void *libComposant2;
	int (*composant1)(int,int);
	int (*composant2)(int,int);
	char *(*getComposant1Version)();
	
	libComposant1 = dlopen (argv[1], RTLD_LOCAL|RTLD_LAZY);
	if (!libComposant1) {
		fputs (dlerror(), stderr);
        exit(1);
    }
	
	libComposant2 = dlopen (argv[2], RTLD_LOCAL|RTLD_LAZY);
	if (!libComposant2) {
		fputs (dlerror(), stderr);
		exit(1);
    }
	
	int data1=3;
	int data2=5;

	int valeur1;
	int valeur2;

	composant1 = (int (*)(int, int)) dlsym(libComposant1, "_Z10composant1ii");
	if ((error = dlerror()) != NULL)  {
		fputs(error, stderr);
		exit(1);
    }
	composant2 = (int (*)(int, int)) dlsym(libComposant2, "_Z10composant2ii");
	if ((error = dlerror()) != NULL)  {
		fputs(error, stderr);
		exit(1);
    }
	
	valeur1=composant1(data1,data2);
	valeur2=composant2(data1,data2);

	getComposant1Version=(char *(*)()) dlsym(libComposant1, "_Z20getComposant1Versionv");
	if ((error = dlerror()) != NULL)  {
		fputs(error, stderr);
		exit(1);
    }
	std::cout << getComposant1Version() << std::endl;
	std::cout << "valeur 1 :" << valeur1 << " valeur 2 :" << valeur2 << std::endl;
	dlclose(libComposant1);
	dlclose(libComposant2);
}
