1. Identification of group member
  Groupmate 1,
  Name: Ma Pui Sang
  UID:3035821245
  Groupmate 2,
  Name: Wong Hao
  UID:3035783584
  
2. Game description/rule

This text-based game is a student simulator at HKU in an alternate universe. The goal of the student is to obtain the highest GPA by the end of the game. The student have stats - health, sanity, and hunger - which are affected by both the choices that the player makes and random events. At the end of each story, there is a chance of a quiz. If the student's stats are high, the mark of the quiz will be higher, vice versa. The GPA calculation is also based on the student stats. Student stats can be modified by obtaining items through game progession, which lasts for 6 turns (6 in-game days). 

Failling to maintain any particular attributes will result in a decrease in others as well. If the stats falls below certain level, the game will end.

3. Game features 

Random events, (satisfying 1. Generation of random game sets or events, 3. dynamic memory management)
Throughout the game, random events can occur. For example,the player may have random encounters. And the player can choose to either ignore it or deal with it which would result in different changes to player stats. Also, since the occurance of quizes is rng-based, the array which stores the marks of the quizes can not be pre-determined and its size would have to be dynamically allocated.
 
Inventory system, (satisfying 2. Data structures for storing game status)
Although the player can obtain up to 5 items, there can only be at most 3 types of item. Both item ids and the number of unique items are stored inside player.txt. The game automatically adds a suitable item to the player's inventory when certain events are triggered. The items have attributes that apply modifications to the player's stats. Moreover, the items are stored as custome data type "Equipment" which has two string variables that stores item name and description. At the beginning of each turn, if the player has at least 1 item, the game will give the player an option to view details of his items.
 
Load and Save, (satisfying 4. File input/output and 5. Program codes in multiple files)
The game file will take an input player.txt file which stores the status and items that the player has. Upon each manual and auto save (which occurs after each turn), the .txt file will be modified. Finally, when the player either exits and saves the program or the student is eliminated, the program will end; the latter case will result in the game 'resetting' and attribute.txt will be restored to its initial version. Note the input file should have 6 lines arranged in the follow format:
  player_health
  player_sanity
  player_hunger
  number of unique items (max. 3)
  five integers (from 1 to 6, inclusive) seperated by a space
  (0 or 1), depending on whether the effects of items have been applied to player stats yet
 
 By default, player.txt is as follows:
  250
  250
  250
  0
  0 0 0 0 0
  0




