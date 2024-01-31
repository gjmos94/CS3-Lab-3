#include <iostream>

using namespace std;

int listPtr = 0;

bool choiceSelector(int someNum)
{
    if (someNum == 1)
    {
        return true;
    }
    else if (someNum == 2)
    {
        return false;
    }
}
bool getAnswer()
{
    cout << "Enter 1 to Add or 2 to Delete a value" << endl;
    int someAns = 0;
    cin >> someAns;
    if(someAns == 1)
    {
        cout << "ADDING" << endl;
        return choiceSelector(someAns);
        
    }
    else if(someAns == 2)
    {
        cout << "DELETING" << endl;
        return choiceSelector(someAns);
        
    }
    else
    {
        cout << "INVALID RESPONSE" << endl;
        
        
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
void addVal( char someL[], int someLk[], int &lPtr)
{
    char tempLetter = ' ';
    int nPosition = 0;
    cout << "Enter a letter to Add:" << endl;
    cin >> tempLetter;
    int i = 0;
    while(someL[i] != NULL)
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
    int j = lPtr;
    while (someL[j] != NULL)
    {
        if (someL[nPosition] < someL[lPtr])
        {
            someLk[nPosition] = lPtr;
            lPtr = nPosition;
            
            break;
        }
        else if(someL[nPosition] > someL[lPtr] && someL[nPosition] < someL[someLk[lPtr]])
        {
            int tempLink = someLk[lPtr];
            someLk[lPtr] = nPosition;
            someLk[nPosition] = tempLink;
            break;
        }
        j = someLk[j];
        
    }
    
    cout << "HEAD:" << lPtr << endl;
    showList(someL, someLk, lPtr);
    
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
    showList(myList, myLink, listPtr);
    
    while (getAnswer != NULL)
    {
        if (getAnswer() == true)
        {
            addVal(myList, myLink, listPtr);
        }
        else if(getAnswer() == false)
        {
            cout << "some deleting stuff goin on" << endl;

        }
    }
}

