#!/bin/sh

echo "Enter the name of the file you wish to create?"

IFS= #Ignoring white space, must be before the read command
read userName

echo "creating file called $userName" #use {} to tell where var ends

touch $userName
