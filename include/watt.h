#include"stackoverflow.h"
#define FILE_SIZE 128

struct tupple {
	int number;
	char* array[FILE_SIZE];
};

struct Config {
	char* apiServer;
	char* token;
	char* prefix;
};

struct tupple str_split(char str[],char* split_from) {
	int point = 0;
	char* token;
	struct tupple ret;
	while ((token = strsep(&str, split_from)) != NULL) {
	//	printf("%d: %s\n", point, token);
		ret.array[point] = token;
		point++;
	}	ret.number = point-1;
	return ret;
}

struct Config config_loader(char* configf) {
	int load = 0;
	struct Config config;

	char* configfb = read_file(configf);
	char* configfs = str_replace(configfb, ": ", ":");
	struct tupple lines = str_split(configfs, "\n");
	
	for (int point = 0; point <= lines.number-1; point++) {
		struct tupple line = str_split(lines.array[point], ":");
		if (strstr("apiServer", line.array[0])) {
		  	printf("[*]: loaded config \"%s\": \"%s\"\n", "server", line.array[1]);
		  	config.apiServer = line.array[1];
			load++;
			continue;   
		} if (strstr("token", line.array[0])) {
			printf("[*]: loaded config \"%s\"\n", "token");
			config.token = line.array[1];
		        load++;
			continue; 
		} if (strstr("prefix", line.array[0])) {
			printf("[*]: loaded config \"%s\": \"%s\"\n", "prefix", line.array[1]);
			config.prefix = line.array[1];
			load++;
			continue;
		}	printf("[W]: unknown setting: \"%s\"\n", line.array[0]);
	}

	assert((load == 3) && "[E]: you should add 3 config, not more not less.");
	return config;
}
