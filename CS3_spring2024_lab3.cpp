#include <iostream>

using namespace std;

int listPtr = 0; // global default list pointer value

int getAnswer()    // function that enables user menu
{
    cout << "Select an option please:" << endl;
    cout << "1 <-----Add Value." << endl;
    cout << "2 <-----Delete value." << endl;
    cout << "Enter ANY other character to EXIT." << endl;
    int someAns = 0;
    cin >> someAns;

    if(someAns == 1)
    {
        cout << " " << endl;
        cout << "+  ADDING  +" << endl; //adding message
        return someAns;
    }
    else if(someAns == 2)
    {
        cout << " " << endl;
        cout << "x DELETING x" << endl; //delete message
        return someAns;   
    }
    else
    {   
        cout << " " << endl;
        cout << "# EXITING #" << endl; // exit message
    }
}


void showList(char someList[],int someLink[])  //function to display position, list, link table
{

    cout << "Position" << " || " << "List" << " || " << "Link" << endl;
    for (int i =0; someList[i] != NULL; i++) // loop through data
    {   
        cout << i << "         " << someList[i] << "         " << someLink[i] << endl;
    }
    cout << "+---------------------------+" << endl;
    cout << " " << endl;
}

void addVal( char someL[], int someLk[]) //     function to add value and arrange links
{
    char tempLetter = ' ';  // empty variable for user input
    int nPosition = 0;  // value to identify new value location
    int curr = listPtr; // current for link traversal
    int dupCurr = 0;    // current to check duplicates
    bool positionSwitch = false;    // position trigger to determine position of new value
    int prev = NULL;    // value to identify previous link
    cout << "Enter a Value to Add:" << endl;
    cin >> tempLetter;  // taking user input
    int i = 0;

    while(dupCurr != 30)  // check list for duplicate value
    {
        if (someL[dupCurr] == ' ' || someL[dupCurr] == NULL)
        {
            positionSwitch = true;  // if empty position is found switch is activated
        }
        if (tempLetter == someL[dupCurr])
        {
            cout << " " << endl;
            cout << "+++++++++++++++++++++++++++++++++++" << endl;
            cout << " Sorry...the Value already exists." << endl;    // duplicate value flag
            cout << "+++++++++++++++++++++++++++++++++++" << endl;
            cout << " " << endl;
            return;
        }
        
        if (!positionSwitch)
        {
            nPosition++;        // position value determined by bool switch
        }
        dupCurr++;  // increase current value for duplicate checker
        
    }
    someL[nPosition] = tempLetter;  // if no duplicate value is found add the value
    
    if (tempLetter < someL[listPtr])    // best case if new value is lower than head value
    {
        someLk[nPosition] = listPtr;    // set link of new value the former "head"
        listPtr = nPosition;    // set list Pointer to the new low value position
    }
    else
    {
        while (curr != 99 && tempLetter > someL[curr])  // iterate through list using links
        {
            prev = curr;    // set prev to current location value
            curr = someLk[curr]; // set current location to link of current location
        }

        if (curr == 99) // reaching end of links if greates value is added
        {
            someLk[prev] = nPosition;       // set prev link to new item location
            someLk[nPosition] = 99;         // set 99 link to new item 
        }
        else
        {
            someLk[prev] = nPosition;       // value is bigger than prev but lower than next link
            someLk[nPosition] = curr;       // set prev link to new value position, and new value link to current
        } 
    }
   
}


void deleteVal(char someL[], int someLk[])
{
    char deleteL = ' '; // default values for user input, current and prev links
    cout << "Enter a Value to Delete." << endl; 
    cin >> deleteL; // gettin user input
    int curr = listPtr;
    int prev = NULL;
    while (curr != 99 && deleteL != someL[curr])    // iterate using links to check if value exists
    {
        prev = curr;
        curr = someLk[curr];
    }
    
    if (curr == 99 && deleteL != someL[prev])   // if end of links is reached and value is not found
    {
        cout << " " << endl;
        cout << "+++++++++++++++++++++++++++++++++++" << endl;
        cout << " Sorry...the Value does not Exist." << endl;
        cout << "+++++++++++++++++++++++++++++++++++" << endl;
        cout << " " << endl;
        return; // break out
          
    }

    someL[curr] = ' ';  // if value is found we delete it

    //  re-arranging links
    if (curr == listPtr)    // if lowest value is removed we equal listPtr to its link  
    {  
        listPtr = someLk[curr];
    }
    else    // if not lowest value we link prev value to link of removed value
    {
        someLk[prev] = someLk[curr];
    }
}

int main()
{

    cout << "+--------------------------+" << endl;
    cout << "|         Welcome          |" << endl;     // Welcoming message
    cout << "+--------------------------+" << endl;
    cout << " " << endl;
    char myList[30] = { 'D','G','J','M','R','W'};   // declaring list array
    int i = 0;   //int for initial list display loop

    cout << "Initial List display" << endl; // initial display of list
    while( myList[i] != NULL)
    {
        cout << myList[i] << endl;
        i++;
    }

    int myLink[30] = { 1,2,3,4,5,99 };  // creating link array after displaying letter list

    cout << "+---------------------------+" << endl;
    cout << "   Initial HEAD display:" << listPtr << endl;     // initial display of ListPointer or "Head"
    cout << "+---------------------------+" << endl;

    showList(myList, myLink);   //displaying initial data
    int checker = getAnswer();  //value is set to check user answer
    while (checker ==1 || checker ==2)
    {
        if (checker == 1)
        {
            addVal(myList, myLink );    // if answer is 1 call addVal function

        }
        else if(checker == 2)
        {
            deleteVal(myList, myLink ); // if answer is 2 call deleteVal functions

        }
        cout << " " << endl;
        cout << "+---------------------------+" << endl;
        cout << "   HEAD:" << listPtr << endl;     // display list Pointer or "Head"
        cout << "+---------------------------+" << endl;
        showList(myList, myLink);   // display data
        checker = getAnswer();  // aquiring new selection from user
    }

    cout << "+--------------------------+" << endl;
    cout << "|        Good Bye :)       |" << endl;     // Welcoming message
    cout << "+--------------------------+" << endl;

    return 0;
}