#include <ctype.h>
#include <string.h>

void stripPunctuation(char *s, char *o) {
  int j = 0;

  for (int i = 0; i < strlen(s); i++) {
    if (!ispunct(s[i]) && !isspace(s[i])) {
      o[j] = tolower(s[i]);
      j++;
    }
  }

  o[j] = '\0';
}
