NAME = ft_ssl
CC = gcc
CFLAGS = -Wall -Werror -g -Wextra
LIBFT = libft
HEADER = inc/ft_ssl.h src/message_digest/message_digest.h
LIBFT_HEADER = libft/ft_printf.h
SOURCES := ft_ssl.c
SOURCES += free.c init.c parse.c parse_helper.c error.c
SOURCES += message_digest/MD5/handle_md5.c message_digest/MD5/md5.c
SOURCES += message_digest/SHA256/handle_sha256.c message_digest/SHA256/sha256.c
SOURCES := $(SOURCES:%.c=src/%.c)
OBJECTS := $(SOURCES:src/%.c=obj/%.o)


all: $(NAME)

$(NAME): object
	@make -C $(LIBFT)
	rm -f ./$(NAME)
	gcc -o $(NAME) $(CFLAGS) $(SOURCES) ./libft/libftprintf.a

test:
	@make re
	@make clean
	./ft_ssl md5 -q -r -p -s "hello"

object: $(SOURCES)
	@mkdir -p obj
	@$(CC) $(FLAGS) -I$(HEADER) -I$(LIBFT_HEADER) -c $(SOURCES)
	@mv *.o obj

clean:
	@make clean -C $(LIBFT)
	@/bin/rm -rf obj

fclean: clean
	@make fclean -C $(LIBFT)
	@/bin/rm -f $(NAME)
	@rm -rf src/SHA256/sha256.h.gch src/MD5/md5.h.gch .vscode
	@/bin/rm -rf $(NAME).dSYM

re: fclean all
