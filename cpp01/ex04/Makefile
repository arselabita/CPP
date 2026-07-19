NAME = sed_is_for_losers

CXX = c++
CXX_FLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp Utils.cpp
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
	@echo " ____           _   _        __              _                         "
	@echo "/ ___|  ___  __| | (_)___   / _| ___  _ __  | | ___  ___  ___ _ __ ___ "
	@echo "\___ \ / _ \/ _\` | | / __| | |_ / _ \| '__| | |/ _ \/ __|/ _ \ '__/ __|"
	@echo " ___) |  __/ (_| | | \__ \ |  _| (_) | |    | | (_) \__ \  __/ |  \__ \\"
	@echo "|____/ \___|\__,_| |_|___/ |_|  \___/|_|    |_|\___/|___/\___|_|  |___/"
endef

export HEADER

header:
	$(HEADER)