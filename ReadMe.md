Persistent State Pattern

    This is the extension of state pattern which defines persistence of states. The behavior of states is explained using a finite state machine. A class called finite state machine which is above the state class governs the transition of states. 
We have a simple use case of the finite state machine, a vending machine which dispenses the product worth 5 rupees by accepting coins of denomination 1, 2 and 5 rupees. Clearly, we cannot assure vending machine always works. So, when it fails before dispensing the product, it should restart from where it had stopped. This is where we have used to the concept of Persistent state Pattern.

Run:
g++-6 client.cpp 

if everything is ok, then the contents of state file is 0 0 representing state 0 and remaining change 0
else it contains state which it had currently failed and the remaining change at that time
