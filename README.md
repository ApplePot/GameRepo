1. Identification of group member
  Groupmate 1,
  Name: Ma Pui Sang
  UID:3035821245
  Groupmate 2,
  Name: Wong Hao
  UID:3035783584
  
2. Game description/rule

 This text-based game is a student simulator at HKU in an alternate universe. The goal of the student is to obtain the highest GPA by the end of the game. The student would have attributes, like health pool, reputation, hunger, socialing score, focus, pressure, and sanity that the player have to actively maintain, which are affected by both the choices that the player makes and random events. The GPA is calculated based on the student's attribute. Student stats can be modified by equipping various items, which are obtainable through game progession. 

 Failling to maintain any particular attributes will result in a decrease in others as well as triggering events, like emotional mangle, a unhealthy, social-lacking life or at the worst case, self-harming actions. These downfalls may cause a potential school withdrawal, leading to a end/loss in the game. 

 In the contrary, successfully maintaining attributes at certain levels for a period of time will increase some of the student status, increasing the odds of having a higher GPA at the end of the game. Some choices are only accessible if the student's attributes are of a particular level.

3. Game features 

Random events, (satisfying 1. Generation of random game sets or events)
 Throughout the game, random events can occur. For example, if the player decides to study in the library, the student may be able to obtain an item that will modify his/her attribute. And the player would have to min-max the student's attributes in order to obtain a better result during game progession. Another example would be meeting uninspiring students on a random school day, which would cause a downgrade in some attributes e.g.(focus and sanity), and only specific items could prevent/reduce the harm of this random event.
 
Inventory system, (satisfying 2. Data structures for storing game status and 3. Dynamic memory management)
 Although the player can obtain and store multiple items in the inventory, there will only be three slots in which the player can equip items. Some items are consumables that will only be effective for a period of time, after which it will be removed from the inventory. 
 
Load and Save, (satisfying 3. Dynamic memory management, 4. File input/output and 5. Program codes in multiple files)
 The game file will take an input player.txt file which stores the status and items that the player has. And as the game progresses, the .txt file will be modified. Finally, when the player either exits and saves the program or the student is eliminated, the program will end; the latter case will result in the game 'resetting' and attribute.txt will be restored to its initial version.
