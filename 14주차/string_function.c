
int MyStrlen(char str[])
{
    int len = 0;
    for(len = 0; str[len] != 0; len++){
        //... 
    }

    return len;
}

void MyStrcpy(char dest[], char src[])
{
    int i = 0;
    for(i = 0; src[i] != 0; i++)
        dest[i] = src[i];
    dest[i] = 0;
}

void MyStrcat(char dest[], char src[])
{
    int i = strlen(dest);
    int j = 0;
    for(j = 0; src[j] != 0; j++)
        dest[i + j] = src[i];
    dest[i + j] = 0;
}

int MyStrcmp(char str1[], char str2[])
{
    int i = 0;
    for(i = 0; str1[i] != '\0'; i++){
        if(str1[i] != str2[i])
            return (int)str1[i] - (int)str2[i];
    }

    if(str2[i] != 0)
        return - (int)str2[i];

    return 0;
}