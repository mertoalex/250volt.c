#include<stdio.h>
#include"watt.h"

int main() {
	struct Config conf = config_loader("config.ini");
	printf("%s\n", conf.token);
	return 0;
}

// export URL='https://api.revolt.chat/users/@me';curl -H 'x-bot-token: $TOKEN' $URL
