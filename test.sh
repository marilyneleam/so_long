# Define colors
END="\033[0m"
RED="\e[38;5;196m"
ORANGE="\e[38;5;202m"
YELLOW="\e[38;5;220m"
GREEN="\e[38;5;118m"
BLUE="\e[38;5;33m"
PURPLE="\e[38;5;129m"

# Function to ask confirmation
ask_conf()
{
while true;
do
    read -p "Do you wish to continue? " yn
    case $yn in
        [Yy]* ) break;;
        [Nn]* ) make fclean; exit;;
        * ) echo "Please answer yes or no.";;
    esac
done
}

make
clear

echo ""
echo "${GREEN} TEST NO ARG ${END}" 
valgrind --leak-check=full --show-leak-kinds=all ./so_long

ask_conf

echo ""
echo "${GREEN} TEST WRONG EXT ${END}" 
valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/map.txt

ask_conf

echo ""
echo "${GREEN} TEST DOES NOT EXIST ${END}" 
valgrind --leak-check=full --show-leak-kinds=all ./so_long dir.ber

ask_conf

echo ""
echo "${GREEN} TEST DIRECTORY ${END}" 
valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/dir.ber

ask_conf

echo ""
echo "${GREEN} TEST SAME NAME ${END}" 
valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/.ber

ask_conf

echo ""
echo "${GREEN} TEST MAP SMALL ${END}" 
valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/map_small.ber

ask_conf

echo ""
echo "${GREEN} TEST IS NOT RECTANGLE ${END}" 
valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/map_not_rectangle.ber

ask_conf

echo ""
echo "${GREEN} TEST IS NOT closed ${END}" 
valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/map_not_closed.ber

ask_conf

echo ""
echo "${GREEN} TEST ERR PARAM ${END}" 
valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/map_param_error.ber

ask_conf

echo ""
echo "${GREEN} TEST HAS 0 PLAYER ${END}" 
valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/map_zero_player.ber

ask_conf

echo ""
echo "${GREEN} TEST HAS 2 PLAYERS ${END}" 
valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/map_two_player.ber

ask_conf

echo ""
echo "${GREEN} TEST HAS NO COLLECTIBLES ${END}" 
valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/map_coll.ber

ask_conf

echo ""
echo "${GREEN} TEST HAS NO EXIT ${END}" 
valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/map_exit.ber

ask_conf
clear

echo ""
echo "${GREEN} VALID MAP ONE ${END}" 
valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/map1.ber

ask_conf
clear

echo ""
echo "${GREEN} VALID MAP TWO ${END}" 
valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/map2.ber

ask_conf