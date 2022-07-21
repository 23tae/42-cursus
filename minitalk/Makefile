MINITALK			= minitalk
SERVER 				= server
CLIENT				= client

CC 					= gcc
CFLAGS				= -Wall -Werror -Wextra

LIBFT 				= ./libft.a

SRCS_PATH			= ./srcs/
SRCS_BONUS_PATH		= ./srcs_bonus/
SERVER_FILES 		= server.c server_receive.c utils.c
CLIENT_FILES 		= client.c client_transmit.c utils.c
SERVER_SRCS			= $(addprefix $(SRCS_PATH), $(SERVER_FILES))
SERVER_SRCS_BONUS	= $(addprefix $(SRCS_BONUS_PATH), $(patsubst %.c, %_bonus.c, $(SERVER_FILES)))
CLIENT_SRCS			= $(addprefix $(SRCS_PATH), $(CLIENT_FILES))
CLIENT_SRCS_BONUS	= $(addprefix $(SRCS_BONUS_PATH), $(patsubst %.c, %_bonus.c, $(CLIENT_FILES)))
SERVER_OBJS			= $(SERVER_SRCS:.c=.o)
SERVER_OBJS_BONUS	= $(SERVER_SRCS_BONUS:.c=.o)
CLIENT_OBJS			= $(CLIENT_SRCS:.c=.o)
CLIENT_OBJS_BONUS	= $(CLIENT_SRCS_BONUS:.c=.o)

OBJS_FOR_CLEAN		= $(SERVER_OBJS) $(SERVER_OBJS_BONUS) $(CLIENT_OBJS) $(CLIENT_OBJS_BONUS)

ifdef WITH_BONUS
	SERVER_OBJECTS 	= $(SERVER_OBJS_BONUS)
	CLIENT_OBJECTS 	= $(CLIENT_OBJS_BONUS)
else
	SERVER_OBJECTS	= $(SERVER_OBJS)
	CLIENT_OBJECTS	= $(CLIENT_OBJS)
endif

all: $(MINITALK)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT) : 
	@make -C ./libft/
	@mv ./libft/$(LIBFT) ./$(LIBFT)

$(SERVER): $(SERVER_OBJECTS)
	@$(CC) $(CFLAGS) $^ -o $@ $(LIBFT)
	@echo "server made"

$(CLIENT): $(CLIENT_OBJECTS)
	@$(CC) $(CFLAGS) $^ -o $@ $(LIBFT)
	@echo "client made"

$(MINITALK): $(LIBFT) $(SERVER) $(CLIENT)

bonus:
	$(MAKE) WITH_BONUS=1 all

re:
	@make fclean
	@make all

clean:
	@make clean -C ./libft
	@$(RM) $(LIBFT) $(OBJS_FOR_CLEAN)
	@echo "server cleaned"
	@echo "client cleaned"

fclean:
	@make clean
	@$(RM) $(SERVER) $(CLIENT)

.PHONY: all re clean fclean bonus
