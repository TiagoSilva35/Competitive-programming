#!/usr/bin/env bash
if [ ! $# -eq 2 ]; then
  echo "Missing file"
  echo "Usage: $0 file input -> example: $0 main.cpp input.in"
  exit 1
fi

# Initialize variables
FILE=$1
FILE_NO_EXT=${FILE%.*}
INPUT=$2

# 1 - Compile
# Verify the file extension and compile
if [[ $FILE == *.cpp ]]; then
  g++ -std=c++17 -Wall -Wextra -O2 -lm -o "$FILE_NO_EXT" "$FILE"
elif [[ $FILE == *.c ]]; then
  gcc -std=c17 -Wall -Wextra -O2 -lm -o "$FILE_NO_EXT" "$FILE"
elif [[ $FILE == *.java ]]; then
  javac -encoding utf8 "$FILE"
elif [[ $FILE == *.py ]]; then
  # Do nothing
  :
else
  echo "File extension not supported"
  exit 1
fi

# 2 - Run with input
# Verify the file extension and run
if [[ $FILE == *.cpp ]]; then
  ./"$FILE_NO_EXT" <"$INPUT"
elif [[ $FILE == *.c ]]; then
  ./"$FILE_NO_EXT" <"$INPUT"
elif [[ $FILE == *.java ]]; then
  java -Xmx256M -Xss256M -classpath . "$FILE_NO_EXT" <"$INPUT"
elif [[ $FILE == *.py ]]; then
  pypy3 "$FILE" <"$INPUT"
else
  echo "Invalid file extension"
  exit 1
fi

