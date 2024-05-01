#include <algorithm>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    int n = 3, k = 3, number_of_edges = 0;
    cout << "Please give number of vertices: \n";
    cin >> n;

    number_of_edges = ((n - 1) * (n)) / 2;
    int a[number_of_edges][2];
    for (int i = 0, index = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            a[index][0] = i;
            a[index][1] = j;
            index++;
        }
    }

    std::cout << ("   Red   |  Green   |   Blue    \n") << endl;

    int count = 0;

    for (int i = 1; i < number_of_edges - 1; i++)
    {
        for (int j = 1; j <= (number_of_edges - i) / 2; j++)
        {
            bool i_j = (i == j) ? true : false;
            bool j_l = (j == (number_of_edges - i - j)) ? true : false;
            bool i_l = (i == (number_of_edges - i - j)) ? true : false;

            if (!i_j && !j_l && !i_l)
            {
                string bitmask(i, 2);
                bitmask.resize(i + j, 1);
                bitmask.resize(number_of_edges, 0);
                do
                {
                    string red = "", green = "", blue = "";

                    for (int k = 0; k < number_of_edges; k++)
                    {
                        if (bitmask[k] == 2)
                        {
                            red += " [" + to_string(a[k][0]) + ", " + to_string(a[k][1]) + "] ";
                        }
                        else if (bitmask[k])
                        {
                            green += " [" + to_string(a[k][0]) + ", " + to_string(a[k][1]) + "] ";
                        }
                        else
                        {
                            blue += " [" + to_string(a[k][0]) + ", " + to_string(a[k][1]) + "] ";
                        }
                    }
                    std::cout << (red + " | " + green + " | " + blue) << endl;
                    count++;
                } while (prev_permutation(bitmask.begin(), bitmask.end()));
            }
            else if (i_j && j_l && i_l) // check once again
            {

                string bitmask(i, 2);
                bitmask.resize(i + j, 1);
                bitmask.resize(number_of_edges, 0);
                do
                {
                    string red = "", green = "", blue = "";
                    if (!bitmask[j])
                    {
                        break;
                    }
                    for (int k = 0; k < number_of_edges; k++)
                    {
                        if (bitmask[k] == 2)
                        {
                            red += " [" + to_string(a[k][0]) + ", " + to_string(a[k][1]) + "] ";
                        }
                        else if (bitmask[k])
                        {
                            blue += " [" + to_string(a[k][0]) + ", " + to_string(a[k][1]) + "] ";
                        }
                        else
                        {
                            green += " [" + to_string(a[k][0]) + ", " + to_string(a[k][1]) + "] ";
                        }
                    }
                    std::cout << (red + " | " + green + " | " + blue) << endl;
                    count++;
                } while (prev_permutation(bitmask.begin(), bitmask.end()));
            }
            else if (i_j)
            {
                // red blue green
                string bitmask(i, 2);
                bitmask.resize(number_of_edges - j, 1);
                bitmask.resize(number_of_edges, 0);
                do
                {
                    string red = "", green = "", blue = "";
                    if (!bitmask[n - i - j])
                    {
                        break;
                    }
                    for (int k = 0; k < number_of_edges; k++)
                    {
                        if (bitmask[k] == 2)
                        {
                            red += " [" + to_string(a[k][0]) + ", " + to_string(a[k][1]) + "] ";
                        }
                        else if (bitmask[k])
                        {
                            blue += " [" + to_string(a[k][0]) + ", " + to_string(a[k][1]) + "] ";
                        }
                        else
                        {
                            green += " [" + to_string(a[k][0]) + ", " + to_string(a[k][1]) + "] ";
                        }
                    }
                    std::cout << (red + " | " + green + " | " + blue) << endl;
                    count++;
                } while (prev_permutation(bitmask.begin(), bitmask.end()));
            }
            else if (j_l)
            {
                // green red blue
                string bitmask(j, 2);
                bitmask.resize(i + j, 1);
                bitmask.resize(number_of_edges, 0);
                do
                {
                    string red = "", green = "", blue = "";
                    if (!bitmask[i])
                    {
                        break;
                    }
                    for (int k = 0; k < number_of_edges; k++)
                    {
                        if (bitmask[k] == 2)
                        {
                            green += " [" + to_string(a[k][0]) + ", " + to_string(a[k][1]) + "] ";
                        }
                        else if (bitmask[k])
                        {
                            red += " [" + to_string(a[k][0]) + ", " + to_string(a[k][1]) + "] ";
                        }
                        else
                        {
                            blue += " [" + to_string(a[k][0]) + ", " + to_string(a[k][1]) + "] ";
                        }
                    }
                    std::cout << (red + " | " + green + " | " + blue) << endl;
                    count++;
                } while (prev_permutation(bitmask.begin(), bitmask.end()));
            }
            else if (i_l)
            {
                // red green blue
                string bitmask(i, 2);
                bitmask.resize(i + j, 1);
                bitmask.resize(number_of_edges, 0);
                do
                {
                    string red = "", green = "", blue = "";
                    if (!bitmask[j])
                    {
                        break;
                    }
                    for (int k = 0; k < number_of_edges; k++)
                    {
                        if (bitmask[k] == 2)
                        {
                            red += " [" + to_string(a[k][0]) + ", " + to_string(a[k][1]) + "] ";
                        }
                        else if (bitmask[k])
                        {
                            blue += " [" + to_string(a[k][0]) + ", " + to_string(a[k][1]) + "] ";
                        }
                        else
                        {
                            green += " [" + to_string(a[k][0]) + ", " + to_string(a[k][1]) + "] ";
                        }
                    }
                    std::cout << (red + " | " + green + " | " + blue) << endl;
                    count++;
                } while (prev_permutation(bitmask.begin(), bitmask.end()));
            }
        }
    }

    cout << "\n Total Graphs generated: " << count << endl;
    return 0;
}