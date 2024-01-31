#include <iostream>

using namespace std;

int listPtr = 0; // default list pointer value

int getAnswer()
{
    cout << "Enter 1 to Add Value" << endl;
    cout << "Enter 2 to Delete Value" << endl;
    cout << "Enter ANY other character to EXIT" << endl;
    int someAns = 0;
    cin >> someAns;

    if(someAns == 1)
    {
        cout << "ADDING" << endl;
        return someAns;
        
    }
    else if(someAns == 2)
    {
        cout << "DELETING" << endl;
        return someAns;
        
    }
    else
    {
        cout << "EXITING" << endl;
        
    }
}


void showList(char someList[],int someLink[], int somePtr)
{
    cout << "Position" << " || " << "List" << " || " << "Link" << endl;
    for (int i =0; someList[i] != NULL; i++)
    {
        cout << i << "         " << someList[i] << "         " << someLink[i] << endl;
    }
}

// Scraped Function
void reLink(char letter, char someL[], int someLk[], int lPtr, int newP)
{
    int tempPtr = 0;
    int prevPtr = 0;
    int nextPtr = 1;
    
    while (someL[tempPtr] != NULL)
    {
        if (letter > someL[tempPtr])
        {
            if (someL[tempPtr + 2] == NULL)
            {   
                someLk[tempPtr] = newP;
                someLk[lPtr] = tempPtr;
                break;
            }
            else
            {
                prevPtr = tempPtr;
                nextPtr = tempPtr + 1;
            }
            
        }
        else if (letter < someL[tempPtr])
        {   
            someLk[prevPtr] = tempPtr;
            someLk[tempPtr]= nextPtr;    
            
        }

        tempPtr++;
    }
}

// implementing addition of value to array, and Link set up
void addVal( char someL[], int someLk[], int &lPtr) // passing list pointer by reference to modify value
{
    char tempLetter = ' ';
    int nPosition = 0;
    cout << "Enter a letter to Add:" << endl;
    cin >> tempLetter;
    int i = 0;
    while(someL[i] != NULL && someL[i] != ' ')
    {
        if (tempLetter == someL[i])
        {
            cout << "Value already exists!!!" << endl;
            return;
        }
        i++;
        nPosition++;
    }
    someL[i] = tempLetter;
    
    if (tempLetter < someL[lPtr])
    {
        someLk[nPosition] = lPtr;
        lPtr = nPosition;
    }
    else
    {
        int curr = lPtr;
        int prev = NULL;

        while (curr != 99 && tempLetter > someL[curr])
        {
            prev = curr;
            curr = someLk[curr];
        }

        if (curr == 99)
        {
            someLk[prev] = nPosition;
            someLk[nPosition] = 99;
        }
        else
        {
            someLk[prev] = nPosition;
            someLk[nPosition] = curr;
        } 
    }
   /*cout << "<===========================>" << endl;
    cout << "HEAD:" << lPtr << endl;
    cout << "<===========================>" << endl;
    showList(someL, someLk, lPtr);*/
    
}


void deleteVal(char someL[], int someLk[], int &lPtr)
{
    char deleteL = ' ';
    cout << "Enter Value to Delete" << endl;
    cin >> deleteL;
    int curr = lPtr;
    int prev = NULL;
    while (curr != 99 && deleteL != someL[curr])
    {
        prev = curr;
        curr = someLk[curr];
    }
    
    if (curr == 99 && deleteL != someL[prev])
    {
        cout << "Value does not Exist!!!" << endl;
        return;
          
    }
    else if (curr == 99 && deleteL == someL[prev])
    {
        someL[prev] = ' ';
        someLk[prev - 1] = curr;
        return;
    }
    else if (curr == lPtr && deleteL == someL[curr])
    {
        someL[curr] = ' ';
        lPtr = someLk[curr];
        return;
    }
    else
    {
        someL[curr] = ' ';
        someLk[prev] = someLk[curr];
        return;
    }

    /*cout << "<===========================>" << endl;
    cout << "HEAD:" << lPtr << endl;
    cout << "<===========================>" << endl;
    showList(someL, someLk, lPtr); */
}

int main()
{
    char myList[99] = { 'D','G','J','M','R','W'};
    int temp = 0;
    cout << "List" << endl;
    while( myList[temp] != NULL)
    {
        cout << myList[temp] << endl;
        temp++;
    }
    int myLink[99] = { 1,2,3,4,5,99};
    int listPtr = 0;
    char tempChar;  // value for user to add or delete
    int tempLink =0;
    cout << "<===========================>" << endl;
    cout << "HEAD:" << listPtr << endl;
    cout << "<===========================>" << endl;
    showList(myList, myLink, listPtr);
    int checker = getAnswer();
    while (checker ==1 || checker ==2)
    {
        if (checker == 1)
        {
            addVal(myList, myLink, listPtr);

        }
        else if(checker == 2)
        {
            deleteVal(myList, myLink, listPtr);

        }
        else
        {
            break;
        }
        cout << "<===========================>" << endl;
        cout << "HEAD:" << listPtr << endl;
        cout << "<===========================>" << endl;
        showList(myList, myLink, listPtr);
        checker = getAnswer();
    }
}

