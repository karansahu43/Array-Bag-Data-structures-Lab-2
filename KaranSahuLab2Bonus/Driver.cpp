// Author:  Karan Sahu
// Assignment Number: Lab 2
// File Name: KaranSahuLab2.cpp
// Course/Section: data struct
// Due Date:   9/20/2018
// Instructor: Bernard Ku
#include <iostream>
#include <string>
#include "ArrayBag.h"

using namespace std;




template <typename ItemType>
void Driver()
{
	ArrayBag<ItemType> bag;
	ArrayBag<ItemType> bag2;
   

	int loopnum1 = 0, loopnum2 = 0;
	ItemType items[15];
	ItemType items2[15];
	
	while (!((loopnum1>0)&&(loopnum1<16)))
	{
	cout <<"How many items for bag 1? (Between 0 and 15): ";
	cin >> loopnum1;
	cout << endl << endl ;
	}
	
	
	for (int i = 1; i < loopnum1 +1; i++)
	{
		cout << "Please eneter item " << i << " for bag 1: ";
		cin >> items[i -1];
		cout << endl;
	}
	cout << endl;
	while (!((loopnum2>0)&&(loopnum2<16)))
	{
	cout <<"How many items for bag 2? (Between 0 and 15): ";
	cin >> loopnum2;
	cout << endl << endl ;
	}	
	
	for (int i = 1; i < loopnum2 + 1 ; i++)
	{
		cout << "Please eneter item " << i << " for bag 2: ";
		cin >> items2[i -1];
		cout << endl;
	}
	cout << endl;
	
	for (int i = 0; i < loopnum1; i++)
    {
		bag.add(items[i]);
	}
	for (int i = 0; i < loopnum2; i++)
   {
		bag2.add(items2[i]);
	}  // end for
	

	ArrayBag<ItemType> result = bag.bagUnion(bag2);
	ArrayBag<ItemType> result2 = bag.bagIntersection(bag2);
	ArrayBag<ItemType> result3 = bag.bagDifference(bag2);
	ArrayBag<ItemType> result4 = bag2.bagDifference(bag);
	
	cout << "this is bag 1" << endl;
	bag.display();
	cout << endl << endl;
	
	cout << "this is bag 2" << endl;
	bag2.display();	
	cout << endl << endl;
	
	cout << "this is bag union" << endl;
	result.display();
	cout << endl << endl;
	
	cout << "this is bag intersection" << endl;	
	result2.display();
	cout << endl << endl;
	
	cout << "this is bag difference bag 1 - bag 2" << endl;
	result3.display();
	cout << endl << endl;
	
	cout << "this is bag difference bag 2 - bag 1" << endl;
	result4.display();

	cout << endl << endl;
	
	
	
   cout << "All done!" << endl;
}

int main()
{
	int selection;
	bool driverLoop = true;

	while(driverLoop == true)
	{
		cout << "1) Digit Char Array" << endl << "2) Alpha Char Array" << endl << "3) String Name Array" << endl << "4) Integer Array" << endl 
		<< "5) Exit" << endl << endl;
		
		do 
		{
			cout << "Please make a selection 1-5: ";
			cin >> selection;
			cout <<endl;
		} while (!(selection == 1 || selection == 2 || selection == 3 || selection == 4 || selection == 5));
		
		if(selection == 1)
		{
			Driver<char>();
		}
		else if(selection == 2)
		{
			Driver<char>();
		}
		else if(selection == 3)
		{
			Driver<string>();
		}
		else if(selection == 4)
		{
			Driver<int>();
		}
		else if(selection == 5)
		{
			driverLoop = false;
		}
	}
	
	
	


}
  // end main
  
  







/* sample outpuut
1) Digit Char Array
2) Alpha Char Array
3) String Name Array
4) Integer Array
5) Exit

Please make a selection 1-5: 1

How many items for bag 1? (Between 0 and 15): 8


Please eneter item 1 for bag 1: 4

Please eneter item 2 for bag 1: 7

Please eneter item 3 for bag 1: 3

Please eneter item 4 for bag 1: 2

Please eneter item 5 for bag 1: 1

Please eneter item 6 for bag 1: 6

Please eneter item 7 for bag 1: 8

Please eneter item 8 for bag 1: 9


How many items for bag 2? (Between 0 and 15): 8


Please eneter item 1 for bag 2: 0

Please eneter item 2 for bag 2: 1

Please eneter item 3 for bag 2: 9

Please eneter item 4 for bag 2: 5

Please eneter item 5 for bag 2: 2

Please eneter item 6 for bag 2: 3

Please eneter item 7 for bag 2: 6

Please eneter item 8 for bag 2: 4


this is bag 1
The bag contains 8 items:
4 7 3 2 1 6 8 9



this is bag 2
The bag contains 8 items:
0 1 9 5 2 3 6 4



this is bag union
The bag contains 9 items:
0 1 2 3 4 5 9 6 7



this is bag intersection
The bag contains 6 items:
1 2 3 4 6 9



this is bag difference bag 1 - bag 2
The bag contains 2 items:
7 8



this is bag difference bag 2 - bag 1
The bag contains 2 items:
0 5



All done!
1) Digit Char Array
2) Alpha Char Array
3) String Name Array
4) Integer Array
5) Exit

Please make a selection 1-5: 2

How many items for bag 1? (Between 0 and 15): 8


Please eneter item 1 for bag 1: d

Please eneter item 2 for bag 1: b

Please eneter item 3 for bag 1: c

Please eneter item 4 for bag 1: a

Please eneter item 5 for bag 1: D

Please eneter item 6 for bag 1: B

Please eneter item 7 for bag 1: C

Please eneter item 8 for bag 1: A


How many items for bag 2? (Between 0 and 15): 4


Please eneter item 1 for bag 2: a

Please eneter item 2 for bag 2: g

Please eneter item 3 for bag 2: A

Please eneter item 4 for bag 2: G


this is bag 1
The bag contains 8 items:
d b c a D B C A



this is bag 2
The bag contains 4 items:
a g A G



this is bag union
The bag contains 10 items:
A B C D G a b c d g



this is bag intersection
The bag contains 2 items:
A a



this is bag difference bag 1 - bag 2
The bag contains 6 items:
B C D b c d



this is bag difference bag 2 - bag 1
The bag contains 2 items:
G g



All done!
1) Digit Char Array
2) Alpha Char Array
3) String Name Array
4) Integer Array
5) Exit

Please make a selection 1-5: 3

How many items for bag 1? (Between 0 and 15): 9


Please eneter item 1 for bag 1: Mary

Please eneter item 2 for bag 1: Joe

Please eneter item 3 for bag 1: Jack

Please eneter item 4 for bag 1: David

Please eneter item 5 for bag 1: Kim

Please eneter item 6 for bag 1: Tom

Please eneter item 7 for bag 1: Johnson

Please eneter item 8 for bag 1: John

Please eneter item 9 for bag 1: Jackson


How many items for bag 2? (Between 0 and 15): 8


Please eneter item 1 for bag 2: Macy

Please eneter item 2 for bag 2: Jose

Please eneter item 3 for bag 2: Jackson

Please eneter item 4 for bag 2: Davis

Please eneter item 5 for bag 2: Kims

Please eneter item 6 for bag 2: Toms

Please eneter item 7 for bag 2: Johnson

Please eneter item 8 for bag 2: Sonny


this is bag 1
The bag contains 9 items:
Mary Joe Jack David Kim Tom Johnson John Jackson



this is bag 2
The bag contains 8 items:
Macy Jose Jackson Davis Kims Toms Johnson Sonny



this is bag union
The bag contains 15 items:
David Davis Jack Jackson Joe John Johnson Jose Kim Kims Macy Mary Sonny Tom Toms



this is bag intersection
The bag contains 2 items:
Jackson Johnson



this is bag difference bag 1 - bag 2
The bag contains 7 items:
David Jack Joe John Kim Mary Tom



this is bag difference bag 2 - bag 1
The bag contains 6 items:
Davis Jose Kims Macy Sonny Toms



All done!
1) Digit Char Array
2) Alpha Char Array
3) String Name Array
4) Integer Array
5) Exit

Please make a selection 1-5: 4

How many items for bag 1? (Between 0 and 15): 12


Please eneter item 1 for bag 1: 42

Please eneter item 2 for bag 1: 71

Please eneter item 3 for bag 1: 34

Please eneter item 4 for bag 1: 21

Please eneter item 5 for bag 1: 100

Please eneter item 6 for bag 1: 498

Please eneter item 7 for bag 1: 6000

Please eneter item 8 for bag 1: 88

Please eneter item 9 for bag 1: 91

Please eneter item 10 for bag 1: 7

Please eneter item 11 for bag 1: 242

Please eneter item 12 for bag 1: 21


How many items for bag 2? (Between 0 and 15): 12


Please eneter item 1 for bag 2: 42

Please eneter item 2 for bag 2: 32

Please eneter item 3 for bag 2: 34

Please eneter item 4 for bag 2: 421

Please eneter item 5 for bag 2: 100

Please eneter item 6 for bag 2: 4

Please eneter item 7 for bag 2: 6001

Please eneter item 8 for bag 2: 88

Please eneter item 9 for bag 2: 912

Please eneter item 10 for bag 2: 7

Please eneter item 11 for bag 2: 241

Please eneter item 12 for bag 2: 42


this is bag 1
The bag contains 12 items:
42 71 34 21 100 498 6000 88 91 7 242 21



this is bag 2
The bag contains 12 items:
42 32 34 421 100 4 6001 88 912 7 241 42



this is bag union
The bag contains 17 items:
4 7 21 32 34 42 71 88 91 100 241 242 421 498 912 6000 6001



this is bag intersection
The bag contains 5 items:
7 34 42 88 100



this is bag difference bag 1 - bag 2
The bag contains 7 items:
21 21 71 91 242 498 6000



this is bag difference bag 2 - bag 1
The bag contains 6 items:
4 32 241 421 912 6001



All done!
1) Digit Char Array
2) Alpha Char Array
3) String Name Array
4) Integer Array
5) Exit

Please make a selection 1-5: 5




 */
