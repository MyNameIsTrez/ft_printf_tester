# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    tester.mk                                          :+:    :+:             #
#                                                      +:+                     #
#    By: sbos <sbos@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/01/20 16:07:18 by sbos          #+#    #+#                  #    Updated: 2022/03/01 18:14:56 by sbos          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

################################################################################

PROJECT_NAME := ft_printf

################################################################################

MAKEFILE_DIR := ../../Projects/$(PROJECT_NAME)

export DEBUG := 1
include $(MAKEFILE_DIR)/Makefile
export NO_STATIC := 1

################################################################################

TESTS_DIR := tests
TESTS_OBJ_DIR := obj_tests

MASSERT_DIR := libmassert

TESTER := tester

TESTER_HEADERS :=											\
	$(addprefix $(MAKEFILE_DIR)/, $(HEADERS))				\
	$(TESTS_DIR)/tests.h									\
	$(MASSERT_DIR)/massert.h								\
	tests/tests_get_type_strings/test_get_type_strings.h
# TODO: ^ Leave this get_type_strings header out?

TESTER_LIB_NAMES :=					\
	$(MASSERT_DIR)/libmassert.a		\
	$(MAKEFILE_DIR)/libftprintf.a

################################################################################

MASSERT := $(MASSERT_DIR)/libmassert.a

TESTER_SOURCES := $(wildcard $(TESTS_DIR)/*.c) $(wildcard $(TESTS_DIR)/**/*.c)
TESTER_OBJECTS := $(addprefix $(TESTS_OBJ_DIR)/,$(TESTER_SOURCES:.c=.o))

TESTER_INCLUDES := $(sort $(addprefix -I, $(dir $(TESTER_HEADERS))))

TESTER_LIB_FLAGS := $(sort $(addprefix -L,$(dir $(TESTER_LIB_NAMES)))) $(sort $(patsubst lib%,-l%,$(basename $(notdir $(TESTER_LIB_NAMES)))))

START_OF_MAKEFILE := bonus
START_OF_MAKEFILE_SHORTCUT := foo$(START_OF_MAKEFILE)

################################################################################

$(START_OF_MAKEFILE_SHORTCUT):
	$(MAKE) -C $(MAKEFILE_DIR) $(START_OF_MAKEFILE)

.DEFAULT_GOAL := $(TESTER)
$(TESTER): $(START_OF_MAKEFILE_SHORTCUT) $(MASSERT) $(TESTER_OBJECTS)
	$(CC) $(CFLAGS) $(TESTER_INCLUDES) -g3 $(TESTER_OBJECTS) $(TESTER_LIB_FLAGS) -o $(TESTER)

$(TESTS_OBJ_DIR)/%.o: %.c $(TESTER_HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -Wno-format $(TESTER_INCLUDES) -c $< -o $@
# TODO: ^ What is this -Wno-format for?

################################################################################

$(MASSERT):
	@$(MAKE) -C $(MASSERT_DIR)

.PHONY: $(MASSERT)

################################################################################

fclean_t:
	rm -rf $(TESTS_OBJ_DIR)
	rm -f $(TESTER)
	@$(MAKE) -C $(MAKEFILE_DIR) fclean
	@$(MAKE) -C $(MASSERT_DIR) fclean

re_t: fclean_t $(TESTER)

.PHONY: fclean_t re_t

################################################################################
