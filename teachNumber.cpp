
//Solved by Ayush
#define CATCH_CONFIG_MAIN  //Giving main to catch2
#include <iostream>
#include <vector>
#include <string>

#include <catch2/catch.hpp>     //For testing

using namespace std;

int teachNumber(vector <string> maze) {

    //Finding the exact location (p,q)(element num, Char Location) of the element which has 0 in it
    int p {0}, q {0}; 
    for(int i = 0; i < maze.size(); i++)
    {
         size_t found = maze.at(i).find('0');
         if(found != string::npos)
         {
             p = i;
             q = static_cast<int>(found);
            break;
         }
    }
    cout << p << " " << q << endl;

    int num {0}, len_str {maze.at(0).length()};
    bool all_cond {1};
    
    while(all_cond == 1) {     //Iterating untill all conditions
        
        all_cond = 0;
        
        //Top Left
        if(p-1 >= 0 && q-1 >= 0) {      //Checking for out of bound issues
           char topLeft  = maze.at(p - 1).at(q - 1);
           cout << "topLeft : " << topLeft << endl;
            if(topLeft != '.'){
                if(static_cast<int>(topLeft) - 48 == num + 1) {
                    p = p -1; q = q -1;
                    num++;
                    all_cond = 1;
                }
           }
        }

        //Top
        //used the all_cond == 0 to stop cheching if valid number found in above if statements
        if(all_cond == 0)
        {
            if(p-1 >= 0) {     
                char top  = maze.at(p-1).at(q);
                cout << "top : " << top << endl;
                if(top != '.'){
                    if(static_cast<int>(top) - 48 == (num + 1)) {
                        p = p - 1;
                        num++;
                        all_cond = 1;
                    }
                }
            }
        }

        // TopRight
        if(all_cond == 0)
        {
            if(p-1 >= 0 && q+1 < len_str) {
            char topRight  = maze.at(p-1).at(q+1);
            cout << "topRight : " << topRight << endl;
                if(topRight != '.'){
                    if(static_cast<int>(topRight) - 48 == (num + 1)) {
                        p = p - 1; q = q + 1;
                        num++;
                        all_cond = 1;
                    }
                }
            }
        }

        // Middle Left
        if(all_cond == 0)
        {
            if(q-1 >= 0 && all_cond == 0) {
                char middleLeft = maze.at(p).at(q-1);
                cout << "midleLeft : " << middleLeft << endl;
                if(middleLeft != '.'){
                    if(static_cast<int>(middleLeft) - 48  == (num + 1)) {
                        q = q - 1;
                        num++;
                        all_cond = 1;
                    }
                }
            }
        }

        //MiddleRight
        if(all_cond == 0)
        {
            if(q + 1 < len_str && all_cond == 0) {
                char middleRight = maze.at(p).at(q+1);
                cout << "midleRight : " << middleRight << endl;
                if(middleRight != '.'){
                    if(static_cast<int>(middleRight) - 48 == (num + 1)) {
                        q = q + 1;
                        num++;
                        all_cond = 1;
                    }
                }
            }
        }

        //BottomLeft
        if(all_cond == 0)
        {
            if(p + 1 < maze.size() && q - 1 >= 0 && all_cond == 0) {
                char bottomLeft = maze.at(p+1).at(q-1);
                cout << "bottomLeft : " << bottomLeft << endl;
                if(bottomLeft != '.'){
                    if(static_cast<int>(bottomLeft) - 48 == (num + 1)) {
                        p = p + 1; q = q - 1;
                        num++;
                        all_cond = 1;
                    }
                }
            }
        }

        //Bottom
        if(all_cond == 0)
        {
            if(p + 1 < maze.size() && all_cond == 0) {
                char bottom = maze.at(p+1).at(q);
                cout << "bottom : " << bottom<< endl;
                if(bottom != '.'){
                    if(static_cast<int>(bottom) - 48== (num + 1)) {
                        p = p + 1;
                        num++;
                        all_cond = 1;
                    }
                }
            }
        }

        //BottomRight
        if(all_cond == 0)
        {
            if(p + 1 < maze.size() && q + 1 < len_str && all_cond == 0) {
                char bottomRight = maze.at(p+1).at(q + 1);
                cout << "bottomRight : " << bottomRight << endl;
                if(bottomRight != '.'){
                    if(static_cast<int>(bottomRight) - 48 == num + 1) {
                        p = p + 1; q = q + 1;
                        num++;
                        all_cond = 1;
                    }
                }
            }
        }

        cout << "num : " << num << endl;
        cout << p << " " << q << endl;
        cout << "----------------" << endl;
                
    }

    return num + 1;
} 

//Testing Using Catch2

TEST_CASE( "Factorials are computed" ) {
    REQUIRE( 
        teachNumber(
            {
                "0...567.",
                "12.4...8",
                "3......9"
            }) == 4);    

    REQUIRE(
        teachNumber(
            {
                "0...576.",
                "21.4...8",
                "3......9"
            }) == 4);

    REQUIRE(
        teachNumber(
            {       
                ".012",
                "..3.",
                ".4..",
                "5...",
                ".6..",
                "..7.",
                "..98"
            }) == 10);
    
    REQUIRE(
        teachNumber(
            {
                ".013",
                "..24",
                "....",
                "5...",
                ".6..",
                "..7.",
                "..98"
            }) == 5);

    REQUIRE(
        teachNumber(
            {
                "....",
                "..78",
                ".6.1",
                ".502",
                "..43"
            }) == 9);

    REQUIRE(
        teachNumber(
            {
                "1024356789"
            }) == 2);

    REQUIRE(
        teachNumber(
            {
                "9786543210"
            }) == 7);

}
    
    

                        



