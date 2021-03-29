CC	= gcc

RM	= rm -f

SRCS	= ./malloc.c	\
		./calloc.c

OBJS	= $(SRCS:.c=.o)

all: main ## Everything

main: $(OBJS)
	gcc -c -Wall -fpic $(SRCS)
	gcc -shared -o libmy_malloc.so -fPIC $(SRCS)
	$(RM) $(OBJS)

clean: ## Clean object files
	$(RM) $(OBJS)

fclean: clean ## Clean object files (including library)
	$(RM) $(NAME)

re: fclean all ## (fclean & all)

.PHONY: all clean fclean re

help:
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'
