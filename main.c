#include"csapp.h"
int main(int argc , char ** argv)
{
  struct addrinfo *p,*listp,hints;
  char buf[MAXLINE];
  int rc,flags;
  if(argc!=2)
  {
    fprintf(stderr, "usage:%s<domain name>\n",argv[0] );
    exit(EXIT_FAILURE);
  }
  //GET A list of addrinfo records
  memset(&hints,0,sizeof(struct addrinfo));
  hints.ai_family=AF_INET;//IPV4
  hints.ai_socktype=SOCK_STREAM;//Connections only
  if((rc=getaddrinfo(argv[1],NULL,&hints,&listp))!=0)
  {
    fprintf(stderr, "getaddrinfo error %s\n",gai_strerror(rc) );
    exit(EXIT_FAILURE);
  }
  //walk the list and display each address
  flags=NI_NUMERICHOST;
  for(p=listp;p;p=p->ai_next)
  {
    getnameinfo(p->ai_addr,p->ai_addrlen,buf,MAXLINE,NULL,0,flags);
    printf("%s\n",buf);

  }
  freeaddrinfo(listp);
  exit(EXIT_SUCCESS);
}
