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

echo "${GREEN} TEST NO ARG ${END}" 
./so_long
echo ""
ask_conf

echo ""
echo "${GREEN} TEST WRONG EXT ${END}" 
./so_long maps/map.txt

echo ""
echo "${GREEN} TEST DOES NOT EXIST ${END}" 
./so_long dir.ber

echo ""
echo "${GREEN} TEST DIRECTORY ${END}" 
./so_long maps/dir.ber

echo ""
echo "${GREEN} TEST OK ${END}" 
./so_long maps/map1.ber
