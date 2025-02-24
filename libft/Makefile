NAME = libft.a
FLAGS = -Wall -Werror -Wextra
CC = cc
HDRS = libft.h

SRC_PART = ft_strlen.c \
           ft_memmove.c \
           ft_memcpy.c \
           ft_strlcpy.c \
           ft_strlcat.c \
           ft_isalpha.c \
           ft_isdigit.c \
           ft_isalnum.c \
           ft_isascii.c \
           ft_isprint.c \
           ft_memset.c \
           ft_bzero.c \
           ft_toupper.c \
           ft_tolower.c \
           ft_strchr.c \
           ft_strrchr.c \
           ft_strncmp.c \
           ft_memchr.c \
           ft_memcmp.c \
           ft_strnstr.c \
           ft_atoi.c \
           ft_calloc.c \
           ft_strdup.c \
           ft_substr.c \
           ft_strjoin.c \
           ft_strtrim.c \
           ft_split.c \
           ft_itoa.c \
           ft_strmapi.c \
           ft_striteri.c \
           ft_putchar_fd.c \
           ft_putstr_fd.c \
           ft_putendl_fd.c \
           ft_putnbr_fd.c

SRC_BONUS = ft_lstadd_back_bonus.c \
            ft_lstadd_front_bonus.c \
            ft_lstclear_bonus.c \
            ft_lstdelone_bonus.c \
            ft_lstiter_bonus.c \
            ft_lstlast_bonus.c \
            ft_lstnew_bonus.c \
            ft_lstsize_bonus.c

OBJ_PART = $(SRC_PART:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

%.o: %.c
	@$(CC) $(FLAGS) -o $@ -c $<
	@echo "\033[90m[\033[32mOK\033[90m]\033[34m Compiling $<\033[0m"

$(NAME): $(OBJ_PART)
	@ar rcs $(NAME) $(OBJ_PART)
	@echo "\033[90m[\033[32mSuccess\033[90m]\033[32m Successfully compiled Libft.\033[0m"

bonus: $(OBJ_PART) $(OBJ_BONUS)
	@ar rcs $(NAME) $(OBJ_PART) $(OBJ_BONUS)
	@echo "\033[90m[\033[32mSuccess\033[90m]\033[32m Successfully compiled Libft with Bonus.\033[0m"

all: $(NAME)

clean:
	@/bin/rm -f $(OBJ_PART) $(OBJ_BONUS)
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m Object files deleted\033[0m"

fclean: clean
	@/bin/rm -f $(NAME) libft.so
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m Libft.a and libft.so deleted.\033[0m"

re: fclean all

.PHONY: all clean fclean re bonus so
