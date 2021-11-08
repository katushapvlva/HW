#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

bool compare(float main_x, float main_y, float x, float y)
{
    bool result = false;
    if (main_x != 0)
    {
        if (main_y/main_x*x > y)
        {
            result = true;
        }
    } else
    {
        if ((x < 0 && main_y > 0) || (x > 0 && main_y < 0))
        {
            result = true;
        }
    }
    return result;
}

// Скалярное произведение
double dot_prod(float main_x,float main_y,float x, float y)
{
    return (main_x*main_x + main_y*y)/(sqrt(pow(x,2)+pow(y, 2))*sqrt(pow(main_x,2)+pow(main_y,2)));
}

// Координата x
float get_coords_x(ifstream &input_file)
{
    string coord1;
    float x;
    input_file >> coord1;
    x = stof(coord1);
    return x;
}

// Координата y
float get_coords_y(ifstream &input_file)
{
    string coord2;
    float y;
    input_file >> ws >> coord2;
    y = stof(coord2);
    return y;
}

int main()
{
    float main_x;
    float main_y;
    double temp_dot_prod;
    double leftmost_x = 0;
    double leftmost_y = 0;
    double leftmost_cos = 2;
    double rightmost_x = 0;
    double rightmost_y = 0;
    double rightmost_cos = 2;
    float x;
    float y;

    string line;

    ifstream input_file("in.txt");

    main_x  = get_coords_x(input_file);
    main_y  = get_coords_y(input_file);


    while (getline(input_file, line))
    {
        x = get_coords_x(input_file);
        y = get_coords_y(input_file);
        temp_dot_prod = dot_prod(main_x, main_y, x, y);
        if (compare(main_x, main_y, x, y))
        {
            if ( temp_dot_prod < leftmost_cos)
            {
                leftmost_x = x;
                leftmost_y = y;
                leftmost_cos = temp_dot_prod;
            }
        } else if (temp_dot_prod < rightmost_cos)
        {
            rightmost_x = x;
            rightmost_y = y;
            rightmost_cos = temp_dot_prod;
        }
    }
    input_file.close();

    cout << "Leftmost: " << leftmost_x << ' ' << leftmost_y << endl;
    cout << "Rightmost: " << rightmost_x << ' ' << rightmost_y << endl;

    return 0;
}
