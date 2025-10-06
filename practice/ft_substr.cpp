#include <stdio.h>
#include <cstdlib>
#include <string> 

char *ft_substr(char *string, size_t pos, size_t len) {
	int i = 0;
	char *newstr = (char *)malloc(sizeof(char) * len);
	while (i < (int)pos) {
		i++;
	}

	int j = 0;

	while (0 < len) {
		newstr[j] = string[i];
		j++;
		i++;
		len--;
	}

	return newstr;
}

int main() {
	char s[] = "Hello world.";
	char *result = ft_substr(s, 3, 3);

	printf("%s\n", result);

}