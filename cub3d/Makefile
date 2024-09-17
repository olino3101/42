
CXX := gcc
#CFLAGS := -Wall -Wextra -g -fsanitize=address -g -O0
CFLAGS := -Wall -Wextra -g -fsanitize=address

# Colors
COLOR_RESET := \033[0m
COLOR_CXX := \033[1;34m
COLOR_OK := \033[1;32m
COLOR_ERROR := \033[1;31m
COLOR_CLEAN := \033[1;36m
COLOR_RE := \033[1;35m
COLOR_MSG := \033[1;35m

# Source and output
SRCS := main.cpp free_err.c init.c
OBJS := $(SRCS:.cpp=.o)
TARGET := cub3d
INCDIR = -I includes -I MLX42/includes
MLX = MLX42
GLFW_DIR = $(shell brew --prefix glfw)/lib
GLFW = -lglfw
MLX_LIB = $(MLX)/libmlx42.a
L_FLAGS = -L$(GLFW_DIR) $(GLFW)
# Program name
PROGRAM_NAME := cub3d

# Custom message with fancy border
MESSAGE := "$(COLOR_MSG)╭───────────────────────────────╮\n│ 🌟 $(PROGRAM_NAME) Built Successfully 🌟 │\n╰───────────────────────────────╯$(COLOR_RESET)"

# Rules
all: $(TARGET)

$(MLX):
	@git clone https://github.com/Golubian/MLX42_4b3deda.git MLX42
	@cmake MLX42 -B MLX42 && make -C MLX42 -j4

$(TARGET): $(MLX_LIB) $(OBJS)
	@echo -e "$(COLOR_CXX)Linking $@...$(COLOR_RESET)"
	@$(CXX) $(CFLAGS) $(L_FLAGS) $(OBJS) $(MLX_LIB) $(INCDIR) -o $(TARGET)
	@echo -e "$(COLOR_OK)Build succeeded!$(COLOR_RESET)"
	@echo $(MESSAGE)

%.o: %.c
	@echo -e "$(COLOR_CXX)Compiling $<...$(COLOR_RESET)"
	@$(CXX) $(CFLAGS) $(INCDIR) -c $< -o $@

clean:
	@echo -e "$(COLOR_RE)Rebuilding the project...$(COLOR_RESET)"
	@rm -f $(OBJS)

fclean: clean
	@echo -e "$(COLOR_CLEAN)Cleaning all including target...$(COLOR_RESET)"
	@rm -f $(TARGET)

re: fclean
	@echo -e "$(COLOR_RE)Rebuilding the project...$(COLOR_RESET)"
	@$(MAKE) --no-print-directory all

# Help command to display available commands
help:
	@echo -e "$(COLOR_CXX)Available commands:$(COLOR_RESET)"
	@echo -e "  $(COLOR_CXX)make$(COLOR_RESET)       - Build the project"
	@echo -e "  $(COLOR_CXX)make clean$(COLOR_RESET) - Clean object files"
	@echo -e "  $(COLOR_CXX)make fclean$(COLOR_RESET) - Full clean (includes target)"
	@echo -e "  $(COLOR_CXX)make re$(COLOR_RESET)    - Rebuild the project"
	@echo -e "  $(COLOR_CXX)make help$(COLOR_RESET)  - Show this help messag

.PHONY: all clean fclean re help
