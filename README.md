# Philosophers - 42 Barcelona

This project is about learning the basics of threading a process and understanding the challenges of parallel computing. Philosophers, in this context, are processes that need to act concurrently, making sure they all get to eat without any of them starving to death.

## Project Details

- One or more philosophers sit at a round table.
- A large bowl of spaghetti is placed in the center of the table.
- Philosophers can only do one of the following at a time: eat, think, or sleep.
  - While eating, they cannot think or sleep.
  - While thinking, they cannot eat or sleep.
  - While sleeping, they cannot eat or think.
- There are forks on the table, one between each philosopher.
- To eat spaghetti, a philosopher needs to pick up both the fork to their right and the one to their left.
- After eating, a philosopher puts down the forks and starts sleeping. Once they wake up, they start thinking.
- The simulation stops when a philosopher dies of starvation.
- Every philosopher needs to eat and should never starve.
- Philosophers don't communicate with each other.
- Philosophers don't know if another philosopher is about to die.
- It goes without saying, philosophers should avoid dying!

## Program Arguments

The program accepts the following arguments:
- `number_of_philosophers`: The number of philosophers and also the number of forks.
- `time_to_die`: If a philosopher hasn't started eating `time_to_die` milliseconds after the start of their last meal or the beginning of the simulation, they die.
- `time_to_eat`: The time it takes for a philosopher to eat. During this time, they will need two forks.
- `time_to_sleep`: The time a philosopher will spend sleeping.
- `number_of_times_each_philosopher_must_eat` (optional): If all philosophers have eaten at least this many times, the simulation stops. If not specified, the simulation stops when a philosopher dies.

---
This project is inspired by the dining philosophers problem, a classic synchronization problem and an example of a common computing problem in concurrency.
_Eat, Sleep, Spaghetti, Repeat._
