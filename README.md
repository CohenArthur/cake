# cake

`cake` is a `GNU make` clone written in C++ as a teaching project


## How to use

`cake` accepts the following options:

- -h, --help to print out the different options
- -f, --file to specify a Cakefile

By default, `cake` looks for the following filenames in the current directory, in this order:

- Cakefile
- cakefile
- GNOUcake

You can specifiy recipes to execute to `cake` simply by passing the recipes' names as arguments. For exemple,

`cake -f this_file_here all check clean` will execute the `all`, `check` and `clean` recipes contained in ./this_file_here.

Syntax:

```make
Variable=Value

Variable_1=$(Variable)
Variable_2=${Variable}
Variable_3=$$SHELL

Recipe=Dependencies
\tCommand \
\tRest of command
```

## How to build

```sh
mkdir build
cd build
cmake ..
make
```
