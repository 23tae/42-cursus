# Minitalk

## What is minitalk?
Small data exchange program using UNIX signals between server and client.

## How to use?
1. enter `make` : make executable files (server, client)
2. enter `./server` : run server
3. server will show its PID
4. enter `./client <server PID> <message>` in different window : run client and send message
	- note that message which contains space should be enclosed by quotation marks.
5. server will show you message
6. send messages several times in the same way
7. `ctrl + c` : terminate server
8. `make fclean` : delete executable files

### etc
- Functions between srcs/ and srcs_bonus/ are exactly the same. To make bonus directory, enter the following commands.
- enter `sh bonus.sh` : make bonus directory
- `make bonus` : make bonus executable files

find more information [here](https://23tae.github.io/categories/minitalk/)
