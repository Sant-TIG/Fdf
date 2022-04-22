M	            = mandatoryL/srcs/
B	            = bonus/srcs/
MO              = mandatoryL/mandatory_objs/
OB              = bonus/bonus_objs/

NAME            = fdf
#BONUS_NAME      = pipex_bonus

CC              = gcc -g
CFLAGS          = -Wall -Werror -Wextra
FSANITIZE       = -fsanitize=address -g3

RM              = -rm -r

MAIN_FILE       = fdf

FREE_FILES      = ft_free
PRINT_FILES     = ft_print
FDF_FILES       = ft_get_map main
LINKED_FILES    = ft_insert_end_char ft_insert_empty_char
STRING_FILES    = ft_isdigit ft_strlen ft_strncpy ft_strndup ft_split


MANDATORY_OBJS  = $(addprefix $(MO), $(addsuffix .o, $(FDF_FILES))) $(addprefix $(MO), $(addsuffix .o, $(FREE_FILES))) $(addprefix $(MO), $(addsuffix .o, $(LINKED_FILES)))  $(addprefix $(MO), $(addsuffix .o, $(PRINT_FILES)))  $(addprefix $(MO), $(addsuffix .o, $(STRING_FILES)))
#BONUS_OBJS      = $(addprefix $(OB), $(addsuffix .o, $(BONUS_MAIN_FILE))) $(addprefix $(OB),$(addsuffix .o, $(BONUS_CHECK_FILES))) $(addprefix $(OB),$(addsuffix .o, $(BONUS_FREE_FILES))) $(addprefix $(OB),$(addsuffix .o, $(BONUS_GNL_FILES))) $(addprefix $(OB),$(addsuffix .o, $(BONUS_STRINGS_FILES))) $(addprefix $(OB),$(addsuffix .o, $(BONUS_UTILS_FILES)))

MANDATORY_SRCS  = $(addprefix $(M), $(addsuffix .c, $(FDF_FILES))) $(addprefix $(M), $(addsuffix .c, $(FREE_FILES))) $(addprefix $(M), $(addsuffix .c, $(LINKED_FILES))) $(addprefix $(M), $(addsuffix .c, $(PRINT_FILES))) $(addprefix $(M), $(addsuffix .c, $(STRING_FILES)))
#BONUS_SRCS      = $(addprefix $(B), $(addsuffix .c, $(BONUS_MAIN_FILE))) $(addprefix $(B),$(addsuffix .c, $(BONUS_CHECK_FILES))) $(addprefix $(B),$(addsuffix .c, $(BONUS_FREE_FILES))) $(addprefix $(B),$(addsuffix .c, $(BONUS_GNL_FILES))) $(addprefix $(B),$(addsuffix .c, $(BONUS_STRINGS_FILES))) $(addprefix $(B),$(addsuffix .c, $(BONUS_UTILS_FILES)))

all: mandatory

mandatory: $(NAME)

$(MO):
	@echo "Creating Objects Folder...."
	mkdir $@
	@echo "Folder created."

$(MANDATORY_OBJS): | $(MO)

#assuming that you have the mlx source in a directory named mlx in the root of your project

$(MANDATORY_OBJS): $(MO)%.o: $M%.c
	$(CC) $(CFLAGS) -c $< -o $@

#to link with the required internal macOS API

$(NAME): $(MANDATORY_OBJS)
	$(CC) $(CFLAGS) $^  -o $(NAME)

#bonus: $(BONUS_NAME)

#$(OB):
#	@echo "Creating Objects Folder...."
#	mkdir $@
#	@echo "Folder created."

#$(BONUS_OBJS): | $(OB)

#$(BONUS_OBJS): $(OB)%.o: $B%.c
#	$(CC) $(CFLAGS) -c $< -o $@

#$(BONUS_NAME): $(BONUS_OBJS)
#	$(CC) $(CFLAGS) $^ -o $(BONUS_NAME)

clean:
ifeq ($(shell test -e bonus/bonus_objs/fdf_bonus.o && echo "0"), $(shell echo "0"))
	$(RM) $(BONUS_OBJS)
endif
ifeq ($(shell test -e mandatory/mandatory_objs/fdf.o && echo "0"), $(shell echo "0"))
	$(RM) $(MANDATORY_OBJS)
endif

fclean: clean
ifeq ($(shell test -e pipex_bonus && echo "0"), $(shell echo "0"))
	$(RM) $(BONUS_NAME) $(OB)
endif
ifeq ($(shell test -e pipex && echo "0"), $(shell echo "0"))
	$(RM) $(NAME) $(OM)
endif

re: fclean all

.PHONY: fclean clean mandatory bonus all