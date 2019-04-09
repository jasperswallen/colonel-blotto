# colonel-blotto

Examining Strategies For Winning Custom Blotto Game

[![Build Status](https://travis-ci.com/jasperswallen/colonel-blotto.svg?branch=machine-learning)](https://travis-ci.com/jasperswallen/colonel-blotto)

Game is played between two players as follows:

1. Each player lays down 100 soldiers at castles marked 1-10, without knowing how many soldiers the other player lays down.
2. Starting with castle 1 and proceeding to castle 10, whoever has more soldiers at each castle wins the number of the castle. For example, if you win castle 2 20-15, you get 2 points. If it is a tie, neither team gets points.
3. Whoever gets to 20 points first wins, and the game is over.

## Usage:

1. Clone the repo
2. Compile with `make`
3. Generate dataset.txt with `$ ./dataset_gen [number of iterations]` (currently, sample dataset contains 100)
4. Run the dataset through blotto with `$ ./blotto_ml [dataset file] [output file]`
5. Repeat step 4, changing the dataset file to the previous output file each time.
 
* Example:
  * `make`
  * `./dataset_gen 100`
  * `./blotto_ml dataset.txt output.txt`
  * `./blotto_ml output.txt output2.txt`
  * `./blotto_ml output2.txt output3.txt`
  * And so on until only one line remains (this is your optimal solution)

## To-do/Completed:

- [x] Make basic ML program ~(sorta works?)~ ~(does not work at all)~ (ok now it actually sort of works!)
- [x] Implement proper random dataset (right now, all exist as modified normal distributions)
- [x] Make basic program for reading in from files to determine who wins
- [ ] Merge with master