# Word Frequency Count with xxHash

This project provides the source code for calculating word frequency in a text file using the xxHash algorithm.

## Build Instructions

To build the project, simply run:
make

The created binary will be placed in the `exec` directory.

## Example Usage

After building the project, you can use the binary to calculate word frequencies in a text file by running: 
  ./exec/freq input.txt output.txt
This command reads `input.txt`, calculates the word frequencies, and saves the results to `output.txt`.
