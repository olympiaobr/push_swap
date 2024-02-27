#!bin/sh
valgrind ./push_swap "  " "  " > test.txt
sleep 1
valgrind ./push_swap "214" "  " >> text.txt
sleep 1
valgrind ./push_swap >> test.txt
sleep 1
valgrind ./push_swap 1 2 3 | ./checker_linux 1 2 3 >> test.txt
sleep 1
valgrind ./push_swap "1 2 3" | ./checker_linux "1 2 3" >> test.txt
sleep 1
valgrind ./push_swap "3 2 1" | ./checker_linux "3 2 1" >> test.txt
sleep 1
