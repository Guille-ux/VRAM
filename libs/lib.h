#define FIN_SYMBOL '_'

int vram_len(const char *string) {
    int length = 0;
    unsigned char ch;
    while ((ch = string[length]) != FIN_SYMBOL) {
        length++;
    }

    return length;
}
int vram_strcmp(const char *str1, const char *str2) {
	if (vram_len(str1) != vram_len(str2)) {
		return 0;
	} else {
		for (int i = 0; i < vram_len(str1); i++) {
			if (str1[i] != str2[i]) {
				return 0;
			}
		}
	}
	return 1;
}
