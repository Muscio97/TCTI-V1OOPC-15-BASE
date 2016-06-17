//===========================================================//
//             Copyright Mike Hilhorst 2016.                 //
// Distributed under the Boost Software License, Version 1.0.//
//    (See accompanying file LICENSE_1_0.txt or copy at      //
//          http://www.boost.org/LICENSE_1_0.txt)            //
//===========================================================//
 
#ifndef MAX7219_HPP
#define MAX7219_HPP

#include "hwlib.hpp"
#include "string.h"
#include "command.hpp"
#include "mbin_to_mhex.hpp"
#include "clean.hpp"
#include "dummy.hpp"
#include "rotate.hpp"
///This is a storage for: 
//
///This class holds all supported charactres, test modes, render, setiings and the sting to dislpay tekst switch. \n
///The characters are all 8x8 (byte)matrices. \n
///Test mode is a mode to test the matrix, it will display every currunt supported charchter. rotated and sometimes inverded. \n
///Render makes a copy of the orignal 8x8 (byte)matrix, sends that to mbin_to_mhex. mbin_to_mhex will process that in a 8x2 (byte)matrix. \n
///Render will take that 8x2 (byte)martix and put it in a ?x8x2 (byte)matrix. When all charachters are put in the ?x8x2 (byte)matrix \n
///render will send it to command().
///Settings is a ?x2 matrix of settings.
///The switch take a input string and with every supported it will call render with the there to belonning character.
class MAX7219
{
private:
    //========spi========//
    hwlib::spi_bus & bus; 
    hwlib::pin_out & cs;
    //===================//
    
    //========varibles========//
    
    //===ints==//
    int count;
    int mode;
    int time;
    int inverd;
    int rotation;
    int number_of_matrices;
    int letter_counter=0;
    
    //===byte matrices===//
    byte matrix_data[8][2];
    byte matrix_rotate[8][8];
    byte matrix_output[8][8];
    byte matrix_dummy[8][8];            
    byte array_data[1000][8][2];
    
    //========================//

    //==========chars==========//
    //A
    byte char_A[8][8] = {{0,0,0,0,0,0,0,0},{0,0,0,1,1,0,0,0},{0,0,1,1,1,1,0,0},{0,1,1,0,0,1,1,0},{0,1,1,1,1,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,0,0,0,0,0,0,0}};
    //B
    byte char_B[8][8] = {{0,0,0,0,0,0,0,0},{0,1,1,1,1,1,0,0},{0,1,0,0,0,0,1,0},{0,1,1,1,1,1,0,0},{0,1,0,0,0,0,1,0},{0,1,0,0,0,0,1,0},{0,1,1,1,1,1,0,0},{0,0,0,0,0,0,0,0}};
    //C
    byte char_C[8][8] = {{0,0,0,0,0,0,0,0},{0,0,1,1,1,1,1,0},{0,1,1,1,1,1,1,0},{0,1,1,0,0,0,0,0},{0,1,1,0,0,0,0,0},{0,1,1,1,1,1,1,0},{0,0,1,1,1,1,1,0},{0,0,0,0,0,0,0,0}};
    //D
    byte char_D[8][8] = {{0,0,0,0,0,0,0,0},{0,1,1,1,1,1,0,0},{0,1,1,1,1,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,1,1,1,1,0},{0,1,1,1,1,1,0,0},{0,0,0,0,0,0,0,0}};
    //E
    byte char_E[8][8] = {{0,0,0,0,0,0,0,0},{0,1,1,1,1,1,1,0},{0,1,1,0,0,0,0,0},{0,1,1,1,1,1,0,0},{0,1,1,1,1,1,0,0},{0,1,1,0,0,0,0,0},{0,1,1,1,1,1,1,0},{0,0,0,0,0,0,0,0}};
    //F
    byte char_F[8][8] = {{0,0,0,0,0,0,0,0},{0,1,1,1,1,1,1,0},{0,1,1,1,1,1,1,0},{0,1,1,0,0,0,0,0},{0,1,1,1,1,0,0,0},{0,1,1,1,1,0,0,0},{0,1,1,0,0,0,0,0},{0,0,0,0,0,0,0,0}}; 
    //G
    byte char_G[8][8] = {{0,0,0,0,0,0,0,0},{0,0,1,1,1,1,1,0},{0,1,1,1,1,1,1,0},{0,1,1,0,0,0,0,0},{0,1,1,0,1,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,1,1,1,1,0},{0,0,0,0,0,0,0,0}};
    //H
    byte char_H[8][8] = {{0,0,0,0,0,0,0,0},{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,1,1,1,1,0},{0,1,1,1,1,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,0,0,0,0,0,0,0}};
    //I
    byte char_I[8][8] = {{0,0,0,0,0,0,0,0},{0,0,1,1,1,1,0,0},{0,0,0,1,1,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,1,1,0,0,0},{0,0,1,1,1,1,0,0},{0,0,0,0,0,0,0,0}};
    //J
    byte char_J[8][8] = {{0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0},{0,0,0,0,0,1,0,0},{0,0,0,0,0,1,0,0},{0,1,0,0,0,1,0,0},{0,1,0,0,0,1,0,0},{0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,0}};
    //K
    byte char_K[8][8] = {{0,0,0,0,0,0,0,0},{0,1,1,0,0,1,1,0},{0,1,1,0,1,1,0,0},{0,1,1,1,1,0,0,0},{0,1,1,1,1,0,0,0},{0,1,1,0,1,1,0,0},{0,1,1,0,0,1,1,0},{0,0,0,0,0,0,0,0}};
    //L
    byte char_L[8][8] = {{0,0,0,0,0,0,0,0},{0,1,1,0,0,0,0,0},{0,1,1,0,0,0,0,0},{0,1,1,0,0,0,0,0},{0,1,1,0,0,0,0,0},{0,1,1,1,1,1,1,0},{0,1,1,1,1,1,1,0},{0,0,0,0,0,0,0,0}};
    //M
    byte char_M[8][8] = {{0,0,0,0,0,0,0,0},{0,1,1,0,0,1,1,0},{0,1,1,1,1,1,1,0},{0,1,0,1,1,0,1,0},{0,1,0,0,0,0,1,0},{0,1,0,0,0,0,1,0},{0,1,0,0,0,0,1,0},{0,0,0,0,0,0,0,0}};
    //N
    byte char_N[8][8] = {{0,0,0,0,0,0,0,0},{0,0,1,1,1,1,0,0},{0,1,1,1,1,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,0,0,0,0,0,0,0}};
    //O
    byte char_O[8][8] = {{0,0,0,0,0,0,0,0},{0,0,1,1,1,1,0,0},{0,1,1,1,1,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,1,1,1,1,0},{0,0,1,1,1,1,0,0},{0,0,0,0,0,0,0,0}};
    //P
    byte char_P[8][8] = {{0,0,0,0,0,0,0,0},{0,1,1,1,1,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,1,1,1,1,0},{0,1,1,0,0,0,0,0},{0,1,1,0,0,0,0,0},{0,0,0,0,0,0,0,0}};
    //Q
    byte char_Q[8][8] = {{0,0,0,0,0,0,0,0},{0,0,1,1,1,1,0,0},{0,1,1,1,1,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,0,1,1,1,0},{0,1,1,1,1,1,1,0},{0,0,1,1,1,1,1,1},{0,0,0,0,0,0,1,1}};
    //R
    byte char_R[8][8] = {{0,0,0,0,0,0,0,0},{0,1,1,1,1,1,0,0},{0,1,0,0,0,0,1,0},{0,1,1,1,1,1,0,0},{0,1,0,1,1,0,0,0},{0,1,0,0,1,1,0,0},{0,1,0,0,0,1,1,0},{0,0,0,0,0,0,0,0}};
    //S
    byte char_S[8][8] = {{0,0,0,0,0,0,0,0},{0,0,1,1,1,1,1,0},{0,1,0,0,0,0,0,0},{0,0,1,1,1,1,0,0},{0,0,0,0,0,0,1,0},{0,0,0,0,0,0,1,0},{0,1,1,1,1,1,0,0},{0,0,0,0,0,0,0,0}};
    //T
    byte char_T[8][8] = {{0,0,0,0,0,0,0,0},{0,1,1,1,1,1,1,0},{0,1,1,1,1,1,1,0},{0,0,0,1,1,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,0,0,0,0,0}};
    //U
    byte char_U[8][8] = {{0,0,0,0,0,0,0,0},{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,0,1,1,1,1,0,0},{0,0,0,0,0,0,0,0}};
    //V
    byte char_V[8][8] = {{0,0,0,0,0,0,0,0},{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,1,1,0,0,1,1,0},{0,0,1,1,1,1,0,0},{0,0,1,1,1,1,0,0},{0,0,0,0,0,0,0,0}};
    //W
    byte char_W[8][8] = {{0,0,0,0,0,0,0,0},{0,1,0,0,0,0,1,0},{0,1,0,0,0,0,1,0},{0,1,0,0,0,0,1,0},{0,1,0,0,0,0,1,0},{0,1,0,1,1,0,1,0},{0,0,1,0,0,1,0,0},{0,0,0,0,0,0,0,0}};
    //X
    byte char_X[8][8] = {{0,0,0,0,0,0,0,0},{0,1,0,0,0,0,1,0},{0,0,1,0,0,1,0,0},{0,0,0,1,1,0,0,0},{0,0,0,1,1,0,0,0},{0,0,1,0,0,1,0,0},{0,1,0,0,0,0,1,0},{0,0,0,0,0,0,0,0}};
    //Y
    byte char_Y[8][8] = {{0,0,0,0,0,0,0,0},{0,1,0,0,0,0,1,0},{0,1,1,0,0,1,1,0},{0,0,1,1,1,1,0,0},{0,0,0,1,1,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,0,0,0,0,0}};
    //Z
    byte char_Z[8][8] = {{0,0,0,0,0,0,0,0},{0,1,1,1,1,1,1,0},{0,0,0,0,0,1,1,0},{0,0,0,0,1,1,0,0},{0,0,0,1,1,0,0,0},{0,0,1,1,0,0,0,0},{0,1,1,1,1,1,1,0},{0,0,0,0,0,0,0,0}};
    //space
    byte char_space[8][8] = {{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};
    //!
    byte char_uit[8][8] = {{0,0,0,0,0,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,0,0,0,0,0}};
    //random
    byte char_random[8][8];
    //underscore
    byte char_underscore[8][8] = {{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{1,1,1,1,1,1,1,1}};
    //?
    byte char_question[8][8] = {{0,0,0,0,0,0,0,0},{0,0,1,1,1,1,0,0},{0,0,0,0,0,0,1,0},{0,0,0,0,0,0,1,0},{0,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0},{0,0,0,1,0,0,0,0},{0,0,0,0,0,0,0,0}};
    //point
    byte char_point[8][8] = {{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,0,0,0,0,0}};
    //comma
    byte char_comma[8][8] = {{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,0,0,1,0,0}};
    //square_L
    byte char_square_L[8][8] = {{0,0,0,0,0,0,0,0},{0,0,1,1,1,1,0,0},{0,0,1,0,0,0,0,0},{0,0,1,0,0,0,0,0},{0,0,1,0,0,0,0,0},{0,0,1,0,0,0,0,0},{0,0,1,1,1,1,0,0},{0,0,0,0,0,0,0,0}};
    //square_R
    byte char_square_R[8][8] = {{0,0,0,0,0,0,0,0},{0,0,1,1,1,1,0,0},{0,0,0,0,0,1,0,0},{0,0,0,0,0,1,0,0},{0,0,0,0,0,1,0,0},{0,0,0,0,0,1,0,0},{0,0,1,1,1,1,0,0},{0,0,0,0,0,0,0,0}};
    //1,
    byte char_one[8][8] = {{0,0,0,0,0,0,0,0},{0,0,1,1,1,0,0,0},{0,1,1,1,1,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,1,1,0,0,0},{0,1,1,1,1,1,1,0},{0,0,0,0,0,0,0,0}};
    //2
    byte char_two[8][8] = {{0,0,0,0,0,0,0,0},{0,1,1,1,1,1,0,0},{0,0,0,0,0,1,1,0},{0,0,0,0,0,1,1,0},{0,0,0,0,1,1,0,0},{0,0,0,1,1,0,0,0},{0,1,1,1,1,1,1,0},{0,0,0,0,0,0,0,0}};
    //3
    byte char_three[8][8] = {{0,0,0,0,0,0,0,0},{0,1,1,1,1,1,0,0},{0,0,0,0,0,1,1,0},{0,0,0,1,1,1,1,0},{0,0,0,1,1,1,1,0},{0,0,0,0,0,1,1,0},{0,1,1,1,1,1,0,0},{0,0,0,0,0,0,0,0}};
    //4,
    byte char_four[8][8] = {{0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0},{0,0,0,0,1,1,0,0},{0,0,0,1,0,1,0,0},{0,0,1,0,0,1,0,0},{0,1,1,1,1,1,1,0},{0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,0}};
    //5
    byte char_five[8][8] = {{0,0,0,0,0,0,0,0},{0,1,1,1,1,1,1,0},{0,1,0,0,0,0,0,0},{0,1,1,1,1,1,0,0},{0,0,0,0,0,0,1,0},{0,0,0,0,0,0,1,0},{0,1,1,1,1,1,0,0},{0,0,0,0,0,0,0,0}};
    //6
    byte char_six[8][8] = {{0,0,0,0,0,0,0,0},{0,0,1,1,1,1,1,0},{0,1,0,0,0,0,0,0},{0,1,1,1,1,1,0,0},{0,1,0,0,0,0,1,0},{0,1,0,0,0,0,1,0},{0,0,1,1,1,1,0,0},{0,0,0,0,0,0,0,0}};
    //7
    byte char_seven[8][8] = {{0,0,0,0,0,0,0,0},{0,1,1,1,1,1,1,0},{0,0,0,0,0,1,1,0},{0,0,0,0,1,1,0,0},{0,0,0,1,1,0,0,0},{0,0,1,1,0,0,0,0},{0,1,1,0,0,0,0,0},{0,0,0,0,0,0,0,0}};
    //8
    byte char_eight[8][8] = {{0,0,0,0,0,0,0,0},{0,0,1,1,1,1,0,0},{0,1,0,0,0,0,1,0},{0,0,1,1,1,1,0,0},{0,1,0,0,0,0,1,0},{0,1,0,0,0,0,1,0},{0,0,1,1,1,1,0,0},{0,0,0,0,0,0,0,0}};
    //9
    byte char_nine[8][8] = {{0,0,0,0,0,0,0,0},{0,0,1,1,1,1,0,0},{0,1,0,0,0,0,1,0},{0,0,1,1,1,1,1,0},{0,0,0,0,0,0,1,0},{0,0,0,0,0,0,1,0},{0,0,1,1,1,1,0,0},{0,0,0,0,0,0,0,0}};
    //0,
    byte char_ten[8][8] = {{0,0,0,0,0,0,0,0},{0,0,1,1,1,1,0,0},{0,1,0,0,0,0,1,0},{0,1,0,0,0,0,1,0},{0,1,0,0,0,0,1,0},{0,1,0,0,0,0,1,0},{0,0,1,1,1,1,0,0},{0,0,0,0,0,0,0,0}};
    //-
    byte char_minus[8][8] = {{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,1,1,1,1,1,1,0},{0,1,1,1,1,1,1,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};
    //+
    byte char_plus[8][8] = {{0,0,0,0,0,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,1,1,0,0,0},{0,1,1,1,1,1,1,0},{0,1,1,1,1,1,1,0},{0,0,0,1,1,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,0,0,0,0,0}};
    //*
    byte char_multiply[8][8] = {{0,0,0,0,0,0,0,0},{0,1,0,1,1,0,1,0},{0,0,1,1,1,1,0,0},{0,1,1,1,1,1,1,0},{0,1,1,1,1,1,1,0},{0,0,1,1,1,1,0,0},{0,1,0,1,1,0,1,0},{0,0,0,0,0,0,0,0}};
    ///
    byte char_divide[8][8] = {{0,0,0,0,0,0,0,0},{0,0,0,0,0,1,1,0},{0,0,0,0,1,1,0,0},{0,0,0,1,1,0,0,0},{0,0,1,1,0,0,0,0},{0,1,1,0,0,0,0,0},{0,1,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};
    //=
    byte char_equal[8][8] = {{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,1,1,1,1,1,1,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,1,1,1,1,1,1,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0}};
    //;
    byte char_semicolom[8][8] = {{0,0,0,0,0,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,1,1,0,0,0},{0,0,0,0,1,0,0,0}};
    //=========================//
    
public:
    MAX7219(hwlib::spi_bus & bus, hwlib::pin_out & cs):
    bus(bus), cs(cs)
    {
        hwlib::wait_ms(1000);       // Hammertime
        hwlib::cout << "=== BEGINING ===\n";
        
        char input_string[] = {"|"};            // input string
        hwlib::cout << "String lenght :" << strlen(input_string);   //lenght of string
        
        number_of_matrices = 4;                                     //Amount of matrices where you want to display on.
        count = 8;                                                  //Amount of pixels on the matrix.
        rotation =  0;                                              //rotation 1=90, 2=180, 3=270, 4=360 etc.
        time = 500;                                                 //The time in ms that the characters will be displayed on the screen
        inverd = 0;                                                 //If inverded 0 = off, !0= on/
        mode = 2;                                                   //The mode the characters will be displayed in
                                                                    // ============================================ //
                                                                    //  1. flashing                                 //
                                                                    //  2. shifting from left to right              //
                                                                    //  3. shifting from right to left              //
                                                                    // ============================================ //
                    
                    
        int string_lenght = strlen(input_string)+number_of_matrices*2;
        
        byte data[][2] ={{ 0x09, 0x00 },    //
                         { 0x0c, 0x01 },    //
                         { 0x0f, 0x00 },    // Test modes : off
                         { 0x0A, 0x05 },    // Intestety :  ~30% 
                         { 0x0B, 0x07 }};   //
        command_settings(data, number_of_matrices, 5);
        
        hwlib::wait_ms(1000);       // Hammertime
        
        //========== Settings display on console ===========//
                
        hwlib::cout << "\nMode:               " << mode;
        if(mode == 1){ hwlib::cout << " - flashing";}
        if(mode == 2){ hwlib::cout << " - shifting from left to right";} 
        if(mode == 3){ hwlib::cout << " - shifting from right to left";} 
        hwlib::cout << "\nInverd:             " << inverd;
        if(inverd == 0){ hwlib::cout << " - off";}
        else{ hwlib::cout << " - on";} 
        hwlib::cout << "\nTime:               " << time <<"ms";
        hwlib::cout << "\nRotation:           " << rotation*90 << "\370";
        hwlib::cout << "\nNumber of pixels:   " << count*count*number_of_matrices;
        hwlib::cout << "\nNumber of matrices: " << number_of_matrices;
        hwlib::cout << '\n';
        
        
        //==================================================//
  
        //=========== Output display on console ============//
       // while(true){
            hwlib::cout << "\nDisplayed text: ";
            for(int i =0; i < number_of_matrices; i++)
            {
                    render(char_space,       time, mode, inverd, rotation, number_of_matrices, count, string_lenght);
            }
            for(char c : input_string)              //This will go thru every element of input_string
            {
                switch(c) 
                {
                    case 'A' : render(char_A,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'A';         break;
                    case 'B' : render(char_B,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'B';         break;
                    case 'C' : render(char_C,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'C';         break;
                    case 'D' : render(char_D,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'D';         break;
                    case 'E' : render(char_E,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'E';         break;
                    case 'F' : render(char_F,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'F';         break;
                    case 'G' : render(char_G,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'G';         break;
                    case 'H' : render(char_H,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'H';         break;
                    case 'I' : render(char_I,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'I';         break;
                    case 'J' : render(char_J,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'J';         break;
                    case 'K' : render(char_K,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'K';         break;
                    case 'L' : render(char_L,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'L';         break;
                    case 'M' : render(char_M,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'M';         break;
                    case 'N' : render(char_N,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'N';         break;
                    case 'O' : render(char_O,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'O';         break;
                    case 'P' : render(char_P,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'P';         break;
                    case 'Q' : render(char_Q,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'Q';         break;
                    case 'R' : render(char_R,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'R';         break;
                    case 'S' : render(char_S,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'S';         break;
                    case 'T' : render(char_T,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'T';         break;
                    case 'U' : render(char_U,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'U';         break;
                    case 'V' : render(char_V,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'V';         break;
                    case 'W' : render(char_W,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'W';         break;
                    case 'X' : render(char_X,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'X';         break;
                    case 'Y' : render(char_Y,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'Y';         break;
                    case 'Z' : render(char_Z,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'Z';         break;
                    case 'a' : render(char_A,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'a';         break;
                    case 'b' : render(char_B,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'b';         break;
                    case 'c' : render(char_C,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'c';         break;
                    case 'd' : render(char_D,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'd';         break;
                    case 'e' : render(char_E,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'e';         break;
                    case 'f' : render(char_F,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'f';         break;
                    case 'g' : render(char_G,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'g';         break;
                    case 'h' : render(char_H,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'h';         break;
                    case 'i' : render(char_I,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'i';         break;
                    case 'j' : render(char_J,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'j';         break;
                    case 'k' : render(char_K,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'k';         break;
                    case 'l' : render(char_L,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'l';         break;
                    case 'm' : render(char_M,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'm';         break;
                    case 'n' : render(char_N,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'n';         break;
                    case 'o' : render(char_O,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'o';         break;
                    case 'p' : render(char_P,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'p';         break;
                    case 'q' : render(char_Q,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'q';         break;
                    case 'r' : render(char_R,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'r';         break;
                    case 's' : render(char_S,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 's';         break;
                    case 't' : render(char_T,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 't';         break;
                    case 'u' : render(char_U,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'u';         break;
                    case 'v' : render(char_V,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'v';         break;
                    case 'w' : render(char_W,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'w';         break;
                    case 'x' : render(char_X,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'x';         break;
                    case 'y' : render(char_Y,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'y';         break;
                    case 'z' : render(char_Z,           time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << 'z';         break;
                    case ' ' : render(char_space,       time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << ' ';         break;
                    case '!' : render(char_uit,         time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << '!';         break;
                    case '~' : render(char_random,      time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << '~';         break;
                    case '_' : render(char_underscore,  time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << '_';         break;
                    case '?' : render(char_question,    time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << '?';         break;
                    case '.' : render(char_point,       time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << '.';         break;
                    case ',' : render(char_comma,       time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << ',';         break;
                    case '[' : render(char_square_L,    time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << '[';         break;
                    case ']' : render(char_square_R,    time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << ']';         break;
                    case '1' : render(char_one,         time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << '1';         break;
                    case '2' : render(char_two,         time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << '2';         break;
                    case '3' : render(char_three,       time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << '3';         break;
                    case '4' : render(char_four,        time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << '4';         break;
                    case '5' : render(char_five,        time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << '5';         break;
                    case '6' : render(char_six,         time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << '6';         break;
                    case '7' : render(char_seven,       time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << '7';         break;
                    case '8' : render(char_eight,       time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << '8';         break;
                    case '9' : render(char_nine,        time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << '9';         break;
                    case '0' : render(char_ten,         time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << '0';         break;
                    case '+' : render(char_plus,        time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << '+';         break;
                    case '-' : render(char_minus,       time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << '-';         break;
                    case '/' : render(char_divide,      time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << '/';         break;
                    case '*' : render(char_multiply,    time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << '*';         break;
                    case '=' : render(char_equal,       time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << '=';         break;
                    case ';' : render(char_semicolom,   time, mode, inverd, rotation, number_of_matrices, count, string_lenght);          hwlib::cout << ';';         break;
                    case '|' : tester(mode, number_of_matrices, count);   hwlib::cout << '|';         break;
                }
            }
            for(int i =0; i < number_of_matrices; i++)
            {
                    render(char_space,       time, mode, inverd, rotation, number_of_matrices, count, string_lenght);
            }
            
        
        //==================================================//

        clean(bus, cs, number_of_matrices, count);
         
        hwlib::cout << "\n\n====== END ======\n";
    }
    
        void command_settings(const byte data[][2], int number_of_matrices , int count)
        ///Executing function, data[][2]: is the filled with hex codes that coronspond to registers of MAX7219. \n\n
        ///Count: is number off row that will be dysplayed. This is over thought choise. This gives more options. \n
        ///The function will send its data via SPI(write_and_read) to the MAX7219. \n
        {   
            byte temp[1000];                                                                         
            for(int i = 0; i < count ;i++)                                           
            {
                int l = 0;
                for(int k = 0; k < number_of_matrices; k++)
                {
                    temp[l] = {data[i][0]};               
                    l++;
                    temp[l] = {data[i][1]};     
                    l++;
                }
                if(data[i][0]!=0x0B){                                                // checks if Scan limit isn't spoken to.
                    bus.write_and_read(cs, 2*number_of_matrices, temp , nullptr);    //data is send over SPI to MAX7219. Only write, read is voided
                }else{
                    bus.write_and_read(cs, 2*number_of_matrices, temp, temp);        //data is send over SPI to MAX7219. Write and read, scan limit is fetched
                    hwlib::cout << "\nScan_limit passed: " << (int)temp << "\n";     // and put in the consol.
                }            
            }
        }
       
        
        ///Render is a function that puts the to be displayed string, in to a format that command understands. \n
        ///Array_data is where the data is stored in. Array_data[number of chars][count][2]. \n\n
        ///-render_input is the data that will be displayed on the matrix. \n
        ///-time is the time(in ms) that the matrix will be displayed. \n
        ///-mode is the modes the matrix will be dysplayed in. \n
        ///-inverd is whether the data is inverder or not. 0 is off, !0 is on. \n
        ///-rotation is the number of times render_input will be rotated 90 degeers. \n
        ///-number_of_matrices the number of matrices where you want to display on. \n
        ///-count number of size of martix in pixels. \n
        ///-string_lenght the lenght of the string you want to display. \n
        /// \n
        /// Modes:
        /// 1. flashing
        /// 2. shifting right to left
        /// 3. shifting left to right
        void render(byte render_input[8][8], int time, int mode, int inverd, int rotation, int number_of_matrices, int count, int string_lenght)
        {   
            command Aether (bus, cs, array_data, mode, time, number_of_matrices, count, string_lenght);
            mbin_to_mhex Aeolus (matrix_dummy, matrix_data, inverd);
            rotate Ares (matrix_dummy, rotation, count);
            dummy Aristaeus (render_input, matrix_dummy, count);
            
            Aristaeus.copier();
            Ares.rotate_matrix();
            Aeolus.coverter();
            static int j=0;
                for(int i = 0; i<count; i++)
                {
                    array_data[j][i][1] = matrix_data[i][1];                       
                }
            j++;
            if(j==string_lenght)
            {
                
                Aether.commander();
                
            }
        }
        
        ///Tester s a function that tests the matrix. \n
        ///It will display every suported character. In different time, inverd and rotation.\n\n
        ///-mode is the modes the matrix will be dysplayed in. \n
        ///-number_of_matrices the number of matrices where you want to display on. \n
        ///-count number of size of martix in pixels. \n
        ///-string_lenght the lenght of the string you want to display. \n
        /// \n
        /// Modes:
        /// 1. flashing
        /// 2. shifting right to left
        /// 3. shifting left to right
        void tester(int mode, int number_of_matrices, int count)
        {
            int string_lenght = 55 + number_of_matrices*2;
            for(int i =0; i < number_of_matrices; i++)
            {
                    render(char_space,       time, mode, inverd, rotation, number_of_matrices, count, string_lenght);
            }
            render(char_A,           100, mode, 0, 0, number_of_matrices, count, string_lenght);
            render(char_B,           110, mode, 1, 1, number_of_matrices, count, string_lenght);
            render(char_C,           50, mode, 0, 2, number_of_matrices, count, string_lenght);
            render(char_D,           1000, mode, 0, 3, number_of_matrices, count, string_lenght);
            render(char_E,           176, mode, 1, 4, number_of_matrices, count, string_lenght);
            render(char_F,           234, mode, 1, 5, number_of_matrices, count, string_lenght);
            render(char_G,           654, mode, 1, 6, number_of_matrices, count, string_lenght);
            render(char_H,           534, mode, 0, 7, number_of_matrices, count, string_lenght);
            render(char_I,           543, mode, 1, 8, number_of_matrices, count, string_lenght);
            render(char_J,           354, mode, 0, 9, number_of_matrices, count, string_lenght);
            render(char_K,           654, mode, 1, 10, number_of_matrices, count, string_lenght);
            render(char_L,           654, mode, 0, 11, number_of_matrices, count, string_lenght);
            render(char_M,           456, mode, 0, 12, number_of_matrices, count, string_lenght);
            render(char_N,           657, mode, 1, 13, number_of_matrices, count, string_lenght);
            render(char_O,           876, mode, 0, 14, number_of_matrices, count, string_lenght);
            render(char_P,           489, mode, 0, 15, number_of_matrices, count, string_lenght);
            render(char_Q,           78, mode, 1, 16, number_of_matrices, count, string_lenght);
            render(char_R,           123, mode, 0, 17, number_of_matrices, count, string_lenght);
            render(char_S,           564, mode, 1, 18, number_of_matrices, count, string_lenght);
            render(char_T,           987, mode, 0, 19, number_of_matrices, count, string_lenght);
            render(char_U,           454, mode, 0, 20, number_of_matrices, count, string_lenght);
            render(char_V,           123, mode, 1, 21, number_of_matrices, count, string_lenght);
            render(char_W,           98, mode, 0, 22, number_of_matrices, count, string_lenght);
            render(char_X,           876, mode, 0, 23, number_of_matrices, count, string_lenght);
            render(char_Y,           846, mode, 0, 24, number_of_matrices, count, string_lenght);
            render(char_Z,           255, mode, 1, 25, number_of_matrices, count, string_lenght);
            render(char_space,       435, mode, 0, 26, number_of_matrices, count, string_lenght);
            render(char_uit,         435, mode, 0, 27, number_of_matrices, count, string_lenght);
            render(char_random,      654, mode, 0, 28, number_of_matrices, count, string_lenght);
            render(char_underscore,  654, mode, 0, 29, number_of_matrices, count, string_lenght);
            render(char_question,    123, mode, 1, 30, number_of_matrices, count, string_lenght);
            render(char_point,       876, mode, 0, 31, number_of_matrices, count, string_lenght);
            render(char_comma,       485, mode, 0, 32, number_of_matrices, count, string_lenght);
            render(char_square_L,    974, mode, 0, 33, number_of_matrices, count, string_lenght);
            render(char_square_R,    345, mode, 0, 34, number_of_matrices, count, string_lenght);
            render(char_one,         974, mode, 1, 35, number_of_matrices, count, string_lenght);
            render(char_two,         345, mode, 0, 36, number_of_matrices, count, string_lenght);
            render(char_three,       974, mode, 0, 37, number_of_matrices, count, string_lenght);
            render(char_four,        354, mode, 0, 38, number_of_matrices, count, string_lenght);
            render(char_five,        545, mode, 1, 39, number_of_matrices, count, string_lenght);
            render(char_six,         455, mode, 0, 40, number_of_matrices, count, string_lenght);
            render(char_seven,       987, mode, 0, 41, number_of_matrices, count, string_lenght);
            render(char_eight,       110, mode, 0, 42, number_of_matrices, count, string_lenght);
            render(char_nine,        976, mode, 0, 43, number_of_matrices, count, string_lenght);
            render(char_ten,         432, mode, 1, 44, number_of_matrices, count, string_lenght);
            render(char_plus,        234, mode, 0, 45, number_of_matrices, count, string_lenght);
            render(char_minus,       456, mode, 0, 46, number_of_matrices, count, string_lenght);
            render(char_divide,      654, mode, 0, 47, number_of_matrices, count, string_lenght);
            render(char_multiply,    704, mode, 0, 48, number_of_matrices, count, string_lenght);
            render(char_equal,       360, mode, 1, 49, number_of_matrices, count, string_lenght);
            render(char_semicolom,   420, mode, 0, 50000, number_of_matrices, count, string_lenght);
            for(int i =0; i < number_of_matrices; i++)
            {
                    render(char_space,       time, mode, inverd, rotation, number_of_matrices, count, string_lenght);
            }
        
        }
    };

#endif // MAX7219_HPP