#include <unistd.h>


char *get_next_line(int fd)
{
	static char *stash;
	char *line;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	stash = read_to_stash(fd, stash);
	if(!stash)
		return NULL;
	line = extract_line(stash);
	stash = clean_stash(stash);
	return line;
}
int ft_strlen(char *str)
{
	int i;
	i = 0;
	while(str[i])
	i++;
	return i;
}

char *extract_line(char *s)
{
	int i;
	char *line;

	if(!s || !*s)
		return NULL;
	i = 0;
	while(s[i] && s[i] != '\n')
		i++;
	line = malloc(i + 1);
	if(!line)
		return NULL;
	i = -1;
	while(s[++i] && s[i] != '\n')
		line[i] = s[i];
	if(s[i] == '\n')
		line[i] = '\0';
	line[++i] = '\0';
	return line;
}

char *clean_stash(char *s)
{
	char *new;
	int i;
	int j;

	i = 0;
	while(s[i] && s[j] != '\n')
		i++;
	if(!s[i])
		return(free(s), NULL);
	i++;
	new = malloc(ft_strlen(s+ i) + 1);
	if(!new)
		return(free(s), NULL);
	j = 0;
	while(s[i])
		new[j++] = s[i++];
	new[j] = '\0';
	free(s);
	return(new);
}

char *read_to_stash(int fd, char *s)
{
	char buf[BUFFER_SIZE];
	int bytes;
	int i;
	int j;
	char *temp;

	bytes = 1;
	while(!s || (!s|| !s[0] == 0) || (s && !find_nl(s))
}