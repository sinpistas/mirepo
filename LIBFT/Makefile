
###############################################BEG

NAME		= libft.a

#------------------------------------------------#
#   VARIABLES                                    #
#------------------------------------------------#
# SRCS      source files
# OBJS      object files
#
# CC        compiler
# CFLAGS    compiler flags

SRCS 		= main.c
OBJS 		= $(SRCS:.c=.o)
DEPS    	= $(OBJS:.o=.d)

CC			= clang
CFLAGS  	= -Wall -Werror -Wextra
CPPFLAGS	= -I
AR			= AR
ARFLAGS		= -r -c -s

CUR_DIR		= $(shell pwd)

#------------------------------------------------#
#   RULES                                        #
#------------------------------------------------#
# all       default goal
# $(NAME)   linking .o -> binary
# %.o       compilation .c -> .o
# clean     remove .o
# fclean    remove .o + binary
# re        remake default goal

all: $(NAME)

$(NAME): $(OBJS)
    $(CC) $(OBJS) -o $(NAME)
	$(info CREATED $(NAME))

%.o: %.c
    $(DIR_DUP)
    $(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
    $(info CREATED $@)

-include $(DEPS)

clean:
    $(RM) $(OBJS)

fclean: clean
    $(RM) $(NAME)

re:
    $(MAKE) fclean
    $(MAKE) all

#------------------------------------------------#
#   SPECIALS                                     #
#------------------------------------------------#

.PHONY: all clean fclean re

####################################### END_1 ####