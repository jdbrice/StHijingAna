#/bin/bash
source star_env

nevents=${1:-1000}
filename=${2:-"testg.fzd"}
echo root4star -b -q -l 'simple.C( '"$nevents"', "'"$filename"'" )'
root4star -b -q -l 'simple.C( '"$nevents"', "'"$filename"'" )'