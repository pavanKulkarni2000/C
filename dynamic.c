#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
typedef void (*function)(void);
int main()
{void * module;
char * error;
function welcome;
if(!(module=dlopen("libwelcome.so",RTLD_LAZY)))
{printf("Unable to open dll!\n");
return 0;
}
dlerror();
welcome=dlsym(module,"welcome");
if((error=dlerror()))
{printf("%s\n",error);
return 0;
}
(*welcome)();
dlclose(module);
return 0;
}

