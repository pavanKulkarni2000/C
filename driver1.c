#include<dlfcn.h>
#include<stdio.h>
#include<stdlib.h>
typedef void (*shared)(void);
int main()
{void *module;
char *err;
shared function;
module=dlopen("libhello.so",RTLD_LAZY);
if(!module)
{printf("unable to open dll\n");
return 0;
}
dlerror();
function=dlsym(module,"hello");
if((err=dlerror()))
{printf("couldn't find : %s",err);printf("\n");
return 0;}
  
(*function)();
dlclose(module);
return 0;
}
