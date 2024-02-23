#ifndef MACDECODER_H
#define MACDECODER_H
#include<iostream>
#include<fstream>
#include "mac_decoder.h"
#include "mac_decoder.cpp"
using namespace  std;

/* header file to get hex value with range 00 to ff */
#include <sstream>
#include <iomanip>

int main(){
    MAC_HEADER obj1;
    int choice;
    string hexadecimal;

    //lable:
    // cout<<"User input for hexadecimal number:"<<endl;
    // cin>>hexadecimal;
    /* FOR EACH HEXA VALUE FROM RANGE 0 TO 255 i.e 0X00 TO 0XFF*/
    for (int i = 0x00; i <= 0xFF; ++i) {
        std::ostringstream oss;
        oss << std::hex << std::setw(2) << std::setfill('0') << i;
        std::string hexadecimal = oss.str().substr(oss.str().size() - 2);
        cout<<"Hexadecimalvalue"<<hexadecimal<<endl;
    
    // if(validation(hexadecimal)){
    //     cout<<"\n"<<"Valid user input"<<endl;
    // }
    // else{
    //     cout<<"Invalid user input"<<endl;
    //     return 0;
    // }

    obj1.header = static_cast<int8_t>(std::stoi(hexadecimal, nullptr, 16));
    cout << "Converted MAC_PDU  header: " << static_cast<int>(obj1.header) <<endl;
    /*writing onto the files*/
    ofstream file1("output_DL.txt", std::ios::out | std::ios::app); // Open file1.txt in write mode
    ofstream file2("output_UL.txt", std::ios::out |std::ios::app); // Open file2.txt in append mode

    if (file1.is_open() && file2.is_open()) {
        // Write content to file1.txt
        file1 << "Converted MAC_PDU  header: " << static_cast<int>(obj1.header) <<endl;

        // Append content to file2.txt
        file2 << "Converted MAC_PDU  header: " << static_cast<int>(obj1.header) <<endl;

        file1.close(); // Close file1.txt
        file2.close(); // Close file2.txt

        std::cout << "Content written to files successfully." << std::endl;
    } else {
        std::cout << "Unable to open the files." << std::endl;
    }
    //lable:
   // while(1){
    cout<<" ****************************************"<<endl;
    cout<<"Enter the valid option for finding LCID "<<endl;
    cout<<"1.Finding the LCID value MAC-PDU decoder DOWNLINK"<<endl;
    cout<<"2.Finding the LCID value MAC-PDU decoder UPLINK"<<endl;
    //cout<<"3.Input to find LCID value for another hex input  "<<endl;
    // cout<<"4. Read the MAC_DECODER_DL data from the file"<<endl;
    // cout<<"5.Read the MAC_DECODER_UL data from the file"<<endl;
    cout<<"3.EXIT FROM EXECUTION "<<endl;
    cout<<" ****************************************"<<endl;
    cin>>choice;
    switch(choice){
        case 1: downlink(hexadecimal);//Find the value of LCID for downlink
                break;
        case 2: uplink(hexadecimal);//Find the value of LCID for uplink
            break;
        // case 3: goto lable; // User input
        //     break;
        // case 4:read_file_for_DL();//Read the content of the file for Downlink LCID value
        //     break;
        // case 5:read_file_for_UL();//Read the content of the file for uplink LCID value
        //     break;
        case 3:exit(0);//exit 
             break;
        default:
                cout<<"Enter valid option"<<endl;
                //goto lable;
                
    }
    }
    return 0;
}
#endif