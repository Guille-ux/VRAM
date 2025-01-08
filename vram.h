#define RAM_LEN 134217728

typedef struct {
	const char name[6];
	char data;
	char free = 1;
} Var;

Var virtual_ram[RAM_LEN];

void ram_init() {
	for (int i = 0; i < RAM_LEN; i++) {
		virtual_ram[i].free = 1;
	}
}

int new_var(const char *name, char data) {
	int res = search_var();
	if (res > 0) {
		return 0;
	}
	for (int i = 0; i < RAM_LEN; i++) {
		if (virtual_ram[i].free) {
			virtual_ram[i].free = 0;
			for (int f = 0; f < 6; f++) {
				virtual_ram[i].name[f] = name[f];
			}
			return 1;
		}
	}
}
int search_var(const char *name) { // ALL VARS NEED TO FINNISH IN FIN_SYMBOL AT LIBS.H
	for (int i = 0; i < RAM_LEN; i++) {
		if (mystrcmp(virtual_ram[i].name, name)) {
			if (virtual_ram[i].free) {
				return i;
			}
		}
	}
	return -1;
}
void delete_var(const char *name) {
	int pos = search_var(name);
	if (pos > 0) {
		virtual_ram[pos].free = 1;
	}
}

void write_var(const char *name, char data) {
	int pos = search_var(name);
	if (pos > 0) {
		virtual_ram[pos].data = data;
	}
}

char read var(const char *name) {
	int pos = search_var(name);
	if (pos > 0) {
		return virtual_ram[pos].data;
	}
	return -1;
}
