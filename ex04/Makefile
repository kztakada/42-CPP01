NAME			=	sedIsForLosers

CXX				=	c++
CXXFLAGS		=	-Wall -Wextra -Werror -std=c++98

SRCS			=	$(wildcard *.cpp)

OBJS_PATH		=	objs/
OBJS			=	$(SRCS:%.cpp=objs/%.o)

ISDEBUG = 0
ARGS ?= 

ifeq ($(ISDEBUG), 1)
	CXX +=  -g -fsanitize=address,undefined
endif

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJS_PATH)%.o:	%.cpp
	@mkdir -p $(OBJS_PATH)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
debug:
	make fclean
	$(MAKE) ISDEBUG=1 all

va:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(ARGS)

FILE ?= 
FROM ?= 
TO ?= 

test:
	@rm -f $(FILE).replace $(FILE).sed_replace /tmp/diff_result
	-./$(NAME) $(FILE) $(FROM) $(TO)
	@test -f $(FILE).replace || (echo "The program did not create the file. If args are incorrect, this test case is OK." >&2 && exit 1)
	sed 's/$(FROM)/$(TO)/g' $(FILE) > $(FILE).sed_replace
	diff -u $(FILE).sed_replace $(FILE).replace > /tmp/diff_result 2>&1 && echo "OK" || (echo "FAILED:" && cat /tmp/diff_result)

clean:
	rm -rf $(OBJS_PATH)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

init:
	bear -- make

.PHONY:	all clean fclean re debug va init test