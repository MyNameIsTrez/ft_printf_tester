# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: sbos <sbos@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/04/22 18:42:17 by sbos          #+#    #+#                  #
#    Updated: 2022/08/31 16:25:00 by sbos          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

################################################################################

# TODO: Can this be removed?
export DEBUG=1

################################################################################

LIBFT := libft/libft.a
PRINTF := ft_printf/libftprintf.a

CC := cc

LIBCTESTER_PATH := libctester

LIBS := $(PRINTF)

override TESTS_DIR := tests
OBJ_DIR := obj

CFLAGS := -Wall -Wextra -Werror -Wconversion -Wpedantic -Wfatal-errors
CFLAGS += -O3
CFLAGS += -g3
# CFLAGS += -fsanitize=address

HEADERS :=\
	tests/tests_get_type_strings/test_get_type_strings.h

INCLUDES_HEADERS :=\
	$(TESTS_DIR)/ft_printf_tests.h\
	ft_printf/src/ft_printf.h\
	$(shell $(MAKE) -C $(HOME)/Documents/Programming/libctester/ -f headers.mk get_includes_headers)

################################################################################

SOURCES := $(shell find $(TESTS_DIR) -name "*.c")

OBJECTS := $(addprefix $(OBJ_DIR)/,$(SOURCES:.c=.o))

HEADERS += $(INCLUDES_HEADERS)

INCLUDES := $(sort $(addprefix -I, $(dir $(INCLUDES_HEADERS))))

################################################################################

# Only cleans when MAKE_DATA changes.
DATA_FILE := .make_data
MAKE_DATA := $(CFLAGS) $(SOURCES)
ifneq ($(shell echo "$(MAKE_DATA)"), $(shell cat "$(DATA_FILE)" 2> /dev/null))
PRE_RULES := clean
endif

################################################################################

.PHONY: all
all: $(PRE_RULES) $(LIBFT) $(PRINTF) $(OBJECTS)
	@echo "$(MAKE_DATA)" > $(DATA_FILE)

################################################################################

.PHONY: $(LIBFT)
$(LIBFT):
	git submodule update --init --recursive
	@$(MAKE) -C $(dir $(LIBFT))

.PHONY: $(PRINTF)
$(PRINTF):
	git submodule update --init --recursive
	@$(MAKE) -C $(dir $(PRINTF))

################################################################################

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

################################################################################

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)

.PHONY: fclean
fclean: clean
	git submodule update --init --recursive
	@$(MAKE) -C $(dir $(LIBFT)) fclean
	@$(MAKE) -C $(dir $(PRINTF)) fclean
	@$(MAKE) -C $(LIBCTESTER_PATH) fclean

.PHONY: re
re: fclean all

################################################################################

.PHONY: get_libs
get_libs:
	@echo $(LIBS)

################################################################################
