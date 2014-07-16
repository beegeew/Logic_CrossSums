% Beverly Genelle Wertz
% CS 4331 - Theory and practice of Logic Programming - Summer II 2011
% Cross Sums Solver - ASP
%
% Cross Sums is the original name for what is now popularly known as kakuro. You are provided
% with a varying sized board (the most common I found was 13x13 in puzzle books) and are provided
% with number clues for the row or column below or to the right of the clue. 
% Each clue has a specific number of cells that the value can take up and each cell must contain
% a unique number from 1-9, and all the values must add up together to the clue cell (I have used 
% the word head in this code). There may be more than one of a number in a column/row but only if they 
% are affected by different row or column heads. It should be noted that every call in a valid cross sums
% puzzle which is part of the solution (not blacked out or a head), is affected by a row and a column
% head. 
% 
% A valid input file will contain the following facts: 
% 
% num(1..9). - The num value will always be 1..9 regardless of puzzle size. 
%
% row(N). col(M).  - Row and col need not be the same size. This sets the possible range of values
% that a row and/or column value could be. While we start the size of the board at zero, a zero will never
% be in the possible ranges since every cell needs a column and row value component. Row and column 0 
% will always be populated by heads or blank, non-game cells. 
% 
% head(Value, Row, Column, Length, r or c, ID). - Again we have value row and column and this lets us 
% know where each item starts and what we need to add up to. The Length is the number of cells away from 
% the start of the head where the last cell that adds up to the value resides. "r or c" is the attribute that 
% allows us to define if we are looking at a row or column range. The ID is just a unique identifier to help
% contraint rules prevent the appearance of duplicate numbers. 
%
% The following will appear in the output file of this program as all other atoms are suppressed:
%
% value(Value,Row,Column,Row Head ID, Column Head ID). - The first three are obviously the value, row
% and column values. The two ID's are from the head ID, each head has a unique ID, since a two heads can
% occupy the same row and column location.


% Our choice rule forces just one valid number to be chosen for each value fact which contains rows, columns, and 
% only exists in the range of a cell which is between the head and up to the end of a valid range. The rest of the 
% cell coordinates are not valid for values to be chosen and will not be a part of the answer set.
1{value(V,R,C,RID,CID):num(V)}1:- row(R), 
		col(C), 
		head(_,RH,C,LC,c,CID), 		% We find the column ID for this value and then make sure its Row
		R > RH, 					% value is greater than the head's row. Finally we ensure row position
		R <= RH + LC, 				% is no greater than the last cell in the range.
		head(_,R,CH,LR,r,RID), 
		C > CH, 					% the same process is carried out for the row ID
		C <= CH + LR.

% Now that we have our row and column IDs, we state that the value for any two items in the same column which have the 
% same head ID but not the same row should not have the same value. The head rule is used here simply to ensure that
% the CID/RID is valid for both rules. The row constraint is set up in a similar fashion.
:-value(V,R1,C,_,CID), value(V,R2,C,_,CID), head(_,_,_,_,_,CID), R1 != R2.
:-value(V,R,C1,RID,_), value(V,R,C2,RID,_), head(_,_,_,_,_,RID), C1 != C2.
		
		
% To find the valid number for a row, we start at the last cell for a head with the position of the last cell set for 
% the position term. The recursive function then will put the value of the previous cell plus the value of the current
% cell in the predicate, and set the column position to the previous column. This allows the full value of the head to 
% be reached when the predicate is pointing to the head and the value is pointed to the first cell used to add up
% to the value along with the recursively called values in the next cells. In a valid result, this will add up to the head
% value. This is important for our constraint rule, as without this fact, we would not have a solution. 
calcrowvalue(RID,C+L,0):- head(V,_,C,L,r,RID).
calcrowvalue(RID,C-1,V+VC):- value(VC,_,C,RID,_), 
		calcrowvalue(RID,C,V).

% When you hit the column of the head ID for a row, you should have the full value of the head as V1. If not, this is not
% a solution.
:-calcrowvalue(RID,C,V1), head(V2,_,C,_,_,RID), V1 != V2.


%These rules work identically to the head rows, but instead for the head columns. 
calccolvalue(CID,R+L,0):- head(V,R,_,L,c,CID).
calccolvalue(CID,R-1,V+VC):- value(VC,R,_,_,CID), 
		calccolvalue(CID,R,V).

:-calccolvalue(CID,R,V1), head(V2,R,_,_,_,CID), V1 != V2.

% Since we already know what's in the head columns, the only output she pass back to the user/calling program will be the 
% values for each cell that is in the range of a head.
#hide.
#show value/5.