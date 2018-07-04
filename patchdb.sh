echo "Removing old files"
rm user.bin
rm user-patched.bin
cd db
make clean
echo "Getting the database"
wget https://github.com/PD1LOI/MD380tools/raw/master/user.bin -O custom.csv
sed -i 1,2d custom.csv 
cd ..
echo "Make new user.bin incl database"
make user.bin
echo "Sorting data for displaying"
sed "s@\(.*\),\(.*\),\(.*\),\(.*\),\(.*\),\(.*\),\(.*\)@\1,\2,\3,\6,\4,\5,\7@g" user.bin > user-patched.bin
echo "Flashing to handset"
./md380-tool spiflashwrite user-patched.bin 0x100000

