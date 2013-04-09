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
	/*Variable Initialization*/
	int ssckt;
	int csckt = 0;
	struct sockaddr_in sadr, cadr;
	int yes = 1;
	socklen_t sktsz = sizeof(struct sockaddr_in);

	char* RPL_WELCOME = "Welcome to the Internet Relay Network";
	int port = 8998;
	char* nicks[20];
	char* users[20];
	int usrcount = 0;
	char hostname[128];
	char peer[128];
	char buf[1024];
	int bytes = 0;
	/*:hostname 001 user1 :*/
	/* user1!user1@foo.example.com\r\n*/
	/*:hostname RPL_WELCOME-numericcode nick :*/
	/*<nick>!<user>@<host(peer)>\r\n*/
		
	int hostattmpt = gethostname(hostname, sizeof(hostname));
	if (hostattmpt)/*Fail to get hostname? Make one up! :D*/
	{
		char* temphostname = "testdefault";
		sethostname(temphostname, sizeof(temphostname));
	}
	/*Server Socket Setup*/
	memset(&sadr, 0, sizeof(sadr));
	sadr.sin_family = AF_INET;
	sadr.sin_port = htons(port);
	sadr.sin_addr.s_addr = INADDR_ANY;
	ssckt = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	setsockopt(ssckt, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
	bind(ssckt, (struct sockaddr *) &sadr, sizeof(sadr));
	listen(ssckt, 10);
	/*END*/
	
	printf("Initializing Server:%s\n",hostname);
	
	while(1)
	{
		if (!csckt)
		{
			csckt = accept(ssckt, (struct sockaddr *) &cadr, &sktsz);
			getnameinfo(&cadr, sizeof(cadr),peer, sizeof(peer), NULL, NULL, 0);
		}
		bytes = recv(csckt, buf, sizeof(buf),0);
		if (bytes)
		{
			printf("Recieved\n");
			char jubby[1028];
			sprintf(jubby, "%d", bytes);	
			send(jubby, peer, strlen(jubby), 0);
		}
		/*Ignore every response other than Nick and User
		/*csckt = accept(ssckt, (struct sockaddr *) &cadr, &sktsz);
		/*get peername
		check for peername in users list
		if in userslist:
			take in input and respond\
		else:
			look for user and nick commands
		/*/			
		char* res =  "RESPONSE\n";
		/*send(res, peer, strlen(res), 0);/*Send response to client*/
		printf("connected:%s %d\n", peer,bytes);
	}

	close(ssckt);

	return 0;
}
