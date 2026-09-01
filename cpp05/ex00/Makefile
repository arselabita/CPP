NAME = bureaucrat

CXX = c++
CXX_FLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp Bureaucrat.cpp
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
	@echo " __  __                                              _                  ___ "
	@echo "|  \/  | ___  _ __ ___  _ __ ___  _   _    __      _| |__   ___ _ __   |_ _|"
	@echo "| |\/| |/ _ \| '_ \` _ \| '_ \` _ \| | | |   \ \ /\ / / '_ \ / _ \ '_ \   | | "
	@echo "| |  | | (_) | | | | | | | | | | | |_| |_   \ V  V /| | | |  __/ | | |  | | "
	@echo "|_|  |_|\___/|_| |_| |_|_| |_| |_|\__, ( )___\_/\_/ |_| |_|\___|_| |_| |___|"
	@echo "  __ _ _ __ _____      __  _   _ _|___/|/|_ _| __      ____ _ _ __ | |_     "
	@echo " / _\` | '__/ _ \ \ /\ / / | | | | '_ \    | |  \ \ /\ / / _\` | '_ \| __|    "
	@echo "| (_| | | | (_) \ V  V /  | |_| | |_) |   | |   \ V  V / (_| | | | | |_     "
	@echo " \__, |_|  \___/ \_/\_/    \__,_| .__( ) |___|   \_/\_/ \__,_|_| |_|\__|    "
	@echo " |___/      _                   |_|  |/                                     "
	@echo "| |_ ___   | |__   ___    __ _                                              "
	@echo "| __/ _ \  | '_ \ / _ \  / _\` |                                             "
	@echo "| || (_) | | |_) |  __/ | (_| |                                             "
	@echo " \__\___/  |_.__/ \___|  \__,_|                  _   _                      "
	@echo "| |__  _   _ _ __ ___  __ _ _   _  ___ _ __ __ _| |_| |                     "
	@echo "| '_ \| | | | '__/ _ \/ _\` | | | |/ __| '__/ _\` | __| |                     "
	@echo "| |_) | |_| | | |  __/ (_| | |_| | (__| | | (_| | |_|_|                     "
	@echo "|_.__/ \__,_|_|  \___|\__,_|\__,_|\___|_|  \__,_|\__(_)                     "
endef

export HEADER

header:
	$(HEADER)