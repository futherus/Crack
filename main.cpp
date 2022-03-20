#include <stdio.h>
#include <string.h>

const int BUFSZ = 32;

struct Vars
{
        char buffer[BUFSZ] = {};
        char greeting[BUFSZ] = "Enter password: ";
};

void success()
{
        printf("Access granted\n");
        return;
}

void denial()
{
        printf("ERROR: Access denied\n");
        return;
}

char* password(Vars* vars)
{
        char* ptr = vars->greeting;
        return ptr + 7;
}

int check()
{
        //printf("Did you know that %ld + %ld + %ld + %ld = %ld + %ld?\n",
        //         nums.a, nums.b, nums.c, nums.d, nums.a + nums.b,  nums.c + nums.d);
        
        Vars vars = {};
        
        printf("%s", vars.greeting);
        
        scanf("%s", vars.buffer);
        
        return strncmp(password(&vars), vars.buffer, 7);
}

int main()
{
        if(check() == 0)
                success();
        else
                denial();

        return 0;
}
