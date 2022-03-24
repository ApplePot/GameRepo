 1. Identification of group member
  Groupmate 1,
  Name: Ma Pui Sang
  UID:3035821245
  Groupmate 2,
  Name: Wong Hao
  UID:3035783584
  
2. Game description/rule
This text-based game is a student simulator at HKU in an alternate universe. The goal of the student is to obtain the highest GPA by the end of the game. The student would have attributes, like reputation, hunger, focus, pressure, and sanity that the player have to actively maintain, that is affected by both the choices that the player makes and random events. The GPA is calculated based on the student's attribute. Student stats can be modified by equipping various items, which are obtainable through game progession. Failling to maintain any particular attributes will result in a decrease in others as well as triggering events, like suicide or withdrawl from study which will end the game immediately. In contrast, successfully maintaining attributes at certain levels for a period of time will buff the status the student, increasing the odds of having a higher GPA at the end of the game. Some choices are only accessible if the student's attributes are of a particular level.

3. Game features
Load and Save,
The game file will take an input player.txt file which stores the status and items that the player has. And as the game progresses, the .txt file will be modified. Finally, when the player either exits and saves the program or the student is eliminated, the program will end; the latter case will result in the game 'resetting' and attribute.txt will be restored to its initial version. This satisfies requirement 3, 4, and 5.

Random events,
Throughout the game, random events can occur. For example, if the player decides to study in the library, the student may be able to obtain an item that will modify his/her attribute. And the player would have to min-max the student's attributes in order to obtain a better result during game progession. This satisfies requirement 1.

Inventory system,
Although the player can obtain and store multiple items in the inventory, there will only be three slots in which the player can equip items. Some items are consumables that will only be effective for a period of time, after which it will be removed from the inventory. This satisfies requirment 2 and 3.
