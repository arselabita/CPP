NAME = function_templates

CXX = c++
CXX_FLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp \
	
OBJS = $(SRCS:.cpp=.o)

SILENT ?=0
GREEN = \033[0;32m
PURPLE = \033[1;35m
CYAN = \033[0;36m
RED = \033[1;31m
RESET = \033[0m

all: header $(NAME)

%.o: %.cpp
	@$(CXX) $(CXX_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@if [ "$(SILENT)" = "0" ]; then echo "$(GREEN)compiling...$(RESET)"; fi
	@$(CXX) $(CXX_FLAGS) -o $(NAME) $(OBJS)
	@if [ "$(SILENT)" = "0" ]; then  echo "$(GREEN)ready to execute$(RESET)"; fi

clean:
	@if [ "$(SILENT)" = "0" ]; then echo "$(CYAN)deleting object files...$(RESET)"; fi
	@rm -f $(OBJS)
	@if [ "$(SILENT)" = "0" ]; then echo "$(CYAN)done$(RESET)"; fi

fclean:
	@rm -f $(NAME) $(OBJS)
	@rm -f *_shrubbery 

re: fclean all

.PHONY: clean fclean all re info header

info: header
define HEADER
	@echo " ____  _             _              _ _   _                __               "
	@echo "/ ___|| |_ __ _ _ __| |_  __      _(_) |_| |__     __ _   / _| _____      __"
	@echo "\___ \| __/ _\` | '__| __| \ \ /\ / / | __| '_ \   / _\` | | |_ / _ \ \ /\ / /"
	@echo " ___) | || (_| | |  | |_   \ V  V /| | |_| | | | | (_| | |  _|  __/\ V  V / "
	@echo "|____/ \__\__,_|_|   \__| _ \_/\_/ |_|\__|_| |_|  \__,_| |_|  \___| \_/\_/  "
	@echo " / _|_   _ _ __   ___| |_(_) ___  _ __  ___                                 "
	@echo "| |_| | | | '_ \ / __| __| |/ _ \| '_ \/ __|                                "
	@echo "|  _| |_| | | | | (__| |_| | (_) | | | \__ \                                "
	@echo "|_|  \__,_|_| |_|\___|\__|_|\___/|_| |_|___/                                "
endef

export HEADER
header:
	$(HEADER)