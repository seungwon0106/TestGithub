#include <stdio.h>
#include <string.h>

typedef int bool;
enum {false, true};

int main()
{
	char word[10];
	int len =0,i;
	bool isPalindrom = true; 
	
	memset(word, '\0', 10);
	printf("write the word: \n");
	//fgets(word, sizeof(word), stdin);
	//gets(word);
	scanf("%s", word);

	while(word[len] != '\0')
			len++;
//	printf("%d\n", len);

	for(i=0; i<len/2; i++)
	{
			// printf("%d %d\n", i, len-i-1);
			// printf("%c %c\n", word[i], word[len-i-1]);
			
			if(word[i] != word[len-i-1])
			{
					isPalindrom = false;
					break;
			}
			
	}
	if (isPalindrom == true)
		printf("OK\n");
	else 
			printf("ERROR\n");

	return 0;
	
}

