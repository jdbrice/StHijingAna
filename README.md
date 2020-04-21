# StHijingAna
---

Tools for analyzing HIJING or other MC events in the STAR Forward framework

Launch an environment:
```sh
./dev.sh
```
you will now be in the `/tmp/work/` directory

Perform a full build of the code (first time only)
```sh
./build 1
```

after first time, you can use:
```sh
./build
```
It is faster than a full cmake and make.

Place simulation files in `work/fzd/` and produce a file listing all that you want to run on. See `work/fzd/short.lis`. Update `multi.sh` if you modified the list and run with:
```sh
./multi.sh
```

this will run over the input files one by one.
You can make some common plots with `plot.C` which will write to `/work/out/`

