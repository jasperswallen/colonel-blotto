# colonel-blotto
Examining Strategies For Winning Custom Blotto Game


Game is played between two players as follows:
1. Each player lays down 100 soldiers at castles marked 1-10, without knowing how many soldiers the other player lays down.
2. Starting with castle 1 and proceeding to castle 10, whoever has more soldiers at each castle wins the number of the castle. For example, if you win castle 2 20-15, you get 2 points. If it is a tie, neither team gets points.
3. Whoever gets to 20 points first wins, and the game is over.

# Usage:
1. Clone the repo
2. Compile `blotto_ml` and `dataset_gen`
3. Generate dataset.txt with `$ ./dataset_gen [number of iterations]` (currently, sample dataset contains 100000)
4. Run the dataset through blotto with `$ ./blotto_ml [dataset file] [output file]`
5. Check the last line of your output file to see what the optimal solution found was.
    1. If you want, you can put the optimal solution in the first line of your dataset file to start with that, then run through it as many times as you want like this.

# To-do/Completed:
- [x] Make basic ML program (sorta works?)
- [ ] Implement proper random dataset (right now, all exist as modified normal distributions)
- [x] Make basic program for reading in from files to determine who wins