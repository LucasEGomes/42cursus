#!/bin/bash
source "$(dirname ""$0"")"/format.sh

SOURCE_DIR=../src
MAKEFILE="${SOURCE_DIR}"/Makefile

for RULE in '$(NAME)' all clean fclean re; do
    
    if [ ! -n "$(grep "${RULE}\s*:" ${MAKEFILE})" ]; then
        echo -e "${FG_RED}Rule '$RULE' not found${FONT_RESET}"
    fi
done
