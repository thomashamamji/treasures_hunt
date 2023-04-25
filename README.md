# Treasures hunt
Treasures hunt game made for a school project.  

## The objective
We want to develop a game with a 2D designed map that is used to place treasures at 4 user-defined locations from CLI prompt.  
The user can either choose the asked locations or to automatically generate random locations.  
Then, the final map is generated and the program lets the user determine his path to reach the 4 mysterious treasures from his initial position.  
The movement to reach the treasures is controlled by the 4 classic arrows of the user's keyboard.  

## Realisation
The program is written in C.  
The 2D map has been created working with GIMP to do some pixel art manipulation.  
SDL lib is used to handle player movements with the keyboard events and to refresh the map that is dynamically displayed to the user interface.  