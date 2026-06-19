
int count(char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return(i);
}


void my_strdup(char *s)
{
    char *result;
    result = malloc(count(s));

    if (!result)
        return (NULL);
    
    while ()
    {
        /* code */
    }
    
}