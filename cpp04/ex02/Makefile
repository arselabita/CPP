NAME = abstract

CXX = c++
CXX_FLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
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

re: fclean all

.PHONY: clean fclean all re info header

info: header
define HEADER
	@echo "    _    _         _                  _      ____ _               "
	@echo "   / \  | |__  ___| |_ _ __ __ _  ___| |_   / ___| | __ _ ___ ___ "
	@echo "  / _ \ | '_ \/ __| __| '__/ _\` |/ __| __| | |   | |/ _\` / __/ __|"
	@echo " / ___ \| |_) \__ \ |_| | | (_| | (__| |_  | |___| | (_| \__ \__ \\"
	@echo "/_/   \_\_.__/|___/\__|_|  \__,_|\___|\__|  \____|_|\__,_|___/___/"
endef

export HEADER

header:
	$(HEADER)