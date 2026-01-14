*This project has been created as part of the 42 curriculum by zkarali.*

# Philosophers

## Description
This project is an implementation of the classic Dining Philosophers problem.
The goal is to handle synchronization issues using threads and mutexes while avoiding deadlocks and data races.
Each philosopher alternates between eating, sleeping, and thinking according to given timing constraints.

## Instructions

### Compilation
make

### Execution
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [must_eat_count]

### Rules & Implementation Notes
- Each philosopher is implemented as a separate thread
- Forks are protected using mutexes
- Time values are expressed in milliseconds
- The simulation stops when a philosopher dies or when all philosophers have eaten the required number of times

## File Structure
philo/
├── philo.h        → shared structs and function prototypes  
├── main.c         → program entry point, thread creation and cleanup  
├── arg_check.c    → argument validation and initialization of input values  
├── cycle_part.c   → philosopher life cycle (eat, sleep, think loop)  
├── check.c        → death detection and must-eat count control  
├── utils.c        → helper functions shared across the project  
├── Makefile  

## Resources
- Dining Philosophers Problem (Wikipedia)
- 42 subject PDF and evaluation guidelines

AI tools were used to:
- Clarify theoretical concepts related to threads and mutexes
- Help design edge cases and test scenarios for the simulation