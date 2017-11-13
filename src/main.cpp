#include <Arduino.h>

struct coordinates_t
{
    int x;
    int y;
};

//debuggin field output format
const String spacer = " ";
const String newLine = "\n";

//size of the field
const int sizeX = 5;
const int sizeY = 5;

//direction of movement
const int left = -1;
const int right = 1;
const int up = -1;
const int down = 1;

// lenght of snake
int lenght;

//for code relevant position info
coordinates_t actualHeadPosition;
bool field[sizeY][sizeX];

coordinates_t moveX(coordinates_t position, int direction)
{
    field[position.y][position.x] = false;
    position.x = position.x + direction;
    if (position.x >= sizeX)
    {
        position.x = 0;
    }
    if (position.x < 0)
    {
        position.x = sizeX - 1;
    }
    field[position.y][position.x] = true;
    return position;
}

coordinates_t moveY(coordinates_t position, int direction)
{
    field[position.y][position.x] = false;
    position.y = position.y + direction;
    if (position.y >= sizeY)
    {
        position.y = 0;
    }

    if (position.y < 0)
    {
        position.y = sizeY - 1;
    }
    field[position.y][position.x] = true;
    return position;
}

void followHead(coordinates_t lastHeadPosition, coordinates_t newHeadPosition, int lenght)
{
    while (lenght > 0)
    {
        
    }
}

coordinates_t findNextElement(coordinates_t lastPosition, coordinates_t newPosition)
{
    coordinates_t foundCordinates;
    // check y axe
    if ((lastPosition.y + down != newPosition.y) && (lastPosition.y + down <= sizeY) && (field[lastPosition.y + down][lastPosition.x]))
    {
        // field[lastPosition.y + down][lastPosition.x] = false;
        // field[lastPosition.y][lastPosition.x] = true;
        // foundCordinates.x = lastPosition.x;
        // foundCordinates.y = lastPosition.y + down;
        return foundCordinates;
    }

    if ((lastPosition.y + up != newPosition.y))
    {
    }
}

void printField()
{
    String printFieldString;
    for (int i = 0; i < sizeY; i++)
    {
        for (int j = 0; j < sizeX; j++)
        {
            printFieldString = printFieldString + field[i][j] + spacer;
        }
        printFieldString = printFieldString + newLine;
    }
    Serial.println(printFieldString);
    delay(1000);
}

void setup()
{
    // exclude this values, they don't necessery
    int firstXPosition = 2;
    int firstYPosition = 3;
    Serial.begin(9600);

    field[firstYPosition][firstXPosition] = true;
    // field[firstYPosition][firstXPosition - 1] = true;

    actualHeadPosition.x = firstXPosition;
    actualHeadPosition.y = firstYPosition;
    lenght = 2;
}

void loop()
{
    actualHeadPosition = moveX(actualHeadPosition, right);
    // moveX(left);
    // moveY(up);
    // moveY(down);
    printField();
}
