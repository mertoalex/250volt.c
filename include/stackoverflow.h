#include <stdio.h>
#include <string.h>
#include <assert.h>
char *_str_replace(char *str, char *orig, char *rep) {//https://stackoverflow.com/questions/4408170/for-string-find-and-replace
	static char buffer[4096];char *p;
	if(!(p = strstr(str, orig))) return str;
	strncpy(buffer, str, p-str);
	buffer[p-str] = '\0';
	sprintf(buffer+(p-str), "%s%s", rep, p+strlen(orig));
	return buffer;
}

char *str_replace(char* str, char* orig, char* rep) {
	char* ret = str;
	while (strstr(ret, orig)) ret = _str_replace(ret,orig,rep);
	return ret;
}

char* read_file(char* filename) {//https://stackoverflow.com/questions/174531/how-to-read-the-content-of-a-file-to-a-string-in-c
	char * buffer = 0;
	long length;
	FILE * f = fopen (filename, "rb");
	if (f) {
  		fseek (f, 0, SEEK_END);
  		length = ftell (f);
  		fseek (f, 0, SEEK_SET);
  		buffer = malloc (length);
  		if (buffer) {
    			fread (buffer, 1, length, f);
  		}	fclose (f);
	}	if (buffer) return buffer;
	assert(0==1 && "[E]: can't read file.");
}
