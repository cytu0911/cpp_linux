#include "unp.h"

int main(int argc, char** argv)
{
	int   sockfd, n;
	char  recvline[256];
	struct sockaddr_in  servaddr;
	
	if(argc != 2)
		printf("usage error!\n");
	
	if( (sockfd= socket(AF_INET,SOCK_STREAM,0) )<0 )
		printf("socket error! \n");

	bzero(&servaddr, sizeof(servaddr) );
	servaddr.sin_family   = AF_INET;
	servaddr.sin_port     = htons(13);

	if( inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <=0 )
		printf("inet_pton error!\n");

	if( connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) <0 )
		printf("connect error!\n");

	while( (n = read(sockfd, recvline, 256)) >0 )
	{
		recvline[n] = 0;
		if( fputs(recvline,stdout) == EOF )
			return -1;
	}

	

	

	return 0;
}
