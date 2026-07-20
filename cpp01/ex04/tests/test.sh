#!/bin/bash

PROGRAM="../sed_is_for_losers"

GREEN="\033[0;32m"
RED="\033[0;31m"
BLUE="\033[0;34m"
RESET="\033[0m"

clear

run_test() {
    FILE=$1
    S1=$2
    S2=$3

    echo -e "${GREEN}-----------------------------------------------${RESET}"
    echo -e "${GREEN}Test:${RESET} $FILE"
    echo -e "${GREEN}Replace:${RESET} \"$S1\" -> \"$S2\""
    echo

    $PROGRAM "$FILE" "$S1" "$S2"

    if [ $? -eq 0 ]; then
        echo
        echo -e "${BLUE}Result:${RESET}"
        cat "$FILE.replace"
    else
        echo -e "${RED}Program returned an error.${RESET}"
    fi

    echo
}

run_test "alice.txt" "Alice" "Ornela"
run_test "dracula.txt" "free" "brave"
run_test "frankenstein.txt" "voyage" "journey"
run_test "iliad.txt" "rage" "glory"
run_test "odyssey.txt" "sea" "ocean"
run_test "shakespeare.txt" "be" "code"
run_test "sherlock.txt" "Holmes" "Watson"

echo -e "${BLUE}"
echo "             Error Handling Tests"
echo -e "${RESET}"

echo "1) Missing file"
$PROGRAM "missing.txt" "hello" "hi"

echo
echo "2) Empty search string"
$PROGRAM "alice.txt" "" "hi"

echo
echo "3) Wrong number of arguments"
$PROGRAM

echo
echo "4) Too many arguments"
$PROGRAM "alice.txt" "Alice" "Ornela" "extra"

echo
echo -e "${GREEN}All tests finished!${RESET}"