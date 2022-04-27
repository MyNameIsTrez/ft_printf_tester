# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: sbos <sbos@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/04/22 18:42:17 by sbos          #+#    #+#                  #
#    Updated: 2022/04/27 17:44:38 by sbos          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

################################################################################

export DEBUG=1

LIBFT := libft/libft.a
PRINTF := ft_printf/libftprintf.a

CC := cc

LIBS := $(PRINTF)

override TESTS_DIR := tests
OBJ_DIR := obj

CFLAGS := -Wall -Wextra -Werror
CFLAGS += -O3 # -O1 or higher adds tail recursion detection.
CFLAGS += -g3 -Wconversion
# CFLAGS += -fsanitize=address

HEADERS :=\
	$(TESTS_DIR)/ft_printf_tests.h\
	ft_printf/src/ft_printf.h\
	ft_printf/src/get_type_strings/pft_get_type_strings.h\
	tests/tests_get_type_strings/test_get_type_strings.h\
	$(addprefix $(HOME)/Documents/Programming/libctester/, $(shell $(MAKE) -C $(HOME)/Documents/Programming/libctester/ -f headers.mk get_headers))

################################################################################

SOURCES := $(shell find $(TESTS_DIR) -name "*.c")

OBJECTS := $(addprefix $(OBJ_DIR)/,$(SOURCES:.c=.o))

INCLUDES := $(sort $(addprefix -I, $(dir $(HEADERS))))

################################################################################

# Only cleans when MAKE_DATA changes.
DATA_FILE := .make_data
MAKE_DATA := $(CFLAGS) $(SOURCES)
ifneq ($(shell echo "$(MAKE_DATA)"), $(shell cat "$(DATA_FILE)" 2> /dev/null))
PRE_RULES := clean
endif

################################################################################

all: $(PRE_RULES) $(LIBFT) $(PRINTF) $(OBJECTS)
	@echo "$(MAKE_DATA)" > $(DATA_FILE)

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(dir $(LIBFT))

$(PRINTF):
	@$(MAKE) -C $(dir $(PRINTF))

.PHONY: all

################################################################################

clean:
	rm -rf $(OBJ_DIR)/

fclean: clean
	@$(MAKE) -C $(dir $(LIBFT)) fclean
	@$(MAKE) -C $(dir $(PRINTF)) fclean

re: fclean all

.PHONY: clean fclean re

################################################################################

get_libs:
	@echo $(LIBS)

.PHONY: get_libs

################################################################################
