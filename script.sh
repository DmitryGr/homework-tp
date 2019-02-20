#!/bin/bash
2> /dev/null;
IFS=$'\n';
if [ -d ~/backuped-files ]; then
    rm -rf ~/backuped-files;
fi
mkdir -p ~/backuped-files;
directoryname=$1;
archivename=$2;
excess=2;
for parameters in $@; do
    if [ "$excess" -ge "1" ]; then
        let "excess-=1";
        continue
    fi
    for filename in $(find $directoryname -iname '*'.$parameters 2>/dev/null); do
        NAME=$(basename -- "$filename");
        NAME="${NAME%.*}";
        extension="${filename##*.}";
        finalname=$NAME;
        if test -f ~/backuped-files/$NAME"."$extension; then
            variable=1;
            while true; do
            try_name=$NAME"("$variable")";
            if test -f ~/backuped-files/$try_name"."$extension; then
                let "variable+=1"
            else
                finalname=$try_name;
                break
            fi
            done
        fi  
        result=$finalname"."$extension;
        cp $filename ~/backuped-files/$result; 
    done
done

cd ~/backuped-files;
tar -rf $archivename.tar *

excess=2;
for parameters in $@; do
    if [ "$excess" -ge "1" ]; then
        let "excess-=1";
        continue
    fi
    for filename in $(find ~/backuped-files -maxdepth 1 -iname '*'.$parameters 2>/dev/null); do
        rm $filename;
    done
done
echo "Done";
