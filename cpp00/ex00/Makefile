NAME = megaphone

CXX = c++
CXX_FLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = megaphone.cpp
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
@echo " __  __ _____ ____    _    ____  _   _  ___  _   _ _____"
@echo "|  \/  | ____/ ___|  / \  |  _ \| | | |/ _ \| \ | | ____|"
@echo "| |\/| |  _|| |  _  / _ \ | |_) | |_| | | | |  \| |  _|"
@echo "| |  | | |__| |_| |/ ___ \|  __/|  _  | |_| | |\  | |___"
@echo "|_|  |_|_____\____/_/   \_\_|   |_| |_|\___/|_| \_|_____|"
endef
export HEADER

header:
	$(HEADER)