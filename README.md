# Treasures hunt
Treasures hunt game made for a school project.  

## The objective 
We want to develop a game with a 2D designed map that is used to place treasures at 4 user-defined locations from the user CLI prompt.  
The user can either choose to specify the asked locations or to automatically generate random locations.  
Then, the final map is generated and the program lets the user determine his path to reach the 4 mysterious treasures from his initial position.  
The movements to reach the treasures are controlled by the 4 classic arrows of the user's keyboard.  

## Realisation  
The program is written in C.  
The 2D map has been created working with GIMP to do some pixel art manipulation.  
SDL lib is used to handle player movements with the keyboard events and to refresh the map that is dynamically displayed to the user interface.  

## Examples
### User prompt 
<img width="1440" alt="Some prompt to place the treasures" src="https://user-images.githubusercontent.com/45339466/234351919-a163a393-3f24-406f-a078-c5e350a5e9cf.png">

### Landing in the MAP 
<img width="261" alt="Landing in the map" src="https://user-images.githubusercontent.com/45339466/234352135-1043a587-3956-4e59-bcf1-78dc4317dfee.png">

### Displaying some placed treasures  
<img width="261" alt="The treasures have been placed" src="https://user-images.githubusercontent.com/45339466/234352543-b5bc7eaa-33bc-4dac-bbd6-1dce84ff3396.png">

### After a treasure has been found and taken  
<img width="261" alt="After picking a treasure" src="https://user-images.githubusercontent.com/45339466/234352792-8846c0ea-89ac-4001-9d8e-632f330ebf51.png">
