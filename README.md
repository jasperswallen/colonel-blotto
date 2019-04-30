# Colonel Blotto

Examining Strategies For Winning Custom Blotto Game

[![Build Status](https://travis-ci.com/jasperswallen/colonel-blotto.svg?branch=machine-learning)](https://travis-ci.com/jasperswallen/colonel-blotto)

Game is played between two players as follows:

1. Each player lays down 100 soldiers at castles marked 1-10, without knowing how many soldiers the other player lays down.
2. Starting with castle 1 and proceeding to castle 10, whoever has more soldiers at each castle wins the number of the castle. For example, if you win castle 2 20-15, you get 2 points. If it is a tie, neither team gets points.
3. Whoever gets to 20 points first wins, and the game is over.

## Usage:

1. Clone the repo
2. Compile with `make`
3. Generate dataset.txt with `$ ./dataset_gen [number of iterations]` (currently, sample dataset contains 1000)
4. Run the dataset through blotto with `$ ./blotto_ml [dataset file] [output file]`
5. Repeat step 4, changing the dataset file to the previous output file each time.
 
* Example:
  * `make`
  * `./dataset_gen 1000`
  * `./blotto_ml dataset.txt output.txt`
  * `./blotto_ml output.txt output2.txt`
  * `./blotto_ml output2.txt output3.txt`
  * And so on until only one line remains (this is your optimal solution)

## To-do/Completed:

- [x] Make basic ML program ~(sorta works?)~ ~(does not work at all)~ (ok now it actually sort of works!)
- [x] Implement proper random dataset (right now, all exist as modified normal distributions)
- [x] Make basic program for reading in from files to determine who wins
- [x] Merge with master


### Status: 'ML' Completed with Caveats

At this point, the machine learning algorithm works. It is a simple round robin that tests against the rest of the given inputs. Limitations primarily consist of:
1. Runtime
2. Random number generation (this part is still off, and I'm not entirely sure how to implement this)
3. ~Changing the command each time (it would be ideal if it just iterated from each file to the next, BUT with large dataset sizes, this would result in hugely long runtimes (each iteration is at least O(n^2))~
4. Also, this whole program was written in C++, which may be awkward to move forward with if anyone wanted to. I mostly just wanted to throw this together in response to the Jane Street challenge.

I am hesitant to say that the ideal solution can be found using this method, since:
a.) The data is randomly generated, but in the real world, competition would be against other people('s algorithms)
and b.) Just because the round robin is won > 50% of the time against the winning dataset does not mean it would be won against the losing dataset. That is, if one sample barely makes it into the winning dataset by winning almost exclusively against the winning dataset, it will then do *very* well against the winning dataset and further iterations, while it would do *very* poorly against the losing dataset.

That being said, I think that this will be as far as I will go with this specific problem, since it is very hard to test if the solved solution is actually a good solution.