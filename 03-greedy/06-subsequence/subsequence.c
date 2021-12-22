#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

void subsequence(char *s, char *t, int n, int k) {
	char ch;
	int i, count, last;
	int new_last, size;
	
	last = new_last = size = 0;
	for (ch = 'z'; ch >= 'a'; ch--) {
		count = 0;
		for (i = last; i < n; i++) {
			if (s[i] == ch) {
				count++;
			}
		}
		if (count >= k) {
			for (i = last; i < n; i++) {
            	if (s[i] == ch) {
            		t[size++] = ch;
            		new_last = i;
            	}
            }
            last = new_last;
		}
	}
	t[size] = '\0';
}

int main(int argc, char* argv[]) {
	char s[SIZE], t[SIZE];
	int n, k;
	
	scanf("%s %i", s, &k);
	n = strlen(s);
	subsequence(s, t, n, k);
	printf("%s\n", t);
	
	return 0;
}
