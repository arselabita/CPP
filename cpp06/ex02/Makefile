NAME = identify_real_type

CXX = c++
CXX_FLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp \
	   Base.cpp \
	   A.cpp \
	   B.cpp \
	   C.cpp
	
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
	@echo " ___    _            _   _  __                        _ "
	@echo "|_ _|__| | ___ _ __ | |_(_)/ _|_   _   _ __ ___  __ _| |"
	@echo " | |/ _\` |/ _ \ '_ \| __| | |_| | | | | '__/ _ \/ _\` | |"
	@echo " | | (_| |  __/ | | | |_| |  _| |_| | | | |  __/ (_| | |"
	@echo "|___\__,_|\___|_| |_|\__|_|_|  \__, | |_|  \___|\__,_|_|"
	@echo "| |_ _   _ _ __   ___          |___/                    "
	@echo "| __| | | | '_ \ / _ \                                  "
	@echo "| |_| |_| | |_) |  __/                                  "
	@echo " \__|\__, | .__/ \___|                                  "
	@echo "     |___/|_|                                           "
endef

export HEADER

header:
	$(HEADER)