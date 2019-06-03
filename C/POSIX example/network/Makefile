all: tcp_server.out tcp_client.out parse_addr.out

tcp_server.out: tcp_server.c
	gcc tcp_server.c -o tcp_server.out

tcp_client.out: tcp_client.c
	gcc tcp_client.c -o tcp_client.out

parse_addr.out: parse_addr.c
	gcc parse_addr.c -o parse_addr.out

clean:
	rm *.out