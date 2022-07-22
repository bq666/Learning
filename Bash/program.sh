#!/bin/bash
echo "===pl_full.txt==="
longest=0
#for word in $(<pl_full.txt)
for word in $(<test.txt)
do
#!v="information"
#case $word in
#    *-*)
#        len=0;; #echo "found \"f\" in ${v}";;
#    *)
#        len=${#word};; #echo "no match found in ${v}"
#esac
    len=${#word}
    if (( len > longest ))
    then
        longest=$len
        longword=$word
    fi
done
printf 'longest word: %s\n' "$longword"



shortest=100000
count=0
allcount=0
#!for word in $(<en_full.txt)
for word in $(<test.txt)
do
    len=${#word}
    if (( len < shortest ))
    then
        shortest=${#word}
        shortword=$word
    fi

    if [[ $word =~ *[0-9]* ]]; then
        break
    else
	((count++))
        #count=$((count+1))
	allcount=$((allcount +$word}))
	#var=$((var + 1))

    fi





done
printf 'shortest word: %s\n' "$shortword"
printf "average length: %d\n" "$allcount/count"
printf "word count: "
tr '\n' '\n' < en_full.txt | wc -l














echo "===pl_full.txt==="
echo
echo
echo "-----------------------------------------------------"
echo "===pl_full.txt===
longest word: cholerniedługiesłowo
shortest word: jajo
average length: 3
word count:  333

===en_full.txt===
longest word: areallylongword
shortest word: s
average length: 8
word count:  123456"
