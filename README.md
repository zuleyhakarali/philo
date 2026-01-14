# Philosophers

This project is an implementation of the Dining Philosophers problem using threads and mutexes.

## Build
make

## Usage
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [must_eat_count]

## Rules & Implementation Notes
- Each philosopher is a thread
- Forks are protected by mutexes
- Time values are in milliseconds

## File Structure
philo/
├── philo.h        → shared structs, macros and function prototypes
├── main.c         → program entry point, thread creation and cleanup
├── arg_check.c    → argument validation and initialization of input values
├── cycle_part.c   → philosopher life cycle (eat, sleep, think loop)
├── check.c        → death detection and must-eat count control
├── utils.c        → helper functions used across the project
├── Makefile
