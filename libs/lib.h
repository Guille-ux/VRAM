#define FIN_SYMBOL '_'

int len(const char *string) {
    int length = 0;
    unsigned char ch;
    while ((ch = string[length]) != FIN_SYMBOL) {
        length++;
    }

    return length;
}
int mystrcmp(const char *str1, const char *str2) {
	if (len(str1) != len(str2)) {
		return 0;
	} else {
		for (int i = 0; i < len(str1); i++) {
			if (str1[i] != str2[i]) {
				return 0;
			}
		}
	}
	return 1;
}
