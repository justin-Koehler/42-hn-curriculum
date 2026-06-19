void swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int my_strlen(char *s)
{
    int i;
    i = 0;
    while (s[i] != '\0')
        i++;
    return(i);
}

void ft_reverse(char *s)
{
    int i;
    int j;
    char tmp;

    i = 0;
    j = my_strlen(s) - 1;

    while (i < j)
    {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }
}


char *ft_strcpy(char *dest, char *src)
{
    int i;

    i = 0;

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return(dest);
}

char *ft_strcat(char *dest, char *src)
{
    int i;
    int j;

    i = 0;
    j = 0;

    while (dest[i] != '\0')
        i++;
    while (src[j] != '\0')
    {
        dest[i] = src[j];
        j++;
        i++;
    }
    dest[i] = '\0';
    return(dest);

}


int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] != '\0')
    {
        if (s1[i] != s2[i])
            return(s1[i] - s2[i]);
        i++;
    }
        return(0);
}