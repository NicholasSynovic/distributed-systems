# Homework 1

> Create a Ceasar Cipher in C++
> By Nicholas Synovic and Erik Pautsch

## Table of Contents

- [Homework 1](#homework-1)
  - [Table of Contents](#table-of-contents)
  - [Note](#note)
  - [Command Line Arguements](#command-line-arguements)
    - [Encoder](#encoder)
    - [Decoder](#decoder)

## Note

- (From Nicholas Synovic) Had difficulty setting up tests. Tests are written but are otherwise non-functional.
- (From Erik Pautsch) ChatGPT was used for questions such as `What sort of C++ data structure can I use to store a pair containing an integer and string?` Additionally, I also used ChapGPT to explain general language operations such as reading from a file/stdin.
- (From Erik Pautsch) Update on tests as of 2/22: Linker is unable to identify functions in test file. Reported error is 'undefined reference to "insert_function_name"'. Explored a variety of solutions without success.

## Command Line Arguements

### Encoder (Nicholas Synovic)

`./encoder -h`

```shell
Caesar Cipher Encoder
Usage: ./encoder [OPTIONS]

Options:
  -h,--help                   Print this help message and exit
  -n,--lines INT: >= 10=10    Number of sentences to generate (default = 10)
  -l,--length INT: >= 3=3     Minimum word length (default = 3)
  -d,--dict TEXT=wordlist.txt Path to dictionary (default = wordlist.txt)
  -o,--output                 Output path (default = $STDOUT)
```

### Decoder (Erik Pautsch)

`./decoder -h`

```shell
COMP 439 HW 1: Ceasar Cipher Decoder
 -d | -dict        Location of dictionary containing the word list (default = wordlist.txt)
 -i | -input       Input filename. No input defaults to $STDIN
 -o | -output      Output filename. No input defaults to $STDOUT
 -h | -help        Display this message
```

