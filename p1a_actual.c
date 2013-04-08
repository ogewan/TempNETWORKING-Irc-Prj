#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
/*/cygdrive/c/Users/Dolapo/Documents/GitHub/chirc/src*/
int main()
{
	int ssckt, csckt;
	struct sockaddr_in sadr, cadr;
	int yes = 1;
	socklen_t sktsz = sizeof(struct sockaddr_in);

	char* welcome = "Welcome to the Internet Relay Network";
	int port = 8998
	char* nicks[20];
	char* users[20];
	int usrcount = 0;
	char* hostname;
	/*:hostname 001 user1 :*/
	/* user1!user1@foo.example.com\r\n*/
	<nick>!<user>@<host>
	if (gethostname(hostname, size_t sizeof(hostname)))
		{
			hostname = "testdefault";
			sethostname(hostname, size_t sizeof(hostname)))
		}
	memset(&serverAddr, 0, sizeof(sadr));
	sadr.sin_family = AF_INET;
	sadr.sin_port = htons(port);
	sadr.sin_addr.s_addr = INADDR_ANY;

	ssckt = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	setsockopt(ssckt, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
	bind(ssckt, (struct sockaddr *) &sadr, sizeof(sadr));
	listen(ssckt, 10);

	while(1)
	{
		csckt = accept(ssckt, (struct sockaddr *) &cadr, &sktsz);
		send(csckt, response, strlen(response), 0);/*Send response to client*/
	}

	close(ssckt);

	return 0;
}
