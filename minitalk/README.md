# Minitalk

## What is minitalk?
Small data exchange program using UNIX signals between client and server.

## How to use?
1. Enter `make` : make executable files(server, client).
2. Enter `./server` : run server.
3. Server will show its PID.
4. Enter `./client <server PID> <message>` in different window : run client and send message.
	- note that message which contains space should be enclosed by quotation marks.
5. Server will show you message.
6. Send messages several times in the same way.
7. `ctrl + c` : terminate server.
8. Enter `make fclean` : delete executable files.

### etc
- Functions between `srcs/` and `srcs_bonus/` are exactly the same.
- To make bonus directory, enter the following commands.
- Enter `sh bonus.sh` : make bonus source files.
- Enter `make bonus` : make executable files using bonus source files.

Find more information [here](https://23tae.github.io/categories/minitalk/).
