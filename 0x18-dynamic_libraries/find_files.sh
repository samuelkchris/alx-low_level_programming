#!/bin/bash
while read file_name; do
	find ../ -type f -name "$file_name" -exec cp {} ./found_files \;
echo "Tim";
done <file_list
